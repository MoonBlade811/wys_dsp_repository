//-----------------------------------------------------------------------------
// \file    main.c
// \brief   implementation of main()
//
//-----------------------------------------------------------------------------

/*****************************************************************************
**                       Include Files
*****************************************************************************/
#include "hw_types.h"
#include "hw_syscfg0_C6748.h"
#include "hw_pllc_C6748.h"
#include "hw_ddr2_mddr.h"
#include "hw_syscfg1_C6748.h"

/* Device/Platform lib headers */
#include "soc_C6748.h"
#include "delay.h"

#include "user_syscfg.h"


/*****************************************************************************
**                     Internal Macro Definitions
*****************************************************************************/
#define CLK_PLL0_SYSCLK3                  (0xFFFFFFF8)

/******************************************************************************
**                     Global variable Definitions
*******************************************************************************/


/******************************************************************************
**                     Local function Declarations
*******************************************************************************/
static void PLL0Init(unsigned char clk_src, unsigned char pllm,
                     unsigned char prediv, unsigned char postdiv, unsigned char div1,
                     unsigned char div3, unsigned char div7);
static void PLL1Init(unsigned char pllm, unsigned char postdiv,
                     unsigned char div1, unsigned char div2, unsigned char div3);




/*
** This function converts a 8 bit number to its ASCII equivalent value.
** The 8 bit number is passed as a parameter to this function.
*/

unsigned int IntToASCII(unsigned char byte)
{
  unsigned int retVal = 0;
  unsigned char lsn = 0, msn = 0;
  lsn = (byte & 0x0F);
  msn = (byte & 0xF0) >> 0x04;

  retVal = (lsn + 0x30);
  retVal |= ((msn + 0x30) << 0x08);

  return retVal;
}

/*
** This function converts the ASCII value of a hexadecimal number to its
** equivalent hexadecimal value.
*/

unsigned char ASCIIToInt(unsigned char byte)
{
  unsigned char retVal = 0;

  /* For numbers from 0x0 to 0x9.*/
  if((byte >= 0x30) && (byte <= 0x39))
  {
    retVal = byte - 0x30;
  }
  /* For alphabets from A to Z.*/
  else if((byte >= 0x41) && (byte <= 0x46))
  {
    retVal = byte - 0x37;
  }

  return retVal;
}

//-----------------------------------------------------------------------------
// \brief   configures the desired pin mux register.
//
// \param   uint32_t in_reg - pin mux register to be configured.
//
// \param   uint32_t in_mask - bits to be set in pin mux register.
//
// \param   uint32_t in_val - value to set the pin mux register.
//
// \return  none.
//-----------------------------------------------------------------------------
void pinmuxConfig(unsigned int in_reg, unsigned int in_mask, unsigned int in_val)
{
  unsigned int savePinmux = 0;

  /* unlock the system config registers. */
  SysCfgRegistersUnlock();

  /* make sure the pinmux register is cleared for the mask bits before setting the value. */
  /* Clearing the bit in context and retaining the other bit values in PINMUX10 register. */
  savePinmux = (HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(in_reg)) & ~(in_mask));
  /* Setting the pins corresponding to GP4[0] in PINMUX10 register.*/
  HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_PINMUX(in_reg)) = (in_val | savePinmux);

  /* lock the system config registers. */
  SysCfgRegistersLock();
}

/*
 * \brief This function Configures the PLL0 registers.
 *      PLL Register are set to achieve the desired frequencies.
 *
 * \param  clk_src
 * \param  pllm             This value is assigned to the PLLMultipler register.
 * \param  prediv           This value is assigned to the PLLMultipler register.
 * \param  postdiv          This value is assigned to the PLL_Postdiv register.
 * \param  div1             This value is assigned to the PLL_DIV1 register.
 * \param  div3             This value is assigned to the PLL_DIV3 register.
 * \param  div7             This value is assigned to the PLL_DIV7 register.
 *
 * \return Int              Returns success or failure
*/
static void PLL0Init(unsigned char clk_src, unsigned char pllm,
                     unsigned char prediv, unsigned char postdiv, unsigned char div1,
                     unsigned char div3, unsigned char div7)
{
  HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_CFGCHIP0) &= ~SYSCFG_CFGCHIP0_PLL_MASTER_LOCK;

  /* PLLENSRC must be cleared before PLLEN bit have any effect */
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLCTL) &= ~PLLC_PLLCTL_PLLENSRC;

  /* PLLCTL.EXTCLKSRC bit 9 should be left at 0  */
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLCTL) &= ~PLLC_PLLCTL_EXTCLKSRC;

  /* PLLEN = 0 put pll in bypass mode  */
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLCTL) &= ~PLLC_PLLCTL_PLLEN;

  /* wait for 2 counts to switch pll to the by pass mode */
  Delay(2);

  /* Select the Clock Mode bit 8 as External Clock or On Chip Oscilator  */
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLCTL) &= ~PLLC_PLLCTL_CLKMODE;
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLCTL) |= (clk_src << 8);

  /* Clear the PLLRST to reset the PLL */
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLCTL) &= ~PLLC_PLLCTL_PLLRST;

  /* Disable PLL out */
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLCTL) |= PLLC_PLLCTL_PLLDIS;

  /* PLL initialization sequece, power up the PLL */
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLCTL) &= ~PLLC_PLLCTL_PLLPWRDN;

  HWREG(SOC_PLLC_0_REGS + PLLC_PLLCTL) &= ~PLLC_PLLCTL_PLLDIS;

  /* Wait for 300 counts */
  Delay(300);

  HWREG(SOC_PLLC_0_REGS + PLLC_PLLM) = pllm;

  /* Program the required multiplier value   */
  HWREG(SOC_PLLC_0_REGS + PLLC_PREDIV) = PLLC_PREDIV_PREDEN | prediv;
  HWREG(SOC_PLLC_0_REGS + PLLC_POSTDIV) = PLLC_POSTDIV_POSTDEN | postdiv;

  /* Check for the GOSTAT bit in PLLSTAT to clear to 0 to indicate that
                no GO operation is currently in progress */
  while (HWREG(SOC_PLLC_0_REGS + PLLC_PLLSTAT) & PLLC_PLLSTAT_GOSTAT  );

  /* divider values are assigned */
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLDIV1) = PLLC_PLLDIV1_D1EN | div1;
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLDIV2) = PLLC_PLLDIV2_D2EN | (((div1 + 1) * 2) - 1);
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLDIV4) = PLLC_PLLDIV4_D4EN | (((div1 + 1) * 4)- 1);
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLDIV6) = PLLC_PLLDIV6_D6EN | div1;
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLDIV3) = PLLC_PLLDIV3_D3EN | div3;
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLDIV7) = PLLC_PLLDIV7_D7EN | div7;

  HWREG(SOC_PLLC_0_REGS + PLLC_PLLCMD) |= PLLC_PLLCMD_GOSET;

  /*Wait for the Gostat bit in PLLSTAT to clear to 0 ( completion of phase alignment) */
  while (HWREG(SOC_PLLC_0_REGS + PLLC_PLLSTAT) & PLLC_PLLSTAT_GOSTAT);

  /* Wait for 40 counts */
  Delay(40);

  /* set the PLLRST bit in PLLCTL to 1,bring the PLL out of reset */
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLCTL) |= PLLC_PLLCTL_PLLRST;

  /* Wait for 300 counts*/
  Delay(300);

  /*removing pll from bypass mode */
  HWREG(SOC_PLLC_0_REGS + PLLC_PLLCTL) |= PLLC_PLLCTL_PLLEN;

  /* set PLL lock bit */
  HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_CFGCHIP0) |= (0x01 << SYSCFG_CFGCHIP0_PLL_MASTER_LOCK_SHIFT) & SYSCFG_CFGCHIP0_PLL_MASTER_LOCK;

  /* DIV45PENA = 0, Divide by 4.5 is disabled.
   * EMA_CLKSRC = 0, EMIFA clock driven by PLL0_SYSCLK3 */
  HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_CFGCHIP3) &= CLK_PLL0_SYSCLK3;
}

/*
 * \brief This function Configures the PLL1 registers.
    PLL Register are set to achieve the desired frequencies.
 *
 * \param  clk_src
 *          pllm             This value is assigned to the PLL1Multipler register.
 *          postdiv          This value is assigned to the PLL1_Postdiv register.
 *          div1             This value is assigned to the PLL1_Div1 register.
 *          div2             This value is assigned to the PLL1_Div2 register.
 *          div3             This value is assigned to the PLL1_Div3 register.
 *
 * \return Int          Returns Success or Failure,depending on the execution
*/
static void PLL1Init(unsigned char pllm, unsigned char postdiv,
                     unsigned char div1, unsigned char div2, unsigned char div3)
{
  /* Clear PLL lock bit */
  HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_CFGCHIP3) &= ~SYSCFG_CFGCHIP3_PLL1_MASTER_LOCK;

  /* PLLENSRC must be cleared before PLLEN has any effect */
  HWREG(SOC_PLLC_1_REGS + PLLC_PLLCTL) &= ~PLLC_PLLCTL_PLLENSRC;

  /* PLLCTL.EXTCLKSRC bit 9 should be left at 0  */
  HWREG(SOC_PLLC_1_REGS + PLLC_PLLCTL) &= ~PLLC_PLLCTL_EXTCLKSRC;

  /* Set PLLEN=0 to put in bypass mode */
  HWREG(SOC_PLLC_1_REGS + PLLC_PLLCTL) &= ~PLLC_PLLCTL_PLLEN;

  /* wait for 4 cycles to allow PLLEN mux switches properly to bypass clock */
  Delay(4);

  /* Clear PLLRST bit to reset the PLL */
  HWREG(SOC_PLLC_1_REGS + PLLC_PLLCTL) &= ~PLLC_PLLCTL_PLLRST;

  /* Disable the PLL output */
  HWREG(SOC_PLLC_1_REGS + PLLC_PLLCTL) &= PLLC_PLLCTL_PLLDIS;

  /* PLL initialization sequence */
  /* Power up the PLL by setting PWRDN bit set to 0 */
  HWREG(SOC_PLLC_1_REGS + PLLC_PLLCTL) &= ~PLLC_PLLCTL_PLLPWRDN ;

  /* Enable the PLL output */
  HWREG(SOC_PLLC_1_REGS + PLLC_PLLCTL) &= ~PLLC_PLLCTL_PLLDIS;

  Delay(300);

  /* Multiplier value is set */
  HWREG(SOC_PLLC_1_REGS + PLLC_PLLM) = pllm;

  HWREG(SOC_PLLC_1_REGS + PLLC_POSTDIV) = PLLC_POSTDIV_POSTDEN | postdiv;

  while ( HWREG(SOC_PLLC_1_REGS + PLLC_PLLSTAT) & PLLC_PLLCMD_GOSET  );
  HWREG(SOC_PLLC_1_REGS + PLLC_PLLDIV1) = PLLC_PLLDIV1_D1EN | div1;
  HWREG(SOC_PLLC_1_REGS + PLLC_PLLDIV2) = PLLC_PLLDIV2_D2EN | div2;
  HWREG(SOC_PLLC_1_REGS + PLLC_PLLDIV3) = PLLC_PLLDIV3_D3EN | div3;

  /* Set the GOSET bit in PLLCMD to 1 to initiate a new divider transition */
  HWREG(SOC_PLLC_1_REGS + PLLC_PLLCMD) |= PLLC_PLLCMD_GOSET;

  while (HWREG(SOC_PLLC_1_REGS + PLLC_PLLSTAT) & PLLC_PLLSTAT_GOSTAT);

  /* Wait for the Gostat bit in PLLSTAT to clear to 0 ( complition of phase alignment ) */
  Delay(40);

  /* set the PLLRST bit in PLLCTL to 1,bring the PLL out of reset  */
  HWREG(SOC_PLLC_1_REGS + PLLC_PLLCTL) |= PLLC_PLLCTL_PLLRST;
  Delay(300);

  /* Removing PLL from bypass mode */
  HWREG(SOC_PLLC_1_REGS + PLLC_PLLCTL) |= PLLC_PLLCTL_PLLEN;

  /* set PLL lock bit */
  HWREG(SOC_SYSCFG_0_REGS + SYSCFG0_CFGCHIP3) |= (0x1 << SYSCFG_CFGCHIP3_PLL1_MASTER_LOCK_SHIFT) & SYSCFG_CFGCHIP3_PLL1_MASTER_LOCK;
}


void SYSCFG_Init(void)
{
  /* Unlock kick registers (necessary on C6748) */
  SysCfgRegistersUnlock();

  /* Set the PLL0 to generate 300MHz for DSP */
  PLL0Init(PLL_CLK_SRC, PLL0_MUL, PLL0_PREDIV, PLL0_POSTDIV, PLL0_DIV1, PLL0_DIV3, PLL0_DIV7);

  /* DDR Initialization 150M */
  PLL1Init(PLL1_MUL, PLL1_POSTDIV, PLL1_DIV1, PLL1_DIV2, PLL1_DIV3);

  /* lock kick registers (necessary on C6748) */
  SysCfgRegistersLock();
}

/********************************* End of file *******************************/

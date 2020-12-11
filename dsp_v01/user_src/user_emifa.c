//-----------------------------------------------------------------------------
// \file    main.c
// \brief   implementation of main()
//
//-----------------------------------------------------------------------------

/*****************************************************************************
**                       Include Files
*****************************************************************************/
/* HW Macros */
#include "hw_types.h"

/* System Defines */
//#include "evmC6748.h"
#include "soc_C6748.h"
#include "hw_syscfg0_C6748.h"
#include "psc.h"
#include "hw_emifa2.h"
#include "emifa.h"
#include "nandlib.h"
#include "nand_emifa2.h"
#include "nandDma.h"
#include "uartStdio.h"
#include "user_syscfg.h"
#include "user_emifa.h"

/*****************************************************************************
**                     Internal Macro Definitions
*****************************************************************************/
#define PINMUX5_EMIFA_MASK       0xFF000000
#define PINMUX5_EMIFA_ENABLE     (SYSCFG_PINMUX5_PINMUX5_31_28_EMA_BA0 << \
                                  SYSCFG_PINMUX5_PINMUX5_31_28_SHIFT) | \
                                 (SYSCFG_PINMUX5_PINMUX5_27_24_EMA_BA1 << \
                                  SYSCFG_PINMUX5_PINMUX5_27_24_SHIFT)

#define PINMUX6_EMIFA_MASK       0x0F00000F
#define PINMUX6_EMIFA_ENABLE     (SYSCFG_PINMUX6_PINMUX6_31_28_NEMA_CS0 << \
                                  SYSCFG_PINMUX6_PINMUX6_31_28_SHIFT) | \
                                 (SYSCFG_PINMUX6_PINMUX6_27_24_EMA_WAIT1 << \
                                  SYSCFG_PINMUX6_PINMUX6_27_24_SHIFT) | \
                                 (SYSCFG_PINMUX6_PINMUX6_23_20_NEMA_WE_DQM1 << \
                                  SYSCFG_PINMUX6_PINMUX6_23_20_SHIFT) | \
                                 (SYSCFG_PINMUX6_PINMUX6_19_16_NEMA_WE_DQM0 << \
                                  SYSCFG_PINMUX6_PINMUX6_19_16_SHIFT) | \
                                 (SYSCFG_PINMUX6_PINMUX6_15_12_NEMA_CAS << \
                                  SYSCFG_PINMUX6_PINMUX6_15_12_SHIFT) | \
                                 (SYSCFG_PINMUX6_PINMUX6_11_8_NEMA_RAS << \
                                  SYSCFG_PINMUX6_PINMUX6_11_8_SHIFT) | \
                                 (SYSCFG_PINMUX6_PINMUX6_7_4_EMA_SDCKE << \
                                  SYSCFG_PINMUX6_PINMUX6_7_4_SHIFT) | \
                                 (SYSCFG_PINMUX6_PINMUX6_3_0_EMA_CLK << \
                                  SYSCFG_PINMUX6_PINMUX6_3_0_SHIFT)

#define PINMUX7_EMIFA_MASK       0x00FF000F
#define PINMUX7_EMIFA_ENABLE     (SYSCFG_PINMUX7_PINMUX7_31_28_EMA_WAIT0 << \
                                  SYSCFG_PINMUX7_PINMUX7_31_28_SHIFT) | \
                                 (SYSCFG_PINMUX7_PINMUX7_27_24_NEMA_RNW << \
                                  SYSCFG_PINMUX7_PINMUX7_27_24_SHIFT) | \
                                 (SYSCFG_PINMUX7_PINMUX7_23_20_NEMA_OE << \
                                  SYSCFG_PINMUX7_PINMUX7_23_20_SHIFT) | \
                                 (SYSCFG_PINMUX7_PINMUX7_19_16_NEMA_WE << \
                                  SYSCFG_PINMUX7_PINMUX7_19_16_SHIFT) | \
                                 (SYSCFG_PINMUX7_PINMUX7_15_12_NEMA_CS5 << \
                                  SYSCFG_PINMUX7_PINMUX7_15_12_SHIFT) | \
                                 (SYSCFG_PINMUX7_PINMUX7_11_8_NEMA_CS4 << \
                                  SYSCFG_PINMUX7_PINMUX7_11_8_SHIFT) | \
                                 (SYSCFG_PINMUX7_PINMUX7_7_4_NEMA_CS3 << \
                                  SYSCFG_PINMUX7_PINMUX7_7_4_SHIFT) | \
                                 (SYSCFG_PINMUX7_PINMUX7_3_0_NEMA_CS2 << \
                                  SYSCFG_PINMUX7_PINMUX7_3_0_SHIFT)

#define PINMUX8_EMIFA_MASK       0xFFFFFFFF
#define PINMUX8_EMIFA_ENABLE     (SYSCFG_PINMUX8_PINMUX8_31_28_EMA_D8 << \
                                  SYSCFG_PINMUX8_PINMUX8_31_28_SHIFT) | \
                                 (SYSCFG_PINMUX8_PINMUX8_27_24_EMA_D9 << \
                                  SYSCFG_PINMUX8_PINMUX8_27_24_SHIFT) | \
                                 (SYSCFG_PINMUX8_PINMUX8_23_20_EMA_D10 << \
                                  SYSCFG_PINMUX8_PINMUX8_23_20_SHIFT) | \
                                 (SYSCFG_PINMUX8_PINMUX8_19_16_EMA_D11 << \
                                  SYSCFG_PINMUX8_PINMUX8_19_16_SHIFT) | \
                                 (SYSCFG_PINMUX8_PINMUX8_15_12_EMA_D12 << \
                                  SYSCFG_PINMUX8_PINMUX8_15_12_SHIFT) | \
                                 (SYSCFG_PINMUX8_PINMUX8_11_8_EMA_D13 << \
                                  SYSCFG_PINMUX8_PINMUX8_11_8_SHIFT) | \
                                 (SYSCFG_PINMUX8_PINMUX8_7_4_EMA_D14 << \
                                  SYSCFG_PINMUX8_PINMUX8_7_4_SHIFT) | \
                                 (SYSCFG_PINMUX8_PINMUX8_3_0_EMA_D15 << \
                                  SYSCFG_PINMUX8_PINMUX8_3_0_SHIFT)

#define PINMUX9_EMIFA_MASK       0xFFFFFFFF
#define PINMUX9_EMIFA_ENABLE     (SYSCFG_PINMUX9_PINMUX9_3_0_EMA_D7 << \
                                 SYSCFG_PINMUX9_PINMUX9_3_0_SHIFT) | \
                                (SYSCFG_PINMUX9_PINMUX9_7_4_EMA_D6 << \
                                 SYSCFG_PINMUX9_PINMUX9_7_4_SHIFT) | \
                                (SYSCFG_PINMUX9_PINMUX9_11_8_EMA_D5 << \
                                 SYSCFG_PINMUX9_PINMUX9_11_8_SHIFT) | \
                                (SYSCFG_PINMUX9_PINMUX9_15_12_EMA_D4 << \
                                 SYSCFG_PINMUX9_PINMUX9_15_12_SHIFT) | \
                                (SYSCFG_PINMUX9_PINMUX9_19_16_EMA_D3 << \
                                 SYSCFG_PINMUX9_PINMUX9_19_16_SHIFT) | \
                                (SYSCFG_PINMUX9_PINMUX9_23_20_EMA_D2 << \
                                 SYSCFG_PINMUX9_PINMUX9_23_20_SHIFT) | \
                                (SYSCFG_PINMUX9_PINMUX9_27_24_EMA_D1 << \
                                 SYSCFG_PINMUX9_PINMUX9_27_24_SHIFT) | \
                                (SYSCFG_PINMUX9_PINMUX9_31_28_EMA_D0 << \
                                 SYSCFG_PINMUX9_PINMUX9_31_28_SHIFT)

#define PINMUX10_EMIFA_MASK       0xFFFFFFFF
#define PINMUX10_EMIFA_ENABLE     (SYSCFG_PINMUX10_PINMUX10_31_28_EMA_A16 << \
                                  SYSCFG_PINMUX10_PINMUX10_31_28_SHIFT) | \
                                 (SYSCFG_PINMUX10_PINMUX10_27_24_EMA_A17 << \
                                  SYSCFG_PINMUX10_PINMUX10_27_24_SHIFT) | \
                                 (SYSCFG_PINMUX10_PINMUX10_23_20_EMA_A18 << \
                                  SYSCFG_PINMUX10_PINMUX10_23_20_SHIFT) | \
                                 (SYSCFG_PINMUX10_PINMUX10_19_16_EMA_A19 << \
                                  SYSCFG_PINMUX10_PINMUX10_19_16_SHIFT) | \
                                 (SYSCFG_PINMUX10_PINMUX10_15_12_EMA_A20 << \
                                  SYSCFG_PINMUX10_PINMUX10_15_12_SHIFT) | \
                                 (SYSCFG_PINMUX10_PINMUX10_11_8_EMA_A21 << \
                                  SYSCFG_PINMUX10_PINMUX10_11_8_SHIFT) | \
                                 (SYSCFG_PINMUX10_PINMUX10_7_4_EMA_A22 << \
                                  SYSCFG_PINMUX10_PINMUX10_7_4_SHIFT) | \
                                 (SYSCFG_PINMUX10_PINMUX10_3_0_EMA_A23 << \
                                  SYSCFG_PINMUX10_PINMUX10_3_0_SHIFT)

#define PINMUX11_EMIFA_MASK       0xFFFFFFFF
#define PINMUX11_EMIFA_ENABLE    (SYSCFG_PINMUX11_PINMUX11_31_28_EMA_A8 << \
                                  SYSCFG_PINMUX11_PINMUX11_31_28_SHIFT) | \
                                 (SYSCFG_PINMUX11_PINMUX11_27_24_EMA_A9 << \
                                  SYSCFG_PINMUX11_PINMUX11_27_24_SHIFT) | \
                                 (SYSCFG_PINMUX11_PINMUX11_23_20_EMA_A10 << \
                                  SYSCFG_PINMUX11_PINMUX11_23_20_SHIFT) | \
                                 (SYSCFG_PINMUX11_PINMUX11_19_16_EMA_A11 << \
                                  SYSCFG_PINMUX11_PINMUX11_19_16_SHIFT) | \
                                 (SYSCFG_PINMUX11_PINMUX11_15_12_EMA_A12 << \
                                  SYSCFG_PINMUX11_PINMUX11_15_12_SHIFT) | \
                                 (SYSCFG_PINMUX11_PINMUX11_11_8_EMA_A13 << \
                                  SYSCFG_PINMUX11_PINMUX11_11_8_SHIFT) | \
                                 (SYSCFG_PINMUX11_PINMUX11_7_4_EMA_A14 << \
                                  SYSCFG_PINMUX11_PINMUX11_7_4_SHIFT) | \
                                 (SYSCFG_PINMUX11_PINMUX11_3_0_EMA_A15 << \
                                  SYSCFG_PINMUX11_PINMUX11_3_0_SHIFT)

#define PINMUX12_EMIFA_MASK       0xFFFFFFFF
#define PINMUX12_EMIFA_ENABLE    (SYSCFG_PINMUX12_PINMUX12_31_28_EMA_A0 << \
                                  SYSCFG_PINMUX12_PINMUX12_31_28_SHIFT) | \
                                 (SYSCFG_PINMUX12_PINMUX12_27_24_EMA_A1 << \
                                  SYSCFG_PINMUX12_PINMUX12_27_24_SHIFT) | \
                                 (SYSCFG_PINMUX12_PINMUX12_23_20_EMA_A2 << \
                                  SYSCFG_PINMUX12_PINMUX12_23_20_SHIFT) | \
                                 (SYSCFG_PINMUX12_PINMUX12_19_16_EMA_A3 << \
                                  SYSCFG_PINMUX12_PINMUX12_19_16_SHIFT) | \
                                 (SYSCFG_PINMUX12_PINMUX12_15_12_EMA_A4 << \
                                  SYSCFG_PINMUX12_PINMUX12_15_12_SHIFT) | \
                                 (SYSCFG_PINMUX12_PINMUX12_11_8_EMA_A5 << \
                                  SYSCFG_PINMUX12_PINMUX12_11_8_SHIFT) | \
                                 (SYSCFG_PINMUX12_PINMUX12_7_4_EMA_A6 << \
                                  SYSCFG_PINMUX12_PINMUX12_7_4_SHIFT) | \
                                 (SYSCFG_PINMUX12_PINMUX12_3_0_EMA_A7 << \
                                  SYSCFG_PINMUX12_PINMUX12_3_0_SHIFT)

#define EMIFA_ASIZE_8BIT_SHIFT         0
#define EMIFA_ASIZE_16BIT_SHIFT        1

/*****************************************************************************/
/*
** Macros which defines the NAND timing info.
**
*/
/* Maximum extended wait time                                       */
#define NAND_MAX_EXT_WAIT                       (0xFF)

/* Setup,strobe,hold times for read/write for the dev MT29F4G08AAA  */
#define NAND_WRITE_SETUP_TIME_IN_NS             (0u)
#define NAND_WRITE_STROBE_TIME_IN_NS            (30u)
#define NAND_WRITE_HOLD_TIME_IN_NS              (30u)
#define NAND_READ_SETUP_TIME_IN_NS              (20u)
#define NAND_READ_STROBE_TIME_IN_NS             (40u)
#define NAND_READ_HOLD_TIME_IN_NS               (0u)
#define NAND_TURN_ARND_TIME_IN_NS               (0u)

/* Setup,strobe,hold times reset values                             */
#define EMIFA_WRITE_SETUP_RESETVAL              (0x0F)
#define EMIFA_WRITE_STROBE_RESETVAL             (0x3F)
#define EMIFA_WRITE_HOLD_RESETVAL               (0x07)
#define EMIFA_READ_SETUP_RESETVAL               (0x0F)
#define EMIFA_READ_STROBE_RESETVAL              (0x3F)
#define EMIFA_READ_HOLD_RESETVAL                (0x07)
#define EMIFA_TA_RESETVAL                       (0x03)

/* NAND Module clk frequency                                        */
#define NAND_MODULE_CLK                         (100000000)//((100u)*(1000u)*(1000u))
#define NAND_MODULE_CLK_IN_MHZ                  (100)//(NAND_MODULE_CLK / 1000000)


/******************************************************************************
**                     Local variable Definitions
*******************************************************************************/

/* NAND structure allocations for this application */
       NandInfo_t              nandInfo;
//static NandCtrlInfo_t          nandCtrlInfo;
//static NandEccInfo_t           nandEccInfo;
//static NandDmaInfo_t           nandDmaInfo;
//static EMIFANANDTimingInfo_t   nandTimingInfo;



/******************************************************************************
**                     Local function Declarations
*******************************************************************************/
static void EMIFAClkConfig(void);
static void EMIFAPinMuxSetup(void);

/******************************************************************************
**                     Global variable Definitions
*******************************************************************************/
//unsigned short NAND_TxData[NAND_DATA_BUFF_SIZE];
//unsigned short NAND_RxData[NAND_DATA_BUFF_SIZE];
//unsigned short NAND_EccData[NAND_ECC_BUFF_SIZE];



/**
 * \brief   This function enables the EMIF modules and clocks on the SoC.
 *
 * \param   None.
 *
 * \return  None.
 */
static void EMIFAClkConfig(void)
{
  /* Power on the EMIFA */
  PSCModuleControl(SOC_PSC_0_REGS, HW_PSC_EMIFA, PSC_POWERDOMAIN_ALWAYS_ON, PSC_MDCTL_NEXT_ENABLE);
}

/**
 * \brief   This function selects the EMIFA pins for use. The EMIFA pins
 *          are multiplexed with pins of other peripherals in the
 *          System on Chip(SoC).
 *
 * \param   None.
 *
 * \return  None.
 */
static void EMIFAPinMuxSetup(void)
{
  /* Pin Multiplexing of EMIFA.*/
  pinmuxConfig(5, PINMUX5_EMIFA_MASK, PINMUX5_EMIFA_ENABLE);
  pinmuxConfig(6, PINMUX6_EMIFA_MASK, PINMUX6_EMIFA_ENABLE);
  pinmuxConfig(7, PINMUX7_EMIFA_MASK, PINMUX7_EMIFA_ENABLE);
  pinmuxConfig(8, PINMUX8_EMIFA_MASK, PINMUX8_EMIFA_ENABLE);
  pinmuxConfig(9, PINMUX9_EMIFA_MASK, PINMUX9_EMIFA_ENABLE);
  pinmuxConfig(10, PINMUX10_EMIFA_MASK, PINMUX10_EMIFA_ENABLE);
  pinmuxConfig(11, PINMUX11_EMIFA_MASK, PINMUX11_EMIFA_ENABLE);
  pinmuxConfig(12, PINMUX12_EMIFA_MASK, PINMUX12_EMIFA_ENABLE);
}

static void EMIFAWriteCycleConfig(unsigned int CEnCFG, unsigned int W_Setup, unsigned int W_Strobe, unsigned int W_Hold)
{
  switch(CEnCFG)
  {
    case EMIFA_CE2CFG:
      CLRREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE2CFG), (EMIFA_CE2CFG_W_SETUP | EMIFA_CE2CFG_W_STROBE | EMIFA_CE2CFG_W_HOLD));
      SETREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE2CFG), \
    		   ((W_Setup << EMIFA_CE2CFG_W_SETUP_SHIFT) | \
    		    (W_Strobe << EMIFA_CE2CFG_W_STROBE_SHIFT) | \
    		    (W_Hold << EMIFA_CE2CFG_W_HOLD_SHIFT)));
	  break;

	case EMIFA_CE3CFG:
	  CLRREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE3CFG), (EMIFA_CE3CFG_W_SETUP | EMIFA_CE3CFG_W_STROBE | EMIFA_CE3CFG_W_HOLD));
	  SETREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE3CFG), \
		       ((W_Setup << EMIFA_CE3CFG_W_SETUP_SHIFT) | \
		        (W_Strobe << EMIFA_CE3CFG_W_STROBE_SHIFT) | \
		        (W_Hold << EMIFA_CE3CFG_W_HOLD_SHIFT)));
	  break;

	case EMIFA_CE4CFG:
	  CLRREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE4CFG), (EMIFA_CE4CFG_W_SETUP | EMIFA_CE4CFG_W_STROBE | EMIFA_CE4CFG_W_HOLD));
	  SETREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE4CFG), \
			   ((W_Setup << EMIFA_CE4CFG_W_SETUP_SHIFT) | \
			    (W_Strobe << EMIFA_CE4CFG_W_STROBE_SHIFT) | \
			    (W_Hold << EMIFA_CE4CFG_W_HOLD_SHIFT)));
	  break;

	case EMIFA_CE5CFG:
	  CLRREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE5CFG), (EMIFA_CE5CFG_W_SETUP | EMIFA_CE5CFG_W_STROBE | EMIFA_CE5CFG_W_HOLD));
	  SETREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE5CFG), \
			   ((W_Setup << EMIFA_CE5CFG_W_SETUP_SHIFT) | \
			    (W_Strobe << EMIFA_CE5CFG_W_STROBE_SHIFT) | \
			    (W_Hold << EMIFA_CE5CFG_W_HOLD_SHIFT)));
	  break;

	default:
	  break;
  }
}

static void EMIFAReadCycleConfig(unsigned int CEnCFG, unsigned int R_Setup, unsigned int R_Strobe, unsigned int R_Hold)
{
  switch(CEnCFG)
  {
    case EMIFA_CE2CFG:
      CLRREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE2CFG), (EMIFA_CE2CFG_R_SETUP | EMIFA_CE2CFG_R_STROBE | EMIFA_CE2CFG_R_HOLD));
      SETREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE2CFG), \
    		   ((R_Setup << EMIFA_CE2CFG_R_SETUP_SHIFT) | \
    		    (R_Strobe << EMIFA_CE2CFG_R_STROBE_SHIFT) | \
    		    (R_Hold << EMIFA_CE2CFG_R_HOLD_SHIFT)));
	  break;

	case EMIFA_CE3CFG:
	  CLRREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE3CFG), (EMIFA_CE3CFG_R_SETUP | EMIFA_CE3CFG_R_STROBE | EMIFA_CE3CFG_R_HOLD));
	  SETREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE3CFG), \
		       ((R_Setup << EMIFA_CE3CFG_R_SETUP_SHIFT) | \
		        (R_Strobe << EMIFA_CE3CFG_R_STROBE_SHIFT) | \
		        (R_Hold << EMIFA_CE3CFG_R_HOLD_SHIFT)));
	  break;

	case EMIFA_CE4CFG:
	  CLRREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE4CFG), (EMIFA_CE4CFG_R_SETUP | EMIFA_CE4CFG_R_STROBE | EMIFA_CE4CFG_R_HOLD));
	  SETREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE4CFG), \
			   ((R_Setup << EMIFA_CE4CFG_R_SETUP_SHIFT) | \
			    (R_Strobe << EMIFA_CE4CFG_R_STROBE_SHIFT) | \
			    (R_Hold << EMIFA_CE4CFG_R_HOLD_SHIFT)));
	  break;

	case EMIFA_CE5CFG:
	  CLRREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE5CFG), (EMIFA_CE5CFG_R_SETUP | EMIFA_CE5CFG_R_STROBE | EMIFA_CE5CFG_R_HOLD));
	  SETREGBIT((SOC_EMIFA_0_REGS + EMIFA_CE5CFG), \
			   ((R_Setup << EMIFA_CE5CFG_R_SETUP_SHIFT) | \
			    (R_Strobe << EMIFA_CE5CFG_R_STROBE_SHIFT) | \
			    (R_Hold << EMIFA_CE5CFG_R_HOLD_SHIFT)));
	  break;

	default:
	  break;
  }
}

/**
 * \brief   This function selects the EMIFA pins for use is 8-bit or 16-bit.
 *
 * \param   None.
 *
 * \return  None.
 */
static void EMIFAAsizeConfig(unsigned int CEnCFG, unsigned int Asize)
{
  switch(CEnCFG)
  {
    case EMIFA_CE2CFG:
      if(Asize == EMIFA_ASIZE_8BIT_SHIFT)
      {
    	/* configure for 8-bit data bus */
        CLRREGBIT((SOC_EMIFA_0_REGS+EMIFA_CE2CFG), EMIFA_CE2CFG_ASIZE>>EMIFA_ASIZE_8BIT_SHIFT);
      }
      else if(Asize == EMIFA_ASIZE_16BIT_SHIFT)
      {
    	/* configure for 16-bit data bus */
    	SETREGBIT((SOC_EMIFA_0_REGS+EMIFA_CE2CFG), EMIFA_CE2CFG_ASIZE>>EMIFA_ASIZE_16BIT_SHIFT);
      }
      else
      {

      }
      break;

    case EMIFA_CE3CFG:
      if(Asize == EMIFA_ASIZE_8BIT_SHIFT)
      {
    	/* configure for 8-bit data bus */
        CLRREGBIT((SOC_EMIFA_0_REGS+EMIFA_CE3CFG), EMIFA_CE3CFG_ASIZE>>EMIFA_ASIZE_8BIT_SHIFT);
      }
      else if(Asize == EMIFA_ASIZE_16BIT_SHIFT)
      {
    	/* configure for 16-bit data bus */
        SETREGBIT((SOC_EMIFA_0_REGS+EMIFA_CE3CFG), EMIFA_CE3CFG_ASIZE>>EMIFA_ASIZE_16BIT_SHIFT);
      }
      else
      {

      }
      break;

    case EMIFA_CE4CFG:
      if(Asize == EMIFA_ASIZE_8BIT_SHIFT)
      {
    	/* configure for 8-bit data bus */
        CLRREGBIT((SOC_EMIFA_0_REGS+EMIFA_CE4CFG), EMIFA_CE4CFG_ASIZE>>EMIFA_ASIZE_8BIT_SHIFT);
      }
      else if(Asize == EMIFA_ASIZE_16BIT_SHIFT)
      {
    	/* configure for 16-bit data bus */
        SETREGBIT((SOC_EMIFA_0_REGS+EMIFA_CE4CFG), EMIFA_CE4CFG_ASIZE>>EMIFA_ASIZE_16BIT_SHIFT);
      }
      else
      {

      }
      break;

    case EMIFA_CE5CFG:
      if(Asize == EMIFA_ASIZE_8BIT_SHIFT)
      {
    	/* configure for 8-bit data bus */
        CLRREGBIT((SOC_EMIFA_0_REGS+EMIFA_CE5CFG), EMIFA_CE5CFG_ASIZE>>EMIFA_ASIZE_8BIT_SHIFT);
      }
      else if(Asize == EMIFA_ASIZE_16BIT_SHIFT)
      {
    	/* configure for 16-bit data bus */
        SETREGBIT((SOC_EMIFA_0_REGS+EMIFA_CE5CFG), EMIFA_CE5CFG_ASIZE>>EMIFA_ASIZE_16BIT_SHIFT);
      }
      else
      {

      }
      break;

	default:
	  break;
  }
}
/******************************************************************************
*                                                                             *
*                                                                             *
* \brief  Function to initalize the EMIFA NAND timing and base addr info.      *
*                                                                             *
* \param  nandTimimgInfo : Pointer to structure containing                    *
*                          NAND timing info.                                  *
*                                                                             *
* \return none.                                                               *
*                                                                             *
******************************************************************************/
//static void NANDTimingInfoInit(void *TimingInfo)
//{
//  int moduleClkInMHz = NAND_MODULE_CLK_IN_MHZ;
//  EMIFANANDTimingInfo_t *nandTimingInfo;
//
//  nandTimingInfo = (EMIFANANDTimingInfo_t * )TimingInfo;
//
//  /* Set the asynchronous wait timing */
//  nandTimingInfo->writeSetup  = ( ((moduleClkInMHz * NAND_WRITE_SETUP_TIME_IN_NS)/1000u) & EMIFA_WRITE_SETUP_RESETVAL );
//  nandTimingInfo->writeStrobe = ( ((moduleClkInMHz * NAND_WRITE_STROBE_TIME_IN_NS)/1000u) & EMIFA_WRITE_STROBE_RESETVAL );
//  nandTimingInfo->writeHold   = ( ((moduleClkInMHz * NAND_WRITE_HOLD_TIME_IN_NS)/1000u) & EMIFA_WRITE_HOLD_RESETVAL );
//
//  nandTimingInfo->readSetup   = ( ((moduleClkInMHz * NAND_READ_SETUP_TIME_IN_NS)/1000u) & EMIFA_READ_SETUP_RESETVAL );
//  nandTimingInfo->readStrobe  = ( ((moduleClkInMHz * NAND_READ_STROBE_TIME_IN_NS)/1000u) & EMIFA_READ_STROBE_RESETVAL );
//  nandTimingInfo->readHold    = ( ((moduleClkInMHz * NAND_READ_HOLD_TIME_IN_NS)/1000u) & EMIFA_READ_HOLD_RESETVAL );
//
//  nandTimingInfo->turnAround  = ( ((moduleClkInMHz * NAND_TURN_ARND_TIME_IN_NS)/1000u) & EMIFA_TA_RESETVAL );
//}
//
///******************************************************************************
//*                                                                             *
//* \brief  Function to initialize the device and controller info.              *
//*                                                                             *
//* \param  nandInfo      : Pointer to structure containing controller and      *
//*                         device information.                                 *
//*                                                                             *
//* \param  csNum         : Chip select where device is interfaced.             *
//*                                                                             *
//* \return none.                                                               *
//*                                                                             *
//******************************************************************************/
//static void NANDInfoInit(NandInfo_t *nandInfo, unsigned int cs)
//{
//  NandCtrlInfo_t *hNandCtrlInfo = nandInfo->hNandCtrlInfo;
//  NandDmaInfo_t  *hNandDmaInfo  = nandInfo->hNandDmaInfo;
//  NandEccInfo_t  *hNandEccInfo  = nandInfo->hNandEccInfo;
//
//  /* Init the NAND Device Info */
//  nandInfo->opMode                        = NAND_DATA_XFER_MODE;
//  nandInfo->eccType                       = NAND_ECC_ALGO_NONE;
//
//  nandInfo->chipSelectCnt                 = 1;
//  nandInfo->dieCnt                        = 1;
//  nandInfo->chipSelects[0]                = cs;
//  nandInfo->busWidth                      = NAND_BUSWIDTH;
//  nandInfo->pageSize                      = NAND_PAGE_SIZE_IN_BYTES;
//  nandInfo->blkSize                       = NAND_BLOCK_SIZE_IN_BYTES;
//  nandInfo->manId                         = NAND_MANUFATURER_MICRON_ID;
//  nandInfo->devId                         = NAND_DEVICE_ID;
//
//  nandInfo->dataRegAddr                   = (SOC_EMIFA_CS3_ADDR + 0x00);
//  nandInfo->addrRegAddr                   = (SOC_EMIFA_CS3_ADDR + 0x08);
//  nandInfo->cmdRegAddr                    = (SOC_EMIFA_CS3_ADDR + 0x10);
//
//  /* Init the NAND Controller Info struct */
//  hNandCtrlInfo->CtrlInit                 = EMIFANANDInit;
//  hNandCtrlInfo->WaitPinStatusGet         = EMIFANANDWaitPinStatusGet;
//  hNandCtrlInfo->currChipSelect           = cs;
//  hNandCtrlInfo->baseAddr                 = SOC_EMIFA_0_REGS;
//  hNandCtrlInfo->eccSupported             = ( NAND_ECC_ALGO_HAMMING_1BIT | NAND_ECC_ALGO_RS_4BIT );
//  hNandCtrlInfo->waitPin                  = EMIFA_EMA_WAIT_PIN0;
//  hNandCtrlInfo->waitPinPol               = EMIFA_EMA_WAIT_PIN_POLARITY_HIGH;
//  hNandCtrlInfo->wpPinPol                 = 0;
//  hNandCtrlInfo->chipSelectBaseAddr[0]    = SOC_EMIFA_CS3_ADDR;
//  hNandCtrlInfo->chipSelectRegionSize[0]  = EMIFA_CHIP_SELECT_3_SIZE;
//  NANDTimingInfoInit(hNandCtrlInfo->hNandTimingInfo);
//
//  /* Init the NAND Ecc Info */
//  hNandEccInfo->baseAddr                  = 0;
//  hNandEccInfo->ECCInit                   = EMIFANANDECCInit;
//  hNandEccInfo->ECCEnable                 = EMIFANANDECCEnable;
//  hNandEccInfo->ECCDisable                = EMIFANANDECCDisable;
//  hNandEccInfo->ECCWriteSet               = EMIFANANDECCWriteSet;
//  hNandEccInfo->ECCReadSet                = EMIFANANDECCReadSet;
//  hNandEccInfo->ECCCalculate              = EMIFANANDECCCalculate;
//  hNandEccInfo->ECCCheckAndCorrect        = EMIFANANDECCCheckAndCorrect;
//
//  /* Init the NAND DMA info */
//  hNandDmaInfo->DMAXfer                   = EMIFANANDDMAXfer;
//  hNandDmaInfo->DMAInit                   = EMIFANANDEdmaInit;
//  hNandDmaInfo->DMAXferSetup              = EMIFANANDXferSetup;
//  hNandDmaInfo->DMAXferStatusGet          = EMIFANANDXferStatusGet;
//
//}
//
///******************************************************************************
//*                                                                             *
//* \brief  This function prints the device ID info of NAND.\n                  *
//*                                                                             *
//* \param  nandInfo        Pointer to structure which conatins controller and  *
//*                         device information.                                 *
//*                                                                             *
//* \return none.                                                               *
//*                                                                             *
//******************************************************************************/
//static void NANDDeviceIdInfoPrint(NandInfo_t *nandInfo)
//{
//    UARTPuts(" ****************** NAND DEVICE INFO ****************** \r\n",-1);
//    UARTPuts("    MANUFACTURER ID    : ",-1);
//    UARTPutHexNum((unsigned int)nandInfo->manId);
//    UARTPuts("\r\n", -1);
//    UARTPuts("    DEVICE ID          : ",-1);
//    UARTPutHexNum((unsigned int)nandInfo->devId);
//    UARTPuts("\r\n", -1);
//    UARTPuts("    PAGESIZE           : ",-1);
//    UARTPutNum((unsigned int)nandInfo->pageSize);
//    UARTPuts(" Bytes\r\n", -1);
//    UARTPuts("    BLK SIZE           : ",-1);
//    UARTPutNum((unsigned int)nandInfo->blkSize);
//    UARTPuts(" Bytes\r\n", -1);
//    UARTPuts("    PAGES PER BLOCK    : ",-1);
//    UARTPutNum((unsigned int)nandInfo->pagesPerBlk);
//    UARTPuts("\r\n", -1);
//    UARTPuts(" ****************************************************** \r\n",-1);
//}
//
///*
//* \brief - NAND Configures.
//* \param - none.
//*
//* \return  none.
//*/
//void NAND_Init(void)
//{
//  unsigned int retVal = E_PASS;
//
//  /* Initialize the nandInfo struct */
//  nandCtrlInfo.hNandTimingInfo = (void *) &nandTimingInfo;
//  nandInfo.hNandCtrlInfo = &nandCtrlInfo;
//  nandInfo.hNandEccInfo = &nandEccInfo;
//  nandInfo.hNandDmaInfo = &nandDmaInfo;
//  NANDInfoInit(&nandInfo, NAND_CHIP_SELECT);
//
//  /* Open the NAND device */
//  retVal = NANDOpen(&nandInfo);
//  if (retVal & NAND_STATUS_FAILED)
//  {
//    UARTPuts("\r\n*** ERROR : NAND Open Failed... ",-1);
//  }
//  else if (retVal & NAND_STATUS_WAITTIMEOUT)
//  {
//    UARTPuts("\r\n*** ERROR : Device Is Not Ready...!!!\r\n", -1);
//  }
//  else if (retVal & NAND_STATUS_NOT_FOUND)
//  {
//    UARTPuts("\r\n*** ERROR : DEVICE MAY NOT BE ACCESSABLE OR NOT PRESENT.""\r\n", -1);
//  }
//  else
//  {
//    /* Print The Device ID info */
//    NANDDeviceIdInfoPrint(&nandInfo);
//  }
//}
//
//-----------------------------------------------------------------------------
// \brief   entry point for code.
//
// \param   none.
//
// \return  none.
//-----------------------------------------------------------------------------
void EMIFA_Init(void)
{
  EMIFAClkConfig();

  EMIFAPinMuxSetup();

  EMIFAAsizeConfig(EMIFA_CE2CFG, EMIFA_ASIZE_16BIT_SHIFT);

  EMIFAReadCycleConfig(EMIFA_CE2CFG, 2, 63, 2);  //63

  EMIFAWriteCycleConfig(EMIFA_CE2CFG, 2, 63, 2);  //63

  EMIFAAsizeConfig(EMIFA_CE4CFG, EMIFA_ASIZE_16BIT_SHIFT);

  EMIFAReadCycleConfig(EMIFA_CE4CFG, 2, 14, 2);  //9

  EMIFAWriteCycleConfig(EMIFA_CE4CFG, 2, 14, 2);
}

/********************************* End of file *******************************/

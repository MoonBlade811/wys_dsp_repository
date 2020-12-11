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
#include "soc_C6748.h"
#include "hw_syscfg0_C6748.h"

#include "gpio.h"
#include "psc.h"
#include "user_syscfg.h"

/*****************************************************************************
**                     Internal Macro Definitions
*****************************************************************************/
/* Identify device is DSP1 or DSP2, DSP1:11, DSP2:00 */
/* Pin Multiplexing bit mask to select GP2[0] pin. */
#define PINMUX6_GPIO2_0_ENABLE    (SYSCFG_PINMUX6_PINMUX6_31_28_GPIO2_0  << \
                                   SYSCFG_PINMUX6_PINMUX6_31_28_SHIFT)

/* Pin Multiplexing bit mask to select GP8[4] pin. */
#define PINMUX3_GPIO8_4_ENABLE    (SYSCFG_PINMUX3_PINMUX3_19_16_GPIO8_4  << \
                                   SYSCFG_PINMUX3_PINMUX3_19_16_SHIFT)

/* Pin Multiplexing bit mask to select GP8[3] pin. */
#define PINMUX3_GPIO8_3_ENABLE    (SYSCFG_PINMUX3_PINMUX3_23_20_GPIO8_3  << \
                                   SYSCFG_PINMUX3_PINMUX3_23_20_SHIFT)

/* Pin of DSP1 download FPGA */
/* Pin of DSP1 download FPGA of base board */
/* Pin Multiplexing bit mask to select GP0[5] pin for INIT and direction is input */
#define PINMUX1_GPIO0_5_ENABLE    (SYSCFG_PINMUX1_PINMUX1_11_8_GPIO0_5  << \
                                   SYSCFG_PINMUX1_PINMUX1_11_8_SHIFT)

/* Pin Multiplexing bit mask to select GP0[9] pin for DONE and direction is input */
#define PINMUX0_GPIO0_9_ENABLE    (SYSCFG_PINMUX0_PINMUX0_27_24_GPIO0_9  << \
                                   SYSCFG_PINMUX0_PINMUX0_27_24_SHIFT)

/* Pin Multiplexing bit mask to select GP0[6] pin for CCLK and direction is output */
#define PINMUX1_GPIO0_6_ENABLE    (SYSCFG_PINMUX1_PINMUX1_7_4_GPIO0_6  << \
                                   SYSCFG_PINMUX1_PINMUX1_7_4_SHIFT)

/* Pin Multiplexing bit mask to select GP0[7] pin for PROG and direction is output */
#define PINMUX1_GPIO0_7_ENABLE    (SYSCFG_PINMUX1_PINMUX1_3_0_GPIO0_7  << \
                                   SYSCFG_PINMUX1_PINMUX1_3_0_SHIFT)

/* Pin Multiplexing bit mask to select GP0[12] pin for DIN and direction is output */
#define PINMUX0_GPIO0_12_ENABLE    (SYSCFG_PINMUX0_PINMUX0_15_12_GPIO0_12  << \
                                   SYSCFG_PINMUX0_PINMUX0_15_12_SHIFT)

/* Pin of DSP1 download FPGA of CCA board */
/* Pin Multiplexing bit mask to select GP0[4] pin for INIT and direction is input */
#define PINMUX1_GPIO0_4_ENABLE    (SYSCFG_PINMUX1_PINMUX1_15_12_GPIO0_4  << \
                                   SYSCFG_PINMUX1_PINMUX1_15_12_SHIFT)

/* Pin Multiplexing bit mask to select GP0[3] pin for DONE and direction is input */
#define PINMUX1_GPIO0_3_ENABLE    (SYSCFG_PINMUX1_PINMUX1_19_16_GPIO0_3  << \
                                   SYSCFG_PINMUX1_PINMUX1_19_16_SHIFT)

/* Pin Multiplexing bit mask to select GP0[1] pin for CCLK and direction is output */
#define PINMUX1_GPIO0_1_ENABLE    (SYSCFG_PINMUX1_PINMUX1_27_24_GPIO0_1  << \
                                   SYSCFG_PINMUX1_PINMUX1_27_24_SHIFT)

/* Pin Multiplexing bit mask to select GP0[10] pin for PROG and direction is output */
#define PINMUX0_GPIO0_10_ENABLE   (SYSCFG_PINMUX0_PINMUX0_23_20_GPIO0_10  << \
                                   SYSCFG_PINMUX0_PINMUX0_23_20_SHIFT)

/* Pin Multiplexing bit mask to select GP0[11] pin for DIN and direction is output */
#define PINMUX0_GPIO0_11_ENABLE   (SYSCFG_PINMUX0_PINMUX0_19_16_GPIO0_11  << \
                                   SYSCFG_PINMUX0_PINMUX0_19_16_SHIFT)

/*****************************DSP1 GPIO*************************************/
/* IRQ1_P Pin Multiplexing bit mask to select GP0[0] pin. */
#define PINMUX1_GPIO0_0_ENABLE    (SYSCFG_PINMUX1_PINMUX1_31_28_GPIO0_0  << \
                                   SYSCFG_PINMUX1_PINMUX1_31_28_SHIFT)

/* IRQ2_P Pin Multiplexing bit mask to select GP1[10] pin. */
#define PINMUX2_GPIO1_10_ENABLE   (SYSCFG_PINMUX2_PINMUX2_23_20_GPIO1_10  << \
                                   SYSCFG_PINMUX2_PINMUX2_23_20_SHIFT)

/* Pin Multiplexing bit mask to select GP8[7] pin. */
#define PINMUX2_GPIO8_7_ENABLE    (SYSCFG_PINMUX2_PINMUX2_31_28_GPIO8_7  << \
                                   SYSCFG_PINMUX2_PINMUX2_31_28_SHIFT)

/* Pin Multiplexing bit mask to select GP0[15] pin. */
#define PINMUX0_GPIO0_15_ENABLE   (SYSCFG_PINMUX0_PINMUX0_3_0_GPIO0_15  << \
                                   SYSCFG_PINMUX0_PINMUX0_3_0_SHIFT)

/* Pin Multiplexing bit mask to select GP1[14] pin. */
#define PINMUX2_GPIO1_14_ENABLE   (SYSCFG_PINMUX2_PINMUX2_7_4_GPIO1_14  << \
                                   SYSCFG_PINMUX2_PINMUX2_7_4_SHIFT)

/* LED1 Pin Multiplexing bit mask to select GP1[13] pin. */
#define PINMUX2_GPIO1_13_ENABLE   (SYSCFG_PINMUX2_PINMUX2_11_8_GPIO1_13  << \
                                   SYSCFG_PINMUX2_PINMUX2_11_8_SHIFT)

/* LED2 Pin Multiplexing bit mask to select GP1[13] pin. */
#define PINMUX2_GPIO8_7_ENABLE    (SYSCFG_PINMUX2_PINMUX2_31_28_GPIO8_7  << \
                                   SYSCFG_PINMUX2_PINMUX2_31_28_SHIFT)
/* LED1 Pin Multiplexing bit mask to select GP1[0] pin. */
#define PINMUX4_GPIO1_0_ENABLE    (SYSCFG_PINMUX4_PINMUX4_31_28_GPIO1_0  << \
                                   SYSCFG_PINMUX4_PINMUX4_31_28_SHIFT)

/*****************************DSP2 GPIO*************************************/
/* IRQ3_P Pin Multiplexing bit mask to select GP1[1] pin. */
#define PINMUX4_GPIO1_1_ENABLE    (SYSCFG_PINMUX4_PINMUX4_27_24_GPIO1_1  << \
                                   SYSCFG_PINMUX4_PINMUX4_27_24_SHIFT)

/* IRQ4_P Pin Multiplexing bit mask to select GP0[11] pin. */
#define PINMUX0_GPIO0_11_ENABLE   (SYSCFG_PINMUX0_PINMUX0_19_16_GPIO0_11  << \
                                   SYSCFG_PINMUX0_PINMUX0_19_16_SHIFT)


/* Pin Multiplexing bit mask to select GP2[10] pin. */
#define PINMUX5_GPIO2_10_ENABLE   (SYSCFG_PINMUX5_PINMUX5_23_20_GPIO2_10  << \
                                   SYSCFG_PINMUX5_PINMUX5_23_20_SHIFT)
/* Pin Multiplexing bit mask to select GP2[10] pin. */
#define PINMUX5_GPIO2_11_ENABLE   (SYSCFG_PINMUX5_PINMUX5_19_16_GPIO2_11  << \
                                   SYSCFG_PINMUX5_PINMUX5_19_16_SHIFT)

/* Pin Multiplexing bit mask to select GP2[12] pin. */
#define PINMUX5_GPIO2_12_ENABLE   (SYSCFG_PINMUX5_PINMUX5_15_12_GPIO2_12  << \
                                   SYSCFG_PINMUX5_PINMUX5_15_12_SHIFT)

/* Pin Multiplexing bit mask to select GP2[13] pin. */
#define PINMUX5_GPIO2_13_ENABLE   (SYSCFG_PINMUX5_PINMUX5_11_8_GPIO2_13  << \
                                   SYSCFG_PINMUX5_PINMUX5_11_8_SHIFT)

#define PINMUX5_GPIO2_14_ENABLE   (SYSCFG_PINMUX5_PINMUX5_7_4_GPIO2_14  << \
                                   SYSCFG_PINMUX5_PINMUX5_7_4_SHIFT)

/* Pin Multiplexing bit mask to select GP0[13] pin. */
#define PINMUX0_GPIO0_13_ENABLE   (SYSCFG_PINMUX0_PINMUX0_11_8_GPIO0_13  << \
                                   SYSCFG_PINMUX0_PINMUX0_11_8_SHIFT)

/* Pin Multiplexing bit mask to select GP0[14] pin. */
#define PINMUX0_GPIO0_14_ENABLE   (SYSCFG_PINMUX0_PINMUX0_7_4_GPIO0_14  << \
                                   SYSCFG_PINMUX0_PINMUX0_7_4_SHIFT)

/* LED1 Pin Multiplexing bit mask to select GP1[10] pin. */
#define PINMUX2_GPIO1_10_ENABLE   (SYSCFG_PINMUX2_PINMUX2_23_20_GPIO1_10  << \
                                   SYSCFG_PINMUX2_PINMUX2_23_20_SHIFT)

/* LED2 Pin Multiplexing bit mask to select GP1[15] pin. */
#define PINMUX2_GPIO1_15_ENABLE   (SYSCFG_PINMUX2_PINMUX2_3_0_GPIO1_15  << \
                                   SYSCFG_PINMUX2_PINMUX2_3_0_SHIFT)

#define PINMUX17_GPIO7_8_ENABLE   (SYSCFG_PINMUX17_PINMUX17_7_4_GPIO7_8  << \
                                   SYSCFG_PINMUX17_PINMUX17_7_4_SHIFT)

/******************************************************************************
**                     Local variable Definitions
*******************************************************************************/



/******************************************************************************
**                     Local function Declarations
*******************************************************************************/
static void Identify_Device(void);
static void pinDLFPGAConfig(void);


/******************************************************************************
**                     Global variable Definitions
*******************************************************************************/
unsigned char Identify_DSP_gui = 0xFF;


/******************************************************************************
**                     Global Function Definitions
*******************************************************************************/

static void pinDLFPGAConfig(void)
{
  /* Configure GPIO for download FPGA software at base board */
  /* Pin Multiplexing bit mask to select GP0[5] pin for INIT and direction is input */
  pinmuxConfig(1, SYSCFG_PINMUX1_PINMUX1_11_8, PINMUX1_GPIO0_5_ENABLE);

  /* Sets the pin 5 of GPIO Bank 0 (6) as input */
  GPIODirModeSet(SOC_GPIO_0_REGS, 6, GPIO_DIR_INPUT);

  /* Pin Multiplexing bit mask to select GP0[9] pin for DONE and direction is input */
  pinmuxConfig(0, SYSCFG_PINMUX0_PINMUX0_27_24, PINMUX0_GPIO0_9_ENABLE);

  /* Sets the pin 9 of GPIO Bank 0 (10) as input */
  GPIODirModeSet(SOC_GPIO_0_REGS, 10, GPIO_DIR_INPUT);

  /* Pin Multiplexing bit mask to select GP0[6] pin for CCLK and direction is output */
  pinmuxConfig(1, SYSCFG_PINMUX1_PINMUX1_7_4, PINMUX1_GPIO0_6_ENABLE);

  /* Sets the pin 6 of GPIO Bank 0 (7) as output */
  GPIODirModeSet(SOC_GPIO_0_REGS, 7, GPIO_DIR_OUTPUT);

  /* Pin Multiplexing bit mask to select GP0[7] pin for PROG and direction is output */
  pinmuxConfig(1, SYSCFG_PINMUX1_PINMUX1_3_0, PINMUX1_GPIO0_7_ENABLE);

  /* Sets the pin 7 of GPIO Bank 0 (8) as output */
  GPIODirModeSet(SOC_GPIO_0_REGS, 8, GPIO_DIR_OUTPUT);

  /* Pin Multiplexing bit mask to select GP0[12] pin for DIN and direction is output */
  pinmuxConfig(0, SYSCFG_PINMUX0_PINMUX0_15_12, PINMUX0_GPIO0_12_ENABLE);

  /* Sets the pin 12 of GPIO Bank 0 (13) as output */
  GPIODirModeSet(SOC_GPIO_0_REGS, 13, GPIO_DIR_OUTPUT);
  /**********************************************************************************/

  /* Configure GPIO for download CCA FPGA software at other board */
  /* Pin Multiplexing bit mask to select GP0[4] pin for INIT and direction is input */
  pinmuxConfig(1, SYSCFG_PINMUX1_PINMUX1_15_12, PINMUX1_GPIO0_4_ENABLE);

  /* Sets the pin 4 of GPIO Bank 0 (5) as input */
  GPIODirModeSet(SOC_GPIO_0_REGS, 5, GPIO_DIR_INPUT);

  /* Pin Multiplexing bit mask to select GP0[3] pin for DONE and direction is input */
  pinmuxConfig(1, SYSCFG_PINMUX1_PINMUX1_19_16, PINMUX1_GPIO0_3_ENABLE);

  /* Sets the pin 3 of GPIO Bank 0 (4) as input */
  GPIODirModeSet(SOC_GPIO_0_REGS, 4, GPIO_DIR_INPUT);

  /* Pin Multiplexing bit mask to select GP0[1] pin for CCLK and direction is output */
  pinmuxConfig(1, SYSCFG_PINMUX1_PINMUX1_27_24, PINMUX1_GPIO0_1_ENABLE);

  /* Sets the pin 1 of GPIO Bank 0 (2) as output */
  GPIODirModeSet(SOC_GPIO_0_REGS, 2, GPIO_DIR_OUTPUT);

  /* Pin Multiplexing bit mask to select GP0[10] pin for PROG and direction is output */
  pinmuxConfig(0, SYSCFG_PINMUX0_PINMUX0_23_20, PINMUX0_GPIO0_10_ENABLE);

  /* Sets the pin 10 of GPIO Bank 0 (11) as output */
  GPIODirModeSet(SOC_GPIO_0_REGS, 11, GPIO_DIR_OUTPUT);

  /* Pin Multiplexing bit mask to select GP0[11] pin for DIN and direction is output */
  pinmuxConfig(0, SYSCFG_PINMUX0_PINMUX0_19_16, PINMUX0_GPIO0_11_ENABLE);

  /* Sets the pin 11 of GPIO Bank 0 (12) as output */
  GPIODirModeSet(SOC_GPIO_0_REGS, 12, GPIO_DIR_OUTPUT);
}


static void Identify_Device(void)
{
	Identify_DSP_gui = DSP1;
}

/**
 * \brief   This function selects the Pin 0 of GPIO bank 4 for use.
 *          This GPIO pin is multiplexed with pins of other peripherals
 *          in the System on Chip(SoC).
 *
 * \return  None.
 *
 */
void GPIO_Init(void)
{
  /* The Local PSC number for GPIO is 3. GPIO belongs to PSC1 module.*/
  PSCModuleControl(SOC_PSC_1_REGS, HW_PSC_GPIO, PSC_POWERDOMAIN_ALWAYS_ON, PSC_MDCTL_NEXT_ENABLE);

  /* Identify device is DSP1 or DSP2, DSP1:11, DSP2:00 */
  Identify_Device();



  if(Identify_DSP_gui == DSP1)
  {
	/* Configure pin of DSP download FPGA Program */
//	pinDLFPGAConfig();

    /* DSP1 External Interrupt form CPCI */
    /* IRQ2_P used for pin 10 of GPIO Bank 1 */
//    pinmuxConfig(2, SYSCFG_PINMUX2_PINMUX2_23_20, PINMUX2_GPIO1_10_ENABLE);
//
//    /* Sets the pin 10 of GPIO Bank 1 (27) as input */
//    GPIODirModeSet(SOC_GPIO_0_REGS, 27, GPIO_DIR_INPUT);

	/* IRQ1_P used for pin 0 of GPIO Bank 0 */
    pinmuxConfig(1, SYSCFG_PINMUX1_PINMUX1_31_28, PINMUX1_GPIO0_0_ENABLE);

    /* Sets the pin 0 of GPIO Bank 0 (1) as input */
    GPIODirModeSet(SOC_GPIO_0_REGS, 1, GPIO_DIR_INPUT);
//
//    /* DSP1 External Interrupt form FPGA */
//    /* DSP1 read LinkPort Data flag used for pin 15 of GPIO Bank 0 */
//    pinmuxConfig(0, SYSCFG_PINMUX0_PINMUX0_3_0, PINMUX0_GPIO0_15_ENABLE);
//
//    /* Sets the pin 15 of GPIO Bank 0 (16) as input.*/
//    GPIODirModeSet(SOC_GPIO_0_REGS, 16, GPIO_DIR_INPUT);
//
//    /* DSP1 write LinkPort Data flag used for pin 14 of GPIO Bank 1 */
//    pinmuxConfig(2, SYSCFG_PINMUX2_PINMUX2_7_4, PINMUX2_GPIO1_14_ENABLE);
//
//    /* Sets the pin 14 of GPIO Bank 1 (31) as output */
//    GPIODirModeSet(SOC_GPIO_0_REGS, 31, GPIO_DIR_OUTPUT);

    /* DSP1 LED0 */
    /* DSP1 LED0 used for pin 1 of GPIO Bank 1 */


    /* DSP1 DSPA_STA0 To Tell Arm DSP has already started up */
    /* DSP1 DSPA_STA0 used for pin 10 of GPIO Bank 2 */
    pinmuxConfig(5, SYSCFG_PINMUX5_PINMUX5_19_16, PINMUX5_GPIO2_11_ENABLE);

    /* Sets the pin 11 of GPIO Bank 2 (44) as output */
    GPIODirModeSet(SOC_GPIO_0_REGS, 44, GPIO_DIR_OUTPUT);

    /* DSP1 DSPA_STA1 */
    /* DSP1 DSPA_STA1 used for pin 13 of GPIO Bank 2 */
    pinmuxConfig(5, SYSCFG_PINMUX5_PINMUX5_11_8, PINMUX5_GPIO2_13_ENABLE);

    /* Sets the pin 43 of GPIO Bank 1 (46) as output */
    GPIODirModeSet(SOC_GPIO_0_REGS, 46, GPIO_DIR_OUTPUT);

    pinmuxConfig(5, SYSCFG_PINMUX5_PINMUX5_7_4, PINMUX5_GPIO2_14_ENABLE);

    /* Sets the pin 43 of GPIO Bank 1 (46) as output */
    GPIODirModeSet(SOC_GPIO_0_REGS, 47, GPIO_DIR_OUTPUT);

    GPIOPinWrite(SOC_GPIO_0_REGS, 44, GPIO_PIN_HIGH);

    GPIOPinWrite(SOC_GPIO_0_REGS, 46, GPIO_PIN_HIGH);

    GPIOPinWrite(SOC_GPIO_0_REGS, 47, GPIO_PIN_HIGH);
  }
}

/********************************* End of file *******************************/

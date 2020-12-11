/*****************************************************************************
**                       Include Files
*****************************************************************************/
/* HW Macros */
#include "hw_types.h"
#include "c6x.h"
#include "soc_C6748.h"
#include "hw_syscfg0_C6748.h"
#include "interrupt.h"
#include "gpio.h"
#include "psc.h"
#include "timer.h"
#include "emac.h"
#include "user_syscfg.h"
#include "user_variable.h"
#include <c6x.h>
#include "user_record.h"
#include "user_interface.h"
#include "algorithm.h"
#include "user_sysglobalvar.h"
#include "delay.h"
/*****************************************************************************
**                     Internal Macro Definitions
*****************************************************************************/
#define TMR_PERIOD_US         150
#define TMR_PERIOD_MS         150000

#define USERPRD_US            250
#define TMR_PERIOD_LSB32      (TMR_PERIOD_US * USERPRD_US)
#define TMR_PERIOD_MSB32      (0x0)

/******************************************************************************
**                     Local function Declarations
*******************************************************************************/
static void GPIOHighpriorityIsr(void);
static void Timer2Isr(void);
static void GPIOIsr_Init(void);
static void Timer2Isr_Init(void);
extern void DAM_Tran();
/******************************************************************************
**                     Local variable Definitions
*******************************************************************************/
extern double CHP_PWM_float_Value;
extern unsigned int SIVPQ_flag;
extern double Ud_ref;
extern double pqqxc;

extern unsigned int SIVCTT_close_count;
extern double Temp_Value;
extern double Temp_Value1;

extern double Udc_fil;
extern double Ufc_fil;

extern double BUKVOLOUT_meas;
extern unsigned int InvState_Check;
extern unsigned int PL_fail_flag;

extern unsigned int PLL_start_flag;
extern unsigned int SIVCTT_Close_allow;
extern double Uout_BUK_Regul_temp;
extern double Uout_Regu_limdata;
extern unsigned int SIVCTT_close_DOUT;

extern volatile unsigned char L_SIVCTT_CLOSE_BL_gui;
extern unsigned int StartOvt_flag;
/******************************************************************************
**                     Global variable Definitions
*******************************************************************************/
unsigned int  TIntCounter_gvuh = 0;
unsigned int  HighInt_WD_Cnt = 0;
unsigned int  LowInt_WD_Cnt = 0;

unsigned int  GPIO_IR_Cnt = 0;
unsigned char TIntCounter_Flag = 0;
unsigned char GPIO_IR_Flag = 0;

extern unsigned char Identify_DSP_gui;
extern unsigned char SysCnt;
extern unsigned char BuckStartFlag;
extern unsigned char DCDC_start_Flag;
extern double BUK_OUT_AIM;
extern double CHP_OUT_AIM;
extern double BUKVOLOUT_meas;
/***********************************************************
*函数介绍：
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
static void Timer2Isr(void)
{
  unsigned int IRP_Temp, ITSR_Temp, CSR_Temp;

  /***********************Saved register status*************************/
  IRP_Temp = IRP;
  CSR_Temp = CSR & 0x2;
  ITSR_Temp = ITSR;

  IntGlobalEnable();

  TimerIntDisable(SOC_TMR_2_REGS, TMR_INT_TMR12_NON_CAPT_MODE);

  IntEventClear(SYS_INT_T64P2_TINTALL);

  TimerIntStatusClear(SOC_TMR_2_REGS, TMR_INT_TMR12_NON_CAPT_MODE);

  /***********************state code start******************************/
  TIntCounter_gvuh++;
  HighInt_WD_Cnt++;
  LowInt_WD_Cnt++;
  /*看门狗计数器启动*/
  LowInt_WD_Cnt = 0;

  if(TIntCounter_gvuh>=2000)
   {
	   TIntCounter_gvuh=0;
   }
  else{;}

  if((TIntCounter_gvuh%1000)==0)
   {
	   if(TIntCounter_Flag==0)
	   {
		   TIntCounter_Flag = 1;
	   }
	   else
	   {
		   TIntCounter_Flag = 0;
	   }
   }
  else{;}

   if(TIntCounter_Flag)
   {
	   GPIOPinWrite(SOC_GPIO_0_REGS, 44, GPIO_PIN_LOW);
   }
   else
   {
	   GPIOPinWrite(SOC_GPIO_0_REGS, 44, GPIO_PIN_HIGH);
   }

  	/***********************USER CODE START**************************/
  	SysCnt++;	
    if((L_BUCK_start_Comm_gui)&&(BuckStartFlag)&&((ACU_DIN_gui&0x20)!=0x20))/*加入APS强迫停止*/
    {
        BuckPWMCtrl();
    }
    else
    {
        StopBuckMdl();
        InitBuckMdl();
    }
  	/***********************user code end***************************/
   TimerIntEnable(SOC_TMR_2_REGS, TMR_INT_TMR12_NON_CAPT_MODE);
   IntGlobalDisable();
   CSR = (CSR & 0xFFFFFFFD) | CSR_Temp;
   ITSR = ITSR_Temp;
   IRP = IRP_Temp;
}

/***********************************************************
*函数介绍：
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
static void GPIOHighpriorityIsr(void)
{

    Debug0 = HWREG(0x01F0C000 + TMR_TIM12);
    Delay(100);
    Debug1 = HWREG(0x01F0C000 + TMR_TIM12);
    Debug2 = (Debug1-Debug0)/150;
    if(Debug2<=0)
    {
        Debug2 = 0;
    }
    if(Debug2>=Debug3)
    {
        Debug3 = Debug2;
    }
    else{;}
	/* Disable the interrupts for pins of bank 0 in GPIO.*/
	GPIOBankIntDisable(SOC_GPIO_0_REGS, 0);
	/* Clear the system interrupt status in the DSPINTC */
	IntEventClear(SYS_INT_GPIO_B0INT);
	/* DSP1 clears the Interrupt Status of GP1[0] in GPIO.*/
	GPIOPinIntClear(SOC_GPIO_0_REGS, 1);
	/*------------------User Code Start---------------------*/
	/*clear watch dog timer*/
	HighInt_WD_Cnt = 0;
	GPIO_IR_Cnt++;
	if(GPIO_IR_Cnt>=6000)
	{
		GPIO_IR_Cnt=0;
	}
	if((GPIO_IR_Cnt%3000)==0)
	{
		if(GPIO_IR_Flag==0)
		{
			GPIO_IR_Flag = 1;
		}
		else
		{
			GPIO_IR_Flag = 0;
		}
	}
	else{;}

	if(GPIO_IR_Flag)
	{
	   GPIOPinWrite(SOC_GPIO_0_REGS, 47, GPIO_PIN_LOW);
	}
	else
	{
	   GPIOPinWrite(SOC_GPIO_0_REGS, 47, GPIO_PIN_HIGH);
	}
	/*------------------算法应用程序---------------------*/
	Debug11++;
	if((Debug11%6000)==0)
	{
		Debug10++;
		Debug11 = 0;
	}
	ControlDataMeas();
	OvtCtrl();
  	LogicInterface();
  	DSP_TO_ARM();
	SivCutoff();


	if((L_DCDC_start_Comm_gui)&&(DCDCStartFlag)&&((ACU_DIN_gui&0x20)!=0x20))/*加入APS强迫停止*/
	{
		DCDCPWMCtrl();
	}
	else
	{
		StopDCDCMdl();
		InitDCDCMdl();
	}

	if((L_SIV_start_Comm_gui==1)&&(InvStartFlag))
	{
		SPLL(&SPLLReg);
		SIVCtrl(&(SVPWMReg.Alpha), &(SVPWMReg.Beta));
		SvpwmModule(&SVPWMReg);
	}
	else
	{
		StopInvMdl();
		InitInvMdl();
	}

    RecordData_Write_FPGA();
    DAM_Tran();



  /*------------------User Code End---------------------*/
  /* Enable interrupts for pins of bank 1.*/
  GPIOBankIntEnable(SOC_GPIO_0_REGS, 0);
}
/***********************************************************
*函数介绍：
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
static void Timer2Isr_Init(void)
{
  /* Set up the Timer2 peripheral */
  /* Configuration of Timer */
  TimerConfigure(SOC_TMR_2_REGS, TMR_CFG_64BIT_CLK_INT);

  /* Set the 64 bit timer period */
  TimerPeriodSet(SOC_TMR_2_REGS, TMR_TIMER12, TMR_PERIOD_LSB32);
  TimerPeriodSet(SOC_TMR_2_REGS, TMR_TIMER34, TMR_PERIOD_MSB32);

  /* Register the Timer ISR */
  IntRegister(C674X_MASK_INT5, Timer2Isr);

  /* Map Timer interrupts to DSP maskable interrupt */
  IntEventMap(C674X_MASK_INT5, SYS_INT_T64P2_TINTALL);

  /* Enable DSP interrupt in DSPINTC */
  //IntEnable(C674X_MASK_INT5);

  /* Enable the timer interrupt */
  //TimerIntEnable(SOC_TMR_2_REGS, TMR_INT_TMR12_NON_CAPT_MODE);

  /* Start the timer. Characters from cntArr will be sent from the ISR */
  //TimerEnable(SOC_TMR_2_REGS, TMR_TIMER12, TMR_ENABLE_CONT);
}
/***********************************************************
*函数介绍：
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
static void GPIOIsr_Init(void)
{
  GPIOIntTypeSet(SOC_GPIO_0_REGS, 1, GPIO_INT_TYPE_FALLEDGE);//外部中断引脚是GPIO0_0


  /* Enable interrupts for Bank 1/0 */
//  GPIOBankIntEnable(SOC_GPIO_0_REGS, 1);//Bank1是参数是1
  GPIOBankIntEnable(SOC_GPIO_0_REGS, 0);//Bank0是参数是0;使能GPIO0_0这个pin的外部中断功�?
  /* Map the system interrupt to the DSP maskable interrupt */
//  IntEventMap(C674X_MASK_INT4, SYS_INT_GPIO_B1INT);//Bank1是参数是SYS_INT_GPIO_B0INT
  IntEventMap(C674X_MASK_INT4, SYS_INT_GPIO_B0INT);//Bank1是参数是SYS_INT_GPIO_B0INT

  /* Configure GPIO interrupts */
  /* Register the ISR in the Interrupt Vector Table */
  IntRegister(C674X_MASK_INT4, GPIOHighpriorityIsr);
  //IntRegister(C674X_MASK_INT5, GPIOLowpriorityIsr);

  /* Enable DSP maskable interrupt */
  //IntEnable(C674X_MASK_INT4);
  //IntEnable(C674X_MASK_INT5);
}

void DSPINTC_Normal_Open(void)
{
  /* Enable GPIO interrupt */
  /* Enable DSP maskable interrupt */
  IntEnable(C674X_MASK_INT4);

  /* Enable Timer interrupt */
  /* Enable DSP interrupt in DSPINTC */
  IntEnable(C674X_MASK_INT5);

  /* Enable the timer interrupt */
  TimerIntEnable(SOC_TMR_2_REGS, TMR_INT_TMR12_NON_CAPT_MODE);

  /* Start the timer. Characters from cntArr will be sent from the ISR */
  TimerEnable(SOC_TMR_2_REGS, TMR_TIMER12, TMR_ENABLE_CONT);
}

void DSPINTC_Normal_Close(void)
{
  /* Enable GPIO interrupt */
  /* Enable DSP maskable interrupt */
  IntDisable(C674X_MASK_INT4);

  /* Enable Timer interrupt */
  /* Enable DSP interrupt in DSPINTC */
  IntDisable(C674X_MASK_INT5);

  /* Enable the timer interrupt */
  TimerIntDisable(SOC_TMR_2_REGS, TMR_INT_TMR12_NON_CAPT_MODE);

  /* Start the timer. Characters from cntArr will be sent from the ISR */
  TimerDisable(SOC_TMR_2_REGS, TMR_TIMER12);
}

void DSPINTC_Init(void)
{
  /* Configuring the AINTC to handle interrupts.*/
  /* Initialize the DSP Interrupt Controller */
  IntDSPINTCInit();

  /* Enable DSP Interrupts Globally */
  IntGlobalEnable();

  GPIOIsr_Init();

  Timer2Isr_Init();

}

/********************************* End of file *******************************/

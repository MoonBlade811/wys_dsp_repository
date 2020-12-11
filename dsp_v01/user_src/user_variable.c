/*****************************************************************************
**                       Include Files
*****************************************************************************/
/* HW Macros */
#include "hw_types.h"
#include "hw_psc_C6748.h"

/* System Defines */
#include "soc_C6748.h"
#include "hw_syscfg0_C6748.h"
#include "gpio.h"
#include "user_syscfg.h"
#include "user_variable.h"
#include "stdio.h"
#include "user_sysglobalvar.h"
#include "user_record.h"
/*****************************************************************************
**                     Internal Macro Definitions
*****************************************************************************/
#define IVT1_PWM_TRP          10000
#define CCA4_SAMPLE_TRP1      0xE4

#define HIGHINT_WD_TIME       CCA4_SAMPLE_TRP1 + CCA4_SAMPLE_TRP1
#define LOWINT_WD_TIME        IVT1_PWM_TRP + IVT1_PWM_TRP

/******************************************************************************
**                     Global variable Definitions
*******************************************************************************/
extern unsigned int  HighInt_WD_Cnt;
extern unsigned int  LowInt_WD_Cnt;
extern unsigned int Flash_Buf_Fresh[5];

/*****ARM to DSP*****/
volatile unsigned int  A_ARMWRDSP_INVCON_gui;

volatile unsigned char L_AUX_SYSRST_gui;
volatile unsigned char L_AUX_EXCLREQ_gui;
volatile unsigned char L_AUX_TESTMODE_gui;
volatile unsigned char L_CHPPWM_REQ_gui;
volatile unsigned char L_INVPWM_REQ_gui;
volatile unsigned char L_PROSET_OK_gui;
volatile unsigned char L_DCDCPWM_REQ_gui;
volatile unsigned char L_RSNCPWM_REQ_gui;
volatile unsigned char L_BUCKPWM_REQ_gui;
volatile unsigned char L_VEHL_RUNMODE_gui;
volatile unsigned char L_INIT_STA_gui;
volatile unsigned char L_SIV_start_Comm_gui;
volatile unsigned char L_DCDC_start_Comm_gui;
volatile unsigned char L_BUCK_start_Comm_gui;
volatile unsigned char L_SIV_init_Flag_gui;
volatile unsigned char L_DCDC_init_Flag_gui;
volatile unsigned char L_BUCK_init_Flag_gui;
volatile unsigned char L_System_Ready_gui;
volatile unsigned char L_Inverter_start_gui;
volatile unsigned char L_SIVCTT_open_Req_Acc_gui;
volatile unsigned char L_BL_master_judgment_gui;
volatile unsigned char L_SIVCTT_CLOSE_BL_gui;
volatile unsigned char L_SIVCTT_close_Sta_gui;
volatile unsigned char CTAX_SIVCutoffCmd_B1_gui;

volatile unsigned int  A_DSPRDFPGA_DOUTLOCALSTA_gui;

volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA0_gui;
volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA1_gui;
volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA2_gui;
volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA3_gui;
volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA4_gui;
volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA5_gui;
volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA6_gui;
volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA7_gui;
volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA8_gui;
volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA9_gui;
volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA10_gui;
volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA11_gui;
volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA12_gui;


volatile unsigned int   A_DSPRDFPGA_PWM_TEST_gui;

volatile unsigned char L_DSPRDFPGA_PWM_TEST_EN_gui;


volatile unsigned int   A_ARMRDDSP_DEBUG9_gui; 
volatile unsigned int   A_ARMRDDSP_DEBUG10_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG11_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG12_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG13_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG14_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG15_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG16_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG41_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG42_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG43_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG44_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG45_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG46_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG47_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG48_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG49_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG50_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG51_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG52_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG53_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG54_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG55_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG56_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG57_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG58_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG59_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG60_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG61_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG62_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG63_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG64_gui;





volatile unsigned int   A_ARMRDDSP_REVREG_gui;
volatile unsigned int   A_ARMRDDSP_DSPSTA_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG1_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG2_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG3_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG4_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG5_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG6_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG7_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG8_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG17_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG18_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG19_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG20_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG21_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG22_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG23_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG24_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG25_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG26_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG27_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG28_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG29_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG30_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG31_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG32_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG33_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG34_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG35_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG36_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG37_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG38_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG39_gui;
volatile unsigned int   A_ARMRDDSP_DEBUG40_gui;

/***************************DSP->FPGA***************************************/
volatile unsigned int A_DSPWRFPGA_PWMCON_gui;
volatile unsigned char L_PWM_TIMERENA_gui;
volatile unsigned char L_PWM_CMPENA_gui;
volatile unsigned char L_CHPPWM_TIMEENA_gui;
volatile unsigned char L_CHPPWM_CMPENA_gui;
volatile unsigned char L_RSTPWM_TIMEENA_gui;
volatile unsigned char L_RSTPWM_CMPENA_gui;
volatile unsigned char L_DCDCPWM_TIMEENA_gui;
volatile unsigned char L_DCDCPWM_CMP1ENA_gui;
volatile unsigned char L_DCDCPWM_CMP2ENA_gui;
volatile unsigned char L_BUCKPWM_TIMEENA_gui;
volatile unsigned char L_BUCKPWM_CMPENA_gui;
volatile unsigned char L_PWM_CHECKIGBTENA_gui;
volatile unsigned char L_CHPPWM_CHECKIGBTENA_gui;
volatile unsigned char L_DCDCPWM_CHECKIGBTENA_gui;
volatile unsigned char L_BuckPWM_CHECKIGBTENA_gui;
/*****PWM*****/
volatile unsigned int A_DSPWRFPGA_PWMTPR_gui;

volatile unsigned int A_DSPWRFPGA_PWMDBCON_gui;
volatile unsigned char L_PWM_DBENA_gui;
volatile unsigned short L_PWM_DBTPR_gui;

volatile unsigned int A_PWM_CMPU_gui;
volatile unsigned int A_PWM_CMPV_gui;
volatile unsigned int A_PWM_CMPW_gui;
/*****CHOP*****/
volatile unsigned int A_DSPWRFPGA_CHPPRD_gui;

volatile unsigned int A_DSPWRFPGA_CHPDBTCON_gui;
volatile unsigned char L_CHPPWM_DBENA_gui;
volatile unsigned short L_CHPPWM_DBTPR_gui;

volatile unsigned int A_DSPWRFPGA_CHPCMPR_gui;
volatile unsigned int A_DSPWRFPGA_RSNCPRD_gui;
/*****RSNC*****/
volatile unsigned int A_DSPWRFPGA_RSNCCMPR_gui;
volatile unsigned int A_DSPWRFPGA_RSNCDBTCON_gui;
volatile unsigned char L_RSNCPWM_DBENA_gui;
volatile unsigned short L_RSNCPWM_DBTPR_gui;
volatile unsigned int A_DSPWRFPGA_RSNCTIMER_gui;
/*****DCDC*****/
volatile unsigned int A_DSPWRFPGA_DCDCPRD_gui;
volatile unsigned int A_DSPWRFPGA_DCDCDBTCON_gui;
volatile unsigned char L_DCDCPWM_DBENA_gui;
volatile unsigned short L_DCDCPWM_DBTPR_gui;
volatile unsigned int A_DSPWRFPGA_DCDCPSLD_gui;
volatile unsigned int A_DSPWRFPGA_DCDCPSLG_gui;
volatile unsigned int A_DSPWRFPGA_DCDCPRULD_gui;
volatile unsigned int A_DSPWRFPGA_DCDCPRULG_gui;
/*****BUCK*****/
volatile unsigned int A_DSPWRFPGA_BUCKPRD_gui;
volatile unsigned int A_DSPWRFPGA_BUCKDBTCON_gui;
volatile unsigned char L_BUCKPWM_DBENA_gui;
volatile unsigned short L_BUCKPWM_DBTPR_gui;
volatile unsigned int A_DSPWRFPGA_BUCKCMPR_gui;
/*****PWM_DSP_BUSY*****/
volatile unsigned int A_DSPWRFPGA_PWM_DSP_BUSY_gui;
/*****DSPSTA*****/
volatile unsigned int A_DSPWRFPGA_INVCON_gui;
volatile unsigned char L_AUX_SYSRST_gui;
volatile unsigned char L_AUX_EXCLREQ_gui;
volatile unsigned char L_AUX_TESTMODE_gui;
volatile unsigned char L_CHPPWM_REQ_gui;
volatile unsigned char L_INVPWM_REQ_gui;
volatile unsigned char L_RSNCPWM_REQ_gui;
volatile unsigned char L_DCDCPWM_REQ_gui;
volatile unsigned char L_BUCKPWM_REQ_gui;
volatile unsigned char L_PROSET_OK_gui;
volatile unsigned char L_VEHL_RUNMODE_gui;
volatile unsigned char L_PQenable_gui;
volatile unsigned char L_Juzero_gui;
/*****13 路 DO DSP to FPGA*****/
volatile unsigned int  A_DSPWRFPGA_DOUTLOCALSTA_gui;
volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA0_gui;
volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA1_gui;
volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA2_gui;
volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA3_gui;
volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA4_gui;
volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA5_gui;
volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA6_gui;
volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA7_gui;
volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA8_gui;
volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA9_gui;
volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA10_gui;
volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA11_gui;
volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA12_gui;
/*****事件记录*****/
volatile unsigned int A_DSPWRFPGA_EVENTRCON2_gui;
volatile unsigned char L_EVENT_CON2_EVENTW_gui;
/*****新增加算法参数*****/
volatile unsigned int A_DSPRDFPGA_CTRLPARAM1_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM2_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM3_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM4_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM5_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM6_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM7_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM8_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM9_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM10_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM11_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM12_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM13_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM14_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM15_gui;
volatile unsigned int A_DSPRDFPGA_CTRLPARAM16_gui;
/*****FREQ_DSP_BUSY*****/
volatile unsigned int A_DSPWRFPGA_FREQ_DSP_BUSY_gui;
/*****DAM调试用*****/
volatile unsigned int A_DSPWRFPGA_DAMREG1_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG2_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG3_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG4_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG5_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG6_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG7_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG8_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG9_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG10_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG11_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG12_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG13_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG14_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG15_gui;
volatile unsigned int A_DSPWRFPGA_DAMREG16_gui;

/*******************************FPGA->DSP*********************************************************/
/*****PWM_FPGA_BUSY*****/
volatile unsigned int A_FPGAWRDSP_PWM_FPGA_BUSY_gui;
/*****FPGASTA*****/
volatile unsigned int A_ARMRDFPGA_STA_gui;
volatile unsigned char L_INV_FAULT_gui;
volatile unsigned char L_FPGA_STA_gui;
volatile unsigned char L_INIT_STA_gui;
volatile unsigned char L_EXCL_STA_gui;
volatile unsigned char L_RSNC_PWMENA_gui;
volatile unsigned char L_CHP_PWMENA_gui;
volatile unsigned char L_INV_PWMENA_gui;
volatile unsigned char L_DCDC_PWMENA_gui;
volatile unsigned char L_BUCK_PWMENA_gui;
volatile unsigned int L_FPGATODSP_Usin_gui;
volatile unsigned int L_FPGATODSP_Ucos_gui;
volatile unsigned int L_FPGATODSP_Isin_gui;
volatile unsigned int L_FPGATODSP_Icos_gui;
/*****FPGACHECKFAULT*****/
volatile unsigned int A_DSPRDFPGA_FPGACHECKFAULT_gui;
volatile unsigned char L_FPGACHECKFAULT_CFDUL_gui;
volatile unsigned char L_FPGACHECKFAULT_CFDUH_gui;
volatile unsigned char L_FPGACHECKFAULT_CFDVL_gui;
volatile unsigned char L_FPGACHECKFAULT_CFDVH_gui;
volatile unsigned char L_FPGACHECKFAULT_CFDWL_gui;
volatile unsigned char L_FPGACHECKFAULT_CFDWH_gui;
volatile unsigned char L_FPGACHECKFAULT_CFDCHP_gui;
volatile unsigned char L_FPGACHECKFAULT_CFDCHPLEADH_gui;
volatile unsigned char L_FPGACHECKFAULT_CFDCHPLEADL_gui;
volatile unsigned char L_FPGACHECKFAULT_CFDCHPLAGH_gui;
volatile unsigned char L_FPGACHECKFAULT_CFDCHPLAGL_gui;
volatile unsigned char L_FPGACHECKFAULT_CFDBUCK_gui;
volatile unsigned char L_FPGACHECKFAULT_CFDRSNC_gui;
volatile unsigned char L_FPGACHECKFAULT_FCOVD_gui;
volatile unsigned char L_FPGACHECKFAULT_BSOCD_gui;
volatile unsigned char L_FPGACHECKFAULT_INVOCD_gui;
volatile unsigned char L_FPGACHECKFAULT_INVOCDU_gui;
volatile unsigned char L_FPGACHECKFAULT_INVOCDV_gui;
volatile unsigned char L_FPGACHECKFAULT_INVOCDW_gui;
volatile unsigned char L_FPGACHECKFAULT_CIOCD_gui;
volatile unsigned char L_FPGACHECKFAULT_INVOVDU_gui;
volatile unsigned char L_FPGACHECKFAULT_INVOVDV_gui;
volatile unsigned char L_FPGACHECKFAULT_BUCKCDV_gui;
volatile unsigned char L_FPGACHECKFAULT_DCDCTOCD_gui;
volatile unsigned char L_FPGACHECKFAULT_DCDCCDV_gui;
volatile unsigned char L_FPGACHECKFAULT_DCDCOCD_gui;
volatile unsigned char L_FPGACHECKFAULT_SIVOCD_gui;
volatile unsigned char L_FPGACHECKFAULT_PSLVD_gui;
volatile unsigned char L_FPGACHECKFAULT_LOCALPLD_gui;
volatile unsigned char L_FPGACHECKFAULT_LOCALPOD_gui;
/*****16 路 DI*****/
volatile unsigned int A_DSPRDFPGA_DINLOCALSTA_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA0_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA1_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA2_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA3_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA4_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA5_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA6_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA7_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA8_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA9_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA10_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA11_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA12_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA13_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA14_gui;
volatile unsigned char L_DSPRDFPGA_DINLOCALSTA15_gui;
/*****DI/DO诊断寄存器*****/
volatile unsigned int A_DSPRDFPGA_DOUTLOCALDIA_gui;
volatile unsigned int A_DSPRDFPGA_DINLOCALDIA_gui;
/*****事件记录*****/
volatile unsigned int A_DSPRDFPGA_EVENTRCON1_gui;
volatile unsigned char L_EVENT_CONL_EVENTRDY_gui;
volatile unsigned char L_EVENT_CONL_EVENTERASE_gui;
volatile unsigned char L_EVENT_CONL_EVENTWRDY_gui;
volatile unsigned char L_EVENT_CONL_EVENTRRDY_gui;
volatile unsigned char L_EVENT_CONL_EVENTN_gui;
volatile unsigned int A_EVENT_CONL_EVENTNUM_gui;
/*****本地模拟量采集*****/
volatile unsigned int A_DSPRDFPGA_LOCALAIN0_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN1_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN2_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN3_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN4_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN5_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN6_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN7_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN8_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN9_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN10_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN11_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN12_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN13_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN14_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN15_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN16_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN17_gui;
volatile unsigned int A_DSPRDFPGA_LOCALPOWERAIN_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN3RMS_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN4RMS_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN5RMS_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN6RMS_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN10RMS_gui;
volatile unsigned int A_DSPRDFPGA_LOCALAIN12RMS_gui;
volatile unsigned int A_DSPRDFPGA_INVUOUTFREQ_gui;
volatile unsigned int A_DSPRDFPGA_INVVOUTFREQ_gui;
volatile unsigned int A_DSPRDFPGA_INVWOUTFREQ_gui;
/*****FREQ_FPGA_BUSY*****/
volatile unsigned int A_FPGAWRDSP_FREQ_FPGA_BUSY_gui;

/*****************************************************************************
**                       Variable of TCU
*****************************************************************************/

//unsigned char               CCA4_FirstSend_gui = 0;
//extern  unsigned char      Identify_DSP_gui;

/* DSP1 and DSP2 EMAC variable */
volatile unsigned int DSP2_EMAC_addr[150];
volatile unsigned int DSP2_EMAC_data[150];
volatile unsigned int DSP_EMAC_addr[150];
extern unsigned int observe_variables_flag;// 0不能观测，1可以观测。
char enet_send_data[4096] = {'\0'};
extern char enet_recv_data[4096];
volatile unsigned int array_1_2[150];//初始化为0,1表示上位机发过来的地址是DSP1的，2是DSP2的
volatile unsigned short enet_dsp2_num = 0;//统计DSP2地址的个数
volatile unsigned int analyze_command_flag = 0;//0解析上位机命令，1不解析
volatile unsigned int recv_data_num = 0;
/******************************************************************************
**                     Local function Declarations
*******************************************************************************/
void WatchDog()
  {
	  if((HighInt_WD_Cnt < HIGHINT_WD_TIME) && (LowInt_WD_Cnt < LOWINT_WD_TIME))
	  {
//	    WD_Status_Out_gui = ~WD_Status_Out_gui;
	  }
//	  DATA_INSERT_BOOLEAN(temp, L_DSP_ERR_gui,     0);
//	  DATA_INSERT_BOOLEAN(temp, WD_Status_Out_gui, 1);
//	  HWREGH(DRAM_To_DSP_IOData_06) = temp;
  }
void DSP_Send_DRAM_ARMData(void)
{
  unsigned short temp = 0;


  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_REVREG_gui, UNSIGNED16_HIGH_BYTE);
  HWREGH(DSP_To_ARM_1284) = temp;
  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_REVREG_gui, UNSIGNED16_LOW_BYTE);
  HWREGH(DSP_To_ARM_1286) = temp;


  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DSPSTA_gui, UNSIGNED16_HIGH_BYTE);
  HWREGH(DSP_To_ARM_1290) = temp;
  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DSPSTA_gui, UNSIGNED16_LOW_BYTE);
  HWREGH(DSP_To_ARM_1292) = temp;


  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG1_gui, UNSIGNED16_HIGH_BYTE);
  HWREGH(DSP_To_ARM_12C0) = temp;
  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG1_gui, UNSIGNED16_LOW_BYTE);
  HWREGH(DSP_To_ARM_12C2) = temp;


  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG2_gui, UNSIGNED16_HIGH_BYTE);
  HWREGH(DSP_To_ARM_12C4) = temp;
  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG2_gui, UNSIGNED16_LOW_BYTE);
  HWREGH(DSP_To_ARM_12C6) = temp;



  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG3_gui, UNSIGNED16_HIGH_BYTE);
  HWREGH(DSP_To_ARM_12C8) = temp;
  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG3_gui, UNSIGNED16_LOW_BYTE);
  HWREGH(DSP_To_ARM_12CA) = temp;


  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG4_gui, UNSIGNED16_HIGH_BYTE);
  HWREGH(DSP_To_ARM_12CC) = temp;
  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG4_gui, UNSIGNED16_LOW_BYTE);
  HWREGH(DSP_To_ARM_12CE) = temp;


  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG5_gui, UNSIGNED16_HIGH_BYTE);
  HWREGH(DSP_To_ARM_12D0) = temp;
  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG5_gui, UNSIGNED16_LOW_BYTE);
  HWREGH(DSP_To_ARM_12D2) = temp;


  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG6_gui, UNSIGNED16_HIGH_BYTE);
  HWREGH(DSP_To_ARM_12D4) = temp;
  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG6_gui, UNSIGNED16_LOW_BYTE);
  HWREGH(DSP_To_ARM_12D6) = temp;



  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG7_gui, UNSIGNED16_HIGH_BYTE);
  HWREGH(DSP_To_ARM_12D8) = temp;
  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG7_gui, UNSIGNED16_LOW_BYTE);
  HWREGH(DSP_To_ARM_12DA) = temp;


  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG8_gui, UNSIGNED16_HIGH_BYTE);
  HWREGH(DSP_To_ARM_12DC) = temp;
  temp = 0;
  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG8_gui, UNSIGNED16_LOW_BYTE);
  HWREGH(DSP_To_ARM_12DE) = temp;
//
//  temp = 0;
//  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG39_gui, UNSIGNED16_HIGH_BYTE);
//  HWREGH(DSP_To_ARM_1358) = temp;
//  temp = 0;
//  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG39_gui, UNSIGNED16_LOW_BYTE);
//  HWREGH(DSP_To_ARM_135A) = temp;
//
//  temp = 0;
//  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG40_gui, UNSIGNED16_HIGH_BYTE);
//  HWREGH(DSP_To_ARM_135C) = temp;
//  temp = 0;
//  DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG40_gui, UNSIGNED16_LOW_BYTE);
//  HWREGH(DSP_To_ARM_135E) = temp;
}
void DSP_Get_DRAM_ARMData(void)
{
	unsigned short temp = 0;
	temp = HWREGH(ARM_To_DSP_128C);
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_PWM_TEST_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_128E);
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_PWM_TEST_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_128C);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_PWM_TEST_EN_gui,    0);

	/*充电机故障存储区域变量*/
	temp = HWREGH(ARM_To_DSP_12E8);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG11_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_12EA);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG11_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_12EC);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG12_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_12EE);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG12_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_12F0);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG13_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_12F2);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG13_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_12F4);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG14_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_12F6);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG14_gui, UNSIGNED16_LOW_BYTE);

    temp = HWREGH(ARM_To_DSP_12F8);
    DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG15_gui, UNSIGNED16_HIGH_BYTE);
    temp = HWREGH(ARM_To_DSP_12FA);
    DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG15_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_1364);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG42_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_1366);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG42_gui, UNSIGNED16_LOW_BYTE);

    EventBuf[0] = A_ARMRDDSP_DEBUG11_gui;
    EventBuf[1] = A_ARMRDDSP_DEBUG12_gui;
    EventBuf[2] = A_ARMRDDSP_DEBUG13_gui;
    EventBuf[3] = A_ARMRDDSP_DEBUG14_gui;
    EventBuf[4] = A_ARMRDDSP_DEBUG15_gui;
    EventBuf[5] = A_ARMRDDSP_DEBUG42_gui;
	/*充电机故障存储区域变量*/


	/*获取逻辑状态*/
	temp = HWREGH(ARM_To_DSP_12E0);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG9_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_12E2);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG9_gui, UNSIGNED16_LOW_BYTE);

    temp= (unsigned short)(A_ARMRDDSP_DEBUG9_gui&0xffff);
    DATA_EXTRACT_BOOLEAN(temp,	  	L_AUX_SYSRST_gui,       		0);
    DATA_EXTRACT_BOOLEAN(temp,  	L_AUX_EXCLREQ_gui,      		1);
    DATA_EXTRACT_BOOLEAN(temp,  	L_AUX_TESTMODE_gui,     		2);
    DATA_EXTRACT_BOOLEAN(temp,  	L_CHPPWM_REQ_gui,       		3);
    DATA_EXTRACT_BOOLEAN(temp,  	L_INVPWM_REQ_gui,       		4);
    DATA_EXTRACT_BOOLEAN(temp,  	L_PROSET_OK_gui,        		6);
    DATA_EXTRACT_BOOLEAN(temp,  	L_DCDCPWM_REQ_gui,      		8);
    DATA_EXTRACT_BOOLEAN(temp,  	L_RSNCPWM_REQ_gui,      		9);
    DATA_EXTRACT_BOOLEAN(temp,  	L_BUCKPWM_REQ_gui,     			10);
    DATA_EXTRACT_BOOLEAN(temp,  	L_VEHL_RUNMODE_gui,    			11);
    DATA_EXTRACT_BOOLEAN(temp,  	L_VEHL_RUNMODE_gui,    			12);
    DATA_EXTRACT_BOOLEAN(temp,  	L_INIT_STA_gui,        			13);
    DATA_EXTRACT_BOOLEAN(temp,  	L_SIV_start_Comm_gui,	  		14);
    DATA_EXTRACT_BOOLEAN(temp,  	L_DCDC_start_Comm_gui, 			15);

    temp= (unsigned short)((A_ARMRDDSP_DEBUG9_gui&0xffff0000)>>16);

    DATA_EXTRACT_BOOLEAN(temp,  	L_BUCK_start_Comm_gui,		     	0);
    DATA_EXTRACT_BOOLEAN(temp,  	L_BL_master_judgment_gui,		  	1);
    DATA_EXTRACT_BOOLEAN(temp,  	L_Inverter_start_gui,      			2);
    DATA_EXTRACT_BOOLEAN(temp,  	L_SIVCTT_open_Req_Acc_gui,		 	3);
    DATA_EXTRACT_BOOLEAN(temp,  	L_System_Ready_gui,        			4);	
    DATA_EXTRACT_BOOLEAN(temp,  	CTAX_SIVCutoffCmd_B1_gui,  			5);
}
void DSP_Send_DRAM_FPGAData(void)
{
	//zsl add
	unsigned short temp = 0;
	unsigned short temp1 = 0;

	temp = 0;
	DATA_INSERT_BOOLEAN(temp,  L_PWM_TIMERENA_gui,             0);
	DATA_INSERT_BOOLEAN(temp,  L_PWM_CMPENA_gui,               1);
	DATA_INSERT_BOOLEAN(temp,  L_CHPPWM_TIMEENA_gui,           2);
	DATA_INSERT_BOOLEAN(temp,  L_CHPPWM_CMPENA_gui,            3);
	DATA_INSERT_BOOLEAN(temp,  L_RSTPWM_TIMEENA_gui,           4);
	DATA_INSERT_BOOLEAN(temp,  L_RSTPWM_CMPENA_gui,            5);
	DATA_INSERT_BOOLEAN(temp,  L_DCDCPWM_TIMEENA_gui,          6);
	DATA_INSERT_BOOLEAN(temp,  L_DCDCPWM_CMP1ENA_gui,          7);
	DATA_INSERT_BOOLEAN(temp,  L_DCDCPWM_CMP2ENA_gui,          8);
	DATA_INSERT_BOOLEAN(temp,  L_BUCKPWM_TIMEENA_gui,          9);
	DATA_INSERT_BOOLEAN(temp,  L_BUCKPWM_CMPENA_gui,          10);
	DATA_INSERT_BOOLEAN(temp,  L_PWM_CHECKIGBTENA_gui,        11);
	DATA_INSERT_BOOLEAN(temp,  L_CHPPWM_CHECKIGBTENA_gui,     12);
	DATA_INSERT_BOOLEAN(temp,  L_DCDCPWM_CHECKIGBTENA_gui,    13);
	DATA_INSERT_BOOLEAN(temp,  L_BuckPWM_CHECKIGBTENA_gui,    14);

	HWREGH(DSP_To_FPGA_0000) = temp;
	///////////////////////////////////////////////////////////////////////////////////////////////SIV
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_PWMTPR_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_FPGA_0004) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_PWMTPR_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_FPGA_0006) = temp;

	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_PWMDBCON_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_FPGA_000C) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_PWMDBCON_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_FPGA_000E) = temp;

///////////////////////////////////////////////////////////////////////////////////////////////////OVT
    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_CHPPRD_gui, UNSIGNED16_HIGH_BYTE);
    HWREGH(DSP_To_FPGA_0020) = temp;
    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_CHPPRD_gui, UNSIGNED16_LOW_BYTE);
    HWREGH(DSP_To_FPGA_0022) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_CHPDBTCON_gui, UNSIGNED16_HIGH_BYTE);
    HWREGH(DSP_To_FPGA_0024) = temp;
    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_CHPDBTCON_gui, UNSIGNED16_LOW_BYTE);
    HWREGH(DSP_To_FPGA_0026) = temp;

////////////////////////////////////////////////////////////////////////////////////////////////////DCDC
    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DCDCPRD_gui, UNSIGNED16_HIGH_BYTE);
    HWREGH(DSP_To_FPGA_0040) = temp;
    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DCDCPRD_gui, UNSIGNED16_LOW_BYTE);
    HWREGH(DSP_To_FPGA_0042) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DCDCDBTCON_gui, UNSIGNED16_HIGH_BYTE);
    HWREGH(DSP_To_FPGA_0044) = temp;
    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DCDCDBTCON_gui, UNSIGNED16_LOW_BYTE);
    HWREGH(DSP_To_FPGA_0046) = temp;

////////////////////////////////////////////////////////////////////////////////////////////////////BUCK

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_BUCKPRD_gui, UNSIGNED16_HIGH_BYTE);
    HWREGH(DSP_To_FPGA_0058) = temp;
    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_BUCKPRD_gui, UNSIGNED16_LOW_BYTE);
    HWREGH(DSP_To_FPGA_005A) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_BUCKDBTCON_gui, UNSIGNED16_HIGH_BYTE);
    HWREGH(DSP_To_FPGA_005C) = temp;
    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_BUCKDBTCON_gui, UNSIGNED16_LOW_BYTE);
    HWREGH(DSP_To_FPGA_005E) = temp;

////////////////////////////////////////////////////////////////////////////////////////////////////DSPWRFPGA

    temp = 0;
    temp1 = 0;
    DATA_INSERT_BOOLEAN(temp,  L_AUX_SYSRST_gui,                0);
    DATA_INSERT_BOOLEAN(temp,  L_AUX_EXCLREQ_gui,               1);
    DATA_INSERT_BOOLEAN(temp,  L_AUX_TESTMODE_gui,              2);
    DATA_INSERT_BOOLEAN(temp,  L_CHPPWM_REQ_gui,                3);
    DATA_INSERT_BOOLEAN(temp,  L_INVPWM_REQ_gui,                4);
    DATA_INSERT_BOOLEAN(temp,  L_RSNCPWM_REQ_gui,               5);
    DATA_INSERT_BOOLEAN(temp,  L_DCDCPWM_REQ_gui,               6);
    DATA_INSERT_BOOLEAN(temp,  L_BUCKPWM_REQ_gui,               7);
    DATA_INSERT_BOOLEAN(temp,  L_PROSET_OK_gui,                 8);
    DATA_INSERT_BOOLEANdb(temp,  L_VEHL_RUNMODE_gui,            9);

    DATA_INSERT_BOOLEAN(temp1,  L_PQenable_gui,                 0);
    DATA_INSERT_BOOLEAN(temp1,  L_Juzero_gui,            		1);
    HWREG(DSP_To_FPGA_00C4) = temp + ((unsigned int)temp1<<16);

}


//**32位数据读取函数**//
void DSP_Get_DRAM_FPGAData(void)
{
	unsigned short temp = 0;

	temp = HWREGH(FPGA_To_DSP_00C0);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDFPGA_STA_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(FPGA_To_DSP_00C2);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDFPGA_STA_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(FPGA_To_DSP_00C0);
	DATA_EXTRACT_BOOLEAN(temp,  L_INV_FAULT_gui,      0);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGA_STA_gui,       1);
	DATA_EXTRACT_BOOLEAN(temp,  L_INIT_STA_gui,       2);
	DATA_EXTRACT_BOOLEAN(temp,  L_EXCL_STA_gui,       3);
	DATA_EXTRACT_BOOLEAN(temp,  L_RSNC_PWMENA_gui,    4);
	DATA_EXTRACT_BOOLEAN(temp,  L_CHP_PWMENA_gui,     5);
	DATA_EXTRACT_BOOLEAN(temp,  L_INV_PWMENA_gui,     6);
	DATA_EXTRACT_BOOLEAN(temp,  L_DCDC_PWMENA_gui,    7);
	DATA_EXTRACT_BOOLEAN(temp,  L_BUCK_PWMENA_gui,    8);

	temp = HWREGH(FPGA_To_DSP_00E0);
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_FPGACHECKFAULT_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(FPGA_To_DSP_00E2);
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_FPGACHECKFAULT_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(FPGA_To_DSP_00E0);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_CFDUL_gui,       0);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_CFDUH_gui,       1);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_CFDVL_gui,       2);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_CFDVH_gui,       3);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_CFDWL_gui,       4);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_CFDWH_gui,       5);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_CFDCHP_gui,      6);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_CFDCHPLEADH_gui, 8);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_CFDCHPLEADL_gui, 9);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_CFDCHPLAGH_gui,       10);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_CFDCHPLAGL_gui,       11);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_CFDBUCK_gui,          12);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_CFDRSNC_gui,          13);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_FCOVD_gui,            14);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_BSOCD_gui,            15);

	temp = HWREGH(FPGA_To_DSP_00E2);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_INVOCD_gui,        0);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_INVOCDU_gui,       1);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_INVOCDV_gui,       2);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_INVOCDW_gui,       3);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_CIOCD_gui,         4);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_INVOVDU_gui,       5);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_INVOVDV_gui,       6);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_BUCKCDV_gui,       7);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_DCDCTOCD_gui,      8);


	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_DCDCCDV_gui,       9);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_DCDCOCD_gui,      10);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_SIVOCD_gui,       11);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_PSLVD_gui,        12);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_LOCALPLD_gui,     13);
	DATA_EXTRACT_BOOLEAN(temp,  L_FPGACHECKFAULT_LOCALPOD_gui,     14);

	temp = HWREGH(FPGA_To_DSP_00E4);
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_DINLOCALSTA_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(FPGA_To_DSP_00E6);
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_DINLOCALSTA_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(FPGA_To_DSP_00E4);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA0_gui,        0);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA1_gui,        1);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA2_gui,        2);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA3_gui,        3);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA4_gui,        4);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA5_gui,        5);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA6_gui,        6);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA7_gui,        7);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA8_gui,        8);

	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA9_gui,       9);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA10_gui,     10);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA11_gui,     11);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA12_gui,     12);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA13_gui,     13);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA14_gui,     14);
	DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DINLOCALSTA15_gui,     15);

	temp = HWREGH(FPGA_To_DSP_00E4);
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_DINLOCALDIA_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(FPGA_To_DSP_00F2);
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_DINLOCALDIA_gui, UNSIGNED16_LOW_BYTE);
}

/********************************* End of file *******************************/

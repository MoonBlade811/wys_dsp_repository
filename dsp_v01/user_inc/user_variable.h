/**
 *  \file  user_uart.h
*/


#ifndef _USER_VARIABLE_H
#define _USER_VARIABLE_H


#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
**                       Variable of ACU
*****************************************************************************/
/* ARM send DSP data */
extern volatile unsigned int  A_ARMWRDSP_INVCON_gui;
extern volatile unsigned char L_AUX_SYSRST_gui;
extern volatile unsigned char L_AUX_EXCLREQ_gui;
extern volatile unsigned char L_AUX_TESTMODE_gui;
extern volatile unsigned char L_CHPPWM_REQ_gui;
extern volatile unsigned char L_INVPWM_REQ_gui;
extern volatile unsigned char L_PROSET_OK_gui;
extern volatile unsigned char L_DCDCPWM_REQ_gui;
extern volatile unsigned char L_RSNCPWM_REQ_gui;
extern volatile unsigned char L_BUCKPWM_REQ_gui;
extern volatile unsigned char L_VEHL_RUNMODE_gui;
extern volatile unsigned char L_INIT_STA_gui;
extern volatile unsigned char L_SIV_start_Comm_gui;
extern volatile unsigned char L_DCDC_start_Comm_gui;
extern volatile unsigned char L_BUCK_start_Comm_gui;
extern volatile unsigned char L_SIV_init_Flag_gui;
extern volatile unsigned char L_DCDC_init_Flag_gui;
extern volatile unsigned char L_BUCK_init_Flag_gui;
extern volatile unsigned char L_System_Ready_gui;
extern volatile unsigned char L_BL_master_judgment_gui;
extern volatile unsigned char L_Inverter_start_gui;
extern volatile unsigned char L_SIVCTT_open_Req_Acc_gui;
extern volatile unsigned char L_SIVCTT_CLOSE_BL_gui;
extern volatile unsigned char L_SIVCTT_close_Sta_gui;

extern volatile unsigned int  A_DSPRDFPGA_DOUTLOCALSTA_gui;
extern volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA0_gui;
extern volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA1_gui;
extern volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA2_gui;
extern volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA3_gui;
extern volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA4_gui;
extern volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA5_gui;
extern volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA6_gui;
extern volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA7_gui;
extern volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA8_gui;
extern volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA9_gui;
extern volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA10_gui;
extern volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA11_gui;
extern volatile unsigned char L_DSPRDFPGA_DOUTLOCALSTA12_gui;
extern volatile unsigned int  A_DSPRDFPGA_PWM_TEST_gui;
extern volatile unsigned char L_DSPRDFPGA_PWM_TEST_EN_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG9_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG10_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG11_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG12_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG13_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG14_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG15_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG16_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG41_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG42_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG43_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG44_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG45_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG46_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG47_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG48_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG49_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG50_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG51_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG52_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG53_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG54_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG55_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG56_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG57_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG58_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG59_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG60_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG61_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG62_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG63_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG64_gui;

/* DSP send ARM data */

extern volatile unsigned int   A_ARMRDDSP_REVREG_gui;
extern volatile unsigned int   A_ARMRDDSP_DSPSTA_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG1_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG2_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG3_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG4_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG5_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG6_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG7_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG8_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG17_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG18_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG19_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG20_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG21_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG22_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG23_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG24_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG25_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG26_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG27_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG28_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG29_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG30_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG31_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG32_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG33_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG34_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG35_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG36_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG37_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG38_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG39_gui;
extern volatile unsigned int   A_ARMRDDSP_DEBUG40_gui;

/* DSP send FPGA data */

extern volatile unsigned int A_DSPWRFPGA_PWMCON_gui;
extern volatile unsigned char L_PWM_TIMERENA_gui;
extern volatile unsigned char L_PWM_CMPENA_gui;
extern volatile unsigned char L_CHPPWM_TIMEENA_gui;
extern volatile unsigned char L_CHPPWM_CMPENA_gui;
extern volatile unsigned char L_RSTPWM_TIMEENA_gui;
extern volatile unsigned char L_RSTPWM_CMPENA_gui;
extern volatile unsigned char L_DCDCPWM_TIMEENA_gui;
extern volatile unsigned char L_DCDCPWM_CMP1ENA_gui;
extern volatile unsigned char L_DCDCPWM_CMP2ENA_gui;
extern volatile unsigned char L_BUCKPWM_TIMEENA_gui;
extern volatile unsigned char L_BUCKPWM_CMPENA_gui;
extern volatile unsigned char L_PWM_CHECKIGBTENA_gui;
extern volatile unsigned char L_CHPPWM_CHECKIGBTENA_gui;
extern volatile unsigned char L_DCDCPWM_CHECKIGBTENA_gui;
extern volatile unsigned char L_BuckPWM_CHECKIGBTENA_gui;

extern volatile unsigned int  A_DSPWRFPGA_PWMTPR_gui;
extern volatile unsigned int  A_DSPWRFPGA_PWMDBCON_gui;
extern volatile unsigned char L_PWM_DBENA_gui;
extern volatile unsigned short L_PWM_DBTPR_gui;
extern volatile unsigned int  A_PWM_CMPU_gui;
extern volatile unsigned int  A_PWM_CMPV_gui;
extern volatile unsigned int  A_PWM_CMPW_gui;
extern volatile unsigned int  A_DSPWRFPGA_CHPPRD_gui;
extern volatile unsigned int  A_DSPWRFPGA_CHPDBTCON_gui;
extern volatile unsigned char L_CHPPWM_DBENA_gui;
extern volatile unsigned short L_CHPPWM_DBTPR_gui;
extern volatile unsigned int  A_DSPWRFPGA_CHPCMPR_gui;
extern volatile unsigned int  A_DSPWRFPGA_RSNCPRD_gui;
extern volatile unsigned int  A_DSPWRFPGA_RSNCCMPR_gui;
extern volatile unsigned int  A_DSPWRFPGA_RSNCDBTCON_gui;
extern volatile unsigned char L_RSNCPWM_DBENA_gui;
extern volatile unsigned short L_RSNCPWM_DBTPR_gui;
extern volatile unsigned int  A_DSPWRFPGA_RSNCTIMER_gui;
extern volatile unsigned int  A_DSPWRFPGA_DCDCPRD_gui;
extern volatile unsigned int  A_DSPWRFPGA_DCDCDBTCON_gui;
extern volatile unsigned char L_DCDCPWM_DBENA_gui;
extern volatile unsigned short L_DCDCPWM_DBTPR_gui;
extern volatile unsigned int  A_DSPWRFPGA_DCDCPSLD_gui;
extern volatile unsigned int A_DSPWRFPGA_DCDCPSLG_gui;
extern volatile unsigned int A_DSPWRFPGA_DCDCPRULD_gui;
extern volatile unsigned int A_DSPWRFPGA_DCDCPRULG_gui;
extern volatile unsigned int A_DSPWRFPGA_BUCKPRD_gui;
extern volatile unsigned int A_DSPWRFPGA_BUCKDBTCON_gui;
extern volatile unsigned char L_BUCKPWM_DBENA_gui;
extern volatile unsigned short L_BUCKPWM_DBTPR_gui;
extern volatile unsigned int A_DSPWRFPGA_BUCKCMPR_gui;
extern volatile unsigned int A_DSPWRFPGA_PWM_DSP_BUSY_gui;
extern volatile unsigned int A_DSPWRFPGA_INVCON_gui;
extern volatile unsigned char L_AUX_SYSRST_gui;
extern volatile unsigned char L_AUX_EXCLREQ_gui;
extern volatile unsigned char L_AUX_TESTMODE_gui;
extern volatile unsigned char L_CHPPWM_REQ_gui;
extern volatile unsigned char L_INVPWM_REQ_gui;
extern volatile unsigned char L_RSNCPWM_REQ_gui;
extern volatile unsigned char L_DCDCPWM_REQ_gui;
extern volatile unsigned char L_BUCKPWM_REQ_gui;
extern volatile unsigned char L_PROSET_OK_gui;
extern volatile unsigned char L_VEHL_RUNMODE_gui;
extern volatile unsigned char L_PQenable_gui;
extern volatile unsigned char L_Juzero_gui;

extern volatile unsigned int A_DSPWRFPGA_DOUTLOCALSTA_gui;
extern volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA0_gui;
extern volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA1_gui;
extern volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA2_gui;
extern volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA3_gui;
extern volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA4_gui;
extern volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA5_gui;
extern volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA6_gui;
extern volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA7_gui;
extern volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA8_gui;
extern volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA9_gui;
extern volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA10_gui;
extern volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA11_gui;
extern volatile unsigned char L_DSPWRFPGA_DOUTLOCALSTA12_gui;
extern volatile unsigned int  A_DSPWRFPGA_EVENTRCON2_gui;
extern volatile unsigned char L_EVENT_CON2_EVENTW_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM1_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM2_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM3_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM4_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM5_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM6_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM7_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM8_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM9_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM10_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM11_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM12_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM13_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM14_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM15_gui;
extern volatile unsigned int A_DSPRDFPGA_CTRLPARAM16_gui;
extern volatile unsigned int A_DSPWRFPGA_FREQ_DSP_BUSY_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG1_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG2_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG3_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG4_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG5_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG6_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG7_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG8_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG9_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG10_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG11_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG12_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG13_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG14_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG15_gui;
extern volatile unsigned int A_DSPWRFPGA_DAMREG16_gui;

/* FPGA send DSP data */

extern volatile unsigned int A_FPGAWRDSP_PWM_FPGA_BUSY_gui;
extern volatile unsigned int A_ARMRDFPGA_STA_gui;
extern volatile unsigned char L_INV_FAULT_gui;
extern volatile unsigned char L_FPGA_STA_gui;
extern volatile unsigned char L_INIT_STA_gui;
extern volatile unsigned char L_EXCL_STA_gui;
extern volatile unsigned char L_RSNC_PWMENA_gui;
extern volatile unsigned char L_CHP_PWMENA_gui;
extern volatile unsigned char L_INV_PWMENA_gui;
extern volatile unsigned char L_DCDC_PWMENA_gui;
extern volatile unsigned char L_BUCK_PWMENA_gui;

extern volatile unsigned int L_FPGATODSP_Usin_gui;
extern volatile unsigned int L_FPGATODSP_Ucos_gui;
extern volatile unsigned int L_FPGATODSP_Isin_gui;
extern volatile unsigned int L_FPGATODSP_Icos_gui;

extern volatile unsigned int A_DSPRDFPGA_FPGACHECKFAULT_gui;
extern volatile unsigned char L_FPGACHECKFAULT_CFDUL_gui;
extern volatile unsigned char L_FPGACHECKFAULT_CFDUH_gui;
extern volatile unsigned char L_FPGACHECKFAULT_CFDVL_gui;
extern volatile unsigned char L_FPGACHECKFAULT_CFDVH_gui;
extern volatile unsigned char L_FPGACHECKFAULT_CFDWL_gui;
extern volatile unsigned char L_FPGACHECKFAULT_CFDWH_gui;
extern volatile unsigned char L_FPGACHECKFAULT_CFDCHP_gui;
extern volatile unsigned char L_FPGACHECKFAULT_CFDCHPLEADH_gui;
extern volatile unsigned char L_FPGACHECKFAULT_CFDCHPLEADL_gui;
extern volatile unsigned char L_FPGACHECKFAULT_CFDCHPLAGH_gui;
extern volatile unsigned char L_FPGACHECKFAULT_CFDCHPLAGL_gui;
extern volatile unsigned char L_FPGACHECKFAULT_CFDBUCK_gui;
extern volatile unsigned char L_FPGACHECKFAULT_CFDRSNC_gui;
extern volatile unsigned char L_FPGACHECKFAULT_FCOVD_gui;
extern volatile unsigned char L_FPGACHECKFAULT_BSOCD_gui;
extern volatile unsigned char L_FPGACHECKFAULT_INVOCD_gui;
extern volatile unsigned char L_FPGACHECKFAULT_INVOCDU_gui;
extern volatile unsigned char L_FPGACHECKFAULT_INVOCDV_gui;
extern volatile unsigned char L_FPGACHECKFAULT_INVOCDW_gui;
extern volatile unsigned char L_FPGACHECKFAULT_CIOCD_gui;
extern volatile unsigned char L_FPGACHECKFAULT_INVOVDU_gui;
extern volatile unsigned char L_FPGACHECKFAULT_INVOVDV_gui;
extern volatile unsigned char L_FPGACHECKFAULT_BUCKCDV_gui;
extern volatile unsigned char L_FPGACHECKFAULT_DCDCTOCD_gui;
extern volatile unsigned char L_FPGACHECKFAULT_DCDCCDV_gui;
extern volatile unsigned char L_FPGACHECKFAULT_DCDCOCD_gui;
extern volatile unsigned char L_FPGACHECKFAULT_SIVOCD_gui;
extern volatile unsigned char L_FPGACHECKFAULT_PSLVD_gui;
extern volatile unsigned char L_FPGACHECKFAULT_LOCALPLD_gui;
extern volatile unsigned char L_FPGACHECKFAULT_LOCALPOD_gui;
extern volatile unsigned int A_DSPRDFPGA_DINLOCALSTA_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA0_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA1_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA2_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA3_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA4_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA5_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA6_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA7_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA8_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA9_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA10_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA11_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA12_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA13_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA14_gui;
extern volatile unsigned char L_DSPRDFPGA_DINLOCALSTA15_gui;
extern volatile unsigned int A_DSPRDFPGA_DOUTLOCALDIA_gui;
extern volatile unsigned int A_DSPRDFPGA_DINLOCALDIA_gui;
extern volatile unsigned int A_DSPRDFPGA_EVENTRCON1_gui;
extern volatile unsigned char L_EVENT_CONL_EVENTRDY_gui;
extern volatile unsigned char L_EVENT_CONL_EVENTERASE_gui;
extern volatile unsigned char L_EVENT_CONL_EVENTWRDY_gui;
extern volatile unsigned char L_EVENT_CONL_EVENTRRDY_gui;
extern volatile unsigned char L_EVENT_CONL_EVENTN_gui;
extern volatile unsigned int A_EVENT_CONL_EVENTNUM_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN0_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN1_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN2_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN3_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN4_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN5_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN6_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN7_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN8_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN9_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN10_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN11_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN12_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN13_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN14_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN15_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN16_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN17_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALPOWERAIN_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN3RMS_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN4RMS_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN5RMS_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN6RMS_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN10RMS_gui;
extern volatile unsigned int A_DSPRDFPGA_LOCALAIN12RMS_gui;
extern volatile unsigned int A_DSPRDFPGA_INVUOUTFREQ_gui;
extern volatile unsigned int A_DSPRDFPGA_INVVOUTFREQ_gui;
extern volatile unsigned int A_DSPRDFPGA_INVWOUTFREQ_gui;
extern volatile unsigned int A_FPGAWRDSP_FREQ_FPGA_BUSY_gui;

#if 1
/******************************************************************************
**                        zxs add
*******************************************************************************/

/* CCA4 TO DSP  */

#define DRAM_To_DSP_LPData_0              0x64000000
#define DRAM_To_DSP_LPData_2              0x64000002
#define DRAM_To_DSP_LPData_4              0x64000004
#define DRAM_To_DSP_LPData_6              0x64000006
#define DRAM_To_DSP_LPData_8              0x64000008
#define DRAM_To_DSP_LPData_A              0x6400000A
#define DRAM_To_DSP_LPData_20             0x64000020
#define DRAM_To_DSP_LPData_22             0x64000022
#define DRAM_To_DSP_LPData_24             0x64000024
#define DRAM_To_DSP_LPData_26             0x64000026
#define DRAM_To_DSP_LPData_28             0x64000028
#define DRAM_To_DSP_LPData_2A             0x6400002A
#define DRAM_To_DSP_LPData_2C             0x6400002C
#define DRAM_To_DSP_LPData_2E             0x6400002E
#define DRAM_To_DSP_LPData_30             0x64000030
#define DRAM_To_DSP_LPData_32             0x64000032


#define DRAM_To_DSP_LPData_40             0x64000040
#define DRAM_To_DSP_LPData_42             0x64000042
#define DRAM_To_DSP_LPData_44             0x64000044
#define DRAM_To_DSP_LPData_46             0x64000046
#define DRAM_To_DSP_LPData_48             0x64000048
#define DRAM_To_DSP_LPData_4A             0x6400004A
#define DRAM_To_DSP_LPData_4C             0x6400004C
#define DRAM_To_DSP_LPData_4E             0x6400004E
#define DRAM_To_DSP_LPData_50             0x64000050
#define DRAM_To_DSP_LPData_60             0x64000060
#define DRAM_To_DSP_LPData_62             0x64000062
#define DRAM_To_DSP_LPData_64             0x64000064
#define DRAM_To_DSP_LPData_66             0x64000066
#define DRAM_To_DSP_LPData_68             0x64000068
#define DRAM_To_DSP_LPData_6A             0x6400006A
#define DRAM_To_DSP_LPData_6C             0x6400006C


#define DRAM_To_DSP_LPData_70             0x64000070
#define DRAM_To_DSP_LPData_72             0x64000072
#define DRAM_To_DSP_LPData_74             0x64000074
#define DRAM_To_DSP_LPData_76             0x64000076
#define DRAM_To_DSP_LPData_78             0x64000078
#define DRAM_To_DSP_LPData_7A             0x6400007A
#define DRAM_To_DSP_LPData_7C             0x6400007C
#define DRAM_To_DSP_LPData_80             0x64000080
#define DRAM_To_DSP_LPData_82             0x64000082
#define DRAM_To_DSP_LPData_84             0x64000084
#define DRAM_To_DSP_LPData_86             0x64000086
#define DRAM_To_DSP_LPData_88             0x64000088
#define DRAM_To_DSP_LPData_8A             0x6400008A
#define DRAM_To_DSP_LPData_8C             0x6400008C


#define DRAM_To_DSP_LPData_90             0x64000090
#define DRAM_To_DSP_LPData_92             0x64000092
#define DRAM_To_DSP_LPData_94             0x64000094
#define DRAM_To_DSP_LPData_96             0x64000096
#define DRAM_To_DSP_LPData_98             0x64000098
#define DRAM_To_DSP_LPData_A0             0x640000A0
#define DRAM_To_DSP_LPData_A2             0x640000A2
#define DRAM_To_DSP_LPData_A4             0x640000A4
#define DRAM_To_DSP_LPData_A6             0x640000A6
#define DRAM_To_DSP_LPData_A8             0x640000A8
#define DRAM_To_DSP_LPData_AA             0x640000AA
#define DRAM_To_DSP_LPData_AC             0x640000AC
#define DRAM_To_DSP_LPData_B0             0x640000B0
#define DRAM_To_DSP_LPData_B2             0x640000B2
#define DRAM_To_DSP_LPData_B4             0x640000B4
#define DRAM_To_DSP_LPData_B6             0x640000B6
#define DRAM_To_DSP_LPData_B8             0x640000B8
#define DRAM_To_DSP_LPData_BA             0x640000BA
#define DRAM_To_DSP_LPData_BC             0x640000BC


#define DRAM_To_DSP_LPData_C0             0x640000C0
#define DRAM_To_DSP_LPData_C2             0x640000C2
#define DRAM_To_DSP_LPData_C4             0x640000C4
#define DRAM_To_DSP_LPData_C6             0x640000C6
#define DRAM_To_DSP_LPData_C8             0x640000C8
#define DRAM_To_DSP_LPData_CA             0x640000CA
#define DRAM_To_DSP_LPData_D0             0x640000D0
#define DRAM_To_DSP_LPData_D2             0x640000D2
#define DRAM_To_DSP_LPData_D4             0x640000D4
#define DRAM_To_DSP_LPData_D6             0x640000D6
#define DRAM_To_DSP_LPData_D8             0x640000D8
#define DRAM_To_DSP_LPData_DA             0x640000DA
#define DRAM_To_DSP_LPData_E0             0x640000E0
#define DRAM_To_DSP_LPData_E2             0x640000E2
#define DRAM_To_DSP_LPData_E4             0x640000E4
#define DRAM_To_DSP_LPData_E6             0x640000E6
#define DRAM_To_DSP_LPData_E8             0x640000E8
#define DRAM_To_DSP_LPData_EA             0x640000EA


#define DRAM_To_DSP_LPData_F0             0x640000F0
#define DRAM_To_DSP_LPData_F2             0x640000F2
#define DRAM_To_DSP_LPData_F4             0x640000F4
#define DRAM_To_DSP_LPData_F6             0x640000F6
#define DRAM_To_DSP_LPData_F8             0x640000F8
#define DRAM_To_DSP_LPData_FA             0x640000FA
#define DRAM_To_DSP_LPData_100            0x64000100
#define DRAM_To_DSP_LPData_102            0x64000102
#define DRAM_To_DSP_LPData_104            0x64000104
#define DRAM_To_DSP_LPData_106            0x64000106
#define DRAM_To_DSP_LPData_108            0x64000108
#define DRAM_To_DSP_LPData_10A            0x6400010A
#define DRAM_To_DSP_LPData_110            0x64000110
#define DRAM_To_DSP_LPData_112            0x64000112
#define DRAM_To_DSP_LPData_114            0x64000114
#define DRAM_To_DSP_LPData_116            0x64000116
#define DRAM_To_DSP_LPData_118            0x64000118




#define DRAM_To_DSP_LPData_700            0x64000700




#define DSP_To_DRAM_LPData_702            0x64000702
#define DSP_To_DRAM_LPData_704            0x64000704
#define DSP_To_DRAM_LPData_706            0x64000706
#define DSP_To_DRAM_LPData_708            0x64000708
#define DSP_To_DRAM_LPData_70A            0x6400070A
#define DSP_To_DRAM_LPData_70C            0x6400070C
#define DSP_To_DRAM_LPData_70E            0x6400070E
#define DSP_To_DRAM_LPData_710            0x64000710
#define DSP_To_DRAM_LPData_712            0x64000712
#define DSP_To_DRAM_LPData_714            0x64000714
#define DSP_To_DRAM_LPData_716            0x64000716
#define DSP_To_DRAM_LPData_718            0x64000718
#define DSP_To_DRAM_LPData_71A            0x6400071A
#define DSP_To_DRAM_LPData_71C            0x6400071C
#define DSP_To_DRAM_LPData_71E            0x6400071E


#define DSP_To_DRAM_LPData_720            0x64000720
#define DSP_To_DRAM_LPData_722            0x64000722
#define DSP_To_DRAM_LPData_724            0x64000724
#define DSP_To_DRAM_LPData_726            0x64000726
#define DSP_To_DRAM_LPData_728            0x64000728
#define DSP_To_DRAM_LPData_72A            0x6400072A
#define DSP_To_DRAM_LPData_72C            0x6400072C
#define DSP_To_DRAM_LPData_72E            0x6400072E
#define DSP_To_DRAM_LPData_730            0x64000730
#define DSP_To_DRAM_LPData_732            0x64000732
#define DSP_To_DRAM_LPData_734            0x64000734
#define DSP_To_DRAM_LPData_736            0x64000736
#define DSP_To_DRAM_LPData_738            0x64000738
#define DSP_To_DRAM_LPData_73A            0x6400073A
#define DSP_To_DRAM_LPData_73C            0x6400073C
#define DSP_To_DRAM_LPData_73E            0x6400073E


#define DSP_To_DRAM_LPData_740            0x64000740
#define DSP_To_DRAM_LPData_742            0x64000742
#define DSP_To_DRAM_LPData_744            0x64000744
#define DSP_To_DRAM_LPData_746            0x64000746
#define DSP_To_DRAM_LPData_748            0x64000748
#define DSP_To_DRAM_LPData_74A            0x6400074A
#define DSP_To_DRAM_LPData_74C            0x6400074C
#define DSP_To_DRAM_LPData_74E            0x6400074E
#define DSP_To_DRAM_LPData_750            0x64000750
#define DSP_To_DRAM_LPData_752            0x64000752
#define DSP_To_DRAM_LPData_754            0x64000754
#define DSP_To_DRAM_LPData_756            0x64000756
#define DSP_To_DRAM_LPData_758            0x64000758
#define DSP_To_DRAM_LPData_75A            0x6400075A
#define DSP_To_DRAM_LPData_75C            0x6400075C
#define DSP_To_DRAM_LPData_75E            0x6400075E
#define DSP_To_DRAM_LPData_760            0x64000760
#define DSP_To_DRAM_LPData_762            0x64000762
#define DSP_To_DRAM_LPData_764            0x64000764
#define DSP_To_DRAM_LPData_766            0x64000766
#define DSP_To_DRAM_LPData_768            0x64000768
#define DSP_To_DRAM_LPData_76A            0x6400076A






#define DRAM_To_DSP_LPData_1FE            0x640001FE
#define DSP_To_DRAM_LPData_1FC            0x640001FC






/****DSP TO CCA4**/

#define DSP_To_DRAM_LPData_400            0x64000400
#define DSP_To_DRAM_LPData_404            0x64000404
#define DSP_To_DRAM_LPData_406            0x64000406
#define DSP_To_DRAM_LPData_408            0x64000408
#define DSP_To_DRAM_LPData_410            0x64000410
#define DSP_To_DRAM_LPData_412            0x64000412
#define DSP_To_DRAM_LPData_414            0x64000414
#define DSP_To_DRAM_LPData_416            0x64000416
#define DSP_To_DRAM_LPData_418            0x64000418
#define DSP_To_DRAM_LPData_41A            0x6400041A
#define DSP_To_DRAM_LPData_420            0x64000420
#define DSP_To_DRAM_LPData_422            0x64000422
#define DSP_To_DRAM_LPData_424            0x64000424
#define DSP_To_DRAM_LPData_426            0x64000426
#define DSP_To_DRAM_LPData_428            0x64000428
#define DSP_To_DRAM_LPData_42A            0x6400042A



#define DSP_To_DRAM_LPData_430            0x64000430
#define DSP_To_DRAM_LPData_432            0x64000432
#define DSP_To_DRAM_LPData_434            0x64000434
#define DSP_To_DRAM_LPData_436            0x64000436
#define DSP_To_DRAM_LPData_438            0x64000438
#define DSP_To_DRAM_LPData_43A            0x6400043A
#define DSP_To_DRAM_LPData_440            0x64000440
#define DSP_To_DRAM_LPData_442            0x64000442
#define DSP_To_DRAM_LPData_444            0x64000444
#define DSP_To_DRAM_LPData_446            0x64000446
#define DSP_To_DRAM_LPData_452            0x64000452
#define DSP_To_DRAM_LPData_454            0x64000454
#define DSP_To_DRAM_LPData_456            0x64000456
#define DSP_To_DRAM_LPData_458            0x64000458
#define DSP_To_DRAM_LPData_45A            0x6400045A
#define DSP_To_DRAM_LPData_45C            0x6400045C
#define DSP_To_DRAM_LPData_45E            0x6400045E

#define DSP_To_DRAM_LPData_462            0x64000462
#define DSP_To_DRAM_LPData_464            0x64000464
#define DSP_To_DRAM_LPData_466            0x64000466
#define DSP_To_DRAM_LPData_468            0x64000468
#define DSP_To_DRAM_LPData_46A            0x6400046A
#define DSP_To_DRAM_LPData_46C            0x6400046C
#define DSP_To_DRAM_LPData_46E            0x6400046E
#define DSP_To_DRAM_LPData_472            0x64000472
#define DSP_To_DRAM_LPData_474            0x64000474
#define DSP_To_DRAM_LPData_476            0x64000476
#define DSP_To_DRAM_LPData_478            0x64000478
#define DSP_To_DRAM_LPData_47A            0x6400047A
#define DSP_To_DRAM_LPData_47C            0x6400047C
#define DSP_To_DRAM_LPData_47E            0x6400047E


#define DSP_To_DRAM_LPData_482            0x64000482
#define DSP_To_DRAM_LPData_484            0x64000484
#define DSP_To_DRAM_LPData_486            0x64000486
#define DSP_To_DRAM_LPData_488            0x64000488
#define DSP_To_DRAM_LPData_48A            0x6400048A
#define DSP_To_DRAM_LPData_48C            0x6400048C
#define DSP_To_DRAM_LPData_48E            0x6400048E
#define DSP_To_DRAM_LPData_492            0x64000492
#define DSP_To_DRAM_LPData_494            0x64000494
#define DSP_To_DRAM_LPData_496            0x64000496
#define DSP_To_DRAM_LPData_498            0x64000498
#define DSP_To_DRAM_LPData_49A            0x6400049A
#define DSP_To_DRAM_LPData_49C            0x6400049C
#define DSP_To_DRAM_LPData_49E            0x6400049E


#define DSP_To_DRAM_LPData_4A0            0x640004A0
#define DSP_To_DRAM_LPData_4A2            0x640004A2
#define DSP_To_DRAM_LPData_4A4            0x640004A4
#define DSP_To_DRAM_LPData_4A6            0x640004A6
#define DSP_To_DRAM_LPData_4A8            0x640004A8
#define DSP_To_DRAM_LPData_4AA            0x640004AA
#define DSP_To_DRAM_LPData_4AC            0x640004AC
#define DSP_To_DRAM_LPData_4B0            0x640004B0
#define DSP_To_DRAM_LPData_4B2            0x640004B2
#define DSP_To_DRAM_LPData_4B4            0x640004B4
#define DSP_To_DRAM_LPData_4B6            0x640004B6
#define DSP_To_DRAM_LPData_4B8            0x640004B8
#define DSP_To_DRAM_LPData_4BA            0x640004BA
#define DSP_To_DRAM_LPData_4BC            0x640004BC



#define DSP_To_DRAM_LPData_4C0            0x640004C0
#define DSP_To_DRAM_LPData_4C2            0x640004C2
#define DSP_To_DRAM_LPData_4C4            0x640004C4
#define DSP_To_DRAM_LPData_4C6            0x640004C6
#define DSP_To_DRAM_LPData_4C8            0x640004C8
#define DSP_To_DRAM_LPData_4CA            0x640004CA
#define DSP_To_DRAM_LPData_4CC            0x640004CC
#define DSP_To_DRAM_LPData_4D0            0x640004D0
#define DSP_To_DRAM_LPData_4D2            0x640004D2
#define DSP_To_DRAM_LPData_4D4            0x640004D4
#define DSP_To_DRAM_LPData_4D6            0x640004D6
#define DSP_To_DRAM_LPData_4D8            0x640004D8
#define DSP_To_DRAM_LPData_4DA            0x640004DA
#define DSP_To_DRAM_LPData_4DC            0x640004DC


#define DSP_To_DRAM_LPData_4E0            0x640004E0
#define DSP_To_DRAM_LPData_4E2            0x640004E2
#define DSP_To_DRAM_LPData_4E4            0x640004E4
#define DSP_To_DRAM_LPData_4E6            0x640004E6
#define DSP_To_DRAM_LPData_4E8            0x640004E8
#define DSP_To_DRAM_LPData_4EA            0x640004EA
#define DSP_To_DRAM_LPData_4EC            0x640004EC
#define DSP_To_DRAM_LPData_4F0            0x640004F0
#define DSP_To_DRAM_LPData_4F2            0x640004F2
#define DSP_To_DRAM_LPData_4F4            0x640004F4
#define DSP_To_DRAM_LPData_4F6            0x640004F6
#define DSP_To_DRAM_LPData_4F8            0x640004F8
#define DSP_To_DRAM_LPData_4FA            0x640004FA


#define DSP_To_DRAM_LPData_500            0x64000500
#define DSP_To_DRAM_LPData_502            0x64000502
#define DSP_To_DRAM_LPData_504            0x64000504
#define DSP_To_DRAM_LPData_506            0x64000506
#define DSP_To_DRAM_LPData_508            0x64000508
#define DSP_To_DRAM_LPData_50A            0x6400050A
#define DSP_To_DRAM_LPData_510            0x64000510
#define DSP_To_DRAM_LPData_512            0x64000512
#define DSP_To_DRAM_LPData_514            0x64000514
#define DSP_To_DRAM_LPData_516            0x64000516
#define DSP_To_DRAM_LPData_518            0x64000518
#define DSP_To_DRAM_LPData_51A            0x6400051A


#define DSP_To_DRAM_LPData_520            0x64000520
#define DSP_To_DRAM_LPData_522            0x64000522
#define DSP_To_DRAM_LPData_524            0x64000524
#define DSP_To_DRAM_LPData_526            0x64000526
#define DSP_To_DRAM_LPData_528            0x64000528
#define DSP_To_DRAM_LPData_52A            0x6400052A
#define DSP_To_DRAM_LPData_530            0x64000530
#define DSP_To_DRAM_LPData_532            0x64000532
#define DSP_To_DRAM_LPData_534            0x64000534
#define DSP_To_DRAM_LPData_536            0x64000536
#define DSP_To_DRAM_LPData_538            0x64000538
#define DSP_To_DRAM_LPData_53A            0x6400053A
#define DSP_To_DRAM_LPData_540            0x64000540
#define DSP_To_DRAM_LPData_542            0x64000542
#define DSP_To_DRAM_LPData_544            0x64000544
#define DSP_To_DRAM_LPData_546            0x64000546
#define DSP_To_DRAM_LPData_548            0x64000548
#define DSP_To_DRAM_LPData_54A            0x6400054A


#define DRAM_To_DSP_LPData_5FE            0x640005FE
#define DSP_To_DRAM_LPData_5FC            0x640005FC



/**DSP TO ARM***/

#define DSP_To_DRAM_ARM_000               0x64000000
#define DSP_To_DRAM_ARM_800               0x64000800
#define DSP_To_DRAM_ARM_802               0x64000802
#define DSP_To_DRAM_ARM_804               0x64000804
#define DSP_To_DRAM_ARM_806               0x64000806
#define DSP_To_DRAM_ARM_808               0x64000808
#define DSP_To_DRAM_ARM_80A               0x6400080A
#define DSP_To_DRAM_ARM_820               0x64000820
#define DSP_To_DRAM_ARM_822               0x64000822
#define DSP_To_DRAM_ARM_824               0x64000824
#define DSP_To_DRAM_ARM_826               0x64000826
#define DSP_To_DRAM_ARM_828               0x64000828
#define DSP_To_DRAM_ARM_82A               0x6400082A
#define DSP_To_DRAM_ARM_82C               0x6400082C
#define DSP_To_DRAM_ARM_82E               0x6400082E


#define DSP_To_DRAM_ARM_830               0x64000830
#define DSP_To_DRAM_ARM_832               0x64000832
#define DSP_To_DRAM_ARM_840               0x64000840
#define DSP_To_DRAM_ARM_842               0x64000842
#define DSP_To_DRAM_ARM_844               0x64000844
#define DSP_To_DRAM_ARM_846               0x64000846
#define DSP_To_DRAM_ARM_848               0x64000848
#define DSP_To_DRAM_ARM_84A               0x6400084A
#define DSP_To_DRAM_ARM_84C               0x6400084C
#define DSP_To_DRAM_ARM_84E               0x6400084E


#define DSP_To_DRAM_ARM_850               0x64000850
#define DSP_To_DRAM_ARM_860               0x64000860
#define DSP_To_DRAM_ARM_862               0x64000862
#define DSP_To_DRAM_ARM_864               0x64000864
#define DSP_To_DRAM_ARM_866               0x64000866
#define DSP_To_DRAM_ARM_868               0x64000868
#define DSP_To_DRAM_ARM_86A               0x6400086A
#define DSP_To_DRAM_ARM_86C               0x6400086C
#define DSP_To_DRAM_ARM_870               0x64000870
#define DSP_To_DRAM_ARM_872               0x64000872
#define DSP_To_DRAM_ARM_874               0x64000874
#define DSP_To_DRAM_ARM_876               0x64000876
#define DSP_To_DRAM_ARM_878               0x64000878
#define DSP_To_DRAM_ARM_87A               0x6400087A
#define DSP_To_DRAM_ARM_87C               0x6400087C



#define DSP_To_DRAM_ARM_880               0x64000880
#define DSP_To_DRAM_ARM_882               0x64000882
#define DSP_To_DRAM_ARM_884               0x64000884
#define DSP_To_DRAM_ARM_886               0x64000886
#define DSP_To_DRAM_ARM_888               0x64000888
#define DSP_To_DRAM_ARM_88A               0x6400088A
#define DSP_To_DRAM_ARM_88C               0x6400088C
#define DSP_To_DRAM_ARM_890               0x64000890
#define DSP_To_DRAM_ARM_892               0x64000892
#define DSP_To_DRAM_ARM_894               0x64000894
#define DSP_To_DRAM_ARM_896               0x64000896
#define DSP_To_DRAM_ARM_898               0x64000898
#define DSP_To_DRAM_ARM_89A               0x6400089A
#define DSP_To_DRAM_ARM_89C               0x6400089C


#define DSP_To_DRAM_ARM_8A0               0x640008A0
#define DSP_To_DRAM_ARM_8A2               0x640008A2
#define DSP_To_DRAM_ARM_8A4               0x640008A4
#define DSP_To_DRAM_ARM_8A6               0x640008A6
#define DSP_To_DRAM_ARM_8A8               0x640008A8
#define DSP_To_DRAM_ARM_8AA               0x640008AA
#define DSP_To_DRAM_ARM_8AC               0x640008AC





#define DSP_To_DRAM_ARM_8B0               0x640008B0
#define DSP_To_DRAM_ARM_8B2               0x640008B2
#define DSP_To_DRAM_ARM_8B4               0x640008B4
#define DSP_To_DRAM_ARM_8B6               0x640008B6
#define DSP_To_DRAM_ARM_8B8               0x640008B8
#define DSP_To_DRAM_ARM_8BA               0x640008BA
#define DSP_To_DRAM_ARM_8BC               0x640008BC
#define DSP_To_DRAM_ARM_8C0               0x640008C0
#define DSP_To_DRAM_ARM_8C2               0x640008C2
#define DSP_To_DRAM_ARM_8C4               0x640008C4
#define DSP_To_DRAM_ARM_8C6               0x640008C6
#define DSP_To_DRAM_ARM_8C8               0x640008C8
#define DSP_To_DRAM_ARM_8CA               0x640008CA
#define DSP_To_DRAM_ARM_8D0               0x640008D0
#define DSP_To_DRAM_ARM_8D2               0x640008D2
#define DSP_To_DRAM_ARM_8D4               0x640008D4
#define DSP_To_DRAM_ARM_8D6               0x640008D6
#define DSP_To_DRAM_ARM_8D8               0x640008D8
#define DSP_To_DRAM_ARM_8DA               0x640008DA




#define DSP_To_DRAM_ARM_8E0               0x640008E0
#define DSP_To_DRAM_ARM_8E2               0x640008E2
#define DSP_To_DRAM_ARM_8E4               0x640008E4
#define DSP_To_DRAM_ARM_8E6               0x640008E6
#define DSP_To_DRAM_ARM_8E8               0x640008E8
#define DSP_To_DRAM_ARM_8EA               0x640008EA
#define DSP_To_DRAM_ARM_8F0               0x640008F0
#define DSP_To_DRAM_ARM_8F2               0x640008F2
#define DSP_To_DRAM_ARM_8F4               0x640008F4
#define DSP_To_DRAM_ARM_8F6               0x640008F6
#define DSP_To_DRAM_ARM_8F8               0x640008F8
#define DSP_To_DRAM_ARM_8FA               0x640008FA
#define DSP_To_DRAM_ARM_900               0x64000900
#define DSP_To_DRAM_ARM_902               0x64000902
#define DSP_To_DRAM_ARM_904               0x64000904
#define DSP_To_DRAM_ARM_906               0x64000906
#define DSP_To_DRAM_ARM_908               0x64000908
#define DSP_To_DRAM_ARM_90A               0x6400090A



#define DSP_To_DRAM_ARM_910               0x64000910
#define DSP_To_DRAM_ARM_912               0x64000912
#define DSP_To_DRAM_ARM_914               0x64000914
#define DSP_To_DRAM_ARM_916               0x64000916
#define DSP_To_DRAM_ARM_918               0x64000918
#define DSP_To_DRAM_ARM_A00               0x64000A00
#define DSP_To_DRAM_ARM_A02               0x64000A02
#define DSP_To_DRAM_ARM_A04               0x64000A04
#define DSP_To_DRAM_ARM_A06               0x64000A06
#define DSP_To_DRAM_ARM_A20               0x64000A20
#define DSP_To_DRAM_ARM_A22               0x64000A22
#define DSP_To_DRAM_ARM_A24               0x64000A24
#define DSP_To_DRAM_ARM_A26               0x64000A26
#define DSP_To_DRAM_ARM_A28               0x64000A28
#define DSP_To_DRAM_ARM_A2A               0x64000A2A
#define DSP_To_DRAM_ARM_A2C               0x64000A2C
#define DSP_To_DRAM_ARM_A2E               0x64000A2E



#define DSP_To_DRAM_ARM_A30               0x64000A30
#define DSP_To_DRAM_ARM_A32               0x64000A32
#define DSP_To_DRAM_ARM_A34               0x64000A34
#define DSP_To_DRAM_ARM_A36               0x64000A36
#define DSP_To_DRAM_ARM_A38               0x64000A38
#define DSP_To_DRAM_ARM_A60               0x64000A60
#define DSP_To_DRAM_ARM_A62               0x64000A62
#define DSP_To_DRAM_ARM_A64               0x64000A64
#define DSP_To_DRAM_ARM_A66               0x64000A66
#define DSP_To_DRAM_ARM_A68               0x64000A68
#define DSP_To_DRAM_ARM_A6A               0x64000A6A
#define DSP_To_DRAM_ARM_A6C               0x64000A6C
#define DSP_To_DRAM_ARM_A6E               0x64000A6E


#define DSP_To_DRAM_ARM_A70               0x64000A70
#define DSP_To_DRAM_ARM_A72               0x64000A72
#define DSP_To_DRAM_ARM_A80               0x64000A80
#define DSP_To_DRAM_ARM_A82               0x64000A82
#define DSP_To_DRAM_ARM_A84               0x64000A84
#define DSP_To_DRAM_ARM_A86               0x64000A86
#define DSP_To_DRAM_ARM_A88               0x64000A88
#define DSP_To_DRAM_ARM_A8A               0x64000A8A
#define DSP_To_DRAM_ARM_AA0               0x64000AA0
#define DSP_To_DRAM_ARM_AC0               0x64000AC0
#define DSP_To_DRAM_ARM_AC2               0x64000AC2
#define DSP_To_DRAM_ARM_AC4               0x64000AC4
#define DSP_To_DRAM_ARM_AC6               0x64000AC6
#define DSP_To_DRAM_ARM_AC8               0x64000AC8
#define DSP_To_DRAM_ARM_ACA               0x64000ACA
#define DSP_To_DRAM_ARM_ACC               0x64000ACC
#define DSP_To_DRAM_ARM_ACE               0x64000ACE


#define DSP_To_DRAM_ARM_AD0               0x64000AD0
#define DSP_To_DRAM_ARM_AD2               0x64000AD2
#define DSP_To_DRAM_ARM_AD4               0x64000AD4
#define DSP_To_DRAM_ARM_AD6               0x64000AD6
#define DSP_To_DRAM_ARM_AD8               0x64000AD8
#define DSP_To_DRAM_ARM_ADA               0x64000ADA
#define DSP_To_DRAM_ARM_ADC               0x64000ADC
#define DSP_To_DRAM_ARM_ADE               0x64000ADE
#define DSP_To_DRAM_ARM_AE0               0x64000AE0
#define DSP_To_DRAM_ARM_AE2               0x64000AE2
#define DSP_To_DRAM_ARM_AE4               0x64000AE4
#define DSP_To_DRAM_ARM_AE6               0x64000AE6
#define DSP_To_DRAM_ARM_AE8               0x64000AE8
#define DSP_To_DRAM_ARM_AEA               0x64000AEA
#define DSP_To_DRAM_ARM_AEC               0x64000AEC
#define DSP_To_DRAM_ARM_AEE               0x64000AEE



#define DSP_To_DRAM_ARM_AF0               0x64000AF0
#define DSP_To_DRAM_ARM_AF2               0x64000AF2
#define DSP_To_DRAM_ARM_AF4               0x64000AF4
#define DSP_To_DRAM_ARM_AF6               0x64000AF6
#define DSP_To_DRAM_ARM_AF8               0x64000AF8
#define DSP_To_DRAM_ARM_AFA               0x64000AFA
#define DSP_To_DRAM_ARM_AFC               0x64000AFC
#define DSP_To_DRAM_ARM_AFE               0x64000AFE
#define DSP_To_DRAM_ARM_B40               0x64000B40
#define DSP_To_DRAM_ARM_B42               0x64000B42
#define DSP_To_DRAM_ARM_B44               0x64000B44
#define DSP_To_DRAM_ARM_B46               0x64000B46
#define DSP_To_DRAM_ARM_B48               0x64000B48
#define DSP_To_DRAM_ARM_B4A               0x64000B4A




#define DSP_To_DRAM_ARM_B60               0x64000B60
#define DSP_To_DRAM_ARM_B62               0x64000B62
#define DSP_To_DRAM_ARM_B64               0x64000B64
#define DSP_To_DRAM_ARM_B66               0x64000B66
#define DSP_To_DRAM_ARM_B68               0x64000B68
#define DSP_To_DRAM_ARM_B6A               0x64000B6A
#define DSP_To_DRAM_ARM_B6C               0x64000B6C
#define DSP_To_DRAM_ARM_B6E               0x64000B6E
#define DSP_To_DRAM_ARM_B70               0x64000B70
#define DSP_To_DRAM_ARM_B72               0x64000B72
#define DSP_To_DRAM_ARM_B74               0x64000B74
#define DSP_To_DRAM_ARM_B76               0x64000B76
#define DSP_To_DRAM_ARM_B78               0x64000B78
#define DSP_To_DRAM_ARM_B7A               0x64000B7A
#define DSP_To_DRAM_ARM_B7C               0x64000B7C
#define DSP_To_DRAM_ARM_B7E               0x64000B7E




#define DSP_To_DRAM_ARM_B80               0x64000B80
#define DSP_To_DRAM_ARM_B82               0x64000B82
#define DSP_To_DRAM_ARM_B84               0x64000B84
#define DSP_To_DRAM_ARM_B86               0x64000B86
#define DSP_To_DRAM_ARM_B88               0x64000B88
#define DSP_To_DRAM_ARM_B8A               0x64000B8A
#define DSP_To_DRAM_ARM_B8C               0x64000B8C
#define DSP_To_DRAM_ARM_B8E               0x64000B8E
#define DSP_To_DRAM_ARM_B90               0x64000B90
#define DSP_To_DRAM_ARM_B92               0x64000B92
#define DSP_To_DRAM_ARM_B94               0x64000B94
#define DSP_To_DRAM_ARM_B96               0x64000B96
#define DSP_To_DRAM_ARM_B98               0x64000B98
#define DSP_To_DRAM_ARM_B9A               0x64000B9A
#define DSP_To_DRAM_ARM_B9C               0x64000B9C
#define DSP_To_DRAM_ARM_B9E               0x64000B9E


#define DRAM_To_DSP_ARM_BFC               0x64000BFC
#define DSP_To_DRAM_ARM_BFE               0x64000BFE



/**ARM TO DSP***/

#define ARM_To_DSP_1280               0x64001280
#define ARM_To_DSP_1282               0x64001282
#define ARM_To_DSP_1288               0x64001288
#define ARM_To_DSP_128A               0x6400128A
#define ARM_To_DSP_128C               0x6400128C
#define ARM_To_DSP_128E               0x6400128E

#define ARM_To_DSP_12E0               0x640012E0
#define ARM_To_DSP_12E2               0x640012E2
#define ARM_To_DSP_12E4               0x640012E4
#define ARM_To_DSP_12E6               0x640012E6
#define ARM_To_DSP_12E8               0x640012E8
#define ARM_To_DSP_12EA               0x640012EA
#define ARM_To_DSP_12EC               0x640012EC
#define ARM_To_DSP_12EE               0x640012EE


#define ARM_To_DSP_12F0               0x640012F0
#define ARM_To_DSP_12F2               0x640012F2
#define ARM_To_DSP_12F4               0x640012F4
#define ARM_To_DSP_12F6               0x640012F6
#define ARM_To_DSP_12F8               0x640012F8
#define ARM_To_DSP_12FA               0x640012FA
#define ARM_To_DSP_12FC               0x640012FC
#define ARM_To_DSP_12FE               0x640012FE


#define ARM_To_DSP_1360               0x64001360
#define ARM_To_DSP_1362               0x64001362
#define ARM_To_DSP_1364               0x64001364
#define ARM_To_DSP_1366               0x64001366
#define ARM_To_DSP_1368               0x64001368
#define ARM_To_DSP_136A               0x6400136A
#define ARM_To_DSP_136C               0x6400136C
#define ARM_To_DSP_136E               0x6400136E


#define ARM_To_DSP_1370               0x64001370
#define ARM_To_DSP_1372               0x64001372
#define ARM_To_DSP_1374               0x64001374
#define ARM_To_DSP_1376               0x64001376
#define ARM_To_DSP_1378               0x64001378
#define ARM_To_DSP_137A               0x6400137A
#define ARM_To_DSP_137C               0x6400137C
#define ARM_To_DSP_137E               0x6400137E


#define ARM_To_DSP_1380               0x64001380
#define ARM_To_DSP_1382               0x64001382
#define ARM_To_DSP_1384               0x64001384
#define ARM_To_DSP_1386               0x64001386
#define ARM_To_DSP_1388               0x64001388
#define ARM_To_DSP_138A               0x6400138A
#define ARM_To_DSP_138C               0x6400138C
#define ARM_To_DSP_138E               0x6400138E


#define ARM_To_DSP_1390               0x64001390
#define ARM_To_DSP_1392               0x64001392
#define ARM_To_DSP_1394               0x64001394
#define ARM_To_DSP_1396               0x64001396
#define ARM_To_DSP_1398               0x64001398
#define ARM_To_DSP_139A               0x6400139A
#define ARM_To_DSP_139C               0x6400139C
#define ARM_To_DSP_139E               0x6400139E


#define ARM_To_DSP_13A0               0x640013A0
#define ARM_To_DSP_13A2               0x640013A2
#define ARM_To_DSP_13A4               0x640013A4
#define ARM_To_DSP_13A6               0x640013A6
#define ARM_To_DSP_13A8               0x640013A8
#define ARM_To_DSP_13AA               0x640013AA
#define ARM_To_DSP_13AC               0x640013AC
#define ARM_To_DSP_13AE               0x640013AE


#define ARM_To_DSP_13B0               0x640013B0
#define ARM_To_DSP_13B2               0x640013B2
#define ARM_To_DSP_13B4               0x640013B4
#define ARM_To_DSP_13B6               0x640013B6
#define ARM_To_DSP_13B8               0x640013B8
#define ARM_To_DSP_13BA               0x640013BA
#define ARM_To_DSP_13BC               0x640013BC
#define ARM_To_DSP_13BE               0x640013BE
/**DSP TO ARM***/

#define DSP_To_ARM_1284               0x64001284
#define DSP_To_ARM_1286               0x64001286
#define DSP_To_ARM_1290               0x64001290
#define DSP_To_ARM_1292               0x64001292


#define DSP_To_ARM_12C0               0x640012C0
#define DSP_To_ARM_12C2               0x640012C2
#define DSP_To_ARM_12C4               0x640012C4
#define DSP_To_ARM_12C6               0x640012C6
#define DSP_To_ARM_12C8               0x640012C8

#define DSP_To_ARM_12CB               0x640012CB
#define DSP_To_ARM_12CA               0x640012CA
#define DSP_To_ARM_12CC               0x640012CC
#define DSP_To_ARM_12CE               0x640012CE


#define DSP_To_ARM_12D0               0x640012D0
#define DSP_To_ARM_12D2               0x640012D2
#define DSP_To_ARM_12D4               0x640012D4
#define DSP_To_ARM_12D6               0x640012D6
#define DSP_To_ARM_12D8               0x640012D8
#define DSP_To_ARM_12DA               0x640012DA
#define DSP_To_ARM_12DC               0x640012DC
#define DSP_To_ARM_12DE               0x640012DE


#define DSP_To_ARM_1300               0x64001300
#define DSP_To_ARM_1302               0x64001302
#define DSP_To_ARM_1304               0x64001304
#define DSP_To_ARM_1306               0x64001306
#define DSP_To_ARM_1308               0x64001308
#define DSP_To_ARM_130A               0x6400130A
#define DSP_To_ARM_130C               0x6400130C
#define DSP_To_ARM_130E               0x6400130E


#define DSP_To_ARM_1310               0x64001310
#define DSP_To_ARM_1312               0x64001312
#define DSP_To_ARM_1314               0x64001314
#define DSP_To_ARM_1316               0x64001316
#define DSP_To_ARM_1318               0x64001318
#define DSP_To_ARM_131A               0x6400131A
#define DSP_To_ARM_131C               0x6400131C
#define DSP_To_ARM_131E               0x6400131E


#define DSP_To_ARM_1320               0x64001320
#define DSP_To_ARM_1322               0x64001322
#define DSP_To_ARM_1324               0x64001324
#define DSP_To_ARM_1326               0x64001326
#define DSP_To_ARM_1328               0x64001328
#define DSP_To_ARM_132A               0x6400132A
#define DSP_To_ARM_132C               0x6400132C
#define DSP_To_ARM_132E               0x6400132E


#define DSP_To_ARM_1330               0x64001330
#define DSP_To_ARM_1332               0x64001332
#define DSP_To_ARM_1334               0x64001334
#define DSP_To_ARM_1336               0x64001336
#define DSP_To_ARM_1338               0x64001338
#define DSP_To_ARM_133A               0x6400133A
#define DSP_To_ARM_133C               0x6400133C
#define DSP_To_ARM_133E               0x6400133E


#define DSP_To_ARM_1340               0x64001340
#define DSP_To_ARM_1342               0x64001342
#define DSP_To_ARM_1344               0x64001344
#define DSP_To_ARM_1346               0x64001346
#define DSP_To_ARM_1348               0x64001348
#define DSP_To_ARM_134A               0x6400134A
#define DSP_To_ARM_134C               0x6400134C
#define DSP_To_ARM_134E               0x6400134E


#define DSP_To_ARM_1350               0x64001350
#define DSP_To_ARM_1352               0x64001352
#define DSP_To_ARM_1354               0x64001354
#define DSP_To_ARM_1356               0x64001356
#define DSP_To_ARM_1358               0x64001358
#define DSP_To_ARM_135A               0x6400135A
#define DSP_To_ARM_135C               0x6400135C
#define DSP_To_ARM_135E               0x6400135E


/**DSP TO FPGA***/

#define DSP_To_FPGA_0000               0x64000000
#define DSP_To_FPGA_0002               0x64000002
#define DSP_To_FPGA_0004               0x64000004
#define DSP_To_FPGA_0006               0x64000006
#define DSP_To_FPGA_000C               0x6400000C
#define DSP_To_FPGA_000E               0x6400000E


#define DSP_To_FPGA_0010               0x64000010
#define DSP_To_FPGA_0012               0x64000012
#define DSP_To_FPGA_0014               0x64000014
#define DSP_To_FPGA_0016               0x64000016
#define DSP_To_FPGA_0018               0x64000018
#define DSP_To_FPGA_001A               0x6400001A


#define DSP_To_FPGA_0020               0x64000020
#define DSP_To_FPGA_0022               0x64000022
#define DSP_To_FPGA_0024               0x64000024
#define DSP_To_FPGA_0026               0x64000026
#define DSP_To_FPGA_0028               0x64000028
#define DSP_To_FPGA_002A               0x6400002A


#define DSP_To_FPGA_0030               0x64000030
#define DSP_To_FPGA_0032               0x64000032
#define DSP_To_FPGA_0034               0x64000034
#define DSP_To_FPGA_0036               0x64000036
#define DSP_To_FPGA_0038               0x64000038
#define DSP_To_FPGA_003A               0x6400003A
#define DSP_To_FPGA_003C               0x6400003C
#define DSP_To_FPGA_003E               0x6400003E


#define DSP_To_FPGA_0040               0x64000040
#define DSP_To_FPGA_0042               0x64000042
#define DSP_To_FPGA_0044               0x64000044
#define DSP_To_FPGA_0046               0x64000046
#define DSP_To_FPGA_0048               0x64000048
#define DSP_To_FPGA_004A               0x6400004A
#define DSP_To_FPGA_004C               0x6400004C
#define DSP_To_FPGA_004E               0x6400004E


#define DSP_To_FPGA_0050               0x64000050
#define DSP_To_FPGA_0052               0x64000052
#define DSP_To_FPGA_0054               0x64000054
#define DSP_To_FPGA_0056               0x64000056
#define DSP_To_FPGA_0058               0x64000058
#define DSP_To_FPGA_005A               0x6400005A
#define DSP_To_FPGA_005C               0x6400005C
#define DSP_To_FPGA_005E               0x6400005E


#define DSP_To_FPGA_0060               0x64000060
#define DSP_To_FPGA_0062               0x64000062


#define DSP_To_FPGA_00B8               0x640000B8
#define DSP_To_FPGA_00BA               0x640000BA


#define DSP_To_FPGA_00C4               0x640000C4
#define DSP_To_FPGA_00C6               0x640000C6


#define DSP_To_FPGA_00E8               0x640000E8
#define DSP_To_FPGA_00EA               0x640000EA

#define DSP_To_FPGA_00F8               0x640000F8
#define DSP_To_FPGA_00FA               0x640000FA



#define DSP_To_FPGA_0140               0x64000140
#define DSP_To_FPGA_0142               0x64000142
#define DSP_To_FPGA_0144               0x64000144
#define DSP_To_FPGA_0146               0x64000146
#define DSP_To_FPGA_0148               0x64000148
#define DSP_To_FPGA_014A               0x6400014A
#define DSP_To_FPGA_014C               0x6400014C
#define DSP_To_FPGA_014E               0x6400014E

#define DSP_To_FPGA_0150               0x64000150
#define DSP_To_FPGA_0152               0x64000152
#define DSP_To_FPGA_0154               0x64000154
#define DSP_To_FPGA_0156               0x64000156
#define DSP_To_FPGA_0158               0x64000158
#define DSP_To_FPGA_015A               0x6400015A
#define DSP_To_FPGA_015C               0x6400015C
#define DSP_To_FPGA_015E               0x6400015E




#define DSP_To_FPGA_0160               0x64000160
#define DSP_To_FPGA_0162               0x64000162
#define DSP_To_FPGA_0164               0x64000164
#define DSP_To_FPGA_0166               0x64000166
#define DSP_To_FPGA_0168               0x64000168
#define DSP_To_FPGA_016A               0x6400016A
#define DSP_To_FPGA_016C               0x6400016C
#define DSP_To_FPGA_016E               0x6400016E



#define DSP_To_FPGA_0170               0x64000170
#define DSP_To_FPGA_0172               0x64000172
#define DSP_To_FPGA_0174               0x64000174
#define DSP_To_FPGA_0176               0x64000176
#define DSP_To_FPGA_0178               0x64000178
#define DSP_To_FPGA_017A               0x6400017A
#define DSP_To_FPGA_017C               0x6400017C
#define DSP_To_FPGA_017E               0x6400017E


#define DSP_To_FPGA_03B8               0x640003B8
#define DSP_To_FPGA_03BA               0x640003BA


#define DSP_To_FPGA_03C0               0x640003C0
#define DSP_To_FPGA_03C2               0x640003C2
#define DSP_To_FPGA_03C4               0x640003C4
#define DSP_To_FPGA_03C6               0x640003C6
#define DSP_To_FPGA_03C8               0x640003C8
#define DSP_To_FPGA_03CA               0x640003CA
#define DSP_To_FPGA_03CC               0x640003CC
#define DSP_To_FPGA_03CE               0x640003CE


#define DSP_To_FPGA_03D0               0x640003D0
#define DSP_To_FPGA_03D2               0x640003D2
#define DSP_To_FPGA_03D4               0x640003D4
#define DSP_To_FPGA_03D6               0x640003D6
#define DSP_To_FPGA_03D8               0x640003D8
#define DSP_To_FPGA_03DA               0x640003DA
#define DSP_To_FPGA_03DC               0x640003DC
#define DSP_To_FPGA_03DE               0x640003DE


#define DSP_To_FPGA_03E0               0x640003E0
#define DSP_To_FPGA_03E2               0x640003E2
#define DSP_To_FPGA_03E4               0x640003E4
#define DSP_To_FPGA_03E6               0x640003E6
#define DSP_To_FPGA_03E8               0x640003E8
#define DSP_To_FPGA_03EA               0x640003EA
#define DSP_To_FPGA_03EC               0x640003EC
#define DSP_To_FPGA_03EE               0x640003EE


#define DSP_To_FPGA_03F0               0x640003F0
#define DSP_To_FPGA_03F2               0x640003F2
#define DSP_To_FPGA_03F4               0x640003F4
#define DSP_To_FPGA_03F6               0x640003F6
#define DSP_To_FPGA_03F8               0x640003F8
#define DSP_To_FPGA_03FA               0x640003FA
#define DSP_To_FPGA_03FC               0x640003FC
#define DSP_To_FPGA_03FE               0x640003FE

#define DSP_To_FPGA_0100               0x64000100
#define DSP_To_FPGA_0102               0x64000102




/**FPGA TO  DSP ***/


#define FPGA_To_DSP_00BC               0x640000BC
#define FPGA_To_DSP_00BE               0x640000BE


#define FPGA_To_DSP_00C0               0x640000C0
#define FPGA_To_DSP_00C2               0x640000C2

#define FPGA_To_DSP_00C8               0x640000C8
#define FPGA_To_DSP_00CA               0x640000CA

#define FPGA_To_DSP_00CC               0x640000CC
#define FPGA_To_DSP_00CE               0x640000CE

#define FPGA_To_DSP_00D0               0x640000D0
#define FPGA_To_DSP_00D2               0x640000D2

#define FPGA_To_DSP_00D4               0x640000D4
#define FPGA_To_DSP_00D6               0x640000D6

#define FPGA_To_DSP_00E0               0x640000E0
#define FPGA_To_DSP_00E2               0x640000E2


#define FPGA_To_DSP_00E4               0x640000E4
#define FPGA_To_DSP_00E6               0x640000E6


#define FPGA_To_DSP_00EC               0x640000E4
#define FPGA_To_DSP_00EE               0x640000E6



#define FPGA_To_DSP_00F0               0x640000F0
#define FPGA_To_DSP_00F2               0x640000F2


#define FPGA_To_DSP_00F4               0x640000F4
#define FPGA_To_DSP_00F6               0x640000F6


#define FPGA_To_DSP_0240               0x64000240
#define FPGA_To_DSP_0242               0x64000242


#define FPGA_To_DSP_0244               0x64000244
#define FPGA_To_DSP_0246               0x64000246

#define FPGA_To_DSP_0248               0x64000248
#define FPGA_To_DSP_024A               0x6400024A


#define FPGA_To_DSP_024C               0x6400024C
#define FPGA_To_DSP_024E               0x6400024E


#define FPGA_To_DSP_0250               0x64000250
#define FPGA_To_DSP_0252               0x64000252


#define FPGA_To_DSP_0254               0x64000254
#define FPGA_To_DSP_0256               0x64000256

#define FPGA_To_DSP_0258               0x64000258
#define FPGA_To_DSP_025A               0x6400025A


#define FPGA_To_DSP_025C               0x6400025C
#define FPGA_To_DSP_025E               0x6400025E


#define FPGA_To_DSP_0260               0x64000260
#define FPGA_To_DSP_0262               0x64000262


#define FPGA_To_DSP_0264               0x64000264
#define FPGA_To_DSP_0266               0x64000266

#define FPGA_To_DSP_0268               0x64000268
#define FPGA_To_DSP_026A               0x6400026A


#define FPGA_To_DSP_026C               0x6400026C
#define FPGA_To_DSP_026E               0x6400026E


#define FPGA_To_DSP_0270               0x64000270
#define FPGA_To_DSP_0272               0x64000272


#define FPGA_To_DSP_0274               0x64000274
#define FPGA_To_DSP_0276               0x64000276

#define FPGA_To_DSP_0278               0x64000278
#define FPGA_To_DSP_027A               0x6400027A


#define FPGA_To_DSP_027C               0x6400027C
#define FPGA_To_DSP_027E               0x6400027E


#define FPGA_To_DSP_0280               0x64000280
#define FPGA_To_DSP_0282               0x64000282


#define FPGA_To_DSP_0284               0x64000284
#define FPGA_To_DSP_0286               0x64000286

#define FPGA_To_DSP_0288               0x64000288
#define FPGA_To_DSP_028A               0x6400028A


#define FPGA_To_DSP_028C               0x6400028C
#define FPGA_To_DSP_028E               0x6400028E


#define FPGA_To_DSP_0290               0x64000290
#define FPGA_To_DSP_0292               0x64000292


#define FPGA_To_DSP_0294               0x64000294
#define FPGA_To_DSP_0296               0x64000296

#define FPGA_To_DSP_0298               0x64000298
#define FPGA_To_DSP_029A               0x6400029A


#define FPGA_To_DSP_029C               0x6400029C
#define FPGA_To_DSP_029E               0x6400029E


#define FPGA_To_DSP_02A0               0x640002A0
#define FPGA_To_DSP_02A2               0x640002A2


#define FPGA_To_DSP_0300               0x64000300
#define FPGA_To_DSP_0302               0x64000302


#define FPGA_To_DSP_0304               0x64000304
#define FPGA_To_DSP_0306               0x64000306

#define FPGA_To_DSP_0308               0x64000308
#define FPGA_To_DSP_030A               0x6400030A


#define FPGA_To_DSP_03BC               0x640003BC
#define FPGA_To_DSP_03BE               0x640003BE






#define DRAM_To_DSP_ARM_C00               0x64000C00
#define DRAM_To_DSP_ARM_C04               0x64000C04
#define DRAM_To_DSP_ARM_C06               0x64000C06
#define DRAM_To_DSP_ARM_C08               0x64000C08
#define DRAM_To_DSP_ARM_C10               0x64000C10
#define DRAM_To_DSP_ARM_C12               0x64000C12
#define DRAM_To_DSP_ARM_C14               0x64000C14
#define DRAM_To_DSP_ARM_C16               0x64000C16
#define DRAM_To_DSP_ARM_C18               0x64000C18
#define DRAM_To_DSP_ARM_C1A               0x64000C1A
#define DRAM_To_DSP_ARM_C20               0x64000C20
#define DRAM_To_DSP_ARM_C22               0x64000C22
#define DRAM_To_DSP_ARM_C24               0x64000C24
#define DRAM_To_DSP_ARM_C26               0x64000C26
#define DRAM_To_DSP_ARM_C28               0x64000C28
#define DRAM_To_DSP_ARM_C2A               0x64000C2A


#define DRAM_To_DSP_ARM_C30               0x64000C30
#define DRAM_To_DSP_ARM_C32               0x64000C32
#define DRAM_To_DSP_ARM_C34               0x64000C34
#define DRAM_To_DSP_ARM_C36               0x64000C36
#define DRAM_To_DSP_ARM_C38               0x64000C38
#define DRAM_To_DSP_ARM_C3A               0x64000C3A
#define DRAM_To_DSP_ARM_C40               0x64000C40
#define DRAM_To_DSP_ARM_C42               0x64000C42
#define DRAM_To_DSP_ARM_C44               0x64000C44
#define DRAM_To_DSP_ARM_C46               0x64000C46
#define DRAM_To_DSP_ARM_C52               0x64000C52
#define DRAM_To_DSP_ARM_C54               0x64000C54
#define DRAM_To_DSP_ARM_C56               0x64000C56
#define DRAM_To_DSP_ARM_C58               0x64000C58
#define DRAM_To_DSP_ARM_C5A               0x64000C5A
#define DRAM_To_DSP_ARM_C5C               0x64000C5C
#define DRAM_To_DSP_ARM_C5E               0x64000C5E



#define DRAM_To_DSP_ARM_C62               0x64000C62
#define DRAM_To_DSP_ARM_C64               0x64000C64
#define DRAM_To_DSP_ARM_C66               0x64000C66
#define DRAM_To_DSP_ARM_C68               0x64000C68
#define DRAM_To_DSP_ARM_C6A               0x64000C6A
#define DRAM_To_DSP_ARM_C6C               0x64000C6C
#define DRAM_To_DSP_ARM_C6E               0x64000C6E
#define DRAM_To_DSP_ARM_C72               0x64000C72
#define DRAM_To_DSP_ARM_C74               0x64000C74
#define DRAM_To_DSP_ARM_C76               0x64000C76
#define DRAM_To_DSP_ARM_C78               0x64000C78
#define DRAM_To_DSP_ARM_C7A               0x64000C7A
#define DRAM_To_DSP_ARM_C7C               0x64000C7C
#define DRAM_To_DSP_ARM_C7E               0x64000C7E
#define DRAM_To_DSP_ARM_C82               0x64000C82
#define DRAM_To_DSP_ARM_C84               0x64000C84
#define DRAM_To_DSP_ARM_C86               0x64000C86
#define DRAM_To_DSP_ARM_C88               0x64000C88
#define DRAM_To_DSP_ARM_C8A               0x64000C8A
#define DRAM_To_DSP_ARM_C8C               0x64000C8C
#define DRAM_To_DSP_ARM_C8E               0x64000C8E





#define DRAM_To_DSP_ARM_C92               0x64000C92
#define DRAM_To_DSP_ARM_C94               0x64000C94
#define DRAM_To_DSP_ARM_C96               0x64000C96
#define DRAM_To_DSP_ARM_C98               0x64000C98
#define DRAM_To_DSP_ARM_C9A               0x64000C9A
#define DRAM_To_DSP_ARM_C9C               0x64000C9C
#define DRAM_To_DSP_ARM_C9E               0x64000C9E
#define DRAM_To_DSP_ARM_CA0               0x64000CA0
#define DRAM_To_DSP_ARM_CA2               0x64000CA2
#define DRAM_To_DSP_ARM_CA4               0x64000CA4
#define DRAM_To_DSP_ARM_CA6               0x64000CA6
#define DRAM_To_DSP_ARM_CA8               0x64000CA8
#define DRAM_To_DSP_ARM_CAA               0x64000CAA
#define DRAM_To_DSP_ARM_CAC               0x64000CAC
#define DRAM_To_DSP_ARM_CB0               0x64000CB0
#define DRAM_To_DSP_ARM_CB2               0x64000CB2
#define DRAM_To_DSP_ARM_CB4               0x64000CB4
#define DRAM_To_DSP_ARM_CB6               0x64000CB6
#define DRAM_To_DSP_ARM_CB8               0x64000CB8
#define DRAM_To_DSP_ARM_CBA               0x64000CBA
#define DRAM_To_DSP_ARM_CBC               0x64000CBC



#define DRAM_To_DSP_ARM_CC0               0x64000CC0
#define DRAM_To_DSP_ARM_CC2               0x64000CC2
#define DRAM_To_DSP_ARM_CC4               0x64000CC4
#define DRAM_To_DSP_ARM_CC6               0x64000CC6
#define DRAM_To_DSP_ARM_CC8               0x64000CC8
#define DRAM_To_DSP_ARM_CCA               0x64000CCA
#define DRAM_To_DSP_ARM_CCC               0x64000CCC
#define DRAM_To_DSP_ARM_CD0               0x64000CD0
#define DRAM_To_DSP_ARM_CD2               0x64000CD2
#define DRAM_To_DSP_ARM_CD4               0x64000CD4
#define DRAM_To_DSP_ARM_CD6               0x64000CD6
#define DRAM_To_DSP_ARM_CD8               0x64000CD8
#define DRAM_To_DSP_ARM_CDA               0x64000CDA
#define DRAM_To_DSP_ARM_CDC               0x64000CDC
#define DRAM_To_DSP_ARM_CE0               0x64000CE0
#define DRAM_To_DSP_ARM_CE2               0x64000CE2
#define DRAM_To_DSP_ARM_CE4               0x64000CE4
#define DRAM_To_DSP_ARM_CE6               0x64000CE6
#define DRAM_To_DSP_ARM_CE8               0x64000CE8
#define DRAM_To_DSP_ARM_CEA               0x64000CEA
#define DRAM_To_DSP_ARM_CEC               0x64000CEC



#define DRAM_To_DSP_ARM_CF0               0x64000CF0
#define DRAM_To_DSP_ARM_CF2               0x64000CF2
#define DRAM_To_DSP_ARM_CF4               0x64000CF4
#define DRAM_To_DSP_ARM_CF6               0x64000CF6
#define DRAM_To_DSP_ARM_CF8               0x64000CF8
#define DRAM_To_DSP_ARM_CFA               0x64000CFA
#define DRAM_To_DSP_ARM_D00               0x64000D00
#define DRAM_To_DSP_ARM_D02               0x64000D02
#define DRAM_To_DSP_ARM_D04               0x64000D04
#define DRAM_To_DSP_ARM_D06               0x64000D06
#define DRAM_To_DSP_ARM_D08               0x64000D08
#define DRAM_To_DSP_ARM_D0A               0x64000D0A
#define DRAM_To_DSP_ARM_D10               0x64000D10
#define DRAM_To_DSP_ARM_D12               0x64000D12
#define DRAM_To_DSP_ARM_D14               0x64000D14
#define DRAM_To_DSP_ARM_D16               0x64000D16
#define DRAM_To_DSP_ARM_D18               0x64000D18
#define DRAM_To_DSP_ARM_D1A               0x64000D1A
#define DRAM_To_DSP_ARM_D20               0x64000D20
#define DRAM_To_DSP_ARM_D22               0x64000D22
#define DRAM_To_DSP_ARM_D24               0x64000D24
#define DRAM_To_DSP_ARM_D26               0x64000D26
#define DRAM_To_DSP_ARM_D28               0x64000D28
#define DRAM_To_DSP_ARM_D2A               0x64000D2A


#define DRAM_To_DSP_ARM_D30               0x64000D30
#define DRAM_To_DSP_ARM_D32               0x64000D32
#define DRAM_To_DSP_ARM_D34               0x64000D34
#define DRAM_To_DSP_ARM_D36               0x64000D36
#define DRAM_To_DSP_ARM_D38               0x64000D38
#define DRAM_To_DSP_ARM_D3A               0x64000D3A
#define DRAM_To_DSP_ARM_D40               0x64000D40
#define DRAM_To_DSP_ARM_D42               0x64000D42
#define DRAM_To_DSP_ARM_D44               0x64000D44
#define DRAM_To_DSP_ARM_D46               0x64000D46
#define DRAM_To_DSP_ARM_D48               0x64000D48
#define DRAM_To_DSP_ARM_D4A               0x64000D4A
#define DRAM_To_DSP_ARM_E60               0x64000E60
#define DRAM_To_DSP_ARM_E62               0x64000E62
#define DRAM_To_DSP_ARM_E64               0x64000E64
#define DRAM_To_DSP_ARM_E66               0x64000E66
#define DRAM_To_DSP_ARM_E68               0x64000E68
#define DRAM_To_DSP_ARM_E6A               0x64000E6A
#define DRAM_To_DSP_ARM_E6C               0x64000E6C
#define DRAM_To_DSP_ARM_E6E               0x64000E6E


#define DRAM_To_DSP_ARM_E70               0x64000E70
#define DRAM_To_DSP_ARM_E72               0x64000E72
#define DRAM_To_DSP_ARM_E74               0x64000E74
#define DRAM_To_DSP_ARM_E76               0x64000E76
#define DRAM_To_DSP_ARM_E78               0x64000E78
#define DRAM_To_DSP_ARM_E7A               0x64000E7A
#define DRAM_To_DSP_ARM_E7C               0x64000E7C
#define DRAM_To_DSP_ARM_E7E               0x64000E7E
#define DRAM_To_DSP_ARM_EA0               0x64000EA0
#define DRAM_To_DSP_ARM_EA2               0x64000EA2
#define DRAM_To_DSP_ARM_EA4               0x64000EA4
#define DRAM_To_DSP_ARM_EA6               0x64000EA6
#define DRAM_To_DSP_ARM_EA8               0x64000EA8
#define DRAM_To_DSP_ARM_EAA               0x64000EAA
#define DRAM_To_DSP_ARM_EAC               0x64000EAC
#define DRAM_To_DSP_ARM_EAE               0x64000EAE


#define DRAM_To_DSP_ARM_EB0               0x64000EB0
#define DRAM_To_DSP_ARM_EB2               0x64000EB2
#define DRAM_To_DSP_ARM_EB4               0x64000EB4
#define DRAM_To_DSP_ARM_EE0               0x64000EE0
#define DRAM_To_DSP_ARM_EE2               0x64000EE2
#define DRAM_To_DSP_ARM_EE4               0x64000EE4
#define DRAM_To_DSP_ARM_EE6               0x64000EE6
#define DRAM_To_DSP_ARM_EE8               0x64000EE8
#define DRAM_To_DSP_ARM_EEA               0x64000EEA
#define DRAM_To_DSP_ARM_EEC               0x64000EEC
#define DRAM_To_DSP_ARM_EEE               0x64000EEE
#define DRAM_To_DSP_ARM_EF0               0x64000EF0
#define DRAM_To_DSP_ARM_EF2               0x64000EF2
#define DRAM_To_DSP_ARM_EF4               0x64000EF4
#define DRAM_To_DSP_ARM_EF6               0x64000EF6
#define DRAM_To_DSP_ARM_EF8               0x64000EF8
#define DRAM_To_DSP_ARM_EFA               0x64000EFA
#define DRAM_To_DSP_ARM_EFC               0x64000EFC
#define DRAM_To_DSP_ARM_EFE               0x64000EFE


#define DRAM_To_DSP_ARM_F00               0x64000F00
#define DRAM_To_DSP_ARM_F02               0x64000F02
#define DRAM_To_DSP_ARM_F04               0x64000F04
#define DRAM_To_DSP_ARM_F06               0x64000F06
#define DRAM_To_DSP_ARM_F08               0x64000F08
#define DRAM_To_DSP_ARM_F0A               0x64000F0A
#define DRAM_To_DSP_ARM_F0C               0x64000F0C
#define DRAM_To_DSP_ARM_F0E               0x64000F0E
#define DRAM_To_DSP_ARM_F10               0x64000F10
#define DRAM_To_DSP_ARM_F12               0x64000F12
#define DRAM_To_DSP_ARM_F14               0x64000F14
#define DRAM_To_DSP_ARM_F16               0x64000F16
#define DRAM_To_DSP_ARM_F18               0x64000F18
#define DRAM_To_DSP_ARM_F1A               0x64000F1A
#define DRAM_To_DSP_ARM_F1C               0x64000F1C
#define DRAM_To_DSP_ARM_F1E               0x64000F1E



#define DRAM_To_DSP_ARM_F40               0x64000F40
#define DRAM_To_DSP_ARM_F42               0x64000F42
#define DRAM_To_DSP_ARM_F60               0x64000F60
#define DRAM_To_DSP_ARM_F62               0x64000F62
#define DRAM_To_DSP_ARM_F64               0x64000F64
#define DRAM_To_DSP_ARM_F66               0x64000F66
#define DRAM_To_DSP_ARM_F68               0x64000F68
#define DRAM_To_DSP_ARM_F6A               0x64000F6A
#define DRAM_To_DSP_ARM_F6C               0x64000F6C
#define DRAM_To_DSP_ARM_F6E               0x64000F6E
#define DRAM_To_DSP_ARM_F70               0x64000F70
#define DRAM_To_DSP_ARM_F72               0x64000F72
#define DRAM_To_DSP_ARM_F74               0x64000F74
#define DRAM_To_DSP_ARM_F76               0x64000F76
#define DRAM_To_DSP_ARM_F78               0x64000F78
#define DRAM_To_DSP_ARM_F7A               0x64000F7A
#define DRAM_To_DSP_ARM_F7C               0x64000F7C
#define DRAM_To_DSP_ARM_F7E               0x64000F7E
#define DRAM_To_DSP_ARM_F80               0x64000F80
#define DRAM_To_DSP_ARM_F82               0x64000F82
#define DRAM_To_DSP_ARM_F84               0x64000F84
#define DRAM_To_DSP_ARM_F86               0x64000F86
#define DRAM_To_DSP_ARM_F88               0x64000F88
#define DRAM_To_DSP_ARM_F8A               0x64000F8A
#define DRAM_To_DSP_ARM_F8C               0x64000F8C
#define DRAM_To_DSP_ARM_F8E               0x64000F8E



#define DRAM_To_DSP_ARM_F90               0x64000F90
#define DRAM_To_DSP_ARM_F92               0x64000F92
#define DRAM_To_DSP_ARM_F94               0x64000F94
#define DRAM_To_DSP_ARM_F96               0x64000F96
#define DRAM_To_DSP_ARM_F98               0x64000F98
#define DRAM_To_DSP_ARM_F9A               0x64000F9A
#define DRAM_To_DSP_ARM_F9C               0x64000F9C
#define DRAM_To_DSP_ARM_F9E               0x64000F9E



#define DSP_To_DRAM_ARM_FFC               0x64000FFC
#define DRAM_To_DSP_ARM_FFE               0x64000FFE





/******************************************************************************
**                        zxs add end
*******************************************************************************/
#endif













/******************************************************************************
**                        Macro Definitions
*******************************************************************************/

/* DSP get  */
#define DRAM_To_DSP_IOData_00             0x64000000
#define DRAM_To_DSP_IOData_06             0x64000006
#define DRAM_To_DSP_IOData_0A             0x6400000A
#define DRAM_To_DSP_IOData_20             0x64000020
#define DRAM_To_DSP_IOData_22             0x64000022
#define DRAM_To_DSP_IOData_24             0x64000024
#define DRAM_To_DSP_IOData_26             0x64000026
#define DRAM_To_DSP_IOData_28             0x64000028
#define DRAM_To_DSP_IOData_2A             0x6400002A
#define DRAM_To_DSP_IOData_2C             0x6400002C
#define DRAM_To_DSP_IOData_2E             0x6400002E
#define DRAM_To_DSP_IOData_30             0x64000030
#define DRAM_To_DSP_IOData_32             0x64000032
#define DRAM_To_DSP_IOData_34             0x64000034
#define DRAM_To_DSP_IOData_36             0x64000036
#define DRAM_To_DSP_IOData_38             0x64000038


#define DSP_To_DRAM_IOData_60             0x64000060
#define DSP_To_DRAM_IOData_62             0x64000062
#define DSP_To_DRAM_IOData_80             0x64000080
#define DSP_To_DRAM_IOData_82             0x64000082
#define DSP_To_DRAM_IOData_84             0x64000084
#define DSP_To_DRAM_IOData_86             0x64000086
#define DSP_To_DRAM_IOData_88             0x64000088
#define DSP_To_DRAM_IOData_8A             0x6400008A
#define DSP_To_DRAM_IOData_8C             0x6400008C
#define DSP_To_DRAM_IOData_8E             0x6400008E
#define DSP_To_DRAM_IOData_90             0x64000090
#define DSP_To_DRAM_IOData_92             0x64000092
#define DSP_To_DRAM_IOData_94             0x64000094
#define DSP_To_DRAM_IOData_A0             0x640000A0
#define DSP_To_DRAM_IOData_A2             0x640000A2
#define DSP_To_DRAM_IOData_A4             0x640000A4
#define DSP_To_DRAM_IOData_A6             0x640000A6
#define DSP_To_DRAM_IOData_A8             0x640000A8
#define DSP_To_DRAM_IOData_AA             0x640000AA
#define DSP_To_DRAM_IOData_AC             0x640000AC
#define DSP_To_DRAM_IOData_AE             0x640000AE
#define DSP_To_DRAM_IOData_B0             0x640000B0
#define DSP_To_DRAM_IOData_B2             0x640000B2
#define DSP_To_DRAM_IOData_C0             0x640000C0
#define DSP_To_DRAM_IOData_C2             0x640000C2
#define DSP_To_DRAM_IOData_C4             0x640000C4
#define DSP_To_DRAM_IOData_C6             0x640000C6
#define DSP_To_DRAM_IOData_C8             0x640000C8
#define DSP_To_DRAM_IOData_CA             0x640000CA
#define DSP_To_DRAM_IOData_CC             0x640000CC
#define DSP_To_DRAM_IOData_CE             0x640000CE
#define DSP_To_DRAM_IOData_D0             0x640000D0
#define DSP_To_DRAM_IOData_D2             0x640000D2
#define DSP_To_DRAM_IOData_D4             0x640000D4
#define DSP_To_DRAM_IOData_D6             0x640000D6
#define DSP_To_DRAM_IOData_D8             0x640000D8
#define DSP_To_DRAM_IOData_E0             0x640000E0
#define DSP_To_DRAM_IOData_E2             0x640000E2
#define DSP_To_DRAM_IOData_E4             0x640000E4
#define DSP_To_DRAM_IOData_E6             0x640000E6
#define DSP_To_DRAM_IOData_E8             0x640000E8
#define DSP_To_DRAM_IOData_EA             0x640000EA
#define DSP_To_DRAM_IOData_EC             0x640000EC
#define DSP_To_DRAM_IOData_EE             0x640000EE
#define DSP_To_DRAM_IOData_F0             0x640000F0
#define DSP_To_DRAM_IOData_F2             0x640000F2
#define DSP_To_DRAM_IOData_F4             0x640000F4
#define DSP_To_DRAM_IOData_F6             0x640000F6
#define DSP_To_DRAM_IOData_F8             0x640000F8
#define DSP_To_DRAM_IOData_FA             0x640000FA
#define DSP_To_DRAM_IOData_FC             0x640000FC
#define DSP_To_DRAM_IOData_FE             0x640000FE
#define DSP_To_DRAM_IOData_100            0x64000100
#define DSP_To_DRAM_IOData_102            0x64000102
#define DSP_To_DRAM_IOData_104            0x64000104
#define DSP_To_DRAM_IOData_106            0x64000106
#define DSP_To_DRAM_IOData_108            0x64000108
#define DSP_To_DRAM_IOData_10A            0x6400010A
#define DSP_To_DRAM_IOData_10C            0x6400010C
#define DSP_To_DRAM_IOData_10E            0x6400010E
#define DSP_To_DRAM_IOData_110            0x64000110
#define DSP_To_DRAM_IOData_112            0x64000112
#define DSP_To_DRAM_IOData_114            0x64000114
#define DSP_To_DRAM_IOData_120            0x64000120
#define DSP_To_DRAM_IOData_122            0x64000122
#define DSP_To_DRAM_IOData_124            0x64000124
#define DSP_To_DRAM_IOData_126            0x64000126
#define DSP_To_DRAM_IOData_128            0x64000128
#define DSP_To_DRAM_IOData_12A            0x6400012A
#define DSP_To_DRAM_IOData_12C            0x6400012C
#define DSP_To_DRAM_IOData_12E            0x6400012E
#define DSP_To_DRAM_IOData_13C            0x6400013C
#define DSP_To_DRAM_IOData_13E            0x6400013E
#define DSP_To_DRAM_IOData_200            0x64000200
#define DSP_To_DRAM_IOData_202            0x64000202
#define DSP_To_DRAM_IOData_204            0x64000204
#define DSP_To_DRAM_IOData_206            0x64000206
#define DSP_To_DRAM_IOData_208            0x64000208
#define DSP_To_DRAM_IOData_20A            0x6400020A
#define DSP_To_DRAM_IOData_20C            0x6400020C
#define DSP_To_DRAM_IOData_20E            0x6400020E
#define DSP_To_DRAM_IOData_21C            0x6400021C
#define DSP_To_DRAM_IOData_21E            0x6400021E
#define DSP_To_DRAM_PTIN1_220             0x64000220
#define DSP_To_DRAM_PTIN1_222             0x64000222
#define DSP_To_DRAM_PTIN1_224             0x64000224
#define DSP_To_DRAM_PTIN1_226             0x64000226
#define DSP_To_DRAM_PTIN1_228             0x64000228
#define DSP_To_DRAM_PTIN1_22A             0x6400022A
#define DSP_To_DRAM_PTIN1_22C             0x6400022C
#define DSP_To_DRAM_PTIN1_22E             0x6400022E
#define DSP_To_DRAM_PTIN1_230             0x64000230
#define DSP_To_DRAM_PTIN1_232             0x64000232
#define DSP_To_DRAM_PTIN1_234             0x64000234
#define DSP_To_DRAM_PTIN1_236             0x64000236
#define DSP_To_DRAM_PTIN1_238             0x64000238
#define DSP_To_DRAM_PTIN1_23A             0x6400023A
#define DSP_To_DRAM_PTIN1_23C             0x6400023C
#define DSP_To_DRAM_PTIN1_23E             0x6400023E


#define DSP_To_DRAM_LPData_400            0x64000400
#define DSP_To_DRAM_LPData_40C            0x6400040C
#define DSP_To_DRAM_LPData_40E            0x6400040E
#define DSP_To_DRAM_LPData_400            0x64000400
#define DSP_To_DRAM_LPData_410            0x64000410
#define DSP_To_DRAM_LPData_412            0x64000412
#define DSP_To_DRAM_LPData_414            0x64000414
#define DSP_To_DRAM_LPData_416            0x64000416
#define DSP_To_DRAM_LPData_418            0x64000418
#define DSP_To_DRAM_LPData_41A            0x6400041A
#define DSP_To_DRAM_LPData_41C            0x6400041C
#define DSP_To_DRAM_LPData_41E            0x6400041E
#define DSP_To_DRAM_LPData_420            0x64000420
#define DSP_To_DRAM_LPData_422            0x64000422
#define DSP_To_DRAM_LPData_424            0x64000424
#define DSP_To_DRAM_LPData_426            0x64000426
#define DSP_To_DRAM_LPData_428            0x64000428
#define DSP_To_DRAM_LPData_42E            0x6400042E
#define DSP_To_DRAM_LPData_430            0x64000430
#define DSP_To_DRAM_LPData_432            0x64000432
#define DSP_To_DRAM_LPData_434            0x64000434
#define DSP_To_DRAM_LPData_436            0x64000436
#define DSP_To_DRAM_LPData_438            0x64000438
#define DSP_To_DRAM_LPData_43E            0x6400043E

#define DSP_To_DRAM_LPData_460            0x64000460
#define DSP_To_DRAM_LPData_462            0x64000462
#define DSP_To_DRAM_LPData_464            0x64000464
#define DSP_To_DRAM_LPData_466            0x64000466
#define DSP_To_DRAM_LPData_468            0x64000468
#define DSP_To_DRAM_LPData_46A            0x6400046A
#define DSP_To_DRAM_LPData_46C            0x6400046C
#define DSP_To_DRAM_LPData_46E            0x6400046E
#define DSP_To_DRAM_LPData_470            0x64000470
#define DSP_To_DRAM_LPData_472            0x64000472
#define DSP_To_DRAM_LPData_474            0x64000474
#define DSP_To_DRAM_LPData_476            0x64000476
#define DSP_To_DRAM_LPData_478            0x64000478
#define DSP_To_DRAM_LPData_47A            0x6400047A
#define DSP_To_DRAM_LPData_47C            0x6400047C
#define DSP_To_DRAM_LPData_47E            0x6400047E
#define DSP_To_DRAM_LPData_480            0x64000480
#define DSP_To_DRAM_LPData_482            0x64000482
#define DSP_To_DRAM_LPData_484            0x64000484
#define DSP_To_DRAM_LPData_486            0x64000486
#define DSP_To_DRAM_LPData_488            0x64000488
#define DSP_To_DRAM_LPData_48A            0x6400048A
#define DSP_To_DRAM_LPData_48C            0x6400048C
#define DSP_To_DRAM_LPData_48E            0x6400048E
#define DSP_To_DRAM_LPData_490            0x64000490
#define DSP_To_DRAM_LPData_492            0x64000492
#define DSP_To_DRAM_LPData_494            0x64000494
#define DSP_To_DRAM_LPData_496            0x64000496
#define DSP_To_DRAM_LPData_498            0x64000498
#define DSP_To_DRAM_LPData_49A            0x6400049A
#define DSP_To_DRAM_LPData_49C            0x6400049C
#define DSP_To_DRAM_LPData_49E            0x6400049E
#define DSP_To_DRAM_LPData_4A0            0x640004A0
#define DSP_To_DRAM_LPData_4A2            0x640004A2
#define DSP_To_DRAM_LPData_4A4            0x640004A4


//////////////////new add by zff////////////////////
#define DSP_To_DRAM_LPData_600            0x64000600
#define DSP_To_DRAM_LPData_602            0x64000602
#define DSP_To_DRAM_LPData_604            0x64000604
#define DSP_To_DRAM_LPData_606            0x64000606
#define DSP_To_DRAM_LPData_608            0x64000608
#define DSP_To_DRAM_LPData_60A            0x6400060A
#define DSP_To_DRAM_LPData_60C            0x6400060C
#define DSP_To_DRAM_LPData_60E            0x6400060E
#define DSP_To_DRAM_LPData_610            0x64000610
#define DSP_To_DRAM_LPData_612            0x64000612
#define DSP_To_DRAM_LPData_614            0x64000614
#define DSP_To_DRAM_LPData_616            0x64000616
#define DSP_To_DRAM_LPData_618            0x64000618
#define DSP_To_DRAM_LPData_61A            0x6400061A
#define DSP_To_DRAM_LPData_61C            0x6400061C
#define DSP_To_DRAM_LPData_61E            0x6400061E
#define DSP_To_DRAM_LPData_620            0x64000620


#define DRAM_To_DSP_LPData_4C0            0x640004C0
#define DRAM_To_DSP_LPData_4C2            0x640004C2
#define DRAM_To_DSP_LPData_4C4            0x640004C4
#define DRAM_To_DSP_LPData_4C6            0x640004C6
#define DRAM_To_DSP_LPData_4Ca            0x640004Ca
#define DRAM_To_DSP_LPData_4CC            0x640004CC
#define DRAM_To_DSP_LPData_4CA            0x640004CA
#define DRAM_To_DSP_LPData_4CE            0x640004CE

#define DRAM_To_DSP_LPData_4D0            0x640004D0
#define DRAM_To_DSP_LPData_4D2            0x640004D2
#define DRAM_To_DSP_LPData_4D4            0x640004D4
#define DRAM_To_DSP_LPData_4D6            0x640004D6
#define DRAM_To_DSP_LPData_4D8            0x640004D8
#define DRAM_To_DSP_LPData_4DA            0x640004DA
#define DRAM_To_DSP_LPData_4DC            0x640004DC
#define DRAM_To_DSP_LPData_4DE            0x640004DE
#define DRAM_To_DSP_LPData_4E0            0x640004E0
#define DRAM_To_DSP_LPData_4E2            0x640004E2
#define DRAM_To_DSP_LPData_4E4            0x640004E4
#define DRAM_To_DSP_LPData_4E6            0x640004E6
#define DRAM_To_DSP_LPData_4E8            0x640004E8
#define DRAM_To_DSP_LPData_4EA            0x640004EA
#define DRAM_To_DSP_LPData_4EC            0x640004EC
#define DRAM_To_DSP_LPData_4EE            0x640004EE
#define DRAM_To_DSP_LPData_4F0            0x640004F0
#define DRAM_To_DSP_LPData_4F2            0x640004F2
#define DRAM_To_DSP_LPData_4F4            0x640004F4
#define DRAM_To_DSP_LPData_4F6            0x640004F6
#define DRAM_To_DSP_LPData_500            0x64000500
#define DRAM_To_DSP_LPData_502            0x64000502
#define DRAM_To_DSP_LPData_504            0x64000504
#define DRAM_To_DSP_LPData_506            0x64000506
#define DRAM_To_DSP_LPData_508            0x64000508
#define DRAM_To_DSP_LPData_50A            0x6400050A
#define DRAM_To_DSP_LPData_50C            0x6400050C
#define DRAM_To_DSP_LPData_510            0x64000510
#define DRAM_To_DSP_LPData_512            0x64000512
#define DRAM_To_DSP_LPData_514            0x64000514
#define DRAM_To_DSP_LPData_516            0x64000516
#define DRAM_To_DSP_LPData_518            0x64000518
#define DRAM_To_DSP_LPData_51A            0x6400051A
#define DRAM_To_DSP_LPData_51C            0x6400051C
#define DRAM_To_DSP_LPData_51E            0x6400051E
#define DRAM_To_DSP_LPData_520            0x64000520
#define DRAM_To_DSP_LPData_522            0x64000522
#define DRAM_To_DSP_LPData_524            0x64000524
#define DRAM_To_DSP_LPData_526            0x64000526
#define DRAM_To_DSP_LPData_528            0x64000528
#define DRAM_To_DSP_LPData_52A            0x6400052A
#define DRAM_To_DSP_LPData_52C            0x6400052C
#define DRAM_To_DSP_LPData_52E            0x6400052E
#define DRAM_To_DSP_LPData_530            0x64000530
#define DRAM_To_DSP_LPData_532            0x64000532
#define DRAM_To_DSP_LPData_534            0x64000534
#define DRAM_To_DSP_LPData_536            0x64000536
#define DRAM_To_DSP_LPData_538            0x64000538
#define DRAM_To_DSP_LPData_53A            0x6400053A
#define DRAM_To_DSP_LPData_53C            0x6400053C
#define DRAM_To_DSP_LPData_53E            0x6400053E
#define DRAM_To_DSP_LPData_540            0x64000540
#define DRAM_To_DSP_LPData_542            0x64000542
#define DRAM_To_DSP_LPData_544            0x64000544
#define DRAM_To_DSP_LPData_558            0x64000558
#define DRAM_To_DSP_LPData_55A            0x6400055A
#define DRAM_To_DSP_LPData_55C            0x6400055C
#define DRAM_To_DSP_LPData_55E            0x6400055E
#define DRAM_To_DSP_LPData_560            0x64000560
#define DRAM_To_DSP_LPData_562            0x64000562
#define DRAM_To_DSP_LPData_564            0x64000564
#define DRAM_To_DSP_LPData_566            0x64000566
#define DRAM_To_DSP_LPData_568            0x64000568
#define DRAM_To_DSP_LPData_56A            0x6400056A
#define DRAM_To_DSP_LPData_56C            0x6400056C
#define DRAM_To_DSP_LPData_56E            0x6400056E
#define DRAM_To_DSP_LPData_570            0x64000570
#define DRAM_To_DSP_LPData_572            0x64000572
#define DRAM_To_DSP_LPData_574            0x64000574
#define DRAM_To_DSP_LPData_576            0x64000576
#define DRAM_To_DSP_LPData_578            0x64000578
#define DRAM_To_DSP_LPData_57A            0x6400057A
#define DRAM_To_DSP_LPData_57C            0x6400057C

#define DRAM_To_DSP_LPData_580            0x64000580
#define DRAM_To_DSP_LPData_582            0x64000582
#define DRAM_To_DSP_LPData_584            0x64000584
#define DRAM_To_DSP_LPData_586            0x64000586
#define DRAM_To_DSP_LPData_588            0x64000588
#define DRAM_To_DSP_LPData_58A            0x6400058A
#define DRAM_To_DSP_LPData_58C            0x6400058C
#define DRAM_To_DSP_LPData_58E            0x6400058E
#define DRAM_To_DSP_LPData_5A0            0x640005A0
#define DRAM_To_DSP_LPData_5A2            0x640005A2
#define DRAM_To_DSP_LPData_5A4            0x640005A4
#define DRAM_To_DSP_LPData_5A6            0x640005A6
#define DRAM_To_DSP_LPData_5A8            0x640005A8
#define DRAM_To_DSP_LPData_5AA            0x640005AA
#define DRAM_To_DSP_LPData_5AC            0x640005AC
#define DRAM_To_DSP_LPData_5AE            0x640005AE
#define DRAM_To_DSP_LPData_5B0            0x640005B0

#define DRAM_To_DSP_LPData_590            0x64000590
#define DRAM_To_DSP_LPData_592            0x64000592

#define DSP_To_DRAM_LPData_4A6            0x640004A6
#define DSP_To_DRAM_LPData_4A8            0x640004A8



/******************************************************************************
**                    External Function Declararions
*******************************************************************************/
extern void DSP_Get_DRAM_FPGAData(void);
extern void DSP_Send_DRAM_FPGAData(void);

extern void DSP_Get_DRAM_ARMData(void);
extern void DSP_Send_DRAM_ARMData(void);

extern void DSPFirstSendLPDataPriod(void);

extern void update_map_data(void);

extern void DSP_Send_DRAM_DSPData(void);
extern void DSP_Get_DRAM_DSPData(void);
extern void WatchDog(void);





#ifdef __cplusplus
}
#endif

#endif


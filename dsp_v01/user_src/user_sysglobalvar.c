/*********************************************************************
Copyright (c),2002-2017,Sifang Rolling Stock Research Institute Ltd.
*File Name:    SysGlobalVar.c
*Author:       JasonLee
*Date:         2017.09.18
*Version:      0.1
*Description:  system global variable definition
*Modification history:
    1.Jason, 2017.9.18, first issue;
**********************************************************************/
#include "user_sysglobalvar.h"


/************************************************************************
                    Global Variable Definitions
************************************************************************/
double Icurr_pu_u_meas = 0;
double Icurr_pu_v_meas = 0;
double Icurr_pu_w_meas = 0;
double Icurr_u_meas = 0;
double Icurr_u_rms = 0;
double Icurr_u_rms_fil =0;
double Icurr_pu_u_fil =0;
double Icurr_pu_v_fil =0;
double Icurr_pu_w_fil =0;
double Icurr_u_fil =0;
double Icurr_bus_meas = 0;
double Icurr_bus_fil = 0;
double Uun_meas =0;
double Uvn_meas =0;
double Uwn_meas =0;
double Uun_fil =0;
double Uvn_fil =0;
double Uwn_fil =0;
double Uuvw_fil =0;
double Uoutpeak =0;
double Uuvw0 =0;
double Uuvw1 =0;
double Uuvw2 =0;
double Uun_Rms_meas =0;
double Uun_Rms_fil =0;
double Uwn_Rms_meas =0;
double Uwn_Rms_fil =0;
double Uout_deve_inter =0;

double square_rms = 0;
double Uvw_fltr = 0;
double Uvw_sign = 0;
double Uvw_bias = 0;
double NetVoltage_meas =0;
double NetVoltage_fil =0;
double FCVoltage_meas =0;
double FCVoltage_fil =0;
double BuckOutVol_meas =0;
double BuckOutVol_fil =0;
double CHPin_fil = 0;
double DCDCOutVol_meas =0;
double DCDCOutVol_fil =0;

double SUMP =0;
double SUMQ =0;
double SUMPBack =0;
double SUMQBack =0;

unsigned char SoftStop =0;
unsigned char SoftStart =0;
unsigned char SysCnt =0;

unsigned char BuckStartFlag =0;
unsigned char DCDCStartFlag =0;
unsigned char InvStartFlag =0;
unsigned char KM3ClsCmd =0;

unsigned char OverVolFlag=0;
unsigned char LessVolFlag=0;
unsigned char LessVolFlagBk=0;
unsigned char StepFlag = 0;
unsigned char LessVolCnt = 0;
unsigned char IntegralCnt = 0;
unsigned int  LessCnt=0;

unsigned char BuckOverVolFlag=0;
unsigned char BuckLessVolFlag=0;
unsigned char BuckLessVolFlagBk=0;
unsigned char BuckStepFlag = 0;
unsigned char BuckLessVolCnt = 0;
unsigned char BuckIntegralCnt = 0;
unsigned int  BuckLessCnt=0;
unsigned int  BuckPIDFlag = 0;
unsigned char DQStart =0;
unsigned char SysStart =0;
unsigned int  	DQcnt = 0;
unsigned char PIDCnt =0;
unsigned char AngleModuStart =0;
unsigned char UdStepFlag =0;
unsigned char MasterSlaveFlag = 0;

unsigned char buck_lessvol_flag = 0;
unsigned char buck_overvol_flag = 0;
unsigned char dcdc_lessvol_flag = 0;
unsigned char dcdc_overvol_flag = 0;
double SIV_F =50.5;
double SIV_V =311;
double AngleErr = 0;

unsigned int ACU_DIN_gui =0;
unsigned int ACU_DIN_gui_last = 0;
unsigned int IGBTCHECKFAULT = 0;
unsigned int CutOffCnt = 0;
unsigned int OvtCnt = 0;
unsigned int PQCnt = 0;
double Udout = 0;
double Uqout = 0;

unsigned int AngleModudelay = 0;

unsigned int EventData[6][150] = {0}; 	/*充电机故障记录数据*/
unsigned int EventBuf[6] = {0};	    	/*充电机故障缓存数组*/
unsigned int BCU_TO_EventIndex = 0; 	/*充电机故障记录索引值*/
unsigned int BCU_TO_EventTrig = 0;  	/*充电机故障记录触发位*/
unsigned char EventSaveDoneFlag = 0;

unsigned int FPGARecordCnt = 0;			
unsigned int LogicTrigFault = 0;
unsigned int LogicTrigFaultCnt = 0;
unsigned int FPGA_TO_EventIndex = 0;    //FPGARead_Count FPGA记录本条故障记录的索引值
unsigned int EventDelay=0;
unsigned int EventEnable = 0;

unsigned int ovt_cnt = 0;
unsigned int ovt_over_flag = 0;

double FreqSum = 0;
double xBuf[20]={0};
unsigned int FreqCnt = 0;
unsigned int slide_cnt = 0;

double buck_duty = 0;
double Debug0 = 0;
double Debug1 = 0;
double Debug2 = 0;
double Debug3 = 0;
double Debug4 = 0;
double Debug5 = 0;
double Debug6 = 0;
double Debug7 = 0;
double Debug8 = 0;
double Debug9 = 0;
double Debug10= 0;
unsigned int Debug11 = 0;
unsigned int Debug12 = 0;
unsigned int Debug13 = 0;
unsigned int Debug14 = 0;
unsigned int Debug15 = 0;
unsigned int Debug16 = 0;
unsigned int Debug17 = 0;
unsigned int Debug18 = 0;
unsigned int Debug19 = 0;
unsigned int Debug20 = 0;

unsigned int A_DSPWRFPGA_DAMREG1 = 0;
unsigned int A_DSPWRFPGA_DAMREG2 = 0;
unsigned int A_DSPWRFPGA_DAMREG3 = 0;
unsigned int A_DSPWRFPGA_DAMREG4 = 0;
unsigned int A_DSPWRFPGA_DAMREG5 = 0;
unsigned int A_DSPWRFPGA_DAMREG6 = 0;
unsigned int A_DSPWRFPGA_DAMREG7 = 0;
unsigned int A_DSPWRFPGA_DAMREG8 = 0;
unsigned int A_DSPWRFPGA_DAMREG9 = 0;
unsigned int A_DSPWRFPGA_DAMREG10 = 0;
unsigned int A_DSPWRFPGA_DAMREG11 = 0;
unsigned int A_DSPWRFPGA_DAMREG12 = 0;
unsigned int A_DSPWRFPGA_DAMREG13 = 0;
unsigned int A_DSPWRFPGA_DAMREG14 = 0;
unsigned int A_DSPWRFPGA_DAMREG15 = 0;
unsigned int A_DSPWRFPGA_DAMREG16 = 0;
unsigned int A_DSPWRFPGA_DAMREG17 = 0;
unsigned int A_DSPWRFPGA_DAMREG18 = 0;
unsigned int A_DSPWRFPGA_DAMREG19 = 0;
unsigned int A_DSPWRFPGA_DAMREG20 = 0;
unsigned int A_DSPWRFPGA_DAMREG21 = 0;
unsigned int A_DSPWRFPGA_DAMREG22 = 0;
unsigned int A_DSPWRFPGA_DAMREG23 = 0;
unsigned int A_DSPWRFPGA_DAMREG24= 0;
unsigned int A_DSPWRFPGA_DAMREG25 = 0;
unsigned int A_DSPWRFPGA_DAMREG26 = 0;
unsigned int A_DSPWRFPGA_DAMREG27 = 0;
unsigned int A_DSPWRFPGA_DAMREG28 = 0;
unsigned int A_DSPWRFPGA_DAMREG29 = 0;
unsigned int A_DSPWRFPGA_DAMREG30 = 0;
unsigned int A_DSPWRFPGA_DAMREG31 = 0;
unsigned int A_DSPWRFPGA_DAMREG32 = 0;

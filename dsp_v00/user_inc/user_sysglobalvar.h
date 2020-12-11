/*********************************************************************
Copyright (c),2002-2017,Sifang Rolling Stock Research Institute Ltd.
*File Name:    SysGlobalVar.h
*Author:       JasonLee
*Date:         2017.09.18
*Version:      0.1
*Description:  system global variable declaration
*Modification history:
    1.Jason, 2017.9.18, first issue;
**********************************************************************/
#ifndef __SYSGLOBALVAR_H__
#define __SYSGLOBALVAR_H__

#ifdef __cplusplus
extern "C" {
#endif

extern double  Icurr_pu_u_meas;
extern double  Icurr_pu_v_meas;
extern double  Icurr_pu_w_meas;
extern double  Icurr_u_meas;
extern double  Icurr_u_rms;
extern double  Icurr_u_rms_fil;
extern double  Icurr_pu_u_fil;
extern double  Icurr_pu_v_fil;
extern double  Icurr_pu_w_fil;
extern double  Icurr_u_fil;
extern double  Icurr_bus_meas;
extern double  Icurr_bus_fil;
extern double  Uun_meas;
extern double  Uvn_meas;
extern double  Uwn_meas;
extern double  Uun_fil;
extern double  Uvn_fil;
extern double  Uwn_fil;
extern double  Uuvw_fil;
extern double  Uoutpeak;
extern double  Uuvw0;
extern double  Uuvw1;
extern double  Uuvw2;
extern double  Uun_Rms_meas;
extern double  Uun_Rms_fil;
extern double  Uwn_Rms_meas;
extern double  Uwn_Rms_fil;
extern double  Uout_deve_inter;

extern double square_rms ;
extern double Uvw_fltr ;
extern double Uvw_sign ;
extern double Uvw_bias ;

extern double  NetVoltage_meas;
extern double  NetVoltage_fil;
extern double  FCVoltage_meas;
extern double  FCVoltage_fil;
extern double  BuckOutVol_meas;
extern double  BuckOutVol_fil;
extern double  CHPin_fil;
extern double  DCDCOutVol_meas;
extern double  DCDCOutVol_fil;

extern double  SUMP;
extern double  SUMQ;
extern double  SUMPBack;
extern double  SUMQBack;

extern unsigned char SoftStop;
extern unsigned char SoftStart;
extern unsigned char SysCnt;


extern unsigned char BuckStartFlag;
extern unsigned char DCDCStartFlag;
extern unsigned char InvStartFlag;
extern unsigned char KM3ClsCmd;
extern unsigned char PIDCnt;


extern unsigned char OverVolFlag;
extern unsigned char LessVolFlag;
extern unsigned char StepFlag;
extern unsigned char LessVolFlagBk;
extern unsigned char LessVolCnt;
extern unsigned char IntegralCnt;
extern unsigned int  LessCnt;

extern unsigned char BuckOverVolFlag;
extern unsigned char BuckLessVolFlag;
extern unsigned char BuckLessVolFlagBk;
extern unsigned char BuckStepFlag;
extern unsigned char BuckLessVolCnt;
extern unsigned char BuckIntegralCnt;
extern unsigned int  BuckLessCnt;
extern unsigned int  BuckPIDFlag;
extern unsigned char DQStart;
extern unsigned int  DQcnt;
extern unsigned char SysStart;
extern unsigned char UdStepFlag;
extern unsigned char AngleModuStart;
extern unsigned char MasterSlaveFlag;
extern unsigned char buck_lessvol_flag;
extern unsigned char buck_overvol_flag;
extern unsigned char dcdc_lessvol_flag;
extern unsigned char dcdc_overvol_flag;
extern double SIV_V;
extern double SIV_F;
extern double AngleErr;

extern unsigned int CutOffCnt;
extern unsigned int OvtCnt;
extern unsigned int ACU_DIN_gui;
extern unsigned int ACU_DIN_gui_last;
extern unsigned int IGBTCHECKFAULT;
extern unsigned int PQCnt;
extern double Udout;
extern double Uqout;
extern unsigned int AngleModudelay;

extern unsigned int EventData[6][150]; 	/*充电机故障记录数据*/
extern unsigned int EventBuf[6];	    	/*充电机故障缓存数组*/
extern unsigned int BCU_TO_EventIndex; 	/*充电机故障记录索引值*/
extern unsigned int BCU_TO_EventTrig;  	/*充电机故障记录触发位*/
extern unsigned char EventSaveDoneFlag;
extern unsigned int FPGARecordCnt;
extern unsigned int LogicTrigFault;
extern unsigned int LogicTrigFaultCnt;
extern unsigned int FPGA_TO_EventIndex;
extern unsigned int EventDelay;
extern unsigned int EventEnable;
extern double buck_duty;
extern unsigned int ovt_cnt;
extern unsigned int ovt_over_flag;
extern double Debug0;/*记录算法执行时间*/
extern double Debug1;/*记录算法执行时间*/
extern double Debug2;/*记录算法执行时间*/
extern double Debug3;
extern double Debug4;
extern double Debug5;
extern double Debug6;
extern double Debug7;
extern double Debug8;
extern double Debug9;
extern double Debug10;
extern unsigned int Debug11;
extern unsigned int Debug12;
extern unsigned int Debug13;
extern unsigned int Debug14;
extern unsigned int Debug15;
extern unsigned int Debug16;
extern unsigned int Debug17;
extern unsigned int Debug18;
extern unsigned int Debug19;
extern unsigned int Debug20;

extern unsigned int A_DSPWRFPGA_DAMREG1;
extern unsigned int A_DSPWRFPGA_DAMREG2;
extern unsigned int A_DSPWRFPGA_DAMREG3;
extern unsigned int A_DSPWRFPGA_DAMREG4;
extern unsigned int A_DSPWRFPGA_DAMREG5;
extern unsigned int A_DSPWRFPGA_DAMREG6;
extern unsigned int A_DSPWRFPGA_DAMREG7;
extern unsigned int A_DSPWRFPGA_DAMREG8;
extern unsigned int A_DSPWRFPGA_DAMREG9;
extern unsigned int A_DSPWRFPGA_DAMREG10;
extern unsigned int A_DSPWRFPGA_DAMREG11;
extern unsigned int A_DSPWRFPGA_DAMREG12;
extern unsigned int A_DSPWRFPGA_DAMREG13;
extern unsigned int A_DSPWRFPGA_DAMREG14;
extern unsigned int A_DSPWRFPGA_DAMREG15;
extern unsigned int A_DSPWRFPGA_DAMREG16;
extern unsigned int A_DSPWRFPGA_DAMREG17;
extern unsigned int A_DSPWRFPGA_DAMREG18;
extern unsigned int A_DSPWRFPGA_DAMREG19;
extern unsigned int A_DSPWRFPGA_DAMREG20;
extern unsigned int A_DSPWRFPGA_DAMREG21;
extern unsigned int A_DSPWRFPGA_DAMREG22;
extern unsigned int A_DSPWRFPGA_DAMREG23;
extern unsigned int A_DSPWRFPGA_DAMREG24;
extern unsigned int A_DSPWRFPGA_DAMREG25;
extern unsigned int A_DSPWRFPGA_DAMREG26;
extern unsigned int A_DSPWRFPGA_DAMREG27;
extern unsigned int A_DSPWRFPGA_DAMREG28;
extern unsigned int A_DSPWRFPGA_DAMREG29;
extern unsigned int A_DSPWRFPGA_DAMREG30;
extern unsigned int A_DSPWRFPGA_DAMREG31;
extern unsigned int A_DSPWRFPGA_DAMREG32;
#endif

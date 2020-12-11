/*********************************************************************
Copyright (c),2002-2017,Sifang Rolling Stock Research Institute Ltd.
*File Name:    user_interface.h
*Author:       JasonLee
*Date:         2017.09.18
*Version:      0.1
*Description:  interface set head files
*Modification history:
    1.Jason, 2017.9.18, first issue;
**********************************************************************/
#ifndef _USERINTERFACE_H_
#define _USERINTERFACE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define 	TPR_DCDC 		2500
#define 	TPR_PWM 		5000
#define 	TPR_BUCK 		15000
#define 	TPR_CHP 		12000
#define 	TIMER_ft      	5000
#define    	TDB				60


extern void  ParaVarZero(void);
extern void  FPGA_Init(void);
extern void  InitBuckMdl(void);
extern void  InitDCDCMdl(void);
extern void  InitInvMdl(void);
extern void  StartBuckMdl(void);
extern void  StopBuckMdl(void);
extern void  StartDCDCMdl(void);
extern void  StopDCDCMdl(void);
extern void  StartInvMdl(void);
extern void  StopInvMdl(void);
extern void  ControlDataMeas(void);
extern void  LogicInterface(void);
extern void  DAM_Tran(void);
extern void  DSP_TO_ARM(void);
extern void  OvtCtrl(void);
extern void  DSP_WR_FPGAPWMReg(void);
#endif

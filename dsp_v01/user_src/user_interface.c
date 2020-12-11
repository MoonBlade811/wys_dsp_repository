/*********************************************************************
Copyright (c),2002-2017,Sifang Rolling Stock Research Institute Ltd.
*File Name:    user_interface.c
*Author:       JasonLee
*Date:         2017.09.18
*Version:      V1.2
*Description:  interface set source files
*Modification history:
    1.Jason, 2017.9.18, first issue;
    	2.JasonLee, 2018.1.26, second issue
**********************************************************************/
#include "user_interface.h"
#include "user_gpio.h"
#include "user_syscfg.h"
#include "hw_types.h"
#include "user_variable.h"
#include "delay.h"
#include "algorithm.h"
#include "user_sysglobalvar.h"
#include <string.h>
/***********************************************************
*函数介绍：OVT斩波函数
*输入参数：无
*输出参数：无
*返 回 值：无
***********************************************************/
void OvtCtrl(void)
{
	unsigned short temp=0;

	if(((ACU_DIN_gui&0x40)==0)&&((ACU_DIN_gui&0x80)==0)&&((ACU_DIN_gui&0x100)==0))
	{
		if((DCDCOutVol_meas>=7))
		{
		    L_CHPPWM_CMPENA_gui = 1;
		    A_DSPWRFPGA_CHPCMPR_gui = TPR_CHP*0.25;
		}
		else
		{
            L_CHPPWM_CMPENA_gui = 0;
            A_DSPWRFPGA_CHPCMPR_gui = 0;
		}
	}
	else{;}

	if(((ACU_DIN_gui&0x40)==0x40)||((ACU_DIN_gui&0x80)==0x80)||((ACU_DIN_gui&0x100)==0x100))
	{
		if((DCDCOutVol_meas >= 670)&&(OvtCnt <= 2000))/*OVT动作检测时间为166ms*/
		{
			L_CHPPWM_CMPENA_gui = 1;
			A_DSPWRFPGA_CHPCMPR_gui = TPR_CHP - TPR_CHP*0.9;//(unsigned int)(TPR_CHP*0.85*DCDCOutVol_meas/680);
			if(A_DSPWRFPGA_CHPCMPR_gui <= 0.1 * TPR_CHP)
			{
				A_DSPWRFPGA_CHPCMPR_gui = 0.1 * TPR_CHP;
			}
			else{;}
			OvtCnt++;
		}
		else{;}
		if(DCDCOutVol_meas <= 650)
		{
			L_CHPPWM_CMPENA_gui = 0;
			A_DSPWRFPGA_CHPCMPR_gui=0;
			OvtCnt = 0;
		}
		else{;}
	}
	else{;}

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

	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_CHPCMPR_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_FPGA_0028) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_CHPCMPR_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_FPGA_002A) = temp;
}

/***********************************************************
*函数介绍：DSP变量观测强制函数
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
void DSP_TO_ARM(void)
{
	unsigned short temp = 0;

	A_ARMRDDSP_DEBUG40_gui = (unsigned int) (SIV_F*1000);
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG40_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_ARM_135C) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG40_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_ARM_135E) = temp;

	A_ARMRDDSP_DEBUG39_gui = (unsigned int) (DCDCReg.OutputPoint);
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG39_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_ARM_1358) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG39_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_ARM_135A) = temp;

	A_ARMRDDSP_DEBUG38_gui = (unsigned int) (BuckReg.OutputPoint);
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG38_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_ARM_1354) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG38_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_ARM_1356) = temp;

	A_ARMRDDSP_DEBUG37_gui = (unsigned int) (SoftStart);
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG37_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_ARM_1350) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG37_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_ARM_1352) = temp;

	A_ARMRDDSP_DEBUG36_gui = (unsigned int) (A_ARMRDDSP_DEBUG46_gui);
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG36_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_ARM_134C) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG36_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_ARM_134E) = temp;

	A_ARMRDDSP_DEBUG35_gui = (unsigned int) (A_ARMRDDSP_DEBUG45_gui);
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG35_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_ARM_1348) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG35_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_ARM_134A) = temp;

	A_ARMRDDSP_DEBUG34_gui = (unsigned int) (Debug2);
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG34_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_ARM_1344) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG34_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_ARM_1346) = temp;

	A_ARMRDDSP_DEBUG33_gui = (unsigned int) (Debug3);
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG33_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_ARM_1340) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG33_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_ARM_1342) = temp;

	A_ARMRDDSP_DEBUG32_gui = (unsigned int) (Debug6);
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG32_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_ARM_133C) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG32_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_ARM_133E) = temp;

	A_ARMRDDSP_DEBUG31_gui = (unsigned int) (EventEnable);
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG31_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_ARM_1338) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG31_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_ARM_133A) = temp;
	/*-------------------------------------------------------------------------*/
	/*-------------------------------------------------------------------------*/
	temp = HWREGH(ARM_To_DSP_1364);	
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG42_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_1366);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG42_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_1368);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG43_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_136A);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG43_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_136C);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG44_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_136E);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG44_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_1370);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG45_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_1372);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG45_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_1374);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG46_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_1376);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG46_gui, UNSIGNED16_LOW_BYTE);	

	temp = HWREGH(ARM_To_DSP_1378);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG47_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_137A);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG47_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_137C);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG48_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_137E);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG48_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_1380);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG49_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_1382);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG49_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_1384);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG50_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_1386);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG50_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_1388);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG51_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_138A);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG51_gui, UNSIGNED16_LOW_BYTE);
}
/***********************************************************
*函数介绍：接受来自ARM的DO输出信号，下发FPGA
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
void LogicInterface()
{
	unsigned short temp = 0;
	temp = HWREGH(ARM_To_DSP_12E4);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG10_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_12E6);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG10_gui, UNSIGNED16_LOW_BYTE);

	if(A_ARMRDDSP_DEBUG1_gui)/*从机接触器闭合命令再次下发，避免逻辑命令清零*/
	{
	    if((A_ARMRDDSP_DEBUG10_gui&0x00000800)==0x00000000)/*逻辑未发出接触器闭合命令，DSP接管下发*/
        {
	        A_ARMRDDSP_DEBUG10_gui|= 0x800;
        }
        else{;}
	}
	/*读取逻辑DO输出*/
	temp =(unsigned short)(A_ARMRDDSP_DEBUG10_gui&0xffff);
    DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA3_gui,    3);
    DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA8_gui,    8);
    DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA9_gui,    9);	/*KCH*/
    DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA10_gui,   10);	/*CTT*/
    DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA11_gui,   11);	/*SIVCTT*/
    DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA12_gui,   12);	/*KM4*/
    /*下发FPGA输出*/
    L_DSPWRFPGA_DOUTLOCALSTA3_gui = L_DSPRDFPGA_DOUTLOCALSTA3_gui;
    L_DSPWRFPGA_DOUTLOCALSTA8_gui = L_DSPRDFPGA_DOUTLOCALSTA8_gui;
    L_DSPWRFPGA_DOUTLOCALSTA9_gui = L_DSPRDFPGA_DOUTLOCALSTA9_gui;
    L_DSPWRFPGA_DOUTLOCALSTA10_gui= L_DSPRDFPGA_DOUTLOCALSTA10_gui;
    L_DSPWRFPGA_DOUTLOCALSTA11_gui= L_DSPRDFPGA_DOUTLOCALSTA11_gui;
    L_DSPWRFPGA_DOUTLOCALSTA12_gui= L_DSPRDFPGA_DOUTLOCALSTA12_gui;

	temp = 0;
	DATA_INSERT_BOOLEAN(temp,  L_DSPWRFPGA_DOUTLOCALSTA3_gui,     3);
	DATA_INSERT_BOOLEAN(temp,  L_DSPWRFPGA_DOUTLOCALSTA8_gui,     8);
	DATA_INSERT_BOOLEAN(temp,  L_DSPWRFPGA_DOUTLOCALSTA9_gui,     9);
	DATA_INSERT_BOOLEAN(temp,  L_DSPWRFPGA_DOUTLOCALSTA10_gui,    10);
	DATA_INSERT_BOOLEAN(temp,  L_DSPWRFPGA_DOUTLOCALSTA11_gui,    11);
	DATA_INSERT_BOOLEAN(temp,  L_DSPWRFPGA_DOUTLOCALSTA12_gui,    12);

	HWREGH(DSP_To_FPGA_00E8) = temp;
}
/***********************************************************
*函数介绍：
*输入参数：
*输出参数：
*返回值	：
***********************************************************/
void  ParaVarZero(void)
{
	if((DQStart==0)||((L_SIV_start_Comm_gui==0)&&(L_INV_PWMENA_gui==0)))
	{
//		SPLLReg = SPLLRegRst;
//		SVPWMReg = SVPWMRegRst;
//		UDPID = UDPIDRst;
//		UQPID = UQPIDRst;
//		UDFivePID = UDFivePIDRst;
//		UQFivePID = UQFivePIDRst;
//		UDSevenPID = UDSevenPIDRst;
//		UQSevenPID = UQSevenPIDRst;
//		PQData 		= PQDataRst;
//        sogi_hq_reg = sogi_hq_reg_rst;

	}
	else{;}

    SVPWMReg = SVPWMRegRst;
    PQData   = PQDataRst;
	SUMP =0;
	SUMQ =0;
	SUMPBack =0;
	SUMQBack =0;


	SoftStop =0;
	SoftStart =0;

	Udout = 0;
//	Uqout = 0;

	KM3ClsCmd = 0;
	SIV_V = 311;
	SIV_F = 50.5;
	AngleModuStart = 0;
	UdStepFlag = 0;
	SysStart = 0;
	CutOffCnt = 0;
	OvtCnt = 0;
	AngleErr = 0;
	A_ARMRDDSP_DEBUG1_gui = 0;/*从机闭合命令复位*/
	AngleModudelay = 0;

	ACU_DIN_gui_last = ACU_DIN_gui;/*接触器状态复位*/
}
/***********************************************************
*函数介绍：FPGA配置函数，配置SIV BUCK DC/DC PWM模块工作方式
*输入参数：无
*输出参数：无
*返 回 值：无
***********************************************************/
void FPGA_Init()  /*FPGA初始化*/
{
	unsigned short temp = 0;
	/****************SIV PWM设置******************/

	A_DSPWRFPGA_PWMTPR_gui = TPR_PWM;     /*INV PWM定时周期值，计数器计数频率60MHz，等腰三角波，定时频率6kHz：PWMTPRREG=(10000/2)*/
	A_DSPWRFPGA_PWMDBCON_gui = 0x3C1;     /*INV PWM死区使能，计数器计数频率60MHz，死区时间3us：L_PWM_DBTPR_gui=120/0x78*/

	/****************OVT PWM设置******************/

	A_DSPWRFPGA_CHPPRD_gui = TPR_CHP;   /*INV PWM定时周期值，计数器计数频率60MHz，锯齿波或直角波，定时频率5kHz：TPR_CHP=20000*/
	A_DSPWRFPGA_CHPDBTCON_gui=0x01;     /*INV PWM死区不使能，计数器计数频率60MHz，死区时间0us,L_CHPPWM_DBTPR_gui=0/0x00*/

	/****************BUCK PWM设置******************/

	A_DSPWRFPGA_BUCKPRD_gui = TPR_BUCK;  /*INV PWM定时周期值，计数器计数频率60MHz，锯齿波或直角波，定时频率4kHz：TPR_BUCK=15000*/
	A_DSPWRFPGA_BUCKDBTCON_gui = 0x01;   /*INV PWM死区使能，计数器计数频率60MHz，死区时间0us,A_DSPWRFPGA_BUCKDBTCON_gui=0/0x01*/

	/****************DCDC PWM设置******************/

	A_DSPWRFPGA_DCDCPRD_gui = TPR_DCDC;   /*INV PWM定时周期值，计数器计数频率60MHz，等腰三角波，定时频率12kHz：TPR_DCDC=(5000/2)*/
	A_DSPWRFPGA_DCDCDBTCON_gui = 0x781;     /*INV PWM死区使能，计数器计数频率60MHz，(死区时间2us)*/

	/****************周期值提前下发，防止计数值减到0溢出******************/
    temp = 0;/*2018年1月16日09:56:53*/
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_PWMTPR_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_FPGA_0004) = temp;

	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_PWMTPR_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_FPGA_0006) = temp;

	temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DCDCPRD_gui, UNSIGNED16_HIGH_BYTE);
    HWREGH(DSP_To_FPGA_0040) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DCDCPRD_gui, UNSIGNED16_LOW_BYTE);
    HWREGH(DSP_To_FPGA_0042) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_BUCKPRD_gui, UNSIGNED16_HIGH_BYTE);
    HWREGH(DSP_To_FPGA_0058) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_BUCKPRD_gui, UNSIGNED16_LOW_BYTE);
    HWREGH(DSP_To_FPGA_005A) = temp;

	Delay(3000);/*延时约为110us*/
	/****************PWM定时器模块使能设置******************/
	L_PWM_TIMERENA_gui = 1;               //PWM Timer  EN
	L_CHPPWM_TIMEENA_gui = 1;             //OVT Timer  EN
	L_DCDCPWM_TIMEENA_gui = 1;            //DCDC Timer EN
	L_BUCKPWM_TIMEENA_gui = 1;            //BUCK Timer EN

	L_PWM_CHECKIGBTENA_gui = 0;			 /*逆变器IGBT检测使能设置,1：INV PWMIGBT检测禁止；0：IGBT检测使能*/
	L_CHPPWM_CHECKIGBTENA_gui = 0;		 /*斩波IGBT检测使能设置,1：CHP PWMIGBT检测禁止；0：IGBT检测使能*/
	L_DCDCPWM_CHECKIGBTENA_gui = 0;		 /*DC/DC IGBT检测使能设置,1：DCDC PWMIGBT检测禁止；0：IGBT检测使能*/
	L_BuckPWM_CHECKIGBTENA_gui = 0;		 /*Buck IGBT检测使能设置,1：Buck PWMIGBT检测禁止；0：IGBT检测使能*/

	L_PQenable_gui = 1;					 /*功率计算使能*/
}
/***********************************************************
*函数介绍：初始化Buck模块函数，初始化PID控制参数及PWM值设置为2
*输入参数：无
*输出参数：无
*返 回 值：无
***********************************************************/
void InitBuckMdl()
{
	unsigned short temp = 0;
	A_DSPWRFPGA_BUCKCMPR_gui = TPR_BUCK - 2;             /*BUCK控制占空比，反脉宽*/
	BuckReg = BuckRegRst;
	BuckLessVolFlag = 0;
	BuckLessVolFlagBk = 0;
	BuckOverVolFlag = 0;
	BuckStepFlag = 0;
	BuckIntegralCnt = 0;
	BuckLessCnt = 0;
	BuckPIDFlag = 0;

	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_BUCKCMPR_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_FPGA_0060) = temp;

	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, 0, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_FPGA_0062) = temp;
}
/***********************************************************
*函数介绍：启动Buck模块，开启Buck模块比较位，启动标志位置1
*输入参数：无
*输出参数：无
*返 回 值：无
***********************************************************/
void StartBuckMdl()
{
	L_BUCKPWM_CMPENA_gui = 1;           //BUCK比较使能
	BuckStartFlag =1;                   //使能标志位置1,禁止重复使能
}
/***********************************************************
*函数介绍：关闭Buck模块：关闭Buck模块比较使能位，标志位复位，PID参数复位
*输入参数：无
*输出参数：无
*返 回 值：无
***********************************************************/
void StopBuckMdl()
{
	Delay(100);
	L_BUCKPWM_CMPENA_gui=0;           /*BUCK比较使能*/
	DSP_WR_FPGAPWMReg();
	BuckStartFlag =0;                 //使能标志位置1,禁止重复使能
	buck_overvol_flag = 0;
	buck_lessvol_flag = 0;

}
/***********************************************************
*函数介绍：初始化DCDC模块：设置桥臂占空比、移相值等参数
*输入参数：无
*输出参数：无
*返 回 值：无
***********************************************************/
void InitDCDCMdl()
{
	unsigned short temp = 0;
	DCDCReg = DCDCRegRst;
	LessVolFlag = 0;
	LessVolFlagBk = 0;
	OverVolFlag = 0;
	StepFlag = 0;
	IntegralCnt = 0;
	LessCnt = 0;
	/************DCDC的控制通过超前臂移相实现，调节开通时间调整移相角，调节关断时间调整PWM占空比来实现变压器防饱和控制*******/

	A_DSPWRFPGA_DCDCPSLD_gui = 0;                //DCDC超前臂移相
	A_DSPWRFPGA_DCDCPRULD_gui = TPR_DCDC-A_DSPWRFPGA_DCDCPSLD_gui;

	A_DSPWRFPGA_DCDCPSLG_gui = 0;				 //DCDC滞后臂移相
	A_DSPWRFPGA_DCDCPRULG_gui = TPR_DCDC-A_DSPWRFPGA_DCDCPSLG_gui;

	/************由于比较值不会超过2000，所以高16位总为0，不必监控FPGA是否在读操作*******/
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DCDCPSLD_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_FPGA_004C) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, 0, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_FPGA_004E) = temp;

	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DCDCPSLG_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_FPGA_0048) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, 0, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_FPGA_004A) = temp;

	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DCDCPRULD_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_FPGA_0054) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, 0, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_FPGA_0056) = temp;

	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DCDCPRULG_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_FPGA_0050) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, 0, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_FPGA_0052) = temp;
}
/***********************************************************
*函数介绍：启动DCDC模块：开启超前臂和滞后臂比较使能位；
*输入参数：无
*输出参数：无
*返 回 值：无
***********************************************************/
void StartDCDCMdl()
{
	L_DCDCPWM_CMP1ENA_gui = 1;           //DCDC超前臂比较使能；
	L_DCDCPWM_CMP2ENA_gui = 1;			 //DCDC滞后臂比较使能；
	DCDCStartFlag = 1;                   //使能标志位置1,禁止重复使能
}
/***********************************************************
*函数介绍：关闭DCDC模块，比较使能位复位，标志位清零
*输入参数：无
*输出参数：无
*返 回 值：无
***********************************************************/
void StopDCDCMdl()
{
	Delay(100);
	L_DCDCPWM_CMP1ENA_gui =0;           //DCDC超前臂比较使能关闭
	L_DCDCPWM_CMP2ENA_gui =0;			//DCDC滞后臂比较使能关闭
	DSP_WR_FPGAPWMReg();
	DCDCStartFlag =0;                	//使能标志位置0,禁止重复使能
	dcdc_lessvol_flag = 0;
	dcdc_overvol_flag = 0;
}
/***********************************************************
*函数介绍：初始化INV模块函数：比较寄存器清零复位，控制参数复位
*输入参数：无
*输出参数：无
*返 回 值：无
***********************************************************/
void InitInvMdl()           /*逆变器启动初始化函数*/
{
	 unsigned short temp = 0;

	 A_PWM_CMPU_gui = 0xffffffff; /* 初始化比较寄存器1*/
	 A_PWM_CMPV_gui = 0xffffffff; /* 初始化比较寄存器2*/
	 A_PWM_CMPW_gui = 0xffffffff; /* 初始化比较寄存器3*/

	 /*-----------------数据写入--------------*/
	 temp = 0;
	 DATA_EXTRACT_UNSIGNED32(temp, A_PWM_CMPU_gui, UNSIGNED16_HIGH_BYTE);
	 HWREGH(DSP_To_FPGA_0010) = temp;
	 temp = 0;
	 DATA_EXTRACT_UNSIGNED32(temp, A_PWM_CMPU_gui, UNSIGNED16_LOW_BYTE);
	 HWREGH(DSP_To_FPGA_0012) = temp;

	 temp = 0;
	 DATA_EXTRACT_UNSIGNED32(temp, A_PWM_CMPV_gui, UNSIGNED16_HIGH_BYTE);
	 HWREGH(DSP_To_FPGA_0014) = temp;
	 temp = 0;
	 DATA_EXTRACT_UNSIGNED32(temp, A_PWM_CMPV_gui, UNSIGNED16_LOW_BYTE);
	 HWREGH(DSP_To_FPGA_0016) = temp;

	 temp = 0;
	 DATA_EXTRACT_UNSIGNED32(temp, A_PWM_CMPW_gui, UNSIGNED16_HIGH_BYTE);
	 HWREGH(DSP_To_FPGA_0018) = temp;
	 temp = 0;
	 DATA_EXTRACT_UNSIGNED32(temp, A_PWM_CMPW_gui, UNSIGNED16_LOW_BYTE);
	 HWREGH(DSP_To_FPGA_001A) = temp;

	 ParaVarZero();
}
/***********************************************************
*函数介绍：逆变器启动函数：
*输入参数：无
*输出参数：无
*返 回 值：无
***********************************************************/
void StartInvMdl()
{
	L_PWM_CMPENA_gui = 1;               //SIV比较使能
	InvStartFlag =1;
}
/***********************************************************
*函数介绍：
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
void StopInvMdl()
{
	Delay(100);
	L_PWM_CMPENA_gui = 0;               //SIV比较使能
	DSP_WR_FPGAPWMReg();
	InvStartFlag =0;
}
/***********************************************************
*函数介绍：控制变量数据测量及滤波函数
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
void ControlDataMeas()
{
	unsigned short temp;
	double ParaFilter = 0.1;

	temp = HWREGH(FPGA_To_DSP_025C);          	//AIN7 网压
	NetVoltage_meas = 0.3868472*(double)(temp&0x0fff);
	NetVoltage_fil = NetVoltage_meas + ParaFilter*(NetVoltage_fil - NetVoltage_meas);

	temp = HWREGH(FPGA_To_DSP_0248);          	//AIN2 BuckFC电压
	FCVoltage_meas = 0.3868472*(double)(temp&0x0fff);
	FCVoltage_fil = FCVoltage_meas + 0.98836447*(FCVoltage_fil - FCVoltage_meas);//0.98836447

	temp = HWREGH(FPGA_To_DSP_0260);          	//AIN8 Buck输出电压
	BuckOutVol_meas = 0.257898130*(double)(temp&0x0fff);
	BuckOutVol_fil = BuckOutVol_meas + ParaFilter*(BuckOutVol_fil - BuckOutVol_meas);

    temp = HWREGH(FPGA_To_DSP_0264);         	//AIN9 DCDC输出电压
    DCDCOutVol_meas = 0.3868472*(double)(temp&0x0fff);
    DCDCOutVol_fil = DCDCOutVol_meas + ParaFilter*(DCDCOutVol_fil-DCDCOutVol_meas);

	temp = HWREGH(FPGA_To_DSP_0268);  		  	//AIN10 接触器前U相电压
	Uun_meas = 0.25789813*(double)((temp&0x0fff)-2048);
	Uun_fil = Uun_meas + ParaFilter*(Uun_fil-Uun_meas);

	temp = HWREGH(FPGA_To_DSP_026C);  	  		//AIN11 接触器后V相电压
	Uvn_meas = 0.25789813*(double)((temp&0x0fff)-2048);
	Uvn_fil = Uvn_meas + ParaFilter*(Uvn_fil-Uvn_meas);

	temp = HWREGH(FPGA_To_DSP_0270);  	  		//AIN12 接触器后W相电压
	Uwn_meas = 0.25789813*(double)((temp&0x0fff)-2048);
    Uwn_fil = Uwn_meas + ParaFilter*(Uwn_fil-Uwn_meas);

	temp = HWREGH(FPGA_To_DSP_029C);  			//AIN10RMS 接触器前U相电压有效值
	Uun_Rms_meas = 0.25789813*(double)((temp&0x0fff)-2048);
	Uun_Rms_fil = Uun_Rms_meas + ParaFilter*(Uun_Rms_fil - Uun_Rms_meas);

    temp = HWREGH(FPGA_To_DSP_02A0);            //AIN12RMS 接触器后W相电压有效值
    Uwn_Rms_meas = 0.25789813*(double)((temp&0x0fff)-2048);
    Uwn_Rms_fil = Uwn_Rms_meas + ParaFilter*(Uwn_Rms_fil - Uwn_Rms_meas);

    temp = HWREGH(FPGA_To_DSP_0240);            //AIN0 母线输出电流
    Icurr_bus_meas = 0.0806*(double)((temp&0x0fff)-0);
    Icurr_bus_fil = Icurr_bus_meas + ParaFilter*(Icurr_bus_fil - Icurr_bus_meas);


    temp = HWREGH(FPGA_To_DSP_0258);  			//AIN6 SIV输出U相电流
    Icurr_u_meas = 0.16116*(double)((temp&0x0fff)-2048);
    Icurr_u_fil = Icurr_u_meas + ParaFilter*(Icurr_u_fil - Icurr_u_meas);

    temp = HWREGH(FPGA_To_DSP_0298);  			//AIN6 SIV输出U相电流有效值
    Icurr_u_rms = 0.16116*(double)((temp&0x0fff)-2048);
    Icurr_u_rms_fil = Icurr_u_rms + ParaFilter*(Icurr_u_rms_fil - Icurr_u_rms);

	temp = HWREGH(FPGA_To_DSP_024C);  			//AIN3 PU侧U相电流
	Icurr_pu_u_meas = 0.16116*(double)((temp&0x0fff)-2048);
	Icurr_pu_u_fil = Icurr_pu_u_meas + ParaFilter*(Icurr_pu_u_fil - Icurr_pu_u_meas);

	temp=HWREGH(FPGA_To_DSP_0250); 				//AIN4 PU侧V相电流
	Icurr_pu_v_meas = 0.16116*(double)((temp&0x0fff)-2048);
	Icurr_pu_v_fil = Icurr_pu_v_meas + ParaFilter*(Icurr_pu_v_fil - Icurr_pu_v_meas);

	temp=HWREGH(FPGA_To_DSP_0254); 				//AIN5 PU侧W相电流
	Icurr_pu_w_meas = 0.16116*(double)((temp&0x0fff)-2048);
	Icurr_pu_w_fil = Icurr_pu_w_meas + ParaFilter*(Icurr_pu_w_fil - Icurr_pu_w_meas);

	temp = HWREGH(FPGA_To_DSP_00E4);			//读取DI状态
	DATA_INSERT_UNSIGNED32(temp, ACU_DIN_gui, UNSIGNED16_HIGH_BYTE);

	temp = HWREGH(FPGA_To_DSP_0304);			//V相频率
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_INVVOUTFREQ_gui, UNSIGNED16_HIGH_BYTE);

	temp = HWREGH(FPGA_To_DSP_0306);
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_INVVOUTFREQ_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(FPGA_To_DSP_0308);			//W相频率
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_INVWOUTFREQ_gui, UNSIGNED16_HIGH_BYTE);

	temp = HWREGH(FPGA_To_DSP_030A);
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_INVWOUTFREQ_gui, UNSIGNED16_LOW_BYTE);

	Uuvw0 = 0 - (Uvn_fil + Uwn_fil);		/*和差化积求取电压幅值*/
	Uuvw1 = 0.7071 * Uuvw0;
	Uuvw2 = 0.4082483 * (Uuvw0 + 2*Uvn_fil);
	Uoutpeak = (double)(sqrt(Uuvw1*Uuvw1 + Uuvw2*Uuvw2))*1.41421356;

	temp = HWREGH(FPGA_To_DSP_00E0);/*FPGACHECKFAULT*/
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_FPGACHECKFAULT_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(FPGA_To_DSP_00E2);
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_FPGACHECKFAULT_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_1360);/*网络停机指令*/
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG41_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_1362);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG41_gui, UNSIGNED16_LOW_BYTE);

	Debug15 =HWREGH(FPGA_To_DSP_0288);
}
/***********************************************************
*函数介绍：
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
void DAM_Tran()
{
	unsigned short temp=0;

    A_DSPWRFPGA_DAMREG1=(unsigned int)(NetVoltage_meas*65.535);
    A_DSPWRFPGA_DAMREG2=(unsigned int)(FCVoltage_meas*65.535);
    A_DSPWRFPGA_DAMREG3=(unsigned int)((BuckOutVol_meas)*65.535);
    A_DSPWRFPGA_DAMREG4=(unsigned int)((DCDCOutVol_meas)*65.535);
    A_DSPWRFPGA_DAMREG5=(unsigned int)((Uun_meas+400)*81.91875);
    A_DSPWRFPGA_DAMREG6=(unsigned int)((Uvn_meas+400)*81.91875);
    A_DSPWRFPGA_DAMREG7=(unsigned int)((Uwn_meas+400)*81.91875);
    A_DSPWRFPGA_DAMREG8=(unsigned int)((Icurr_pu_u_meas+250)*131.07);
    A_DSPWRFPGA_DAMREG9=(unsigned int)((Icurr_pu_v_meas+250)*131.07);
    A_DSPWRFPGA_DAMREG10=(unsigned int)((Icurr_pu_w_meas+250)*131.07);
    A_DSPWRFPGA_DAMREG11=(unsigned int)((Icurr_u_meas+250)*131.07);
    A_DSPWRFPGA_DAMREG12=(unsigned int)(((BuckReg.OutputPoint))*81.91875);
    A_DSPWRFPGA_DAMREG13=(unsigned int)(DCDCReg.OutputPoint*81.91875);
    A_DSPWRFPGA_DAMREG14=(unsigned int)((UDPID.OutputPoint)*163.8375);
    A_DSPWRFPGA_DAMREG15=(unsigned int)((UQPID.OutputPoint+10)*3276.75);
    A_DSPWRFPGA_DAMREG16=(unsigned int)((SPLLReg.SpllAngle)*6553.5);
    A_DSPWRFPGA_DAMREG17=(unsigned int)((SVPWMReg.RoAngle)*6553.5);
    A_DSPWRFPGA_DAMREG18=(unsigned int)((PQData.SIV_P+20E3)*1.638375);
    A_DSPWRFPGA_DAMREG19=(unsigned int)((PQData.SIV_Q+20E3)*1.638375);
    A_DSPWRFPGA_DAMREG20=(unsigned int)((SPLLReg.Ualpha+500)*65.535);
    A_DSPWRFPGA_DAMREG21=(unsigned int)((SPLLReg.Ubeta+500)*65.535);
    A_DSPWRFPGA_DAMREG22=(unsigned int)((0-(Uvn_meas+Uwn_meas)+400)*81.91875);
    A_DSPWRFPGA_DAMREG23=(unsigned int)(HWREGH(DSP_To_FPGA_00E8)*6.5535);
    A_DSPWRFPGA_DAMREG24=(unsigned int)((SPLLReg.UdnFilter+20)*1638.375);
    A_DSPWRFPGA_DAMREG25=(unsigned int)((SPLLReg.UqnFilter+20)*1638.375);
    A_DSPWRFPGA_DAMREG26=(unsigned int)((SoftStop)*32767.5);
    A_DSPWRFPGA_DAMREG27=(unsigned int)((SoftStart)*32767.5);
    A_DSPWRFPGA_DAMREG28=(unsigned int)((SIV_V)*163.8375);
    A_DSPWRFPGA_DAMREG29=(unsigned int)((SIV_F)*1191.545454);
    A_DSPWRFPGA_DAMREG30=(unsigned int)((DQStart)*32767.5);
    A_DSPWRFPGA_DAMREG31=(unsigned int)((SysStart)*32767.5);
    A_DSPWRFPGA_DAMREG32=(unsigned int)((SPLLReg.uq_out_filter+1)*32767.5);

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG1, 0);
    HWREGH(DSP_To_FPGA_03C0) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG2, 0);
    HWREGH(DSP_To_FPGA_03C2) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG3, 0);
    HWREGH(DSP_To_FPGA_03C4) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG4, 0);
    HWREGH(DSP_To_FPGA_03C6) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG5, 0);
    HWREGH(DSP_To_FPGA_03C8) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG6, 0);
    HWREGH(DSP_To_FPGA_03CA) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG7, 0);
    HWREGH(DSP_To_FPGA_03CC) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG8, 0);
    HWREGH(DSP_To_FPGA_03CE) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG9, 0);
    HWREGH(DSP_To_FPGA_03D0) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG10, 0);
    HWREGH(DSP_To_FPGA_03D2) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG11, 0);
    HWREGH(DSP_To_FPGA_03D4) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG12, 0);
    HWREGH(DSP_To_FPGA_03D6) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG13, 0);
    HWREGH(DSP_To_FPGA_03D8) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG14, 0);
    HWREGH(DSP_To_FPGA_03DA) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG15, 0);
    HWREGH(DSP_To_FPGA_03DC) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG16, 0);
    HWREGH(DSP_To_FPGA_03DE) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG17, 0);
    HWREGH(DSP_To_FPGA_03E0) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG18, 0);
    HWREGH(DSP_To_FPGA_03E2) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG19, 0);
    HWREGH(DSP_To_FPGA_03E4) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG20, 0);
    HWREGH(DSP_To_FPGA_03E6) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG21, 0);
    HWREGH(DSP_To_FPGA_03E8) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG22, 0);
    HWREGH(DSP_To_FPGA_03EA) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG23, 0);
    HWREGH(DSP_To_FPGA_03EC) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG24, 0);
    HWREGH(DSP_To_FPGA_03EE) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG25, 0);
    HWREGH(DSP_To_FPGA_03F0) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG26, 0);
    HWREGH(DSP_To_FPGA_03F2) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG27, 0);
    HWREGH(DSP_To_FPGA_03F4) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG28, 0);
    HWREGH(DSP_To_FPGA_03F6) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG29, 0);
    HWREGH(DSP_To_FPGA_03F8) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG30, 0);
    HWREGH(DSP_To_FPGA_03FA) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG31, 0);
    HWREGH(DSP_To_FPGA_03FC) = temp;

    temp = 0;
    DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DAMREG32, 0);
    HWREGH(DSP_To_FPGA_03FE) = temp;
}
/***********************************************************
*函数介绍：
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
void DSP_WR_FPGAPWMReg(void)
{
	unsigned temp = 0;
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
}
/***********************************************************
*函数介绍：
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
double slide_filter(double *x)
{
    unsigned int loop_cnt = 0;
    double  FreqSum = 0;
    xBuf[FreqCnt++] = *x;
    if(FreqCnt == 20)
    {
        FreqCnt = 0;
    }
    else{;}

    for(loop_cnt=0;loop_cnt<20;loop_cnt++)
    {
        FreqSum += xBuf[loop_cnt];
    }
    return (FreqSum/20.0);
}

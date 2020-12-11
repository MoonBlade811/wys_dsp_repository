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
*�������ܣ�OVTն������
*�����������
*�����������
*�� �� ֵ����
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
		if((DCDCOutVol_meas >= 670)&&(OvtCnt <= 2000))/*OVT�������ʱ��Ϊ166ms*/
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
*�������ܣ�DSP�����۲�ǿ�ƺ���
*���������
*���������
*�� �� ֵ��
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
*�������ܣ���������ARM��DO����źţ��·�FPGA
*���������
*���������
*�� �� ֵ��
***********************************************************/
void LogicInterface()
{
	unsigned short temp = 0;
	temp = HWREGH(ARM_To_DSP_12E4);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG10_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_12E6);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG10_gui, UNSIGNED16_LOW_BYTE);

	if(A_ARMRDDSP_DEBUG1_gui)/*�ӻ��Ӵ����պ������ٴ��·��������߼���������*/
	{
	    if((A_ARMRDDSP_DEBUG10_gui&0x00000800)==0x00000000)/*�߼�δ�����Ӵ����պ����DSP�ӹ��·�*/
        {
	        A_ARMRDDSP_DEBUG10_gui|= 0x800;
        }
        else{;}
	}
	/*��ȡ�߼�DO���*/
	temp =(unsigned short)(A_ARMRDDSP_DEBUG10_gui&0xffff);
    DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA3_gui,    3);
    DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA8_gui,    8);
    DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA9_gui,    9);	/*KCH*/
    DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA10_gui,   10);	/*CTT*/
    DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA11_gui,   11);	/*SIVCTT*/
    DATA_EXTRACT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA12_gui,   12);	/*KM4*/
    /*�·�FPGA���*/
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
*�������ܣ�
*���������
*���������
*����ֵ	��
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
	A_ARMRDDSP_DEBUG1_gui = 0;/*�ӻ��պ����λ*/
	AngleModudelay = 0;

	ACU_DIN_gui_last = ACU_DIN_gui;/*�Ӵ���״̬��λ*/
}
/***********************************************************
*�������ܣ�FPGA���ú���������SIV BUCK DC/DC PWMģ�鹤����ʽ
*�����������
*�����������
*�� �� ֵ����
***********************************************************/
void FPGA_Init()  /*FPGA��ʼ��*/
{
	unsigned short temp = 0;
	/****************SIV PWM����******************/

	A_DSPWRFPGA_PWMTPR_gui = TPR_PWM;     /*INV PWM��ʱ����ֵ������������Ƶ��60MHz���������ǲ�����ʱƵ��6kHz��PWMTPRREG=(10000/2)*/
	A_DSPWRFPGA_PWMDBCON_gui = 0x3C1;     /*INV PWM����ʹ�ܣ�����������Ƶ��60MHz������ʱ��3us��L_PWM_DBTPR_gui=120/0x78*/

	/****************OVT PWM����******************/

	A_DSPWRFPGA_CHPPRD_gui = TPR_CHP;   /*INV PWM��ʱ����ֵ������������Ƶ��60MHz����ݲ���ֱ�ǲ�����ʱƵ��5kHz��TPR_CHP=20000*/
	A_DSPWRFPGA_CHPDBTCON_gui=0x01;     /*INV PWM������ʹ�ܣ�����������Ƶ��60MHz������ʱ��0us,L_CHPPWM_DBTPR_gui=0/0x00*/

	/****************BUCK PWM����******************/

	A_DSPWRFPGA_BUCKPRD_gui = TPR_BUCK;  /*INV PWM��ʱ����ֵ������������Ƶ��60MHz����ݲ���ֱ�ǲ�����ʱƵ��4kHz��TPR_BUCK=15000*/
	A_DSPWRFPGA_BUCKDBTCON_gui = 0x01;   /*INV PWM����ʹ�ܣ�����������Ƶ��60MHz������ʱ��0us,A_DSPWRFPGA_BUCKDBTCON_gui=0/0x01*/

	/****************DCDC PWM����******************/

	A_DSPWRFPGA_DCDCPRD_gui = TPR_DCDC;   /*INV PWM��ʱ����ֵ������������Ƶ��60MHz���������ǲ�����ʱƵ��12kHz��TPR_DCDC=(5000/2)*/
	A_DSPWRFPGA_DCDCDBTCON_gui = 0x781;     /*INV PWM����ʹ�ܣ�����������Ƶ��60MHz��(����ʱ��2us)*/

	/****************����ֵ��ǰ�·�����ֹ����ֵ����0���******************/
    temp = 0;/*2018��1��16��09:56:53*/
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

	Delay(3000);/*��ʱԼΪ110us*/
	/****************PWM��ʱ��ģ��ʹ������******************/
	L_PWM_TIMERENA_gui = 1;               //PWM Timer  EN
	L_CHPPWM_TIMEENA_gui = 1;             //OVT Timer  EN
	L_DCDCPWM_TIMEENA_gui = 1;            //DCDC Timer EN
	L_BUCKPWM_TIMEENA_gui = 1;            //BUCK Timer EN

	L_PWM_CHECKIGBTENA_gui = 0;			 /*�����IGBT���ʹ������,1��INV PWMIGBT����ֹ��0��IGBT���ʹ��*/
	L_CHPPWM_CHECKIGBTENA_gui = 0;		 /*ն��IGBT���ʹ������,1��CHP PWMIGBT����ֹ��0��IGBT���ʹ��*/
	L_DCDCPWM_CHECKIGBTENA_gui = 0;		 /*DC/DC IGBT���ʹ������,1��DCDC PWMIGBT����ֹ��0��IGBT���ʹ��*/
	L_BuckPWM_CHECKIGBTENA_gui = 0;		 /*Buck IGBT���ʹ������,1��Buck PWMIGBT����ֹ��0��IGBT���ʹ��*/

	L_PQenable_gui = 1;					 /*���ʼ���ʹ��*/
}
/***********************************************************
*�������ܣ���ʼ��Buckģ�麯������ʼ��PID���Ʋ�����PWMֵ����Ϊ2
*�����������
*�����������
*�� �� ֵ����
***********************************************************/
void InitBuckMdl()
{
	unsigned short temp = 0;
	A_DSPWRFPGA_BUCKCMPR_gui = TPR_BUCK - 2;             /*BUCK����ռ�ձȣ�������*/
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
*�������ܣ�����Buckģ�飬����Buckģ��Ƚ�λ��������־λ��1
*�����������
*�����������
*�� �� ֵ����
***********************************************************/
void StartBuckMdl()
{
	L_BUCKPWM_CMPENA_gui = 1;           //BUCK�Ƚ�ʹ��
	BuckStartFlag =1;                   //ʹ�ܱ�־λ��1,��ֹ�ظ�ʹ��
}
/***********************************************************
*�������ܣ��ر�Buckģ�飺�ر�Buckģ��Ƚ�ʹ��λ����־λ��λ��PID������λ
*�����������
*�����������
*�� �� ֵ����
***********************************************************/
void StopBuckMdl()
{
	Delay(100);
	L_BUCKPWM_CMPENA_gui=0;           /*BUCK�Ƚ�ʹ��*/
	DSP_WR_FPGAPWMReg();
	BuckStartFlag =0;                 //ʹ�ܱ�־λ��1,��ֹ�ظ�ʹ��
	buck_overvol_flag = 0;
	buck_lessvol_flag = 0;

}
/***********************************************************
*�������ܣ���ʼ��DCDCģ�飺�����ű�ռ�ձȡ�����ֵ�Ȳ���
*�����������
*�����������
*�� �� ֵ����
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
	/************DCDC�Ŀ���ͨ����ǰ������ʵ�֣����ڿ�ͨʱ���������ǣ����ڹض�ʱ�����PWMռ�ձ���ʵ�ֱ�ѹ�������Ϳ���*******/

	A_DSPWRFPGA_DCDCPSLD_gui = 0;                //DCDC��ǰ������
	A_DSPWRFPGA_DCDCPRULD_gui = TPR_DCDC-A_DSPWRFPGA_DCDCPSLD_gui;

	A_DSPWRFPGA_DCDCPSLG_gui = 0;				 //DCDC�ͺ������
	A_DSPWRFPGA_DCDCPRULG_gui = TPR_DCDC-A_DSPWRFPGA_DCDCPSLG_gui;

	/************���ڱȽ�ֵ���ᳬ��2000�����Ը�16λ��Ϊ0�����ؼ��FPGA�Ƿ��ڶ�����*******/
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
*�������ܣ�����DCDCģ�飺������ǰ�ۺ��ͺ�۱Ƚ�ʹ��λ��
*�����������
*�����������
*�� �� ֵ����
***********************************************************/
void StartDCDCMdl()
{
	L_DCDCPWM_CMP1ENA_gui = 1;           //DCDC��ǰ�۱Ƚ�ʹ�ܣ�
	L_DCDCPWM_CMP2ENA_gui = 1;			 //DCDC�ͺ�۱Ƚ�ʹ�ܣ�
	DCDCStartFlag = 1;                   //ʹ�ܱ�־λ��1,��ֹ�ظ�ʹ��
}
/***********************************************************
*�������ܣ��ر�DCDCģ�飬�Ƚ�ʹ��λ��λ����־λ����
*�����������
*�����������
*�� �� ֵ����
***********************************************************/
void StopDCDCMdl()
{
	Delay(100);
	L_DCDCPWM_CMP1ENA_gui =0;           //DCDC��ǰ�۱Ƚ�ʹ�ܹر�
	L_DCDCPWM_CMP2ENA_gui =0;			//DCDC�ͺ�۱Ƚ�ʹ�ܹر�
	DSP_WR_FPGAPWMReg();
	DCDCStartFlag =0;                	//ʹ�ܱ�־λ��0,��ֹ�ظ�ʹ��
	dcdc_lessvol_flag = 0;
	dcdc_overvol_flag = 0;
}
/***********************************************************
*�������ܣ���ʼ��INVģ�麯�����ȽϼĴ������㸴λ�����Ʋ�����λ
*�����������
*�����������
*�� �� ֵ����
***********************************************************/
void InitInvMdl()           /*�����������ʼ������*/
{
	 unsigned short temp = 0;

	 A_PWM_CMPU_gui = 0xffffffff; /* ��ʼ���ȽϼĴ���1*/
	 A_PWM_CMPV_gui = 0xffffffff; /* ��ʼ���ȽϼĴ���2*/
	 A_PWM_CMPW_gui = 0xffffffff; /* ��ʼ���ȽϼĴ���3*/

	 /*-----------------����д��--------------*/
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
*�������ܣ����������������
*�����������
*�����������
*�� �� ֵ����
***********************************************************/
void StartInvMdl()
{
	L_PWM_CMPENA_gui = 1;               //SIV�Ƚ�ʹ��
	InvStartFlag =1;
}
/***********************************************************
*�������ܣ�
*���������
*���������
*�� �� ֵ��
***********************************************************/
void StopInvMdl()
{
	Delay(100);
	L_PWM_CMPENA_gui = 0;               //SIV�Ƚ�ʹ��
	DSP_WR_FPGAPWMReg();
	InvStartFlag =0;
}
/***********************************************************
*�������ܣ����Ʊ������ݲ������˲�����
*���������
*���������
*�� �� ֵ��
***********************************************************/
void ControlDataMeas()
{
	unsigned short temp;
	double ParaFilter = 0.1;

	temp = HWREGH(FPGA_To_DSP_025C);          	//AIN7 ��ѹ
	NetVoltage_meas = 0.3868472*(double)(temp&0x0fff);
	NetVoltage_fil = NetVoltage_meas + ParaFilter*(NetVoltage_fil - NetVoltage_meas);

	temp = HWREGH(FPGA_To_DSP_0248);          	//AIN2 BuckFC��ѹ
	FCVoltage_meas = 0.3868472*(double)(temp&0x0fff);
	FCVoltage_fil = FCVoltage_meas + 0.98836447*(FCVoltage_fil - FCVoltage_meas);//0.98836447

	temp = HWREGH(FPGA_To_DSP_0260);          	//AIN8 Buck�����ѹ
	BuckOutVol_meas = 0.257898130*(double)(temp&0x0fff);
	BuckOutVol_fil = BuckOutVol_meas + ParaFilter*(BuckOutVol_fil - BuckOutVol_meas);

    temp = HWREGH(FPGA_To_DSP_0264);         	//AIN9 DCDC�����ѹ
    DCDCOutVol_meas = 0.3868472*(double)(temp&0x0fff);
    DCDCOutVol_fil = DCDCOutVol_meas + ParaFilter*(DCDCOutVol_fil-DCDCOutVol_meas);

	temp = HWREGH(FPGA_To_DSP_0268);  		  	//AIN10 �Ӵ���ǰU���ѹ
	Uun_meas = 0.25789813*(double)((temp&0x0fff)-2048);
	Uun_fil = Uun_meas + ParaFilter*(Uun_fil-Uun_meas);

	temp = HWREGH(FPGA_To_DSP_026C);  	  		//AIN11 �Ӵ�����V���ѹ
	Uvn_meas = 0.25789813*(double)((temp&0x0fff)-2048);
	Uvn_fil = Uvn_meas + ParaFilter*(Uvn_fil-Uvn_meas);

	temp = HWREGH(FPGA_To_DSP_0270);  	  		//AIN12 �Ӵ�����W���ѹ
	Uwn_meas = 0.25789813*(double)((temp&0x0fff)-2048);
    Uwn_fil = Uwn_meas + ParaFilter*(Uwn_fil-Uwn_meas);

	temp = HWREGH(FPGA_To_DSP_029C);  			//AIN10RMS �Ӵ���ǰU���ѹ��Чֵ
	Uun_Rms_meas = 0.25789813*(double)((temp&0x0fff)-2048);
	Uun_Rms_fil = Uun_Rms_meas + ParaFilter*(Uun_Rms_fil - Uun_Rms_meas);

    temp = HWREGH(FPGA_To_DSP_02A0);            //AIN12RMS �Ӵ�����W���ѹ��Чֵ
    Uwn_Rms_meas = 0.25789813*(double)((temp&0x0fff)-2048);
    Uwn_Rms_fil = Uwn_Rms_meas + ParaFilter*(Uwn_Rms_fil - Uwn_Rms_meas);

    temp = HWREGH(FPGA_To_DSP_0240);            //AIN0 ĸ���������
    Icurr_bus_meas = 0.0806*(double)((temp&0x0fff)-0);
    Icurr_bus_fil = Icurr_bus_meas + ParaFilter*(Icurr_bus_fil - Icurr_bus_meas);


    temp = HWREGH(FPGA_To_DSP_0258);  			//AIN6 SIV���U�����
    Icurr_u_meas = 0.16116*(double)((temp&0x0fff)-2048);
    Icurr_u_fil = Icurr_u_meas + ParaFilter*(Icurr_u_fil - Icurr_u_meas);

    temp = HWREGH(FPGA_To_DSP_0298);  			//AIN6 SIV���U�������Чֵ
    Icurr_u_rms = 0.16116*(double)((temp&0x0fff)-2048);
    Icurr_u_rms_fil = Icurr_u_rms + ParaFilter*(Icurr_u_rms_fil - Icurr_u_rms);

	temp = HWREGH(FPGA_To_DSP_024C);  			//AIN3 PU��U�����
	Icurr_pu_u_meas = 0.16116*(double)((temp&0x0fff)-2048);
	Icurr_pu_u_fil = Icurr_pu_u_meas + ParaFilter*(Icurr_pu_u_fil - Icurr_pu_u_meas);

	temp=HWREGH(FPGA_To_DSP_0250); 				//AIN4 PU��V�����
	Icurr_pu_v_meas = 0.16116*(double)((temp&0x0fff)-2048);
	Icurr_pu_v_fil = Icurr_pu_v_meas + ParaFilter*(Icurr_pu_v_fil - Icurr_pu_v_meas);

	temp=HWREGH(FPGA_To_DSP_0254); 				//AIN5 PU��W�����
	Icurr_pu_w_meas = 0.16116*(double)((temp&0x0fff)-2048);
	Icurr_pu_w_fil = Icurr_pu_w_meas + ParaFilter*(Icurr_pu_w_fil - Icurr_pu_w_meas);

	temp = HWREGH(FPGA_To_DSP_00E4);			//��ȡDI״̬
	DATA_INSERT_UNSIGNED32(temp, ACU_DIN_gui, UNSIGNED16_HIGH_BYTE);

	temp = HWREGH(FPGA_To_DSP_0304);			//V��Ƶ��
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_INVVOUTFREQ_gui, UNSIGNED16_HIGH_BYTE);

	temp = HWREGH(FPGA_To_DSP_0306);
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_INVVOUTFREQ_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(FPGA_To_DSP_0308);			//W��Ƶ��
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_INVWOUTFREQ_gui, UNSIGNED16_HIGH_BYTE);

	temp = HWREGH(FPGA_To_DSP_030A);
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_INVWOUTFREQ_gui, UNSIGNED16_LOW_BYTE);

	Uuvw0 = 0 - (Uvn_fil + Uwn_fil);		/*�Ͳ����ȡ��ѹ��ֵ*/
	Uuvw1 = 0.7071 * Uuvw0;
	Uuvw2 = 0.4082483 * (Uuvw0 + 2*Uvn_fil);
	Uoutpeak = (double)(sqrt(Uuvw1*Uuvw1 + Uuvw2*Uuvw2))*1.41421356;

	temp = HWREGH(FPGA_To_DSP_00E0);/*FPGACHECKFAULT*/
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_FPGACHECKFAULT_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(FPGA_To_DSP_00E2);
	DATA_INSERT_UNSIGNED32(temp, A_DSPRDFPGA_FPGACHECKFAULT_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(ARM_To_DSP_1360);/*����ͣ��ָ��*/
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG41_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(ARM_To_DSP_1362);
	DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG41_gui, UNSIGNED16_LOW_BYTE);

	Debug15 =HWREGH(FPGA_To_DSP_0288);
}
/***********************************************************
*�������ܣ�
*���������
*���������
*�� �� ֵ��
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
*�������ܣ�
*���������
*���������
*�� �� ֵ��
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
*�������ܣ�
*���������
*���������
*�� �� ֵ��
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

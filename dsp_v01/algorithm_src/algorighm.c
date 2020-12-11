/*********************************************************************
Copyright (c),2002-2017,Sifang Rolling Stock Research Institute Ltd.
*File Name:    algorithm.c
*Author:       JasonLee
*Date:         2017.09.18
*Version:      V1.2
*Description:  algorithm source files
*Modification history:
    1.BiJingbin, 2015.1.18, first issue;
    	2.JasonLee, 2017.9.18, second issue
    		3.JasonLee, 2018.1.26, third issue
**********************************************************************/

#include "algorithm.h"
#include "user_variable.h"
#include "hw_types.h"
#include "user_syscfg.h"
#include "user_sysglobalvar.h"
#include "user_interface.h"
#include "user_interface.h"
#include <string.h>
SPLLPARASTRUCT  		 	SPLLReg     		= SPLLPARADEAULATS;
SPLLPARASTRUCT  		 	SPLLRegRst 			= SPLLPARADEAULATS;
SVPWMPARASTRUCT 		 	SVPWMReg    		= SVPWMREGDEFAULTS;
SVPWMPARASTRUCT 		 	SVPWMRegRst 		= SVPWMREGDEFAULTS;
UDFivePIDPARASTRUCT  	 	UDFivePID 			= UDFivePIDPARADEFAULTS;
UDFivePIDPARASTRUCT  	 	UDFivePIDRst 		= UDFivePIDPARADEFAULTS;
UQFivePIDPARASTRUCT 	 	UQFivePID 			= UQFivePIDPARADEFAULTS;
UQFivePIDPARASTRUCT  	 	UQFivePIDRst 		= UQFivePIDPARADEFAULTS;
UDSevenPIDPARASTRUCT	 	UDSevenPID  		= UDSevenPIDPARADEFAULTS;
UDSevenPIDPARASTRUCT	 	UDSevenPIDRst	  	= UDSevenPIDPARADEFAULTS;
UQSevenPIDPARASTRUCT	 	UQSevenPID  		= UQSevenPIDPARADEFAULTS;
UQSevenPIDPARASTRUCT 	 	UQSevenPIDRst	  	= UQSevenPIDPARADEFAULTS;
PQCALCSTRUCT			 	PQData 				= PQCALCDEFAULTS;
PQCALCSTRUCT			 	PQDataRst 			= PQCALCDEFAULTS;
UDPIDPARASTRUCT 	 	 	UDPID 				= UDPIDPARADEFAULTS;
UDPIDPARASTRUCT 	 	 	UDPIDRst 			= UDPIDPARADEFAULTS;
UQPIDPARASTRUCT 		 	UQPID 				= UQPIDPARADEFAULTS;
UQPIDPARASTRUCT 		 	UQPIDRst 			= UQPIDPARADEFAULTS;
DCDCPARASTRUCT  		 	DCDCReg 			= DCDCPIDPARADEFAULTS;
DCDCPARASTRUCT  		 	DCDCRegRst 			= DCDCPIDPARADEFAULTS;
BUCKPARASTRUCT   		 	BuckReg 			= BUCKPIDPARADEFAULTS;
BUCKPARASTRUCT  		 	BuckRegRst 			= BUCKPIDPARADEFAULTS;
sogi_hq_struct              sogi_hq_reg         = sogi_hq_para_default;
sogi_hq_struct              sogi_hq_reg_rst     = sogi_hq_para_default;

/***********************************************************
*函数介绍：
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
void DCDCPWMCtrl()
{
	unsigned short temp = 0;
	DCDCReg.MeasurePoint = DCDCOutVol_meas;

	switch(L_AUX_TESTMODE_gui)
	{
		case 0:
		{
			DCDCReg.SetPoint += 0.05;
			if(DCDCReg.SetPoint >= 620)
			{
				DCDCReg.SetPoint = 620;
				StepFlag = 1;
			}
			break;
		}
		case 1:
		{
			DCDCReg.SetPoint += 0.01;
			if(DCDCReg.SetPoint>=110)
			{
				DCDCReg.SetPoint = 110;
			}
			break;
		}
		default:break;
	}
#if 0
	//FIXME 2020年7月28日
	/*over voltage handle*/
	if((DCDCReg.SetPoint==600)&&(DCDCReg.MeasurePoint>=640)&&(dcdc_overvol_flag==0)){
	    L_DCDCPWM_CMP1ENA_gui =0;           //DCDC超前臂比较使能关闭
	    L_DCDCPWM_CMP2ENA_gui =0;           //DCDC滞后臂比较使能关闭
	    DSP_WR_FPGAPWMReg();
	    dcdc_overvol_flag = 1;
	}
	else{;}

	if((DCDCReg.SetPoint==600)&&(DCDCReg.MeasurePoint<=620)&&(dcdc_overvol_flag==1)){
        L_DCDCPWM_CMP1ENA_gui =1;           //DCDC超前臂比较使能开启
        L_DCDCPWM_CMP2ENA_gui =1;           //DCDC滞后臂比较使能开启
        DSP_WR_FPGAPWMReg();
        dcdc_overvol_flag = 0;
	}
	/*over voltage handle*/
#endif
#if 0
	/*less voltage handle*/
	if((DCDCReg.SetPoint==600)&&(DCDCReg.MeasurePoint<=560)&&(dcdc_lessvol_flag==0)){
	    if(DCDCReg.OutputPoint<=300){
	        DCDCReg.SumErr = 380/DCDCReg.KI;
	    }
	    else if((DCDCReg.OutputPoint<=400)&&(DCDCReg.OutputPoint>300)){
	        DCDCReg.SumErr = 480/DCDCReg.KI;
	    }
        else if((DCDCReg.OutputPoint<=450)&&(DCDCReg.OutputPoint>400)){
            DCDCReg.SumErr = 500/DCDCReg.KI;
        }
        else if((DCDCReg.OutputPoint<=500)&&(DCDCReg.OutputPoint>450)){
            DCDCReg.SumErr = 550/DCDCReg.KI;
        }
        else if((DCDCReg.OutputPoint<=550)&&(DCDCReg.OutputPoint>500)){
            DCDCReg.SumErr = 600/DCDCReg.KI;
        }
        else if((DCDCReg.OutputPoint<=600)&&(DCDCReg.OutputPoint>550)){
            DCDCReg.SumErr = 650/DCDCReg.KI;
        }
        else if((DCDCReg.OutputPoint<=650)&&(DCDCReg.OutputPoint>600)){
            DCDCReg.SumErr = 700/DCDCReg.KI;
        }else{;}
	    dcdc_lessvol_flag = 1;
	}
    if((DCDCReg.SetPoint==600)&&(DCDCReg.MeasurePoint>=580)&&(dcdc_lessvol_flag==1)){
        dcdc_lessvol_flag = 0;
    }
    /*less voltage handle*/
#endif


    DCDCCtrl(&DCDCReg);

	A_DSPWRFPGA_DCDCPSLG_gui = (unsigned int) (DCDCReg.OutputPoint*TPR_DCDC/TransformerRatio/480);//BuckOutVol_fil

    if(A_DSPWRFPGA_DCDCPSLG_gui >= TPR_DCDC)
    {
       	A_DSPWRFPGA_DCDCPSLG_gui = TPR_DCDC;
    }
    else if(A_DSPWRFPGA_DCDCPSLG_gui <= 0)
    {
       	A_DSPWRFPGA_DCDCPSLG_gui = 0;
    }
    else{;}

	A_DSPWRFPGA_DCDCPRULG_gui = (unsigned int) (TPR_DCDC - A_DSPWRFPGA_DCDCPSLG_gui);

    A_DSPWRFPGA_DCDCPSLD_gui = (unsigned int) 0;
    A_DSPWRFPGA_DCDCPRULD_gui = (unsigned int)(TPR_DCDC -A_DSPWRFPGA_DCDCPSLD_gui);

	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DCDCPSLG_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_FPGA_0048) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, 0, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_FPGA_004A) = temp;

	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DCDCPSLD_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_FPGA_004C) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, 0, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_FPGA_004E) = temp;

	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DCDCPRULG_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_FPGA_0050) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, 0, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_FPGA_0052) = temp;

	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_DCDCPRULD_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_FPGA_0054) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, 0, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_FPGA_0056) = temp;
}
/***********************************************************
*函数介绍：
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
void BuckPWMCtrl()
{
	unsigned short temp = 0;
	if(L_AUX_TESTMODE_gui)
	{
		BuckReg.SetPoint += 0.075;
		if(BuckReg.SetPoint >= 80)
		{
			BuckReg.SetPoint = 80;
		}
		else{;}
	}
	else
	{
		BuckReg.SetPoint += 0.075;
		if(BuckReg.SetPoint >= 480)
		{
			BuckReg.SetPoint = 480;
			BuckStepFlag = 1;
		}
		else{;}
	}
	BuckReg.MeasurePoint = BuckOutVol_meas;

#if 0
	if((BuckReg.MeasurePoint<=420)&&(BuckStepFlag)&&(BuckPIDFlag != 1))
	{
		BuckReg.KP_Ratio = 12.5; /*KP = 6.25, Kp*Err = 500*/
		if(BuckPIDFlag != 1)
		{
			BuckReg.SumErr = (BuckReg.Integral + BuckReg.Proportion)/BuckReg.KI;
			BuckPIDFlag = 1;
		}
		else{;}
	}
	else if((BuckReg.MeasurePoint <= 430)&&(BuckStepFlag)&&(BuckPIDFlag != 2))
	{
		BuckReg.KP_Ratio = 11.4; /*KP = 6.25, Kp*Err = 400*/
		if(BuckPIDFlag != 2)
		{
			BuckReg.SumErr = (BuckReg.Integral + BuckReg.Proportion)/BuckReg.KI;
			BuckPIDFlag = 2;
		}
		else{;}
	}
	else if((BuckReg.MeasurePoint <= 440)&&(BuckStepFlag)&&(BuckPIDFlag != 3))
	{
		BuckReg.KP_Ratio = 8; /*KP = 4*/
		if(BuckPIDFlag != 3)
		{
			BuckReg.SumErr = (BuckReg.Integral + BuckReg.Proportion)/BuckReg.KI;
			BuckPIDFlag = 3;
		}
		else{;}
	}
	else if((BuckReg.MeasurePoint <= 450)&&(BuckStepFlag))
	{
		BuckReg.KP_Ratio = 5; /*KP = 2.5, Kp*Err = 400*/
		if(BuckPIDFlag != 4)
		{
			BuckReg.SumErr = (BuckReg.Integral + BuckReg.Proportion)/BuckReg.KI;
			BuckPIDFlag = 4;
		}
		else{;}
	}
	else if((BuckReg.MeasurePoint > 450)&&(BuckStepFlag)&&(BuckReg.MeasurePoint <= 550))
	{
		BuckReg.KP_Ratio = 1; /*KP = 0.5, Kp*Err = 400*/
		if(BuckPIDFlag != 0)
		{
			BuckReg.SumErr = (BuckReg.Integral + BuckReg.Proportion)/BuckReg.KI;
			BuckPIDFlag = 0;
		}
		else{;}
	}
	else if((BuckStepFlag)&&(BuckReg.MeasurePoint > 550)&&(BuckReg.MeasurePoint <= 600)&&(BuckPIDFlag != 5))
	{
		BuckReg.KP_Ratio = 2;/*KP = 2, Kp*Err = 400*/
		if(BuckPIDFlag != 5)
		{
			BuckReg.SumErr = (BuckReg.Integral + BuckReg.Proportion)/BuckReg.KI;
			BuckPIDFlag = 5;
		}
		else{;}
	}
	else if((BuckStepFlag)&&(BuckReg.MeasurePoint > 600)&&(BuckPIDFlag != 6))
	{
		BuckReg.KP_Ratio = 8;/*KP = 4, Kp*Err = 400*/
		if(BuckPIDFlag != 6)
		{
			BuckReg.SumErr = (BuckReg.Integral + BuckReg.Proportion)/BuckReg.KI;
			BuckPIDFlag = 6;
		}
		else{;}
	}
	else{;}
#endif

#if 1 //FIXME 2020年7月28日
    buck_duty =  (BuckReg.SetPoint/FCVoltage_fil)*FCVoltage_fil*0.5+buck_duty*0.5;
	/*欠压处理*/
	if((BuckReg.SetPoint==480)&&(BuckReg.MeasurePoint<=440)&&(buck_lessvol_flag==0)){
	    BuckReg.SumErr = buck_duty/BuckReg.KI;
	    buck_lessvol_flag = 1;
	}
	else{;}
    if((BuckReg.SetPoint==480)&&(BuckReg.MeasurePoint>=460)&&(buck_lessvol_flag==1)){
        buck_lessvol_flag = 0;
    }
    else{;}
    /*欠压处理*/

    /*过压处理*/
    if((BuckReg.MeasurePoint>=550)&&(buck_overvol_flag==0)){
        L_BUCKPWM_CMPENA_gui=0;           /*BUCK比较使能关闭*/
        DSP_WR_FPGAPWMReg();
        buck_overvol_flag = 1;
    }
    else{;}

    if((BuckReg.MeasurePoint<=530)&&(buck_overvol_flag==1)){
        L_BUCKPWM_CMPENA_gui=1;           /*BUCK比较使能关闭*/
        DSP_WR_FPGAPWMReg();
        buck_overvol_flag = 0;
    }
    else{;}
    /*过压处理*/
#endif
//    BuckReg.KP = A_ARMRDDSP_DEBUG46_gui*0.0001;
//    BuckReg.KI = A_ARMRDDSP_DEBUG45_gui*0.0001;
	BuckCtrl(&BuckReg);

	A_DSPWRFPGA_BUCKCMPR_gui = (unsigned int) (TPR_BUCK*BuckReg.OutputPoint/FCVoltage_fil);

	if(A_DSPWRFPGA_BUCKCMPR_gui <= 400)/*窄脉冲6us*/
	{
		A_DSPWRFPGA_BUCKCMPR_gui = 400;
	}
	else if(A_DSPWRFPGA_BUCKCMPR_gui >= TPR_BUCK - 400)
	{
		A_DSPWRFPGA_BUCKCMPR_gui = TPR_BUCK - 400;
	}
	else{;}

	A_DSPWRFPGA_BUCKCMPR_gui = TPR_BUCK - A_DSPWRFPGA_BUCKCMPR_gui;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_DSPWRFPGA_BUCKCMPR_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_FPGA_0060) = temp;

	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, 0, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_FPGA_0062) = temp;
}
/***********************************************************
*函数介绍：SVPWM角度调整函数，SVPWM跟踪SPLL角度，并发出接触器闭合命令
*输入参数：输出采集SPLL角度
*输出参数：SVPWM角度，接触器闭合命令
*返 回 值：无
***********************************************************/
void AngleModul(void)
{
	unsigned short temp = 0;
	if((AngleModuStart==0)&&(DQStart)&&(L_BL_master_judgment_gui==0)&&(UDPID.MeasurePoint>=270)\
			&&(UDPID.OutputPoint>=270)&&(UQPID.OutputPoint>=-10)&&(UQPID.OutputPoint<=10))
	{
		AngleModudelay++;
		if(AngleModudelay >= 6000)/*延时5s，方便从机获取主机频率信息*/
		{
			AngleModuStart = 1;
			AngleModudelay = 0;
		}
		else{;}

	}
	else{;}

	if((L_SIV_start_Comm_gui)&&(InvStartFlag))
	{
		AngleErr = SVPWMReg.RoAngle - SPLLReg.SpllAngle;
	}
	else
	{
		AngleErr = 0;
	}

	if(((ACU_DIN_gui&0x00000100)==0)&&(AngleModuStart)&&(SoftStart==0))
	{
		if(AngleErr >= 0.0003)
		{
			SVPWMReg.RoAngle -= AngleStep;
		}
		else{;}
		if(AngleErr <= -0.0003)
		{
			SVPWMReg.RoAngle += AngleStep;
		}
		else{;}

		if((AngleErr < 0.0003)&&(AngleErr > -0.0003))
		{
			SoftStop = 1;
		}
		else{;}

		if((SoftStop)&&(KM3ClsCmd==0))/*锁相成功后，寻求合适角度，发出接触器闭合命令*/
		{
			if((SPLLReg.SpllAngle <= (PI32 + AngleBC + TsComp*SIV_F*DOUBLE_PI))&&(SPLLReg.SpllAngle >= (PI32 - AngleBC + TsComp*SIV_F*DOUBLE_PI)))
		  	{
				/***************SIVCTT闭合指令给逻辑***************/
				A_ARMRDDSP_DEBUG1_gui = (unsigned int) (1);/*SIVCTT_Close_Slave == 1*/
				temp = 0;
				DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG1_gui, UNSIGNED16_HIGH_BYTE);
				HWREGH(DSP_To_ARM_12C0) = temp;
				temp = 0;
				DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG1_gui, UNSIGNED16_LOW_BYTE);
				HWREGH(DSP_To_ARM_12C2) = temp;
				/***************SIVCTT闭合指令给逻辑***************/


				/***************读取逻辑DO命令,DSP下发***************/
				temp = 0;
				temp = HWREGH(ARM_To_DSP_12E4);
				DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG10_gui, UNSIGNED16_HIGH_BYTE);
				temp = HWREGH(ARM_To_DSP_12E6);
				DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG10_gui, UNSIGNED16_LOW_BYTE);

		  		if((A_ARMRDDSP_DEBUG10_gui&0x00000800)==0x00000000)/*逻辑未发出接触器闭合命令，DSP接管下发*/
		  		{
		  		    A_ARMRDDSP_DEBUG10_gui|= 0x800;
		  		}
		  		else{;}

		  		KM3ClsCmd = 1;

		  		temp =(unsigned short)(A_ARMRDDSP_DEBUG10_gui&0xffff);
		  		DATA_INSERT_BOOLEAN(temp,  L_DSPWRFPGA_DOUTLOCALSTA3_gui,     3);
		  		DATA_INSERT_BOOLEAN(temp,  L_DSPWRFPGA_DOUTLOCALSTA8_gui,     8);
		  		DATA_INSERT_BOOLEAN(temp,  L_DSPWRFPGA_DOUTLOCALSTA9_gui,     9);
		  		DATA_INSERT_BOOLEAN(temp,  L_DSPWRFPGA_DOUTLOCALSTA10_gui,    10);
		  		DATA_INSERT_BOOLEAN(temp,  L_DSPWRFPGA_DOUTLOCALSTA11_gui,    11);
		  		DATA_INSERT_BOOLEAN(temp,  L_DSPWRFPGA_DOUTLOCALSTA12_gui,    12);
		  		HWREGH(DSP_To_FPGA_00E8) = temp;
		  		/***************读取逻辑DO命令,DSP下发***************/
		  	}
			else{;}
		}
		else{;}
	}
	else{;}
}
/***********************************************************************
*函数介绍：SVPWM控制函数，主、从机采用相同控制程序，分别控制UD和UQ
*输入参数：无
*输出参数：Alpha,Beta向量
*返 回 值：
***********************************************************************/
void SIVCtrl(double *Alpha, double *Beta)
{
	unsigned short temp = 0;
	PQDataCalc(&PQData,&Uun_fil);

//	SIV_V = 311 - QKV*PQData.SIV_Q - QKVD*(PQData.SIV_Q -  PQData.SIV_Q_Back);
//	SIV_F = 50.5 - PKF*PQData.SIV_P - PKFD*(PQData.SIV_P -  PQData.SIV_P_Back);

//    SIV_V = 311 - QKV*PQData.SIV_Q;// - PKV*PQData.SIV_P;
//    SIV_F = 50.5 - PKF*PQData.SIV_P;// + QKF*PQData.SIV_Q;

//	SIV_V = 311 - QKV*PQData.SIV_Q;
//	SIV_F = 50.5 - PKF*PQData.SIV_P;

//	SIV_V = 311 - A_ARMRDDSP_DEBUG48_gui*0.000001*PQData.SIV_Q - A_ARMRDDSP_DEBUG49_gui*0.000001*(PQData.SIV_Q -  PQData.SIV_Q_Back);
//	SIV_F = 50.5 - A_ARMRDDSP_DEBUG50_gui*0.000001*PQData.SIV_P - A_ARMRDDSP_DEBUG51_gui*0.000001*(PQData.SIV_P -  PQData.SIV_P_Back);

//    SIV_V = 311 - A_ARMRDDSP_DEBUG48_gui*0.000001*PQData.SIV_Q - A_ARMRDDSP_DEBUG49_gui*0.000001*PQData.SIV_P;
//    SIV_F = 50.5 - A_ARMRDDSP_DEBUG50_gui*0.000001*PQData.SIV_P + A_ARMRDDSP_DEBUG51_gui*0.000001*PQData.SIV_Q;

    SIV_V = 311 - 200*0.000001*PQData.SIV_Q - 500*0.000001*PQData.SIV_P;
    SIV_F = 50.5 - 10*0.000001*PQData.SIV_P + 15*0.000001*PQData.SIV_Q;

    PQData.SIV_Q_Back = PQData.SIV_Q;
	PQData.SIV_P_Back = PQData.SIV_P;

    if(L_BL_master_judgment_gui==0)/*从机频率设置*/
    {
    	if(SoftStart==0)
    	{
    		SIV_F = 50.5 - SPLLReg.uq_out_filter;/*接触器未吸合，从机以主机频率运行*/
//			SIV_F = 120000000/(A_DSPRDFPGA_INVVOUTFREQ_gui + A_DSPRDFPGA_INVWOUTFREQ_gui);/*接触器未吸合，从机以主机频率运行*/

			if(SIV_F >= 50.5)
			{
			 	SIV_F = 50.5;
			}
			else if(SIV_F <= 50)
			{
				SIV_F = 50;
			}
			else{;}
    	}
    }

	SVPWMReg.RoAngle += (double)(SIV_F * CarryFreq * 1.0);/*主、从机以相同频率运行*/

//    if(SysStart == 1)
//    {
//        if(L_BL_master_judgment_gui)
//        {
//            SVPWMReg.RoAngle += (double)(SIV_F * CarryFreq);/*主机*/
//        }
//        else/*从机*/
//        {
//            if(SoftStart==1)/*并联成功，切换成一套算法*/
//            {
//                SVPWMReg.RoAngle += (double)(SIV_F * CarryFreq);
//            }
//            else/*锁相跟踪阶段*/
//            {
//                SVPWMReg.RoAngle = SPLLReg.SpllAngle;
//            }
//        }
//    }

    AngleModul();

    switch (SoftStop) /*主、从机相位同步判断*/
    {
    	case 0:				/*主、从机相位未同步，或并联成功，从机以主机步进角度运行*/
    	{
//	    	if(SVPWMReg.RoAngle > DOUBLE_PI)
//	    	{
//	    		SVPWMReg.RoAngle -= DOUBLE_PI;
//	    	}
//	    	else if(SVPWMReg.RoAngle < 0)
//	    	{
//	    		SVPWMReg.RoAngle += DOUBLE_PI;
//	    	}
//	    	else{;}
//    		SVPWMReg.SinValue = sin(SVPWMReg.RoAngle);
//    		SVPWMReg.CosValue = cos(SVPWMReg.RoAngle);
    	}
    	break;

    	case 1:				/*主从机相位同步，分两种阶段*/
	    {
	    	if(SoftStart == 0)/*接触器延迟吸合期间，SVPWM角度微调或不调节*/
	    	{
	    		//SVPWMReg.RoAngle -= *Uqout*0.00104719755119659774615421446109;
	    	}
	    	else{;}

	    	if(KM3ClsCmd == 1)/*发出接触器KM3吸合命令，通过电流判断是否真正吸合*/
	    	{
	    		 if((Icurr_u_meas >= 5)||(Icurr_u_meas <= -5))/*冲击电流大于5A，认为接触器吸合*/
	    		 {
	    		       SoftStop  = 0;
	    		       SoftStart = 1;
	    		 }
	    		 else{;}
	    	}
	    	else{;}

//    		if(SVPWMReg.RoAngle > DOUBLE_PI)
//    		{
//    			SVPWMReg.RoAngle -= DOUBLE_PI;
//    		}
//    		else if(SVPWMReg.RoAngle < 0)
//    		{
//    			SVPWMReg.RoAngle += DOUBLE_PI;
//    		}
//    		else{;}
//    		SVPWMReg.SinValue = sin(SVPWMReg.RoAngle);
//    		SVPWMReg.CosValue = cos(SVPWMReg.RoAngle);
    	}
    	break;
   		default:break;
    }
    if(SVPWMReg.RoAngle > DOUBLE_PI)
    {
        SVPWMReg.RoAngle -= DOUBLE_PI;
    }
    else if(SVPWMReg.RoAngle < 0)
    {
        SVPWMReg.RoAngle += DOUBLE_PI;
    }
    else{;}

    SVPWMReg.SinValue = sin(SVPWMReg.RoAngle);
    SVPWMReg.CosValue = cos(SVPWMReg.RoAngle);


    switch(L_BL_master_judgment_gui)/*主、从机Ud控制*/
    {
    	case Slave:/*从机控制*/
    	{
    		switch(SoftStart)
    		{
    			case 0:/*接触器未吸合*/
    			{
    				if(L_Inverter_start_gui)/*系统正常启动*/
    				{
        				UDPID.MeasurePoint = 1.414213562373*Uun_Rms_fil;/*测量值*/
        				if(SysStart == 1)/*待锁相稳定后，逆变器软启动*/
        				{
        					if((UDPID.SetPoint < SPLLReg.UdpFilter)&&(UdStepFlag == 0))
        					{
        						UDPID.SetPoint += 0.05;
        					}
        					else
        					{
        						UDPID.SetPoint = SPLLReg.UdpFilter;
        						UdStepFlag = 1;
        					}
        				}
        				else{;}
    				}
    				else{;}
    			}
    			break;

    			case 1:/*接触器吸合*/
	    		{
	    			if(L_Inverter_start_gui)/*系统正常启动*/
	    			{
		    			UDPID.MeasurePoint = SPLLReg.UdpFilter;
		    			UDPID.SetPoint = SIV_V;
		    			Debug7++;
	    			}
	    			else{;}
	    		}
	    		break;

	    		default:break;
    		}
	   	}
	    break;

	    case Master:/*主机运行*/
	    {
	    	if((ACU_DIN_gui&0x00000100)==0x00000100)
	    	{
	    		if(L_Inverter_start_gui==1)/*系统正常启动*/
	    		{
	    			UDPID.MeasurePoint = SPLLReg.UdpFilter;
	    			if(L_AUX_TESTMODE_gui==0)
	    			{
	    				if((UDPID.SetPoint <= SIV_V)&&(UdStepFlag == 0))
	    				{
	    					UDPID.SetPoint += 0.05;
	    				}
	    				else
	    				{
	    					UDPID.SetPoint = SIV_V;
	    					UdStepFlag = 1;
	    		            Debug7++;
	    				}
	    			}
	    			else
	    			{
	    				UDPID.SetPoint += 0.02;
	    				if(UDPID.SetPoint >= 60)
	    				{
	    					UDPID.SetPoint = 60;
	    				}
	    				else{;}
	    			}
	    		}
	    		else{;}
	    	}
	    	else{;}
	    }
	    break;

	    default:break;
    }

	UDCtrl(&UDPID);

	if((((ACU_DIN_gui_last&0x00000100)==0x100)&&((ACU_DIN_gui&0x00000100)==0))\
	||(L_Inverter_start_gui==0))/*新增切除条件：两次接触器状态不一致，或L_Inverter_start_gui=0*/
	{
	   	UDPID.MeasurePoint = 0;/*控制变量清零复位*/
	   	UDPID.SetPoint = 0;
	   	UDPID.OutputPoint = UDPID.OutputPoint>=100?(UDPID.OutputPoint - 50):UDPID.OutputPoint;
		UQPID.MeasurePoint = 0;
	   	UQPID.OutputPoint = 0;

	   	L_PWM_CMPENA_gui = 0;/*关闭比较使能*/
		DSP_WR_FPGAPWMReg();

		A_PWM_CMPU_gui = 0xffffffff; /*初始化比较寄存器1*/
		A_PWM_CMPV_gui = 0xffffffff; /*初始化比较寄存器2*/
		A_PWM_CMPW_gui = 0xffffffff; /*初始化比较寄存器3*/

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

		temp = HWREGH(ARM_To_DSP_12E4);
		DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG10_gui, UNSIGNED16_HIGH_BYTE);
		temp = HWREGH(ARM_To_DSP_12E6);
		DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG10_gui, UNSIGNED16_LOW_BYTE);
	}

	ACU_DIN_gui_last = ACU_DIN_gui;/*判断两次接触器状态*/

	if(L_AUX_TESTMODE_gui)/*启动初始值*/
	{
		UDPID.OutputPoint = UDPID.OutputPoint<=20?20:UDPID.OutputPoint;
	}
	else
	{
		UDPID.OutputPoint = UDPID.OutputPoint<=50?50:UDPID.OutputPoint;
	}

	*Alpha = UDPID.OutputPoint * SVPWMReg.CosValue - UQPID.OutputPoint * SVPWMReg.SinValue;
	*Beta = UDPID.OutputPoint * SVPWMReg.SinValue + UQPID.OutputPoint * SVPWMReg.CosValue;

//	*Alpha = UDPID.OutputPoint * SVPWMReg.CosValue;
//	*Beta = UDPID.OutputPoint * SVPWMReg.SinValue;
}
/***********************************************************
*函数介绍：双DQ变换锁相
*输入参数：三相UVW相电压
*输出参数：SVPWM矢量旋转角度SpllAngle
*返 回 值：无
***********************************************************/
void SPLL(SPLLPARASTRUCT *p)
{
	if(DQStart == 1)
	{
		if((ACU_DIN_gui&0x00000100)==0x00000100)
		{
			p->Ualpha = 0.666666666*Uun_fil - 0.333333333*Uvn_fil - 0.333333333*Uwn_fil;
			p->Ubeta = 0.577350269189*Uvn_fil - 0.577350269*Uwn_fil;
		}
		else if((ACU_DIN_gui&0x00000100)==0)
		{
//		    square_rms = Uwn_Rms_fil*Uwn_Rms_fil - 48360.5;
//		    Uvw_bias = square_rms>=0?sqrt(square_rms):0;
//		    Uvw_fltr = 0.01*Uuvw_fil + 0.99*Uuvw_fil;
//		    Uvw_bias = Uvw_fltr>0?(Uvw_bias):(0-Uvw_bias);
//
//            Uuvw_fil = 3*Uvw_bias - (Uvn_fil+Uwn_fil);
//		    p->Ualpha = 0.666666666*Uuvw_fil - 0.333333333*Uvn_fil - 0.333333333*Uwn_fil;
//			p->Ubeta = 0.577350269189*Uvn_fil - 0.577350269*Uwn_fil;

            p->Ubeta = 0.577350269189*Uvn_fil - 0.577350269*Uwn_fil;
            sogi_hq_reg.U_K = p->Ubeta;
            sogi_hq(&sogi_hq_reg);
            p->Ualpha = 0 - sogi_hq_reg.Y_K;
		}
		else{;}

		p->Udp = p->sinwt * p->Ubeta  + p->coswt * p->Ualpha;
		p->Uqp = p->coswt * p->Ubeta  - p->sinwt * p->Ualpha;
		p->Udn = p->coswt * p->Ualpha - p->sinwt * p->Ubeta;
		p->Uqn = p->coswt * p->Ubeta  + p->sinwt * p->Ualpha;

		p->UdpDpl = p->Udp - p->UqnFilter*p->sindwt - p->UdnFilter*p->cosdwt;
		p->UdpFilter = FilterPara*(p->UdpDpl - p->UdpFilter) + p->UdpFilter;
		
		p->UqpDpl = p->Uqp - p->UqnFilter*p->cosdwt + p->UdnFilter*p->sindwt;
		p->UqpFilter = FilterPara*(p->UqpDpl - p->UqpFilter) + p->UqpFilter;

		p->UdnDpl = p->Udn - p->UdpFilter*p->cosdwt + p->UqpFilter*p->sindwt;
		p->UdnFilter = FilterPara*(p->UdnDpl - p->UdnFilter) + p->UdnFilter;
		
		p->UqnDpl = p->Uqn - p->UdpFilter*p->sindwt - p->UqpFilter*p->cosdwt;
		p->UqnFilter = FilterPara*(p->UqnDpl - p->UqnFilter) + p->UqnFilter;

       	UQPID.MeasurePoint = p->UqpDpl;
       	UQCtrl(&UQPID);

      	Uqout = 0.999*(Uqout - UQPID.OutputPoint) + UQPID.OutputPoint;
        slide_cnt++;
        if((slide_cnt%6)==0)
        {
            slide_cnt = 0;
            p->uq_out_filter = slide_filter(&Uqout);
        }
        else{;}

       	p->Angle += CarryFreq*(50.5 - UQPID.OutputPoint);

       	if(p->Angle >= DOUBLE_PI)
        {
        	p->Angle -= DOUBLE_PI;
        }
		else if(p->Angle<=0)
        {
			p->Angle += DOUBLE_PI;
        }
        else{;}
        p->sinwt = sin(p->Angle);
        p->coswt = cos(p->Angle);

        p->DoubleAngle = p->Angle + p->Angle;
        if(p->DoubleAngle >= DOUBLE_PI)
        {
        	p->DoubleAngle -= DOUBLE_PI;
        }
		else if(p->DoubleAngle<=0)
        {
			p->DoubleAngle += DOUBLE_PI;
        }
        else{;}

        p->sindwt = sin(p->DoubleAngle);
        p->cosdwt = cos(p->DoubleAngle);

//        p->SpllAngle = p->Angle + AngleBC;
//       	p->SpllAngle = p->Angle + (double)A_ARMRDDSP_DEBUG47_gui*1e-3 - 1;
        p->SpllAngle = p->Angle + (double)1015*1e-3 - 1;
		if(p->SpllAngle > DOUBLE_PI)
        {
            p->SpllAngle -= DOUBLE_PI;
        }
        else if(p->SpllAngle < 0)
        {
            p->SpllAngle -= DOUBLE_PI;
        }
        else{;}
	}
	else
	{
		//ParaVarZero();
        SPLLReg = SPLLRegRst;

        UDPID = UDPIDRst;
        UQPID = UQPIDRst;
//        UDFivePID = UDFivePIDRst;
//        UQFivePID = UQFivePIDRst;
//        UDSevenPID = UDSevenPIDRst;
//        UQSevenPID = UQSevenPIDRst;
//        PQData      = PQDataRst;
        sogi_hq_reg = sogi_hq_reg_rst;

        slide_cnt = 0;
        FreqCnt = 0;
        memset(xBuf, 0,  20);
	}

	if((p->Angle>=0)&&(p->Angle <= SysStartAngel)&&(L_BL_master_judgment_gui==0)\
	&&(L_SIV_start_Comm_gui)&&(InvStartFlag)&&(L_Inverter_start_gui)&&(SPLLReg.UdpFilter>=295)&&(SysStart==0))/*从机启动时刻，减少锁相时间*/
	{
		SysStart = 1;
		SVPWMReg.RoAngle = SPLLReg.SpllAngle;
	}
	else{;}
	if((L_BL_master_judgment_gui)&&(L_SIV_start_Comm_gui)&&(InvStartFlag)&&(L_Inverter_start_gui))
	{
		SysStart = 1;
	}
	else{;}
}
/***********************************************************
*函数介绍：功率计算函数，滑窗定义法计算，采样频率18kHz
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
void PQDataCalc(PQCALCSTRUCT *p,double *Uin)
{
	unsigned short temp = 0;
	unsigned short temp1 = 0;
	if(*Uin <= -100)
	{
		L_Juzero_gui = 1;
	}
	else{;}
	if(*Uin >= 100)
	{
		L_Juzero_gui = 0;
	}
	else{;}
	
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

	temp = HWREGH(FPGA_To_DSP_00C8);
	DATA_INSERT_UNSIGNED32(temp, L_FPGATODSP_Usin_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(FPGA_To_DSP_00CA);
	DATA_INSERT_UNSIGNED32(temp, L_FPGATODSP_Usin_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(FPGA_To_DSP_00CC);
	DATA_INSERT_UNSIGNED32(temp, L_FPGATODSP_Ucos_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(FPGA_To_DSP_00CE);
	DATA_INSERT_UNSIGNED32(temp, L_FPGATODSP_Ucos_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(FPGA_To_DSP_00D0);
	DATA_INSERT_UNSIGNED32(temp, L_FPGATODSP_Isin_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(FPGA_To_DSP_00D2);
	DATA_INSERT_UNSIGNED32(temp, L_FPGATODSP_Isin_gui, UNSIGNED16_LOW_BYTE);

	temp = HWREGH(FPGA_To_DSP_00D4);
	DATA_INSERT_UNSIGNED32(temp, L_FPGATODSP_Icos_gui, UNSIGNED16_HIGH_BYTE);
	temp = HWREGH(FPGA_To_DSP_00D6);
	DATA_INSERT_UNSIGNED32(temp, L_FPGATODSP_Icos_gui, UNSIGNED16_LOW_BYTE);

//	float*Ui = (float*)&L_FPGATODSP_Usin_gui;
//	p->Ui = (double)(*Ui*0.0001790959235);
//
//	float*Ur = (float*)&L_FPGATODSP_Ucos_gui;
//	p->Ur = (double)(*Ur*0.0001790959235);
//
//	float*Ii = (float*)&L_FPGATODSP_Isin_gui;
//	p->Ii = (double)(*Ii*0.00005595833325);
//
//	float*Ir = (float*)&L_FPGATODSP_Icos_gui;
//	p->Ir = (double)(*Ir*0.00005595833325);

	/*FPGA功率计算程序替换为18kHz*/
	float*Ui = (float*)&L_FPGATODSP_Usin_gui;
	p->Ui = (double)(*Ui*0.000716383694);

	float*Ur = (float*)&L_FPGATODSP_Ucos_gui;
	p->Ur = (double)(*Ur*0.000716383694);

	float*Ii = (float*)&L_FPGATODSP_Isin_gui;
	p->Ii = (double)(*Ii*4.476667e-4);

	float*Ir = (float*)&L_FPGATODSP_Icos_gui;
	p->Ir = (double)(*Ir*4.476667e-4);
	/*FPGA功率计算程序替换为18kHz*/

	p->SIV_P = 6*(p->Ur*p->Ir + p->Ui*p->Ii);
	p->SIV_Q = 6*(p->Ur*p->Ii - p->Ui*p->Ir);

	p->SIV_PFil = 0.5*(p->SIV_PFil - p->SIV_P) + p->SIV_P;
	p->SIV_QFil = 0.5*(p->SIV_QFil - p->SIV_Q) + p->SIV_Q;

	p->SIV_Power = sqrt(p->SIV_P*p->SIV_P + p->SIV_Q*p->SIV_Q);
}
/***********************************************************
*函数介绍：SVPWM调制函数
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
void SvpwmModule(SVPWMPARASTRUCT *p)
{
	if((SysStart==1)&&(L_Inverter_start_gui==1))
	{
		Mytype_float64 temp_t1,temp_t2,temp_tk;
        Mytype_float64 Cmp0,Cmp1,Cmp2,temp;
		
        p->su = p->Beta;
	   	p->sv = 0.8660254*p->Alpha - 0.5*p->Beta;
	   	p->sw = 0-0.8660254*p->Alpha - 0.5*p->Beta;
	   	if(p->su>0){p->sa=1;}else { p->sa=0;}
	   	if(p->sv>0){p->sb=2;}else { p->sb=0;}
	   	if(p->sw>0){p->sc=4;}else { p->sc=0;}
        p->Sector = p->sa + p->sb + p->sc;
        switch(p->Sector)
        {
        	case 1:/*N = 2*/
            {
            	p->CMPT1 = (0.8660254*p->Beta-1.5*p->Alpha)*TIMER_ft/DCDCOutVol_meas;//DCDCOutVol_meas
                p->CMPT2 = (0.8660254*p->Beta+1.5*p->Alpha)*TIMER_ft/DCDCOutVol_meas;
                if(p->CMPT1 <= 0){p->CMPT1 = 5;}
                if(p->CMPT2 <= 0){p->CMPT2 = 5;}
                if((p->CMPT1 + p->CMPT2) > TIMER_ft)
                {
	            	temp_t1 = p->CMPT1;
	            	temp_t2 = p->CMPT2;
	            	temp_tk = TIMER_ft/(temp_t1+temp_t2);
	            	p->CMPT1 = temp_t1*temp_tk;
	            	p->CMPT2 = temp_t2*temp_tk;
                }
                Cmp0=(unsigned int)(TIMER_ft- p->CMPT1 - p->CMPT2)*0.5;
                Cmp1=(unsigned int)p->CMPT1;
                Cmp2=(unsigned int)p->CMPT2;
				p->temp_cmu = Cmp0+Cmp1;
	       	    p->temp_cmv = Cmp0;
	       	    p->temp_cmw = Cmp0+Cmp1+Cmp2;
            }
            break;

            case 2:/*N = 6*/
            {
               	p->CMPT1 = (0.8660254*p->Beta+1.5*p->Alpha)*TIMER_ft/DCDCOutVol_meas;
            	p->CMPT2 = (0-1.7320508*p->Beta)*TIMER_ft/DCDCOutVol_meas;
				if(p->CMPT1 <= 0){p->CMPT1 = 5;}
				if(p->CMPT2 <= 0){p->CMPT2 = 5;}
                if((p->CMPT1+p->CMPT2) > TIMER_ft)
                {
	            	temp_t1 = p->CMPT1;
	            	temp_t2 = p->CMPT2;
	            	temp_tk = TIMER_ft/(p->CMPT1 + p->CMPT2);
	            	p->CMPT1 = temp_t1*temp_tk;
	            	p->CMPT2 = temp_t2*temp_tk;
                }
                Cmp0=(unsigned int)(TIMER_ft - p->CMPT1 - p->CMPT2)*0.5;
                Cmp1=(unsigned int)p->CMPT1;
                Cmp2=(unsigned int)p->CMPT2;
				p->temp_cmu = Cmp0;
	     	    p->temp_cmv = Cmp0+Cmp1+Cmp2;
	     	    p->temp_cmw = Cmp0+Cmp1;
            }
            break;

            case 3:/*N = 1*/
            {
                p->CMPT1 = (1.5* p->Alpha-0.8660254* p->Beta)*TIMER_ft/DCDCOutVol_meas;
            	p->CMPT2 = (1.7320508* p->Beta)*TIMER_ft/DCDCOutVol_meas;
				if(p->CMPT1 <= 0){p->CMPT1 = 5;}
                if(p->CMPT2 <= 0){p->CMPT2 = 5;}
                if((p->CMPT1+p->CMPT2) > TIMER_ft)
                {
	            	temp_t1 = p->CMPT1;
	            	temp_t2 = p->CMPT2;
	            	temp_tk = TIMER_ft/(p->CMPT1 + p->CMPT2);
	            	p->CMPT1 = temp_t1*temp_tk;
	            	p->CMPT2 = temp_t2*temp_tk;
                }
                Cmp0=(unsigned int)(TIMER_ft - p->CMPT1 - p->CMPT2)*0.5;
                Cmp1=(unsigned int)p->CMPT1;
                Cmp2=(unsigned int)p->CMPT2;
				p->temp_cmu = Cmp0;
	     	    p->temp_cmv = Cmp0+Cmp1;
	     	    p->temp_cmw = Cmp0+Cmp1+Cmp2;
            }
            break;

            case 4:/*N = 4*/
            {
                p->CMPT1 =(0-1.7320508*p->Beta)*TIMER_ft/DCDCOutVol_meas;
            	p->CMPT2 =(0.8660254*p->Beta-1.5*p->Alpha)*TIMER_ft/DCDCOutVol_meas;
                if(p->CMPT1 <= 0){p->CMPT1 = 5;}
             	if(p->CMPT2 <= 0){p->CMPT2 = 5;}
             	if((p->CMPT1+p->CMPT2) > TIMER_ft)
             	{
	         		temp_t1 = p->CMPT1;
	         		temp_t2 = p->CMPT2;
	         		temp_tk = TIMER_ft/(p->CMPT1 + p->CMPT2);
	         		p->CMPT1 = temp_t1*temp_tk;
	         		p->CMPT2 = temp_t2*temp_tk;
             	}
             	Cmp0=(unsigned int)(TIMER_ft - p->CMPT1 - p->CMPT2)*0.5;
             	Cmp1=(unsigned int)p->CMPT1;
             	Cmp2=(unsigned int)p->CMPT2;
             	p->temp_cmu = Cmp0+Cmp1+Cmp2;
	     	    p->temp_cmv = Cmp0+Cmp1;
	     	    p->temp_cmw = Cmp0;
            }
            break;

            case 5:/*N = 3*/
            {
                p->CMPT1 = (1.73205080*p->Beta)*TIMER_ft/DCDCOutVol_meas;
            	p->CMPT2 = (0-0.8660254*p->Beta-1.5*p->Alpha)*TIMER_ft/DCDCOutVol_meas;
                if(p->CMPT1 <= 0){p->CMPT1 = 5;}
                if(p->CMPT2 <= 0){p->CMPT2 = 5;}
                if((p->CMPT1+p->CMPT2) > TIMER_ft)
                {
                	temp_t1 = p->CMPT1;
	               	temp_t2 = p->CMPT2;
	               	temp_tk = TIMER_ft/(p->CMPT1 + p->CMPT2);
	               	p->CMPT1 = temp_t1*temp_tk;
	               	p->CMPT2 = temp_t2*temp_tk;
                }
                Cmp0 = (unsigned int)(TIMER_ft - p->CMPT1 - p->CMPT2)*0.5;
                Cmp1 = (unsigned int)p->CMPT1;
                Cmp2 = (unsigned int)p->CMPT2;
				p->temp_cmu = Cmp0+Cmp1+Cmp2;
				p->temp_cmv = Cmp0;
				p->temp_cmw = Cmp0+Cmp1;
            }
            break;

            case 6:/*N = 5*/
            {
                 p->CMPT1 = (0 - 0.8660254*p->Beta - 1.5*p->Alpha)*TIMER_ft/DCDCOutVol_meas;
	     	 	 p->CMPT2 = (1.5*p->Alpha - 0.8660254*p->Beta)*TIMER_ft/DCDCOutVol_meas;
                 if(p->CMPT1 <= 0){p->CMPT1 = 5;}
             	 if(p->CMPT2 <= 0){p->CMPT2 = 5;}
             	if((p->CMPT1+p->CMPT2) > TIMER_ft)
              	  {
             		 temp_t1 = p->CMPT1;
	               	 temp_t2 = p->CMPT2;
	               	 temp_tk = TIMER_ft/(p->CMPT1 + p->CMPT2);
	               	 p->CMPT1 = temp_t1*temp_tk;
	               	 p->CMPT2 = temp_t2*temp_tk;
                  }
                  Cmp0 = (unsigned int)(TIMER_ft - p->CMPT1 - p->CMPT2)*0.5;
                  Cmp1 = (unsigned int)p->CMPT1;
                  Cmp2 = (unsigned int)p->CMPT2;
                  p->temp_cmu = Cmp0+Cmp1;
	     	      p->temp_cmv = Cmp0+Cmp1+Cmp2;
	     	      p->temp_cmw = Cmp0;
             }
             break;
             default:{break;}
        }
		if(p->temp_cmu > TIMER_ft) p->temp_cmu = TIMER_ft-TDB;
	 	else if(p->temp_cmu < TDB) p->temp_cmu = TDB;

	 	if(p->temp_cmv > TIMER_ft) p->temp_cmv = TIMER_ft-TDB;
	 	else if(p->temp_cmv < TDB) p->temp_cmv = TDB;

	 	if(p->temp_cmw > TIMER_ft) p->temp_cmw = TIMER_ft-TDB;
	 	else if(p->temp_cmw < TDB) p->temp_cmw = TDB;

	 	/*-----------------数据写入-----------------------------------*/
	 	A_PWM_CMPU_gui = p->temp_cmu;
	 	A_PWM_CMPV_gui = p->temp_cmv;
	 	A_PWM_CMPW_gui = p->temp_cmw;

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
		}
		else{;}
}
/***********************************************************
*函数介绍：
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
void UQCtrl(UQPIDPARASTRUCT *p)
{
	p->Err = p->SetPoint - p->MeasurePoint;
	p->SumErr += p->Err;
	p->Integral = p->KI*p->SumErr;
	if(p->Integral>= p->UpLimit)
	{
		p->Integral = p->UpLimit;
	}
	else if(p->Integral<=p->DownLimit)
	{
		p->Integral = p->DownLimit;
	}
	else{;}
	p->Proportion = p->KP*p->Err;
	p->Derivative = p->KD*(p->Err - p->BackErr);
	p->BackErr = p->Err;
	p->Proportion = p->KP*p->Err;
	p->Derivative = p->KD*(p->Err - p->BackErr);
	p->BackErr = p->Err;

	p->OutputPoint = p->Proportion + p->Integral + p->Derivative;
	if(p->OutputPoint>=p->UpLimit)
	{
		p->OutputPoint = p->UpLimit;
	}
	else if(p->OutputPoint<=p->DownLimit)
	{
		p->OutputPoint = p->DownLimit;
	}
	else{;}
}
/***********************************************************
*函数介绍：
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
void UDCtrl(UDPIDPARASTRUCT *p)
{
	p->Err = p->SetPoint - p->MeasurePoint;
	p->SumErr += p->Err;
	if(p->SumErr <= p->DownLimit)
	{
		p->SumErr = p->DownLimit;
	}
	else{;}
	p->Integral = p->KI*p->SumErr;
	if(p->Integral>= p->UpLimit)
	{
		p->Integral = p->UpLimit;
	}
	else if(p->Integral<=p->DownLimit)
	{
		p->Integral = p->DownLimit;
	}
	else{;}
	p->Proportion = p->KP*p->Err;
	p->Derivative = p->KD*(p->Err - p->BackErr);
	p->BackErr = p->Err;
	p->OutputPoint = p->Proportion + p->Integral + p->Derivative;
	if(p->OutputPoint>=p->UpLimit)
	{
		p->OutputPoint = p->UpLimit;
	}
	else if(p->OutputPoint<=p->DownLimit)
	{
		p->OutputPoint = p->DownLimit;
	}
	else{;}
}
/***********************************************************
*函数介绍：Buck PID控制函数
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
void BuckCtrl(BUCKPARASTRUCT *p)
{
	p->Err = p->SetPoint - p->MeasurePoint;
	p->SumErr += p->Err;
	if(p->SumErr <= p->DownLimit)
	{
		p->SumErr = p->DownLimit;
	}
	else{;}
	p->Integral = p->KI*p->SumErr;
	if(p->Integral>= p->UpLimit)
	{
		p->Integral = p->UpLimit;
	}
	else if(p->Integral<=p->DownLimit)
	{
		p->Integral = p->DownLimit;
	}
	else{;}
	p->Proportion = p->KP*p->KP_Ratio*p->Err;
	p->Derivative = p->KD*p->KD_Ratio*(p->Err - p->BackErr);
	p->BackErr = p->Err;

	p->OutputPoint = p->Proportion + p->Integral + p->Derivative;
	if(p->OutputPoint>=p->UpLimit)
	{
		p->OutputPoint = p->UpLimit;
	}
	else if(p->OutputPoint<=p->DownLimit)
	{
		p->OutputPoint = p->DownLimit;
	}
	else{;}
}
/***********************************************************
*函数介绍：DCDC控制函数
*输入参数：
*输出参数：
*返 回 值：
***********************************************************/
void DCDCCtrl(DCDCPARASTRUCT *p)
{
	p->Err = p->SetPoint - p->MeasurePoint;
	p->SumErr += p->Err;
	if(p->SumErr <= p->DownLimit)
	{
		p->SumErr = p->DownLimit;
	}
	else{;}
	p->Integral = p->KI*p->SumErr;
	if(p->Integral>= p->UpLimit)
	{
		p->Integral = p->UpLimit;
	}
	else if(p->Integral<=p->DownLimit)
	{
		p->Integral = p->DownLimit;
	}
	else{;}
	p->Proportion = p->KP*p->KP_Ratio*p->Err;
	p->Derivative = p->KD*p->KD_Ratio*(p->Err - p->BackErr);
	p->BackErr = p->Err;

	p->OutputPoint = p->Proportion + p->Integral + p->Derivative;
	if(p->OutputPoint>=p->UpLimit)
	{
		p->OutputPoint = p->UpLimit;
	}
	else if(p->OutputPoint<=p->DownLimit)
	{
		p->OutputPoint = p->DownLimit;
	}
	else{;}
}
/***********************************************************
*函数介绍：常态下行过程中，出现IGBT故障、网压欠压故障、网络切除故障、停止命令安全退出
*输入参数：无
*输出参数：无
*返 回 值：无
***********************************************************/
void SivCutoff(void)
{
	unsigned short temp = 0;

	if(((A_DSPRDFPGA_FPGACHECKFAULT_gui&0x3FBF)!=0)||(L_SIVCTT_open_Req_Acc_gui)\
	 ||((ACU_DIN_gui&0x20)==0x20)||((NetVoltage_fil <= 480)&&(L_AUX_TESTMODE_gui==0))||((A_ARMRDDSP_DEBUG41_gui&0x01)==0x01)\
	 ||(L_Inverter_start_gui==0)||(L_System_Ready_gui==0))
	{
		L_Inverter_start_gui = 0;/*by Jason@2017年11月9日17:59:20*/

		L_PWM_CMPENA_gui = 0;
		DSP_WR_FPGAPWMReg();

		A_PWM_CMPU_gui = 0xffffffff; /*初始化比较寄存器1*/
		A_PWM_CMPV_gui = 0xffffffff; /*初始化比较寄存器2*/
		A_PWM_CMPW_gui = 0xffffffff; /*初始化比较寄存器3*/

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

		temp = HWREGH(ARM_To_DSP_12E4);
		DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG10_gui, UNSIGNED16_HIGH_BYTE);
		temp = HWREGH(ARM_To_DSP_12E6);
		DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG10_gui, UNSIGNED16_LOW_BYTE);

		/*读取逻辑DO输出*/

		if((A_ARMRDDSP_DEBUG10_gui&0x00000800)==0x00000800)
		{
			A_ARMRDDSP_DEBUG10_gui &= 0xfffff7ff;
		}
		else{;}

		DATA_EXTRACT_BOOLEAN(A_ARMRDDSP_DEBUG10_gui,  L_DSPRDFPGA_DOUTLOCALSTA3_gui,    3);
		DATA_EXTRACT_BOOLEAN(A_ARMRDDSP_DEBUG10_gui,  L_DSPRDFPGA_DOUTLOCALSTA8_gui,    8);
		DATA_EXTRACT_BOOLEAN(A_ARMRDDSP_DEBUG10_gui,  L_DSPRDFPGA_DOUTLOCALSTA9_gui,    9);	    /*KCH*/
		DATA_EXTRACT_BOOLEAN(A_ARMRDDSP_DEBUG10_gui,  L_DSPRDFPGA_DOUTLOCALSTA10_gui,   10);	/*CTT*/
		DATA_EXTRACT_BOOLEAN(A_ARMRDDSP_DEBUG10_gui,  L_DSPRDFPGA_DOUTLOCALSTA11_gui,   11);	/*SIVCTT*/
		DATA_EXTRACT_BOOLEAN(A_ARMRDDSP_DEBUG10_gui,  L_DSPRDFPGA_DOUTLOCALSTA12_gui,   12);	/*KM4*/

		temp = 0;
		DATA_INSERT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA3_gui,     3);
		DATA_INSERT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA8_gui,     8);
		DATA_INSERT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA9_gui,     9);
		DATA_INSERT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA10_gui,    10);
		DATA_INSERT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA11_gui,    11);
		DATA_INSERT_BOOLEAN(temp,  L_DSPRDFPGA_DOUTLOCALSTA12_gui,    12);
		HWREGH(DSP_To_FPGA_00E8) = temp;
	}

	A_ARMRDDSP_DEBUG6_gui = L_Inverter_start_gui&0x01;/*InverterStartCmd==0*/

	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG6_gui, UNSIGNED16_HIGH_BYTE);
	HWREGH(DSP_To_ARM_12D4) = temp;
	temp = 0;
	DATA_EXTRACT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG6_gui, UNSIGNED16_LOW_BYTE);
	HWREGH(DSP_To_ARM_12D6) = temp;
}
/***********************************************************
*函数介绍：
*输入参数：无
*输出参数：无
*返 回 值：无
***********************************************************/
void sogi_hq(sogi_hq_struct *p)
{
    p->Y_K = p->cofA* p->U_K +  p->cofB *  p->U_K_1 + p->cofC * p->U_K_2 - p->cofD *p->Y_K_1 - p->cofE * p->Y_K_2;
    p->Y_K_2 = p->Y_K_1;
    p->Y_K_1 = p->Y_K;
    p->U_K_2 = p->U_K_1;
    p->U_K_1 = p->U_K;
}


/*********************************************************************
Copyright (c),2002-2017,Sifang Rolling Stock Research Institute Ltd.
*File Name:    main.c
*Author:       JasonLee
*Date:         2017.09.18
*Version:      V4.0
*Description:  main function source files
*Modification history:
    1.Jason, 2017.9.18, first issue;
    2.JasonLee, 2018.1.26, second issue
**********************************************************************/

#include "hw_types.h"
#include "soc_C6748.h"
#include "hw_syscfg0_C6748.h"
#include "user_main.h"
#include "user_syscfg.h"
#include "user_cache.h"
#include "user_dspintc.h"
#include "user_edma3.h"
#include "user_emifa.h"
#include "user_gpio.h"
#include "user_variable.h"
#include "interrupt.h"
#include "gpio.h"
#include "delay.h"
#include "algorithm.h"
#include "math.h"
#include "user_record.h"
#include "user_interface.h"
#include "user_sysglobalvar.h"

/************************************************************************
                    Global Variable Definitions
************************************************************************/

OPERATE_TYPE 	OperateMode_gui = OM_INITING;

unsigned int ModeState = 0;


/************************************************************************
                    Main  Function  Definitions
************************************************************************/

static void OM_Initing(void)
{
   if(OperateMode_gui != OM_INITING)
   {
   	return;
   }

   CACHE_DISABLE();
   EMIFA_Init();
   EDMA3_Init();
   GPIO_Init();
   DSPINTC_Init();
   OperateMode_gui = OM_SELFTEST;
}

static void OM_SelfTest(void)
{
  if(OperateMode_gui != OM_SELFTEST)
  {
    return;
  }
  OperateMode_gui = OM_NORMAL;
  DSPINTC_Normal_Open();
}

static void Device_PreOperate(void)
{
  if(OperateMode_gui != OM_NORMAL)
  {
    return;
  }
  CACHE_ENABLE();
}


void main(void)
{
  unsigned int tempcnt = 0;
  while(1)
  {
	  switch(ModeState)
      {
      		case 0:                             /*ϵͳ��ʼ��*/
    	 	{
    	    	OM_Initing();                   /*��ʼ��,��FLASH��Ϣ����С���汾��Ϣ;�����һ��ûд�ɹ���Ӧ��ʾδ���سɹ�*/
    	    	OM_SelfTest();            		/*�Բ��ԣ�����*/
    	    	Device_PreOperate();            /*CACHE��ʼ��*/
    	    	ParaVarZero();                  /*��ʼ������*/
	        	FPGA_Init();					/*FPGA��ʼ������*/
	        	InitBuckMdl();
	        	InitDCDCMdl();
	        	InitInvMdl();
	        	DSP_Send_DRAM_FPGAData();

				/********************�ȴ�Timer����**********************/
	        	if(SysCnt != 0)
	        	{
	        		ModeState = 1;
	        	}
				else{;}
     	  	}
   	     	break;

      		case 1:
   	   	  	{
				/******************������ʱ����ֹ����ģ�����ɼ�����***************/

   	   	  		if(DQcnt < 150)
   	   	  		{
   	   	  			DQcnt++;
   	   	  		}
   	   	  		else
   	   	  		{
   	   	  			if(L_BL_master_judgment_gui)
   	   	  			{
   	   	  				DQStart = 1;
   	   	  			}
   	   	  			else if((L_BL_master_judgment_gui==0)&&(Uvn_fil >= 280))
   	   	  			{
   	   	  				DQStart = 1;
   	   	  			}
   	   	  			else{;}
   	   	  		}
   	   	  		if(L_System_Ready_gui==0)
   	   	  		{
   	   	  			DQStart = 0;
   	   	  		}
   	   	  		else{;}
				/****************************����������***************************/
	        	DSP_Get_DRAM_ARMData();
	        	DSP_Get_DRAM_FPGAData();
    	    	if((L_BUCK_start_Comm_gui==1)&&(BuckStartFlag==0))
				{
    	    		StartBuckMdl();
				}
    	    	else{;}
   	    		if(L_BUCK_start_Comm_gui==0)
				{
   	    			StopBuckMdl();
   	    			InitBuckMdl();
				}
   	    		else{;}
   	    		/******************************************************************/
    	    	if((L_DCDC_start_Comm_gui==1)&&(DCDCStartFlag==0))
				{
    	    		StartDCDCMdl();
				}
    	    	else{;}
   	    		if(L_DCDC_start_Comm_gui==0)
				{
   	    			StopDCDCMdl();
					InitDCDCMdl();
				}
   	    		else{;}
   	    		/******************************************************************/
   	        	if((L_SIV_start_Comm_gui==1)&&(InvStartFlag==0))
				{
   	        		StartInvMdl();
				}
   	        	else{;}
   	       		if((L_SIV_start_Comm_gui==0)&&(L_INV_PWMENA_gui==0))
				{
   	       			StopInvMdl();
					InitInvMdl();
				}
   	       		else{;}
   	       		/******************************************************************/
   	       	    A_ARMRDDSP_REVREG_gui = 9111939;

   	       		RecordData_Write_DSP();   /*��ȡ��������*/
   	       	 	DSP_Send_DRAM_ARMData();
   	        	DSP_Send_DRAM_FPGAData();

   	        	tempcnt++;
   	        	A_ARMRDDSP_DEBUG3_gui=(unsigned int) (PQData.SIV_P + 100000);
   	          	A_ARMRDDSP_DEBUG4_gui=(unsigned int) (PQData.SIV_Q + 100000);
   	          	A_ARMRDDSP_DEBUG5_gui=(unsigned int) (PQData.SIV_Power);
   	          	/***********************�߼����ĺ������ƣ�20msִ������***************/
   	        	while(SysCnt < 80)  {;} /*20ms��ʱ�ȴ�*/
   	        	SysCnt = 0;
   	   	  	}
            break;

       		default:break;
    	}
  	}
}
/********************************* End of file *******************************/

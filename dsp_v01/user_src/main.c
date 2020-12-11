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
      		case 0:                             /*系统初始化*/
    	 	{
    	    	OM_Initing();                   /*初始化,读FLASH信息、大小、版本信息;如果上一次没写成功，应提示未下载成功*/
    	    	OM_SelfTest();            		/*自测试，保留*/
    	    	Device_PreOperate();            /*CACHE初始化*/
    	    	ParaVarZero();                  /*初始化函数*/
	        	FPGA_Init();					/*FPGA初始化设置*/
	        	InitBuckMdl();
	        	InitDCDCMdl();
	        	InitInvMdl();
	        	DSP_Send_DRAM_FPGAData();

				/********************等待Timer启动**********************/
	        	if(SysCnt != 0)
	        	{
	        		ModeState = 1;
	        	}
				else{;}
     	  	}
   	     	break;

      		case 1:
   	   	  	{
				/******************锁相延时，防止启机模拟量采集不稳***************/

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
				/****************************功能主函数***************************/
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

   	       		RecordData_Write_DSP();   /*读取充电机故障*/
   	       	 	DSP_Send_DRAM_ARMData();
   	        	DSP_Send_DRAM_FPGAData();

   	        	tempcnt++;
   	        	A_ARMRDDSP_DEBUG3_gui=(unsigned int) (PQData.SIV_P + 100000);
   	          	A_ARMRDDSP_DEBUG4_gui=(unsigned int) (PQData.SIV_Q + 100000);
   	          	A_ARMRDDSP_DEBUG5_gui=(unsigned int) (PQData.SIV_Power);
   	          	/***********************逻辑节拍函数控制，20ms执行周期***************/
   	        	while(SysCnt < 80)  {;} /*20ms延时等待*/
   	        	SysCnt = 0;
   	   	  	}
            break;

       		default:break;
    	}
  	}
}
/********************************* End of file *******************************/

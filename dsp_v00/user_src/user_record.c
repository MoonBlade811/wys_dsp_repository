//-----------------------------------------------------------------------------
// \file    main.c
// \brief   implementation of main()
//
//-----------------------------------------------------------------------------

/*****************************************************************************
**                       Include Files
*****************************************************************************/
/* HW Macros */
#include "hw_types.h"
/* System Defines */
#include "uartStdio.h"
#include "user_syscfg.h"
#include "user_record.h"
#include "user_variable.h"
#include "user_sysglobalvar.h"
#include "algorithm.h"


/***********************************************************
*�������ܣ�CANͨ�Ŵ������ݱ��ش洢��ִ��ʱ��20ms
*���������
*���������
*�� �� ֵ��
***********************************************************/
void RecordData_Write_DSP(void)
{
	BCU_TO_EventIndex = (unsigned int)(EventBuf[0]&0x00ff); /*�������ϼ�¼����ֵ*/
	BCU_TO_EventTrig =  (unsigned int)((EventBuf[0]>>15)&0x01);/*�������ϱ�־λ*/

	EventDelay++;
	if(EventDelay>=200)
	{
		EventEnable = 1;
		EventDelay = 200;
	}
	else{;}

	if((BCU_TO_EventTrig)&&(EventEnable)) /*�����������ϼ�¼����ʼ��¼*/
	{
		if((EventSaveDoneFlag == 0)&&(BCU_TO_EventIndex <= 149))  /*DSP���ϴ洢������DSP�洢δ���Ҽ�¼����ֵδ��*/
		{
			EventData[0][BCU_TO_EventIndex] = EventBuf[0];/*���ϼ�¼ʹ��&����ֵ-��ѹ��ԭ�ߵ���*/
			EventData[1][BCU_TO_EventIndex] = EventBuf[1];/*�������-FC��ѹ*/
			EventData[2][BCU_TO_EventIndex] = EventBuf[2];/*������-�����ѹ*/
			EventData[3][BCU_TO_EventIndex] = EventBuf[3];/*ԭ�ߵ���-DSP״̬*/
			EventData[4][BCU_TO_EventIndex] = EventBuf[4];/*���ϵ�16λ-���ϸ�16λ*/
			EventData[5][BCU_TO_EventIndex] = EventBuf[5];/*�ο���ѹ-����ֵ*/
			A_ARMRDDSP_DEBUG2_gui = BCU_TO_EventIndex;/*���ֻ���*/
			if(BCU_TO_EventIndex >= 149)/*DSP���ϴ洢��EventSaveDoneFlag��1���ȴ�FPGA��¼�������*/
			{
				EventSaveDoneFlag = 1;
			}
			else{;}
		}
	}
	else/*����δ�������ϣ���λ��־λ*/
	{
		A_ARMRDDSP_DEBUG2_gui = 0;
	}
}
/***********************************************************
*�������ܣ����ϼ�¼����FPGA�洢,ִ��ʱ��1ms
*���������
*���������
*�� �� ֵ��
***********************************************************/
void RecordData_Write_FPGA(void)
{
	unsigned short temp;
	FPGARecordCnt++;
	if((FPGARecordCnt%6)==0)
	{
		FPGARecordCnt = 0;

		temp = HWREGH(FPGA_To_DSP_00F4);               					/*�õ�FPGA�洢״̬*/

		DATA_EXTRACT_BOOLEAN(temp,  L_EVENT_CONL_EVENTRDY_gui,  	0); /*���ݼ�¼�����ȴ���ȡ*/
		DATA_EXTRACT_BOOLEAN(temp,  L_EVENT_CONL_EVENTERASE_gui,    1); /*���ݼ�¼�������*/
		DATA_EXTRACT_BOOLEAN(temp, 	L_EVENT_CONL_EVENTWRDY_gui,     2); /*���ݼ�¼�洢���*/
		DATA_EXTRACT_BOOLEAN(temp,  L_EVENT_CONL_EVENTRRDY_gui,     3); /*���ݼ�¼��ȡ���*/
		DATA_EXTRACT_BOOLEAN(temp,  L_EVENT_CONL_EVENTN_gui,        4); /*���ϼ�¼��*/

	    temp = HWREGH(ARM_To_DSP_12FC);                                 /*�߼����ϴ�����¼*/
	    DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG16_gui, UNSIGNED16_HIGH_BYTE);
	    temp = HWREGH(ARM_To_DSP_12FE);
	    DATA_INSERT_UNSIGNED32(temp, A_ARMRDDSP_DEBUG16_gui, UNSIGNED16_LOW_BYTE);

	    if(((A_ARMRDDSP_DEBUG16_gui&0x01)==1)||(LogicTrigFaultCnt!=0))/*�߼����ϴ�����¼*/
	    {
	    	LogicTrigFaultCnt++;
	    	LogicTrigFault =1;
	    }
	    else{;}

	    if(LogicTrigFaultCnt >= 100)/*�߼����ϴ���λ����100ms*/
	    {
	    	LogicTrigFaultCnt = 0;
	    	LogicTrigFault = 0;
	    }
	    else{;}

	    /*------------------���Թ��ϼ�¼����-------------------------*/
		A_DSPRDFPGA_CTRLPARAM7_gui = PQData.SIV_P + 100000;
		A_DSPRDFPGA_CTRLPARAM8_gui = PQData.SIV_Q + 100000;
	    A_DSPRDFPGA_CTRLPARAM9_gui = UDPID.MeasurePoint + 10000;
	    A_DSPRDFPGA_CTRLPARAM10_gui = UDPID.OutputPoint + 10000;
        A_DSPRDFPGA_CTRLPARAM11_gui = UQPID.MeasurePoint + 10000;
        A_DSPRDFPGA_CTRLPARAM12_gui = UQPID.OutputPoint + 10000;
		A_DSPRDFPGA_CTRLPARAM13_gui = BuckReg.OutputPoint;
		A_DSPRDFPGA_CTRLPARAM14_gui = DCDCReg.OutputPoint;
		A_DSPRDFPGA_CTRLPARAM15_gui = SIV_V*1000;
		A_DSPRDFPGA_CTRLPARAM16_gui = SIV_F*1000;

	    /*------------------���Թ��ϼ�¼����-------------------------*/
	    /*��ͣˢ�´洢�Ĺ��ϣ����浽FPGA�Ĺ��ϻ�������һ���������ϼ�¼�㽫����������д��Flash*/
		if((EventSaveDoneFlag)&&(L_EVENT_CONL_EVENTWRDY_gui==0)&&(FPGA_TO_EventIndex <= 149)&&(EventEnable))
		{
			A_DSPRDFPGA_CTRLPARAM1_gui = EventData[0][FPGA_TO_EventIndex];
			A_DSPRDFPGA_CTRLPARAM2_gui = EventData[1][FPGA_TO_EventIndex];
			A_DSPRDFPGA_CTRLPARAM3_gui = EventData[2][FPGA_TO_EventIndex];
			A_DSPRDFPGA_CTRLPARAM4_gui = EventData[3][FPGA_TO_EventIndex];
			A_DSPRDFPGA_CTRLPARAM5_gui = EventData[4][FPGA_TO_EventIndex];
			A_DSPRDFPGA_CTRLPARAM6_gui = EventData[5][FPGA_TO_EventIndex];
			FPGA_TO_EventIndex++;
		}
		else{;}

		if((((EventSaveDoneFlag)&&(FPGA_TO_EventIndex >= 99))||(LogicTrigFault==1))&&(L_EVENT_CONL_EVENTWRDY_gui==0)&&(EventEnable))
		{
			L_EVENT_CON2_EVENTW_gui = 1;
			temp = 0;
			DATA_INSERT_BOOLEAN(temp,L_EVENT_CON2_EVENTW_gui,2);
			HWREGH(DSP_To_FPGA_00F8) = temp;
		}
		else
		{
			L_EVENT_CON2_EVENTW_gui = 0;
			temp = 0;
			DATA_INSERT_BOOLEAN(temp,L_EVENT_CON2_EVENTW_gui,2);
			HWREGH(DSP_To_FPGA_00F8) = temp;
		}

		if((EventSaveDoneFlag)&&(L_EVENT_CONL_EVENTWRDY_gui==0)&&(FPGA_TO_EventIndex>=149)&&(EventEnable))  //���ϼ�¼��ϣ�������ϴ洢����־����������λ
		{
			EventSaveDoneFlag = 0;
			FPGA_TO_EventIndex = 0;
		}
		else{;}

		/*************���ݷ��͸�FPGA*************/
		temp = 0;
		DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM1_gui, UNSIGNED16_HIGH_BYTE);
		HWREGH(DSP_To_FPGA_0140) = temp;
		temp = 0;
		DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM1_gui, UNSIGNED16_LOW_BYTE);
		HWREGH(DSP_To_FPGA_0142) = temp;

		temp = 0;
		DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM2_gui, UNSIGNED16_HIGH_BYTE);
		HWREGH(DSP_To_FPGA_0144) = temp;
		temp = 0;
		DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM2_gui, UNSIGNED16_LOW_BYTE);
		HWREGH(DSP_To_FPGA_0146) = temp;

		temp = 0;
		DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM3_gui, UNSIGNED16_HIGH_BYTE);
		HWREGH(DSP_To_FPGA_0148) = temp;
		temp = 0;
		DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM3_gui, UNSIGNED16_LOW_BYTE);
		HWREGH(DSP_To_FPGA_014A) = temp;

		temp = 0;
		DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM4_gui, UNSIGNED16_HIGH_BYTE);
		HWREGH(DSP_To_FPGA_014C) = temp;
		temp = 0;
		DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM4_gui, UNSIGNED16_LOW_BYTE);
		HWREGH(DSP_To_FPGA_014E) = temp;

		temp = 0;
		DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM5_gui, UNSIGNED16_HIGH_BYTE);
		HWREGH(DSP_To_FPGA_0150) = temp;
		temp = 0;
		DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM5_gui, UNSIGNED16_LOW_BYTE);
		HWREGH(DSP_To_FPGA_0152) = temp;

	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM6_gui, UNSIGNED16_HIGH_BYTE);
	    HWREGH(DSP_To_FPGA_0154) = temp;
	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM6_gui, UNSIGNED16_LOW_BYTE);
	    HWREGH(DSP_To_FPGA_0156) = temp;

	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM7_gui, UNSIGNED16_HIGH_BYTE);
	    HWREGH(DSP_To_FPGA_0158) = temp;
	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM7_gui, UNSIGNED16_LOW_BYTE);
	    HWREGH(DSP_To_FPGA_015A) = temp;

	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM8_gui, UNSIGNED16_HIGH_BYTE);
	    HWREGH(DSP_To_FPGA_015C) = temp;
	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM8_gui, UNSIGNED16_LOW_BYTE);
	    HWREGH(DSP_To_FPGA_015E) = temp;

	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM9_gui, UNSIGNED16_HIGH_BYTE);
	    HWREGH(DSP_To_FPGA_0160) = temp;
	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM9_gui, UNSIGNED16_LOW_BYTE);
	    HWREGH(DSP_To_FPGA_0162) = temp;

	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM10_gui, UNSIGNED16_HIGH_BYTE);
	    HWREGH(DSP_To_FPGA_0164) = temp;
	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM10_gui, UNSIGNED16_LOW_BYTE);
	    HWREGH(DSP_To_FPGA_0166) = temp;

	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM11_gui, UNSIGNED16_HIGH_BYTE);
	    HWREGH(DSP_To_FPGA_0168) = temp;
	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM11_gui, UNSIGNED16_LOW_BYTE);
	    HWREGH(DSP_To_FPGA_016A) = temp;

	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM12_gui, UNSIGNED16_HIGH_BYTE);
	    HWREGH(DSP_To_FPGA_016C) = temp;
	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM12_gui, UNSIGNED16_LOW_BYTE);
	    HWREGH(DSP_To_FPGA_016E) = temp;

	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM13_gui, UNSIGNED16_HIGH_BYTE);
	    HWREGH(DSP_To_FPGA_0170) = temp;
	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM13_gui, UNSIGNED16_LOW_BYTE);
	    HWREGH(DSP_To_FPGA_0172) = temp;

	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM14_gui, UNSIGNED16_HIGH_BYTE);
	    HWREGH(DSP_To_FPGA_0174) = temp;
	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM14_gui, UNSIGNED16_LOW_BYTE);
	    HWREGH(DSP_To_FPGA_0176) = temp;

	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM15_gui, UNSIGNED16_HIGH_BYTE);
	    HWREGH(DSP_To_FPGA_0178) = temp;
	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM15_gui, UNSIGNED16_LOW_BYTE);
	    HWREGH(DSP_To_FPGA_017A) = temp;

	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM16_gui, UNSIGNED16_HIGH_BYTE);
	    HWREGH(DSP_To_FPGA_017C) = temp;
	    temp = 0;
	    DATA_EXTRACT_UNSIGNED32(temp, A_DSPRDFPGA_CTRLPARAM16_gui, UNSIGNED16_LOW_BYTE);
	    HWREGH(DSP_To_FPGA_017E) = temp;
	} 
}
/********************************* End of file *******************************/

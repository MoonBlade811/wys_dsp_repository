/**
 *  \file  main.h
 *
 *  \brief This file contains the function prototypes for the device abstraction 
 *         layer for PSC. It also contains some related macro definitions and some 
 *         files to be included.
 */


#ifndef _MAIN_H
#define _MAIN_H


#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
**
*****************************************************************************/
/******************************************************************************
 [ENUM TYPE]    -  OPERATE_MODE
 [PURPOSE]      -
 [SYNTAX]       -
 [ELEMENTS]     -
 [REMARKS]      -  define operate mode
******************************************************************************/
typedef enum
{
  OM_INITING			= 1,  /* Initialisation mode     */
  OM_SELFTEST           = 2,  /* SelfTest mode           */
  OM_PREOPERATE	        = 3,  /* Pre-Operational mode    */
  OM_NORMAL		        = 4,  /* Normal Operational mode */
  OM_SWDOWNLOAD         = 5,  /* DSP&FPGA SW write flash */
  OM_SWIMAGECOPY        = 6,  /* FPGA SW copy from flash to FPGA */
  OM_CONFIGURE          = 7,  /* PC configure information */
  OM_STOPPED			= 8   /* Stop mode               */
} OPERATE_TYPE;


/******************************************************************************
**                        Macro Definitions
*******************************************************************************/


/******************************************************************************
**                    External Function Declararions
*******************************************************************************/


extern volatile unsigned char L_BL_master_judgment_gui;
extern double SIV_PW;
extern double SIV_QW;

extern unsigned int SIVCTT_open_flag;

extern unsigned char SysCnt;
extern unsigned int  MVB_CommError;
extern unsigned char Fault_Record_Flag_gui;
extern unsigned char Fault_Writing;








/***********************************************************************/

#ifdef __cplusplus
}
#endif

#endif


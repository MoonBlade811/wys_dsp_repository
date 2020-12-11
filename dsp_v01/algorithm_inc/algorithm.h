/*********************************************************************
Copyright (c),2002-2017,Sifang Rolling Stock Research Institute Ltd.
*File Name:    algorithm.h
*Author:       JasonLee
*Date:         2017.09.18
*Version:      0.1
*Description:  algorithm head files
*Modification history:
    1.Jason, 2017.9.18, first issue;
**********************************************************************/
#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "math.h"
#include <stdio.h>

/*Type definition*/
typedef         unsigned int                   	Mytype_uint32;
typedef         int                            	Mytype_int32;
typedef         unsigned char                  	Mytype_uint8;
typedef         float                          	Mytype_float32;
typedef         double                         	Mytype_float64;
typedef         long unsigned int              	Mytype_uint64;
/*Constant definition*/

#define UQPIDPARADEFAULTS {		0.044,\
								0.014,\
								0,\
								0,\
								0,\
								0,\
								0,\
								0,\
								0,\
								30,\
								-30,\
								0,\
								0,\
								0}

#define UDPIDPARADEFAULTS {		0.044,\
								0.014,\
								0,\
								0,\
								0,\
								0,\
								0,\
								0,\
								0,\
								350,\
								0,\
								0,\
								0,\
								0}

#define DCDCPIDPARADEFAULTS {       6,\
                                    1,\
                                    0.2,\
                                    1,\
                                    2,\
                                    1,\
                                    0,\
                                    0,\
                                    0,\
                                    0,\
                                    0,\
                                    0,\
                                    700,\
                                    0,\
                                    0,\
                                    0,\
                                    0}

#define BUCKPIDPARADEFAULTS {       0.5,\
                                    1,\
                                    0.01,\
                                    1,\
                                    6,\
                                    1,\
                                    0,\
                                    0,\
                                    0,\
                                    0,\
                                    0,\
                                    0,\
                                    600,\
                                    0,\
                                    0,\
                                    0,\
                                    0}

#define UDFivePIDPARADEFAULTS {		0.012,\
									0.005,\
									0,\
									0,\
									0,\
									0,\
									0,\
									0,\
									0,\
									200,\
									-200,\
									0,\
									0,\
									0}


#define UQFivePIDPARADEFAULTS {		0.012,\
									0.005,\
									0,\
									0,\
									0,\
									0,\
									0,\
									0,\
									0,\
									200,\
									-200,\
									0,\
									0,\
									0}

#define UDSevenPIDPARADEFAULTS {	 0.02,\
								 	 0.01,\
									 1,\
									 0,\
									 0,\
									 0,\
									 0,\
									 0,\
									 0,\
									 200,\
									 -200,\
									 0,\
									 0,\
									 0}

#define UQSevenPIDPARADEFAULTS { 	 0.02,\
								 	 0.01,\
									 1,\
								 	 0,\
								 	 0,\
								 	 0,\
								 	 0,\
								 	 0,\
								 	 0,\
									 200,\
									 -200,\
									 0,\
									 0,\
									 0}

#define sogi_hq_para_default    {   0.0009339,\
                                    0.001868,\
                                    0.0009339,\
                                    -1.926,\
                                    0.9287,\
                                    0,\
                                    0,\
                                    0,\
                                    0,\
                                    0,\
                                    0}

#define SVPWMREGDEFAULTS {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
						  0,0,0,0,0,0,0,0,0,0,0,0}

#define PQCALCDEFAULTS {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

#define SPLLPARADEAULATS {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
                         	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
#define     TsComp              5e-3
#define 	FilterPara 			0.01//0.008
#define 	PI1            		3.1415926535
#define 	PI3            		1.0471975512
#define 	PI21           		1.57079632678
#define 	PI23           		2.09439510239
#define 	PI32           		4.71238898038
#define 	PI14				0.7853981634
#define 	DOUBLE_PI      		6.28318530718
#define 	AngleBC				0.125
#define 	PKF 		    	0.000006//0.000005
#define 	PKFD				0.0002
#define 	QKF 				0.0000001
#define 	QKV 				0.00050//0.00020
#define 	QKVD				0.0005//0.0003
#define 	PKV 				0.00010
#define 	AngleStep      		0.00003
#define 	SysStartAngel  		0.015231964381041421762243119434082
#define 	Master         		1
#define 	Slave          		0
#define 	CarryFreq			0.0010471975511
#define    TransformerRatio		1.7
/*Variable declaration*/
typedef struct PQCALCPARA{
							Mytype_uint8   	PQCalcStart;
							Mytype_float64 	Ur;
							Mytype_float64 	Ui;
							Mytype_float64 	Ir;
							Mytype_float64	Ii;
							Mytype_float64 	SIV_P;
							Mytype_float64  SIV_PFil;
							Mytype_float64 	SIV_Q;
							Mytype_float64  SIV_QFil;
							Mytype_float64 	SIV_P_Back;
							Mytype_float64 	SIV_Q_Back;
							Mytype_float64 	SIV_Power;
							Mytype_uint32  	ZeroRst;
							Mytype_float64 	UinBack;
							Mytype_uint32  	PQDataReadCnt;
							}PQCALCSTRUCT,*PQCALCHANDLE;
typedef struct SPLLPARA{
                            Mytype_float64 Angle;
                            Mytype_float64 DoubleAngle;
                            Mytype_float64 TripleAngle;
                            Mytype_float64 QuadraAngle;
					        Mytype_float64 PentaAngle;
					        Mytype_float64 HexaAngle;
						    Mytype_float64 SevenAngle;
						    Mytype_float64 EightAngle;
                            Mytype_float64 SpllAngle;
                            Mytype_float64 Udp;
                            Mytype_float64 Uqp;
                            Mytype_float64 Udn;
                            Mytype_float64 Uqn;
                            Mytype_float64 UdpFilter;
                            Mytype_float64 UqpFilter;
                            Mytype_float64 UdnFilter;
                            Mytype_float64 UqnFilter;
                            Mytype_float64 UdpDpl;
                            Mytype_float64 UqpDpl;
                            Mytype_float64 UdnDpl;
                            Mytype_float64 UqnDpl;
						    Mytype_float64 UdDouble;
						    Mytype_float64 UdDoubleDpl;
						    Mytype_float64 UdDoubleFilter;
						    Mytype_float64 UqDouble;
						    Mytype_float64 UqDoubleDpl;
						    Mytype_float64 UqDoubleFilter;
                            Mytype_float64 UdFive;
                            Mytype_float64 UdFiveDpl;
                            Mytype_float64 UdFiveFilter;
                            Mytype_float64 UqFive;
                            Mytype_float64 UqFiveDpl;
                            Mytype_float64 UqFiveFilter;
                            Mytype_float64 UdSeven;
						    Mytype_float64 UdSevenDpl;
                            Mytype_float64 UdSevenFilter;
                            Mytype_float64 UqSeven;
						    Mytype_float64 UqSevenDpl;
                            Mytype_float64 UqSevenFilter;
                            Mytype_float64 Ualpha;
                            Mytype_float64 Ubeta;
                            Mytype_float64 sinwt;
                            Mytype_float64 coswt;
                            Mytype_float64 sindwt;
                            Mytype_float64 cosdwt;
                            Mytype_float64 sintwt;
                            Mytype_float64 costwt;
                            Mytype_float64 sinqwt;
                            Mytype_float64 cosqwt;
                            Mytype_float64 sinpwt;
                            Mytype_float64 cospwt;
                            Mytype_float64 sinhwt;
                            Mytype_float64 coshwt;
						    Mytype_float64 sinswt;
                            Mytype_float64 cosswt;
						    Mytype_float64 sinewt;
                            Mytype_float64 cosewt;
                        }SPLLPARASTRUCT,*SPLLPARAHANDLE;
typedef struct SVPWMPARA{
                            Mytype_float64 RoVector;
                            Mytype_float64 RoAngle;
                            Mytype_float64 Ua;
                            Mytype_float64 Ub;
                            Mytype_float64 Uc;
                            Mytype_uint8   Sector;
                            Mytype_uint8   MiniSector;
                            Mytype_float64 su;
                            Mytype_float64 sv;
                            Mytype_float64 sw;
                            Mytype_uint8   sa;
                            Mytype_uint8   sb;
                            Mytype_uint8   sc;
                            Mytype_float64 Alpha;
                            Mytype_float64 Beta;
                            Mytype_float64 CMPT1;
                            Mytype_float64 CMPT2;
                            Mytype_float64 temp_cmu;
                            Mytype_float64 temp_cmv;
                            Mytype_float64 temp_cmw;
                            Mytype_float64 SinValue;
                            Mytype_float64 CosValue;
                            Mytype_float64 SindValue;
                            Mytype_float64 CosdValue;
                            Mytype_float64 SintValue;
                            Mytype_float64 CostValue;
                            Mytype_float64 SinfValue;
                            Mytype_float64 CosfValue;
                            Mytype_float64 SinpValue;
                            Mytype_float64 CospValue;
                            Mytype_float64 SinhValue;
                            Mytype_float64 CoshValue;
                            Mytype_float64 SinsValue;
                            Mytype_float64 CossValue;
                            Mytype_float64 SineValue;
                            Mytype_float64 CoseValue;
                        }SVPWMPARASTRUCT,*SVPWMPARAHANDLE;
typedef struct DCDCPIDPARA{
							Mytype_float64 KP;
							Mytype_float64 KP_Ratio;
	                        Mytype_float64 KI;
	                        Mytype_float64 KI_Ratio;
	                        Mytype_float64 KD;
	                        Mytype_float64 KD_Ratio;
	                        Mytype_float64 Err;
	                        Mytype_float64 SumErr;
	                        Mytype_float64 BackErr;
	                        Mytype_float64 MeasurePoint;
	                        Mytype_float64 SetPoint;
	                        Mytype_float64 OutputPoint;
	                        Mytype_float64 UpLimit;
	                        Mytype_float64 DownLimit;
	                        Mytype_float64 Proportion;
	                        Mytype_float64 Integral;
	                        Mytype_float64 Derivative;
						}DCDCPARASTRUCT,*DCDCHANDLE;
typedef struct UDSevenPIDPARA{
                            Mytype_float64 KP;
                            Mytype_float64 KI;
                            Mytype_float64 KD;
                            Mytype_float64 Err;
                            Mytype_float64 SumErr;
                            Mytype_float64 BackErr;
                            Mytype_float64 MeasurePoint;
                            Mytype_float64 SetPoint;
                            Mytype_float64 OutputPoint;
                            Mytype_float64 UpLimit;
                            Mytype_float64 DownLimit;
                            Mytype_float64 Proportion;
                            Mytype_float64 Integral;
                            Mytype_float64 Derivative;
                          }UDSevenPIDPARASTRUCT,*UDSevenPIDPARAHANDLE;
typedef struct UQSevenPIDPARA{
                            Mytype_float64 KP;
                            Mytype_float64 KI;
                            Mytype_float64 KD;
                            Mytype_float64 Err;
                            Mytype_float64 SumErr;
                            Mytype_float64 BackErr;
                            Mytype_float64 MeasurePoint;
                            Mytype_float64 SetPoint;
                            Mytype_float64 OutputPoint;
                            Mytype_float64 UpLimit;
                            Mytype_float64 DownLimit;
                            Mytype_float64 Proportion;
                            Mytype_float64 Integral;
                            Mytype_float64 Derivative;
                          }UQSevenPIDPARASTRUCT,*UQSevenPIDPARAHANDLE;
typedef struct UDFivePIDPARA{
                            Mytype_float64 KP;
                            Mytype_float64 KI;
                            Mytype_float64 KD;
                            Mytype_float64 Err;
                            Mytype_float64 SumErr;
                            Mytype_float64 BackErr;
                            Mytype_float64 MeasurePoint;
                            Mytype_float64 SetPoint;
                            Mytype_float64 OutputPoint;
                            Mytype_float64 UpLimit;
                            Mytype_float64 DownLimit;
                            Mytype_float64 Proportion;
                            Mytype_float64 Integral;
                            Mytype_float64 Derivative;
                          }UDFivePIDPARASTRUCT,*UDFivePIDPARAHANDLE;
typedef struct UQFivePIDPARA{
                            Mytype_float64 KP;
                            Mytype_float64 KI;
                            Mytype_float64 KD;
                            Mytype_float64 Err;
                            Mytype_float64 SumErr;
                            Mytype_float64 BackErr;
                            Mytype_float64 MeasurePoint;
                            Mytype_float64 SetPoint;
                            Mytype_float64 OutputPoint;
                            Mytype_float64 UpLimit;
                            Mytype_float64 DownLimit;
                            Mytype_float64 Proportion;
                            Mytype_float64 Integral;
                            Mytype_float64 Derivative;
                          }UQFivePIDPARASTRUCT,*UQFivePIDPARAHANDLE;
typedef struct BUCKPIDPARA{
							Mytype_float64 KP;
							Mytype_float64 KP_Ratio;
							Mytype_float64 KI;
							Mytype_float64 KI_Ratio;
							Mytype_float64 KD;
							Mytype_float64 KD_Ratio;
							Mytype_float64 Err;
							Mytype_float64 SumErr;
							Mytype_float64 BackErr;
							Mytype_float64 MeasurePoint;
							Mytype_float64 SetPoint;
							Mytype_float64 OutputPoint;
							Mytype_float64 UpLimit;
							Mytype_float64 DownLimit;
							Mytype_float64 Proportion;
							Mytype_float64 Integral;
							Mytype_float64 Derivative;
						   }BUCKPARASTRUCT,*BUCKHANDLE;
typedef struct UQPIDPARA{
							Mytype_float64 KP;
							Mytype_float64 KI;
							Mytype_float64 KD;
							Mytype_float64 Err;
							Mytype_float64 SumErr;
							Mytype_float64 BackErr;
							Mytype_float64 MeasurePoint;
							Mytype_float64 SetPoint;
							Mytype_float64 OutputPoint;
							Mytype_float64 UpLimit;
							Mytype_float64 DownLimit;
							Mytype_float64 Proportion;
							Mytype_float64 Integral;
							Mytype_float64 Derivative;
							}UQPIDPARASTRUCT,*UQPIDPARAHANDLE;
typedef struct UDPIDPARA{Mytype_float64 KP;
Mytype_float64 KI;
Mytype_float64 KD;
Mytype_float64 Err;
Mytype_float64 SumErr;
Mytype_float64 BackErr;
Mytype_float64 MeasurePoint;
Mytype_float64 SetPoint;
Mytype_float64 OutputPoint;
Mytype_float64 UpLimit;
Mytype_float64 DownLimit;
Mytype_float64 Proportion;
Mytype_float64 Integral;
Mytype_float64 Derivative;
							
							}UDPIDPARASTRUCT,*UDPIDPARAHANDLE;
							typedef struct sogi_hq_para{
							                            Mytype_float64 cofA;
							                            Mytype_float64 cofB;
							                            Mytype_float64 cofC;
							                            Mytype_float64 cofD;
							                            Mytype_float64 cofE;
							                            Mytype_float64 Y_K;
							                            Mytype_float64 Y_K_1;
							                            Mytype_float64 Y_K_2;
							                            Mytype_float64 U_K;
							                            Mytype_float64 U_K_1;
							                            Mytype_float64 U_K_2;
							                        }sogi_hq_struct,*sogi_hq_handle;
/*Variable declaration*/
extern  	SPLLPARASTRUCT  	  	SPLLReg;
extern  	SPLLPARASTRUCT  	  	SPLLRegRst;
extern  	SVPWMPARASTRUCT 	  	SVPWMReg;
extern		SVPWMPARASTRUCT 	  	SVPWMRegRst;
extern 	 	UDFivePIDPARASTRUCT   	UDFivePID;
extern 		UDFivePIDPARASTRUCT   	UDFivePIDRst;
extern  	UQFivePIDPARASTRUCT   	UQFivePID;
extern  	UQFivePIDPARASTRUCT   	UQFivePIDRst;
extern  	UDSevenPIDPARASTRUCT  	UDSevenPID;
extern  	UDSevenPIDPARASTRUCT  	UDSevenPIDRst;
extern  	UQSevenPIDPARASTRUCT  	UQSevenPID;
extern  	UQSevenPIDPARASTRUCT  	UQSevenPIDRst;
extern  	PQCALCSTRUCT  		  	PQData;
extern  	PQCALCSTRUCT		  	PQDataRst;
extern	  	UDPIDPARASTRUCT		  	UDPID;
extern	 	UDPIDPARASTRUCT		  	UDPIDRst;
extern	 	UQPIDPARASTRUCT		  	UQPID;
extern	 	UQPIDPARASTRUCT		  	UQPIDRst;
extern	 	DCDCPARASTRUCT	  		DCDCReg;
extern		DCDCPARASTRUCT 	  		DCDCRegRst;
extern	 	BUCKPARASTRUCT 	  		BuckReg;
extern 	 	BUCKPARASTRUCT 	  		BuckRegRst;
extern      sogi_hq_struct          sogi_hq_reg;
extern      sogi_hq_struct          sogi_hq_reg_rst;
/*Function declaration*/
extern void SPLL(SPLLPARAHANDLE);
extern void UDFiveCtrl(UDFivePIDPARAHANDLE);
extern void UQFiveCtrl(UQFivePIDPARAHANDLE);
extern void UDSevenCtrl(UDSevenPIDPARAHANDLE);
extern void UQSevenCtrl(UQSevenPIDPARAHANDLE);
extern void SvpwmModule(SVPWMPARAHANDLE);
extern void SIVCtrl(double *alpha, double *beta);
extern void CtrlDataMeasure(void);
extern void AngelModul(void);
extern void BuckPWMCtrl(void);
extern void DCDCPWMCtrl(void);
extern void PQDataCalc(PQCALCHANDLE,double *Uin);
extern void UQCtrl(UQPIDPARAHANDLE);
extern void UDCtrl(UDPIDPARAHANDLE);
extern void BuckCtrl(BUCKHANDLE);
extern void DCDCCtrl(DCDCHANDLE);
extern void SivCutoff(void);
extern void sogi_hq(sogi_hq_handle);
/*-----------------------------------------------------------------------*/

#endif



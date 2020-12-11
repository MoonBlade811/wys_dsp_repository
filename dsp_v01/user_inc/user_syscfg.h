/**
 *  \file  user_syscfg.h
*/


#ifndef _USER_SYSCFG_H
#define _USER_SYSCFG_H


#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************
**                       Include Files
*****************************************************************************/



/******************************************************************************
**                        Macro Definitions
*******************************************************************************/

#define DSP1         1
#define DSP2         0


#define DSP_300MHZ

#ifdef DSP_300MHZ
 /* Fixing PLL0 register values */
 #define PLL_CLK_SRC             0
 #define PLL0_MUL                24
 #define PLL0_PREDIV             0
 #define PLL0_POSTDIV            1
 #define PLL0_DIV1               0
 #define PLL0_DIV3               2
 #define PLL0_DIV7               5

 /* Fixing PLL1 register values */
 #define PLL1_MUL                24
 #define PLL1_POSTDIV            1
 #define PLL1_DIV1               0
 #define PLL1_DIV2               1
 #define PLL1_DIV3               2
#else
    #error Unsupported frequency !!
#endif


//-----------------------------------------------------------------------------
// bit manipulation macros and bitval lookup table declarations.
//-----------------------------------------------------------------------------
#define SETREGBIT(dest,mask)     (HWREG(dest) |= mask)
#define CLRREGBIT(dest,mask)     (HWREG(dest) &= ~mask)
#define TGLREGBIT(dest,mask)     (HWREG(dest) ^= mask)
#define CHKREGBIT(dest,mask)     (HWREG(dest) & mask)
#define SETDATBIT(dest,mask)     ((dest) |= mask)
#define CLRDATBIT(dest,mask)     ((dest) &= ~mask)
#define TGLDATBIT(dest,mask)     ((dest) ^= mask)
#define CHKDATBIT(dest,mask)     ((dest) & mask)

#define UNSIGNED8_HIGH_BYTE      8
#define UNSIGNED8_LOW_BYTE       0
#define UNSIGNED16_HIGH_BYTE     0 //为了调整高低字节
#define UNSIGNED16_LOW_BYTE      16

#define DATA_INSERT_BOOLEAN(dest, var, pos)      \
	    ((dest) = ((unsigned short)(dest) & ~(0x000000001 << pos)) | ((var & 0x00000001) << pos))

#define DATA_INSERT_UNSIGNED8(dest, var, pos)    \
	    ((dest) = ((unsigned short)(dest) & ~(0x000000FF << pos)) | ((var & 0x000000FF) << pos))

#define DATA_INSERT_UNSIGNED32(dest, var, pos)   \
	    ((var) = ((var) & ~(0x0000FFFF << pos)) | ((unsigned int)(dest) << pos))

#define DATA_EXTRACT_BOOLEAN(dest, var, pos)     \
	    ((var) = ((unsigned short)(dest) >> pos) & 0x00000001)

#define DATA_EXTRACT_UNSIGNED8(dest, var, pos)   \
	    ((var) = ((unsigned short)(dest) >> pos) & 0x000000FF)

#define DATA_EXTRACT_UNSIGNED32(dest, var, pos)  \
	    ((dest) = (unsigned short)(((var) >> pos) & 0x0000FFFF))



#define DATA_EXTRACT_BOOLEANd0b01(dest, var, pos)     \
		((var) = (((unsigned short)(dest)) & 0x00000003)>> pos)

#define DATA_EXTRACT_BOOLEANd0b23(dest, var, pos)     \
		((var) = (((unsigned short)(dest)) & 0x0000000C)>> pos)

#define DATA_EXTRACT_BOOLEANd0b45(dest, var, pos)     \
		((var) = (((unsigned short)(dest)) & 0x00000030)>> pos)

#define DATA_EXTRACT_BOOLEANd0b67(dest, var, pos)     \
		((var) = (((unsigned short)(dest)) & 0x000000C0)>> pos)

#define DATA_EXTRACT_BOOLEANd1b01(dest, var, pos)     \
		((var) = (((unsigned short)(dest)>> 8) & 0x00000003)>> pos)

#define DATA_EXTRACT_BOOLEANd1b23(dest, var, pos)     \
		((var) = (((unsigned short)(dest)>> 8) & 0x0000000C)>> pos)

#define DATA_EXTRACT_BOOLEANd1b45(dest, var, pos)     \
		((var) = (((unsigned short)(dest)>> 8) & 0x00000030)>> pos)

#define DATA_EXTRACT_BOOLEANd1b67(dest, var, pos)     \
		((var) = (((unsigned short)(dest)>> 8) & 0x000000C0)>> pos)



#define DATA_EXTRACT_BOOLEANdb(dest, var, pos)     \
	    ((var) = ((unsigned short)(dest) >> pos) & 0x00000003)




#define DATA_INSERT_BOOLEANdb(dest, var, pos)      \
	    ((dest) = ((unsigned short)(dest) & ~(0x000000003 << pos)) | ((var << pos) & (0x000000003 << pos)))



#define WRITE_FLASH_OK            0x5A
#define WRITE_FLASH_ERR           0xA5

/******************************************************************************
**                    External Function Declararions
*******************************************************************************/
extern void SYSCFG_Init(void);
extern void pinmuxConfig(unsigned int in_reg, unsigned int in_mask, unsigned int in_val);
extern void SysCfgRegistersUnlock(void);
extern void SysCfgRegistersLock(void);
extern unsigned char ASCIIToInt(unsigned char byte);
extern unsigned int IntToASCII(unsigned char byte);

/***********************************************************************/

#ifdef __cplusplus
}
#endif

#endif


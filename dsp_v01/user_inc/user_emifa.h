/**
 *  \file  user_emifa.h
 */


#ifndef _USER_EMIFA_H
#define _USER_EMIFA_H


#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
**                       Include Files
*****************************************************************************/
#include "nandlib.h"

typedef struct _nandbootheader_
{
    unsigned int magicNum;
    unsigned int entryPoint;
    unsigned int numPage;
    unsigned int block;
    unsigned int page;
    unsigned int ldAddress;
}
BL_NAND_Header;



/******************************************************************************
**                        Macro Definitions
*******************************************************************************/

/*****************************************************************************/
/*
** Macros which defines the data integrity status.
**
*/
#define NAND_DATA_INTEGRITY_PASS                (0)
#define NAND_DATA_INTEGRITY_FAIL                (1)

/*****************************************************************************/
/*
** Macros which defines attached device info like num of pages per block,
** number of blocks, device ID and manufacturer ID.
**
*/
#define NAND_DATA_XFER_MODE                     (NAND_XFER_MODE_CPU)
#define NAND_BUSWIDTH                           (NAND_BUSWIDTH_8BIT)
#define NAND_CHIP_SELECT                        (EMIFA_CHIP_SELECT_3)
#define NAND_PAGE_SIZE_IN_BYTES                 (NAND_PAGESIZE_2048BYTES)
#define NAND_BLOCK_SIZE_IN_BYTES                (NAND_BLOCKSIZE_128KB)
#define NAND_NUMOF_BLK                          (4096)
#define NAND_MANUFATURER_MICRON_ID              (0x2C)
#define NAND_DEVICE_ID                          (0xDC)


#define NAND_PAGE_NUM_IN_BLK                    (64)
#define NAND_BLOCK_NUM_IN_PLANE                 (1024)

/*****************************************************************************/
/*
** Macros which defines the read write size, buffer size and number of transfers
**
*/
#define NAND_DATA_BUFF_SIZE                     (NAND_PAGE_SIZE_IN_BYTES)
#define NAND_ECC_BUFF_SIZE                      ((NAND_PAGE_SIZE_IN_BYTES/NAND_BYTES_PER_TRNFS) * NAND_MAX_ECC_BYTES_PER_TRNFS)


/******************************************************************************
**                    External Function Declararions
*******************************************************************************/
extern void NAND_Init(void);
extern void EMIFA_Init(void);


/***********************************************************************/

#ifdef __cplusplus
}
#endif

#endif


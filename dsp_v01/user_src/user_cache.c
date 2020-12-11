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
#include "soc_C6748.h"
#include "dspcache.h"
#include "user_cache.h"

/*****************************************************************************
**                     Internal Macro Definitions
*****************************************************************************/
#define L2CFG         *(unsigned int*) (0x01840000)
#define L1DCFG        *(unsigned int*) (0x01840040)
#define L1PCFG        *(unsigned int*) (0x01840020)

#define MAR128        *(unsigned int*) (0x01848200)

#define MAR192        *(unsigned int*) (0x01848300)
#define MAR193        *(unsigned int*) (0x01848304)
#define MAR194        *(unsigned int*) (0x01848308)
#define MAR195        *(unsigned int*) (0x0184830C)
#define MAR196        *(unsigned int*) (0x01848310)
#define MAR197        *(unsigned int*) (0x01848314)
#define MAR198        *(unsigned int*) (0x01848318)
#define MAR199        *(unsigned int*) (0x0184831C)
#define MAR200        *(unsigned int*) (0x01848320)
#define MAR201        *(unsigned int*) (0x01848324)
#define MAR202        *(unsigned int*) (0x01848328)
#define MAR203        *(unsigned int*) (0x0184832C)
#define MAR204        *(unsigned int*) (0x01848330)
#define MAR205        *(unsigned int*) (0x01848334)
#define MAR206        *(unsigned int*) (0x01848338)
#define MAR207        *(unsigned int*) (0x0184833C)
#define MAR208        *(unsigned int*) (0x01848340)
#define MAR209        *(unsigned int*) (0x01848344)
#define MAR210        *(unsigned int*) (0x01848348)
#define MAR211        *(unsigned int*) (0x0184834C)
#define MAR212        *(unsigned int*) (0x01848350)
#define MAR213        *(unsigned int*) (0x01848354)
#define MAR214        *(unsigned int*) (0x01848358)
#define MAR215        *(unsigned int*) (0x0184835C)
#define MAR216        *(unsigned int*) (0x01848360)
#define MAR217        *(unsigned int*) (0x01848364)
#define MAR218        *(unsigned int*) (0x01848368)
#define MAR219        *(unsigned int*) (0x0184836C)
#define MAR220        *(unsigned int*) (0x01848370)
#define MAR221        *(unsigned int*) (0x01848374)
#define MAR222        *(unsigned int*) (0x01848378)
#define MAR223        *(unsigned int*) (0x0184837C)

/******************************************************************************
**                     Local variable Definitions
*******************************************************************************/



/******************************************************************************
**                     Local function Declarations
*******************************************************************************/



/******************************************************************************
**                     Global variable Definitions
*******************************************************************************/







/******************************************************************************
**                     Global Function Definitions
*******************************************************************************/

void CACHE_ENABLE(void)
{
  /* Enable Cache */
  //CacheEnable(L1PCFG_L1PMODE_32K | L1DCFG_L1DMODE_32K | L2CFG_L2MODE_32K);
  L2CFG = 1;
  /* Enabling the MAR max memory size.*/
  //MAR128 |= 0x1;

  MAR192 |= 0x1;
  MAR193 |= 0x1;
  MAR194 |= 0x1;
  MAR195 |= 0x1;
  MAR196 |= 0x1;
  MAR197 |= 0x1;
  MAR198  = 0;
  MAR199  = 0;

#if 0
  CacheEnable(L1PCFG_L1PMODE_32K | L1DCFG_L1DMODE_32K | L2CFG_L2MODE_256K);
  /* setup MAR bits to enable cache for transmit buffer */
  CacheEnableMAR((unsigned int)0xC0000000, 0x1000000);
  CacheDisableMAR((unsigned int)0xC6000000, 0x2000000);

  /* setup MAR bits to enable cache for transmit buffer */
  //CacheEnableMAR((unsigned int)buffer, TX_BUFFER_SIZE);
#endif
}
void CACHE_DISABLE(void)
{
  /* Enable Cache */
  //CacheDisable(L1PCFG_L1PMODE_32K | L1DCFG_L1DMODE_32K | L2CFG_L2MODE_32K);

  /* Enabling the MAR max memory size.*/
  MAR128 = 0;

  MAR192 = 0;
  MAR193 = 0;
  MAR194 = 0;
  MAR195 = 0;
  MAR196 = 0;
  MAR197 = 0;
  MAR198 = 0;
  MAR199 = 0;
}
/********************************* End of file *******************************/

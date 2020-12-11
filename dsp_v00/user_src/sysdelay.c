/**
 * \file   delay.c
 *
 * \brief  Delay routines
 */

/*
* Copyright (C) 2012 Texas Instruments Incorporated - http://www.ti.com/
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "interrupt.h"
#include "soc_C6748.h"
#include "hw_syscfg0_C6748.h"
#include "timer.h"
//#include "evmC6748.h"
#include "delay.h"

static volatile unsigned int flagIsrCnt = 1;

/******************************************************************************
**                      INTERNAL MACRO DEFINITIONS
*******************************************************************************/
#define TMR_PERIOD_LSB32              0x5DC0
#define TMR_PERIOD_MSB32              0x0




void DelayTimerSetup(void)
{
    SysDelayTimerSetup();
}


/**
 * \brief   This function generate a delay of specified milli-seconds.
 *
 * \param   milliSec     This is the number of mill-seconds for delay
 *
 * \return  None.
 *
 * \Note   This a wrapper API. The actual implementation can found in platform
 *         specific files
 */

void delay(unsigned int milliSec)
{
    Sysdelay(milliSec);
}

/*
 * \brief Delay function.
 *
 * \param  count - Halts execution depend upon the value of the variable.
 *
 * \return none
 *
 * \add to zhp
*/
void Delay(volatile unsigned int count)
{
    while(count--);
}

/*
** Timer Interrupt Service Routine. 
*/
static void TimerIsr(void)
{
#ifdef _TMS320C6X
    /* Disable the timer interrupt */
    TimerIntDisable(SOC_TMR_0_REGS, TMR_INT_TMR12_NON_CAPT_MODE);

    /* Clear the interrupt status in INTC and in timer */
    IntEventClear(SYS_INT_T64P0_TINT12);
    TimerIntStatusClear(SOC_TMR_0_REGS, TMR_INT_TMR12_NON_CAPT_MODE);
  
     
    flagIsrCnt = 0;
  
    /* Enable the timer interrupt */
    TimerIntEnable(SOC_TMR_0_REGS, TMR_INT_TMR12_NON_CAPT_MODE);
#else
    /* Disable the timer interrupt */
    TimerIntDisable(SOC_TMR_0_REGS, TMR_INT_TMR12_NON_CAPT_MODE);

    /* Clear the interrupt status in AINTC and in timer */
    IntSystemStatusClear(SYS_INT_TINT12_0);
    TimerIntStatusClear(SOC_TMR_0_REGS, TMR_INT_TMR12_NON_CAPT_MODE);
  
     
    flagIsrCnt = 0;
  
    /* Enable the timer interrupt */
    TimerIntEnable(SOC_TMR_0_REGS, TMR_INT_TMR12_NON_CAPT_MODE);
#endif
}


/*
** Set up the ARM Interrupt Controller for generating timer interrupt
*/
static void AintcTimerIntrSetUp(void)
{
#ifdef _TMS320C6X
    /* Register the Timer ISR */
    IntRegister(C674X_MASK_INT10, TimerIsr);
  
    /* Set the channel number for Timer interrupt, it will map to IRQ */
    IntEventMap(C674X_MASK_INT10, SYS_INT_T64P0_TINT12);
      
    /* Enable timer interrupts in AINTC */
    IntEnable(C674X_MASK_INT10);
#else
    /* Register the Timer ISR */
    IntRegister(SYS_INT_TINT12_0, TimerIsr);
  
    /* Set the channel number for Timer interrupt, it will map to IRQ */
    IntChannelSet(SYS_INT_TINT12_0, 3);
      
    /* Enable timer interrupts in AINTC */
    IntSystemEnable(SYS_INT_TINT12_0);
#endif
}

void SysDelayTimerSetup(void)
{    

    /* Configuration of Timer */
    TimerConfigure(SOC_TMR_0_REGS, TMR_CFG_32BIT_UNCH_CLK_BOTH_INT);

    /* Set up the AINTC to generate Timer2 interrupts */
    AintcTimerIntrSetUp();

    /* Enable the timer interrupt */
    TimerIntEnable(SOC_TMR_0_REGS, TMR_INT_TMR12_NON_CAPT_MODE);    
   
}


void Sysdelay(unsigned int milliSec)
{

	TimerPeriodSet(SOC_TMR_0_REGS, TMR_TIMER12, (milliSec * TMR_PERIOD_LSB32));
	
	/* Start the timer. Characters from cntArr will be sent from the ISR */
	TimerEnable(SOC_TMR_0_REGS, TMR_TIMER12, TMR_ENABLE_ONCE);

	while(flagIsrCnt);
	
	flagIsrCnt = 1;
	/* Disable the timer. No more timer interrupts */
	TimerDisable(SOC_TMR_0_REGS, TMR_TIMER12); 

}


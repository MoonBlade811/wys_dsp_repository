/** ============================================================================
 *   \file  hw_tmr.h
 *
 *   \brief  This file contains the Register Descriptions for Timer
 *
 *  ============================================================================
 */

/*
* Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
*/
/*
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
*
*/



#ifndef _HW_TMR_H_
#define _HW_TMR_H_

#ifdef __cplusplus
extern "C" {
#endif

#define TMR_REVID	(0x0)
#define TMR_EMUMGT	(0x4)
#define TMR_GPINTGPEN	(0x8)
#define TMR_GPDATGPDIR	(0xC)
#define TMR_TIM12	(0x10)
#define TMR_TIM34	(0x14)
#define TMR_PRD12	(0x18)
#define TMR_PRD34	(0x1C)
#define TMR_TCR		(0x20)
#define TMR_TGCR	(0x24)
#define TMR_WDTCR	(0x28)
#define TMR_REL12	(0x34)
#define TMR_REL34	(0x38)
#define TMR_CAP12	(0x3C)
#define TMR_CAP34	(0x40)
#define TMR_INTCTLSTAT	(0x44)
#define TMR_CMP(n)	(0x60 + (n * 4))

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* REVID */

#define TMR_REVID_REV           (0xFFFFFFFFu)
#define TMR_REVID_REV_SHIFT          (0x00000000u)

/* EMUMGT */
#define TMR_EMUMGT_SOFT         (0x00000002u)
#define TMR_EMUMGT_SOFT_SHIFT        (0x00000001u)
/*----SOFT Tokens----*/
#define TMR_EMUMGT_SOFT_IMMEDIATE    (0x00000000u)
#define TMR_EMUMGT_SOFT_INCREMENT    (0x00000001u)

#define TMR_EMUMGT_FREE         (0x00000001u)
#define TMR_EMUMGT_FREE_SHIFT        (0x00000000u)

/* GPINTGPEN */
#define TMR_GPINTGPEN_GPENO34   (0x02000000u)
#define TMR_GPINTGPEN_GPENO34_SHIFT  (0x00000019u)
#define TMR_GPINTGPEN_GPENI34   (0x01000000u)
#define TMR_GPINTGPEN_GPENI34_SHIFT  (0x00000018u)
#define TMR_GPINTGPEN_GPENO12   (0x00020000u)
#define TMR_GPINTGPEN_GPENO12_SHIFT  (0x00000011u)
#define TMR_GPINTGPEN_GPENI12   (0x00010000u)
#define TMR_GPINTGPEN_GPENI12_SHIFT  (0x00000010u)
#define TMR_GPINTGPEN_GPINT34INVO (0x00002000u)
#define TMR_GPINTGPEN_GPINT34INVO_SHIFT (0x0000000Du)
#define TMR_GPINTGPEN_GPINT34INVI (0x00001000u)
#define TMR_GPINTGPEN_GPINT34INVI_SHIFT (0x0000000Cu)
#define TMR_GPINTGPEN_GPINT34ENO (0x00000200u)
#define TMR_GPINTGPEN_GPINT34ENO_SHIFT (0x00000009u)
#define TMR_GPINTGPEN_GPINT34ENI (0x00000100u)
#define TMR_GPINTGPEN_GPINT34ENI_SHIFT (0x00000008u)
#define TMR_GPINTGPEN_GPINT12INVO (0x00000020u)
#define TMR_GPINTGPEN_GPINT12INVO_SHIFT (0x00000005u)
#define TMR_GPINTGPEN_GPINT12INVI (0x00000010u)
#define TMR_GPINTGPEN_GPINT12INVI_SHIFT (0x00000004u)
#define TMR_GPINTGPEN_GPINT12ENO (0x00000002u)
#define TMR_GPINTGPEN_GPINT12ENO_SHIFT (0x00000001u)
#define TMR_GPINTGPEN_GPINT12ENI (0x00000001u)
#define TMR_GPINTGPEN_GPINT12ENI_SHIFT (0x00000000u)

/* GPDATGPDIR */
#define TMR_GPDATGPDIR_GPDIRO34 (0x02000000u)
#define TMR_GPDATGPDIR_GPDIRO34_SHIFT (0x00000019u)
#define TMR_GPDATGPDIR_GPDIRI34 (0x01000000u)
#define TMR_GPDATGPDIR_GPDIRI34_SHIFT (0x00000018u)
#define TMR_GPDATGPDIR_GPDIRO12 (0x00020000u)
#define TMR_GPDATGPDIR_GPDIRO12_SHIFT (0x00000011u)
#define TMR_GPDATGPDIR_GPDIRI12 (0x00010000u)
#define TMR_GPDATGPDIR_GPDIRI12_SHIFT (0x00000010u)
#define TMR_GPDATGPDIR_GPDATO34 (0x00000200u)
#define TMR_GPDATGPDIR_GPDATO34_SHIFT (0x00000009u)
#define TMR_GPDATGPDIR_GPDATI34 (0x00000100u)
#define TMR_GPDATGPDIR_GPDATI34_SHIFT (0x00000008u)
#define TMR_GPDATGPDIR_GPDATO12 (0x00000002u)
#define TMR_GPDATGPDIR_GPDATO12_SHIFT (0x00000001u)
#define TMR_GPDATGPDIR_GPDATI12 (0x00000001u)
#define TMR_GPDATGPDIR_GPDATI12_SHIFT (0x00000000u)

/* TIM12 */
#define TMR_TIM12_TIM12         (0xFFFFFFFFu)
#define TMR_TIM12_TIM12_SHIFT        (0x00000000u)

/* TIM34 */
#define TMR_TIM34_TIM34         (0xFFFFFFFFu)
#define TMR_TIM34_TIM34_SHIFT        (0x00000000u)

/* PRD12 */
#define TMR_PRD12_PRD12         (0xFFFFFFFFu)
#define TMR_PRD12_PRD12_SHIFT        (0x00000000u)

/* PRD34 */
#define TMR_PRD34_PRD34         (0xFFFFFFFFu)
#define TMR_PRD34_PRD34_SHIFT        (0x00000000u)

/* TCR */
#define TMR_TCR_CAPEVTMODE34    (0x30000000u)
#define TMR_TCR_CAPEVTMODE34_SHIFT   (0x0000001Cu)
/*----CAPEVTMODE34 Tokens----*/
#define TMR_TCR_CAPEVTMODE34_RISE    (0x00000000u)
#define TMR_TCR_CAPEVTMODE34_FALL    (0x00000001u)
#define TMR_TCR_CAPEVTMODE34_BOTH    (0x00000002u)

#define TMR_TCR_CAPMODE34       (0x08000000u)
#define TMR_TCR_CAPMODE34_SHIFT      (0x0000001Bu)
#define TMR_TCR_READRSTMODE34   (0x04000000u)
#define TMR_TCR_READRSTMODE34_SHIFT  (0x0000001Au)
#define TMR_TCR_TIEN34          (0x02000000u)
#define TMR_TCR_TIEN34_SHIFT         (0x00000019u)
#define TMR_TCR_CLKSRC34        (0x01000000u)
#define TMR_TCR_CLKSRC34_SHIFT       (0x00000018u)
#define TMR_TCR_ENAMODE34       (0x00C00000u)
#define TMR_TCR_ENAMODE34_SHIFT      (0x00000016u)
/*----ENAMODE34 Tokens----*/
#define TMR_TCR_ENAMODE34_EN_ONCE    (0x00000001u)
#define TMR_TCR_ENAMODE34_EN_CONT    (0x00000002u)
#define TMR_TCR_ENAMODE34_EN_CONTRELOAD (0x00000003u)
#define TMR_TCR_PWID34          (0x00300000u)
#define TMR_TCR_PWID34_SHIFT         (0x00000014u)

/*----PWID34 Tokens----*/
#define TMR_TCR_PWID34_ONE_CLK       (0x00000000u)
#define TMR_TCR_PWID34_TWO_CLK       (0x00000001u)
#define TMR_TCR_PWID34_THREE_CLK     (0x00000002u)
#define TMR_TCR_PWID34_FOUR_CLK      (0x00000003u)
#define TMR_TCR_CP34            (0x00080000u)
#define TMR_TCR_CP34_SHIFT           (0x00000013u)
#define TMR_TCR_INVINP34        (0x00040000u)
#define TMR_TCR_INVINP34_SHIFT       (0x00000012u)
#define TMR_TCR_INVOUTP34       (0x00020000u)
#define TMR_TCR_INVOUTP34_SHIFT      (0x00000011u)
#define TMR_TCR_TSTAT34         (0x00010000u)
#define TMR_TCR_TSTAT34_SHIFT        (0x00000010u)
#define TMR_TCR_CAPEVTMODE12    (0x00003000u)
#define TMR_TCR_CAPEVTMODE12_SHIFT   (0x0000000Cu)
/*----CAPEVTMODE12 Tokens----*/
#define TMR_TCR_CAPEVTMODE12_RISE    (0x00000000u)
#define TMR_TCR_CAPEVTMODE12_FALL    (0x00000001u)
#define TMR_TCR_CAPEVTMODE12_BOTH    (0x00000002u)

#define TMR_TCR_CAPMODE12       (0x00000800u)
#define TMR_TCR_CAPMODE12_SHIFT      (0x0000000Bu)
#define TMR_TCR_READRSTMODE12   (0x00000400u)
#define TMR_TCR_READRSTMODE12_SHIFT  (0x0000000Au)
#define TMR_TCR_TIEN12          (0x00000200u)
#define TMR_TCR_TIEN12_SHIFT         (0x00000009u)

#define TMR_TCR_CLKSRC12        (0x00000100u)
#define TMR_TCR_CLKSRC12_SHIFT       (0x00000008u)

#define TMR_TCR_ENAMODE12       (0x000000C0u)
#define TMR_TCR_ENAMODE12_SHIFT      (0x00000006u)
/*----ENAMODE12 Tokens----*/
#define TMR_TCR_ENAMODE12_EN_ONCE    (0x00000001u)
#define TMR_TCR_ENAMODE12_EN_CONT    (0x00000002u)
#define TMR_TCR_ENAMODE12_EN_CONTRELOAD (0x00000003u)

#define TMR_TCR_PWID12          (0x00000030u)
#define TMR_TCR_PWID12_SHIFT         (0x00000004u)
/*----PWID12 Tokens----*/
#define TMR_TCR_PWID12_ONE_CLK       (0x00000000u)
#define TMR_TCR_PWID12_TWO_CLK       (0x00000001u)
#define TMR_TCR_PWID12_THREE_CLK     (0x00000002u)
#define TMR_TCR_PWID12_FOUR_CLK      (0x00000003u)

#define TMR_TCR_CP12            (0x00000008u)
#define TMR_TCR_CP12_SHIFT           (0x00000003u)
#define TMR_TCR_INVINP12        (0x00000004u)
#define TMR_TCR_INVINP12_SHIFT       (0x00000002u)
#define TMR_TCR_INVOUTP12       (0x00000002u)
#define TMR_TCR_INVOUTP12_SHIFT      (0x00000001u)
#define TMR_TCR_TSTAT12         (0x00000001u)
#define TMR_TCR_TSTAT12_SHIFT        (0x00000000u)

/* TGCR */
#define TMR_TGCR_TDDR34         (0x0000F000u)
#define TMR_TGCR_TDDR34_SHIFT        (0x0000000Cu)
#define TMR_TGCR_PSC34          (0x00000F00u)
#define TMR_TGCR_PSC34_SHIFT         (0x00000008u)
#define TMR_TGCR_PLUSEN         (0x00000010u)
#define TMR_TGCR_PLUSEN_SHIFT        (0x00000004u)
#define TMR_TGCR_TIMMODE        (0x0000000Cu)
#define TMR_TGCR_TIMMODE_SHIFT       (0x00000002u)
/*----TIMMODE Tokens----*/
#define TMR_TGCR_TIMMODE_64BIT_GPT   (0x00000000u)
#define TMR_TGCR_TIMMODE_32BIT_UNCHAIN (0x00000001u)
#define TMR_TGCR_TIMMODE_64BIT_WDT   (0x00000002u)
#define TMR_TGCR_TIMMODE_32_CHAIN    (0x00000003u)

#define TMR_TGCR_TIM34RS        (0x00000002u)
#define TMR_TGCR_TIM34RS_SHIFT       (0x00000001u)
#define TMR_TGCR_TIM12RS        (0x00000001u)
#define TMR_TGCR_TIM12RS_SHIFT       (0x00000000u)

/* WDTCR */
#define TMR_WDTCR_WDKEY         (0xFFFF0000u)
#define TMR_WDTCR_WDKEY_SHIFT        (0x00000010u)
/*----WDKEY Tokens----*/
#define TMR_WDTCR_WDKEY_CMD1         (0x0000A5C6u)
#define TMR_WDTCR_WDKEY_CMD2         (0x0000DA7Eu)

#define TMR_WDTCR_WDFLAG        (0x00008000u)
#define TMR_WDTCR_WDFLAG_SHIFT       (0x0000000Fu)
#define TMR_WDTCR_WDEN          (0x00004000u)
#define TMR_WDTCR_WDEN_SHIFT         (0x0000000Eu)

/* REL12 */
#define TMR_REL12_REL12         (0xFFFFFFFFu)
#define TMR_REL12_REL12_SHIFT        (0x00000000u)

/* REL34 */
#define TMR_REL34_REL34         (0xFFFFFFFFu)
#define TMR_REL34_REL34_SHIFT        (0x00000000u)

/* CAP12 */
#define TMR_CAP12_CAP12         (0xFFFFFFFFu)
#define TMR_CAP12_CAP12_SHIFT        (0x00000000u)

/* CAP34 */
#define TMR_CAP34_CAP34         (0xFFFFFFFFu)
#define TMR_CAP34_CAP34_SHIFT        (0x00000000u)

/* INTCTLSTAT */
#define TMR_INTCTLSTAT_EVTINTSTAT34 (0x00080000u)
#define TMR_INTCTLSTAT_EVTINTSTAT34_SHIFT (0x00000013u)
#define TMR_INTCTLSTAT_EVTINTEN34 (0x00040000u)
#define TMR_INTCTLSTAT_EVTINTEN34_SHIFT (0x00000012u)
#define TMR_INTCTLSTAT_PRDINTSTAT34 (0x00020000u)
#define TMR_INTCTLSTAT_PRDINTSTAT34_SHIFT (0x00000011u)
#define TMR_INTCTLSTAT_PRDINTEN34 (0x00010000u)
#define TMR_INTCTLSTAT_PRDINTEN34_SHIFT (0x00000010u)
#define TMR_INTCTLSTAT_EVTINTSTAT12 (0x00000008u)
#define TMR_INTCTLSTAT_EVTINTSTAT12_SHIFT (0x00000003u)
#define TMR_INTCTLSTAT_EVTINTEN12 (0x00000004u)
#define TMR_INTCTLSTAT_EVTINTEN12_SHIFT (0x00000002u)
#define TMR_INTCTLSTAT_PRDINTSTAT12 (0x00000002u)
#define TMR_INTCTLSTAT_PRDINTSTAT12_SHIFT (0x00000001u)
#define TMR_INTCTLSTAT_PRDINTEN12 (0x00000001u)
#define TMR_INTCTLSTAT_PRDINTEN12_SHIFT (0x00000000u)

/* CMP */
#define TMR_CMP0_CMP           (0xFFFFFFFFu)
#define TMR_CMP0_CMP_SHIFT          (0x00000000u)

#ifdef __cplusplus
}
#endif

#endif


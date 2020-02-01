/*************************************************************************************
* @file         f_systemDef.h
* @author       Guangwei Huang
* @date         2018-07-11
* @attention     
* @Revision History
------------------------------------------------------------------------------------
* Version        Date         Author               Description
*-----------------------------------------------------------------------------------
* 00.01.00       2018-07-11   Guangwei Huang       Initial Version

*************************************************************************************/


#ifndef __F_SYSTEMDEF_H
#define __F_SYSTEMDEF_H
/*************************************************************************************
* INCLUDES
*************************************************************************************/

/*************************************************************************************
* FUNCTION PROTOTYPES
*************************************************************************************/

/*************************************************************************************
* GLOBAL CONSTANT MACROS
*************************************************************************************/
/* System Clock */
#define SYS_CLOCK_REG                   (NULL)
	
/* CPU Clock 168MHz */
#define CPU_CLOCK                       (168U)  

/* SYS TICK CLK 21MHz*/
#define SYS_TICK_CLOCK                  (CPU_CLOCK/8U)

/* Clock Ticker For Time Slice */
#define TIME_01MS                       (SYS_TICK_CLOCK * 1000000UL / 10000UL)    /* 0.1 MS */
#define TIME_05MS                       (TIME_01MS * 5U)                          /* 0.5 MS */
#define TIME_1MS                        (TIME_01MS * 10U)                         /* 1 MS */
#define TIME_2MS                        (TIME_01MS * 20U)                         /* 2 MS */
#define TIME_10MS                       (TIME_01MS * 100U)                        /* 10 MS */

/************************************************************************************
* Standard Data Type Definitions 
************************************************************************************/
typedef unsigned short      bool;
typedef unsigned char       u8;
typedef signed short        s16;
typedef signed int          s32;
typedef signed long         s64;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long       u64;
	
/* Standard Recturn Code for Success.*/
#ifndef TRUE
#define TRUE               ((bool)1U)
#endif
/* Standard Recturn Code for failure/error. */
#ifndef FALSE
#define FALSE              ((bool)0U)
#endif
/* Standard Recturn Code for none. */
#define NULL               (0)
/* Bit number in one word */
#define WORD_BIT_NUM                    (16U)
	
/* Number type 0:Decimal 1:Hexadecimal */
#define NUM_TYPE_DEC (0U)
#define NUM_TYPE_HEX (1U)
	
/* Mask Code for bit0~bit32. */
#define BIT0    (0x00000001UL)
#define BIT1    (0x00000002UL)
#define BIT2    (0x00000004UL)
#define BIT3    (0x00000008UL)
#define BIT4    (0x00000010UL)
#define BIT5    (0x00000020UL)
#define BIT6    (0x00000040UL)
#define BIT7    (0x00000080UL)
#define BIT8    (0x00000100UL)
#define BIT9    (0x00000200UL)
#define BIT10   (0x00000400UL)
#define BIT11   (0x00000800UL)
#define BIT12   (0x00001000UL)
#define BIT13   (0x00002000UL)
#define BIT14   (0x00004000UL)
#define BIT15   (0x00008000UL)
#define BIT16   (0x00010000UL)
#define BIT17   (0x00020000UL)
#define BIT18   (0x00040000UL)
#define BIT19   (0x00080000UL)
#define BIT20   (0x00100000UL)
#define BIT21   (0x00200000UL)
#define BIT22   (0x00400000UL)
#define BIT23   (0x00800000UL)
#define BIT24   (0x01000000UL)
#define BIT25   (0x02000000UL)
#define BIT26   (0x04000000UL)
#define BIT27   (0x08000000UL)
#define BIT28   (0x10000000UL)
#define BIT29   (0x20000000UL)
#define BIT30   (0x40000000UL)
#define BIT31   (0x80000000UL)

/* Time unit */
#define TIME_UNIT_SEC_PER_HOUR      (3600U)    /* 1hour = 3600sec */
#define TIME_UNIT_MIN_PER_HOUR      (60U)      /* 1hour = 60min */
#define TIME_UNIT_SEC_PER_MIN       (60U)
#define TIME_UNIT_MS_PER_SEC        (1000U)    /* 1s = 1000ms */

#endif
/*********************************** END OF FILE ************************************/

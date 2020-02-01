/*************************************************************************************
* @file         main.c
* @author       Guangwei Huang
* @date         2018-09-06
* @attention     
* @Revision History
------------------------------------------------------------------------------------
* Version        Date         Author               Description
*-----------------------------------------------------------------------------------
* 00.01.00       2018-09-06   Guangwei Huang       Initial Version

*************************************************************************************/

/*************************************************************************************
* INCLUDES
*************************************************************************************/
#include "stm32f4xx.h"
#include "f_systemDef.h"
#include "led.h"

/*************************************************************************************
* VARIABLE DEFINITION AND DECLARATION
*************************************************************************************/
#define GET_TIME()   (SysTick->VAL)
u16 u16LoopFlag = 0u;

/*************************************************************************************
* FUNCTION PROTOTYPES
*************************************************************************************/
void SystemDeltaTime(u32 u32DelayTime);
void RCC_HSE_Config(u32 pllm,u32 plln,u32 pllp,u32 pllq);
void InitSysTick(void);
void TaskLoop1MS(void);

/*******************************************************************************
* 函 数 名          : main
* 函数功能		     : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
int main()
{
    u32 u32BaseTime, u32DeltaTime; 
    RCC_HSE_Config(8, 336, 2, 7);  // cpu clock 168MHz
    InitSysTick();
    LED_Init();
    while(1)
    {
        SystemDeltaTime((u32)TIME_1MS);
        TaskLoop1MS();
    }
}

/*=============================================================================*
 * FUNCTION: InitSysTick
 * PURPOSE : init system clock
 * INPUT:    void
 * RETURN:   void
 * Author:   huangguangwei
 * Date:     2018/09/13
 * Modified:   
 *=============================================================================*/
void InitSysTick(void)
{
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);    // sys tick clock 21MHz
    SysTick->LOAD = 0xFFFFFF;
    SysTick->VAL = 0x00;                                     // clear count
    SysTick->CTRL |= 0x01;                                   // start countdown
}

/*=============================================================================*
 * FUNCTION: SystemDeltaTime
 * PURPOSE : Calculation system clock time
 * INPUT:    u32delayTimeMS
 * RETURN:   void
 * Author:   huangguangwei
 * Date:     2018/09/03
 * Modified:   
 *=============================================================================*/
void SystemDeltaTime(u32 u32delayTimeMS)
{
    
}

/*******************************************************************************
* FUNCTION: RCC_HSE_Config
* PURPOSE : 自定义系统时钟
* INPUT   : pllm：VCO 输入时钟 分频因子，范围0-63
            plln：VCO 输出时钟 倍频因子，范围192-432
            pllp：PLLCLK 时钟分频因子，范围2, 4, 6, or 8
            pllq：OTG FS,SDIO,RNG 时钟分频因子，范围4-15
* RETURN  : void
stm32 clock config
https://blog.csdn.net/jdsnpgxj/article/details/72149501
*******************************************************************************/
void RCC_HSE_Config(u32 pllm,u32 plln,u32 pllp,u32 pllq)
{
    RCC_DeInit(); //将外设RCC寄存器重设为缺省值
    RCC_HSEConfig(RCC_HSE_ON);//设置外部高速晶振（HSE）
    if(RCC_WaitForHSEStartUp()==SUCCESS) //等待HSE起振
    {
        RCC_HCLKConfig(RCC_SYSCLK_Div1);//设置AHB时钟（HCLK）
        RCC_PCLK2Config(RCC_HCLK_Div2);//设置低速APB2时钟（PCLK2）
        RCC_PCLK1Config(RCC_HCLK_Div4);//设置低速APB1时钟（PCLK1）
        RCC_PLLConfig(RCC_PLLSource_HSE,pllm,plln,pllp,pllq);//设置PLL时钟源及倍频系数
        RCC_PLLCmd(ENABLE); //使能或者失能PLL
        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);//检查指定的RCC标志位设置与否,PLL就绪
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//设置系统时钟（SYSCLK）
        while(RCC_GetSYSCLKSource()!=0x08);//返回用作系统时钟的时钟源,0x08：PLL作为系统时钟
    }	
}

/*=============================================================================*
 * FUNCTION: TaskLoop1MS
 * PURPOSE : task every 1ms loop
 * INPUT:    void
 * RETURN:   void
 * Author:   huangguangwei
 * Date:     2018/09/03
 * Modified:   
 *=============================================================================*/
void TaskLoop1MS(void)
{
    Flash_LED();
    if (0U == (u16LoopFlag & 0x03U))
    {

    }
    else if (1U == (u16LoopFlag & 0x03U))
    {

    }
    else if (2U == (u16LoopFlag & 0x03U))
    {

    }
    else if (3U == (u16LoopFlag & 0x03U))
    {

    }
    else
    {
        /* do nothing */
    }
    
    // FeedDog();
		
    u16LoopFlag++;
}

/*********************************** END OF FILE ************************************/


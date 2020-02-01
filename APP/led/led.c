/*************************************************************************************
* @file         led.c
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
#include "led.h"
#include "publicFunction.h"

/*******************************************************************************
* FUNCTION: LED_Init
* PURPOSE : LED_Init
* INPUT:    void
* RETURN:   void
* Author:   huangguangwei
* Date:     2018/09/03
* Modified:   
*******************************************************************************/
void LED_Init()
{
    GPIO_InitTypeDef GPIO_InitStructure; //定义结构体变量

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE); //使能端口F时钟

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; //输出模式
    GPIO_InitStructure.GPIO_Pin = (GPIOF, GPIO_Pin_9);//管脚设置F9
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//速度为100M
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
    GPIO_Init(GPIOF, &GPIO_InitStructure); //初始化结构体
    GPIO_SetBits(GPIOF, (GPIOF, GPIO_Pin_9));
}

/*******************************************************************************
* FUNCTION: Flash_LED
* PURPOSE : 
* INPUT:    void
* RETURN:   void
* Author:   huangguangwei
* Date:     2018/09/03
* Modified:   
*******************************************************************************/
void Flash_LED(void)
{
    static bool ledoff = TRUE;
    static u16  timeDelay = 0u;
    if (Func_DelayTimeU16(&timeDelay, 5*TIME_UNIT_MS_PER_SEC, TIME_1MS))
    {
        timeDelay = 0u;
        if(ledoff == TRUE)
        {
            GPIO_SetBits(GPIOF,(GPIOF,GPIO_Pin_9));   // 置位F9
        }
        else
        {
            GPIO_ResetBits(GPIOF,GPIO_Pin_9);         // 复位F9
        }
        ledoff = ~ledoff;
    }
}

/*********************************** END OF FILE ************************************/


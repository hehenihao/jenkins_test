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
    GPIO_InitTypeDef GPIO_InitStructure; //����ṹ�����

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE); //ʹ�ܶ˿�Fʱ��

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; //���ģʽ
    GPIO_InitStructure.GPIO_Pin = (GPIOF, GPIO_Pin_9);//�ܽ�����F9
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//�ٶ�Ϊ100M
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
    GPIO_Init(GPIOF, &GPIO_InitStructure); //��ʼ���ṹ��
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
            GPIO_SetBits(GPIOF,(GPIOF,GPIO_Pin_9));   // ��λF9
        }
        else
        {
            GPIO_ResetBits(GPIOF,GPIO_Pin_9);         // ��λF9
        }
        ledoff = ~ledoff;
    }
}

/*********************************** END OF FILE ************************************/


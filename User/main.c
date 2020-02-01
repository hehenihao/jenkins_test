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
* �� �� ��          : main
* ��������		     : ������
* ��    ��         : ��
* ��    ��         : ��
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
* PURPOSE : �Զ���ϵͳʱ��
* INPUT   : pllm��VCO ����ʱ�� ��Ƶ���ӣ���Χ0-63
            plln��VCO ���ʱ�� ��Ƶ���ӣ���Χ192-432
            pllp��PLLCLK ʱ�ӷ�Ƶ���ӣ���Χ2, 4, 6, or 8
            pllq��OTG FS,SDIO,RNG ʱ�ӷ�Ƶ���ӣ���Χ4-15
* RETURN  : void
stm32 clock config
https://blog.csdn.net/jdsnpgxj/article/details/72149501
*******************************************************************************/
void RCC_HSE_Config(u32 pllm,u32 plln,u32 pllp,u32 pllq)
{
    RCC_DeInit(); //������RCC�Ĵ�������Ϊȱʡֵ
    RCC_HSEConfig(RCC_HSE_ON);//�����ⲿ���پ���HSE��
    if(RCC_WaitForHSEStartUp()==SUCCESS) //�ȴ�HSE����
    {
        RCC_HCLKConfig(RCC_SYSCLK_Div1);//����AHBʱ�ӣ�HCLK��
        RCC_PCLK2Config(RCC_HCLK_Div2);//���õ���APB2ʱ�ӣ�PCLK2��
        RCC_PCLK1Config(RCC_HCLK_Div4);//���õ���APB1ʱ�ӣ�PCLK1��
        RCC_PLLConfig(RCC_PLLSource_HSE,pllm,plln,pllp,pllq);//����PLLʱ��Դ����Ƶϵ��
        RCC_PLLCmd(ENABLE); //ʹ�ܻ���ʧ��PLL
        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);//���ָ����RCC��־λ�������,PLL����
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//����ϵͳʱ�ӣ�SYSCLK��
        while(RCC_GetSYSCLKSource()!=0x08);//��������ϵͳʱ�ӵ�ʱ��Դ,0x08��PLL��Ϊϵͳʱ��
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


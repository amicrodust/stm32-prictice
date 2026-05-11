/**
 * stm32f103c8t6 经典项目
 * 
 * PIN_A0: LED小灯每秒闪烁一次
 * B12(SDA),B13(SCL): Num计次加一并显示在OLED屏幕上
 * 
 */




#include "stm32f10x.h"
#include "cmsis_os2.h"
#include "stm32f10x_rcc.h"
#include "system_stm32f10x.h"

#include "OLED.h"  
#include "Delay.h"


int main(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    


    int32_t Num = 0;

    OLED_Init();
    OLED_ShowString(1, 3, "Hello, World!");
    OLED_ShowString(2, 1, "Num:");
    while (1) {

        GPIO_SetBits(GPIOA, GPIO_Pin_0);
        Delay_ms(100);
        Num++;
        OLED_ShowNum(2, 5, Num, 5);
        GPIO_ResetBits(GPIOA, GPIO_Pin_0);
        Delay_ms(900);
    }
    return 0;
}

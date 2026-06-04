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

#include "Delay.h"
#include "OLED.h"
#include "Timer.h"

uint16_t count = 0;

void Watch_Time(uint16_t* CNT);

int main(void)
{
    Delay_ms(20);
    OLED_Init();
    Timer_Init();
    OLED_ShowString(1, 5 , "|CLOCK|");
    while (1) {
        Watch_Time(&count);
        if (count > 86400){
            count = 0;
        }
    }
}

void Watch_Time(uint16_t* CNT){
    static uint8_t second = 0;
    static uint8_t minute = 0;
    static uint8_t hour   = 0;

    hour = *CNT / 3600;
    minute = (*CNT % 3600) / 60;
    second = (*CNT % 3600) % 60;

    OLED_ShowNum(2, 4, hour, 2);
    OLED_ShowChar(2, 6, ':');
    OLED_ShowNum(2, 7, minute, 2);
    OLED_ShowChar(2, 9, ':');
    OLED_ShowNum(2, 10, second, 2);
}

void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        count++;
    }
}

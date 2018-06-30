#include"LED.h"
#include "Main.h"
#include "Port.h"

tLED_State led_state = LED_OFF;

//void Delay_MS(tWord delay);

void LED_Init(void)
{
    GPIO_InitPortPin(LED_PORT_CR, LED_PIN, GPIO_OUT);
    GPIO_WritePortPin(LED_PORT_DR, LED_PIN, LED_OFF);
}

void LED_Toggle(void)
{
    if(led_state == LED_OFF)
    {
        GPIO_WritePortPin(LED_PORT_DR, LED_PIN, LED_ON);
        led_state = LED_ON;
    }
    else
    {
        GPIO_WritePortPin(LED_PORT_DR, LED_PIN, LED_OFF);
        led_state = LED_OFF;
    }
}

tLED_State LED_GetState(void)
{
    return led_state;
}

//void Delay_MS(tWord delay)
//{
//    tWord x;
//    tWord y;
//
//    for (x = 0; x <= delay; x++){
//        for (y = 0; y <= 120; y++);
//    }
//}

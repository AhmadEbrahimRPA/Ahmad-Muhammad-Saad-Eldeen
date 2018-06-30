#include "SW.h"
#include "LED.h"
#include "UART.h"
#include "Sensor.h"
#include "Timer.h"
#include "Control.h"
#include "Main.h"
#include "Port.h"

/* Configuration bits: adapt to your setup and needs */
unsigned int __at (0x2007) CONFIG = _HS_OSC & _WDT_OFF & _PWRTE_ON & _BODEN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _DEBUG_OFF & _CP_OFF;



void main()
{
    /* Initialization */
    SW_Init();
    LED_Init();
    UART_init();
    sensor_init();
    TMR_Init();
    TMR_Start();

    while(1)
    {
        /* Do Nothing
        if (GPIO_ReadPortPin(SW_PORT_DR, SW_PIN) == PRESSED_LEVEL)
        {
            Delay_MS(30);
            if (GPIO_ReadPortPin(SW_PORT_DR, SW_PIN) == PRESSED_LEVEL)
                LED_Toggle();
        }
        Delay_MS(30);
        */
    }
}




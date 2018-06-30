#include "Control.h"
#include "Timer.h"
#include "Main.h"
#include "SW.h"
#include "LED.h"
#include "UART.h"

#define CTRL_PREIOD   50

void Control(void)
{
    /*
    -wait its period
    -check sw if pre pressed or not
    -if yes toggle LED then send SW & LED states
    */
    static tByte ctrl_counter = 0;
    ctrl_counter += TMR_TICK_MS;
    if(ctrl_counter != CTRL_PREIOD)
    {
        return;
    }
    ctrl_counter = 0;

    if(SW_GetState() == SW_PRE_PRESSED)
    {
        LED_Toggle();
        UART_tx_str("pressed");
        if(LED_GetState() == LED_OFF)
            UART_tx_str("OFF");
        else
            UART_tx_str("ON");
    }
    else
    {
        /* Do Nothing */
    }
}

#include"SW.h"
#include "Main.h"
#include "Port.h"
#include "Timer.h"

/*Private constants*/
#define N_SAMPLES   3

/*switch task period*/
#define SWITCH_PREIOD   50

static typedef struct
{
    tSW_State state;
    tByte samples[N_SAMPLES];
}tSW_info;

static tSW_info sw_infos;

void SW_Init(void)
{
    /*
    -init switch Pin as input
    - init switch state as Released
    -init switch samples as RELEASED_LEVEL
    */
    /*init switch Pin as input*/
    GPIO_InitPortPin(SW_PORT_CR,SW_PIN,GPIO_IN);

    /*init switch samples as RELEASED_LEVEL*/
    sw_infos.samples[0] = RELEASED_LEVEL;
    sw_infos.samples[1] = RELEASED_LEVEL;
    sw_infos.samples[2] = RELEASED_LEVEL;

    /*init switch state as Released*/
    sw_infos.state = SW_RELEASED;
}

void SW_Update(void)
{
    /*
    -wait switch task period
    -shift & update samples
    -update state
    -when switch pre pressed toggle led and send sw state and led state
    */
    tByte i = 0;
    static tByte sw_counter = 0;
    sw_counter += TMR_TICK_MS;
    if(sw_counter != SWITCH_PREIOD)
    {
        return;
    }
    sw_counter = 0;

    sw_infos.samples[0] = sw_infos.samples[1];
    sw_infos.samples[1] = sw_infos.samples[2];
    sw_infos.samples[2] = GPIO_ReadPortPin(SW_PORT_DR, SW_PIN);
    switch(sw_infos.state)
    {
    case SW_RELEASED:
        {
            if((sw_infos.samples[2] == PRESSED_LEVEL) &&
                (sw_infos.samples[0] == RELEASED_LEVEL))
                sw_infos.state = SW_PRE_PRESSED;
            break;
        }
    case SW_PRE_PRESSED:
        {
            if((sw_infos.samples[2] == PRESSED_LEVEL) &&
                (sw_infos.samples[1] == PRESSED_LEVEL))
                sw_infos.state = SW_PRESSED;
            break;
        }
    case SW_PRESSED:
        {
            if((sw_infos.samples[2] == RELEASED_LEVEL) &&
                (sw_infos.samples[0]  == PRESSED_LEVEL))
                sw_infos.state = SW_PRE_RELEASED;
            break;
        }
    case SW_PRE_RELEASED:
        {
            if((sw_infos.samples[2] == RELEASED_LEVEL) &&
                (sw_infos.samples[1] == RELEASED_LEVEL))
                sw_infos.state = SW_RELEASED;
            break;
        }
        default:
            /*should not com here*/
            break;
    }
}

tSW_State SW_GetState(void)
{
    return sw_infos.state;
}

#include"ADC.h"

void ADC_Init(tByte clock)
{
    ADC_OFF;
    ADC_SELECT_CLOCK(clock);
    ADC_CONFIGURE_PORT;
}

tWord ADC_Read(tByte channel,tByte adjustment)
{
    static tWord read = 0;
    /*
    -select adjustment
    -select channel
    -go
    -while(go)
    -return read
    */
    ADC_ON;
    ADC_ADJUST_RESULT(adjustment);
    ADC_SELECT_CHANNEL(channel);
    ADC_START_CONVERSION;
    ADC_WAIT_FOR_RESULT;
    read = ADC_READ_RESULT(adjustment);
    ADC_OFF;
    return read;
}

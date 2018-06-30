#include "Sensor.h"
#include "ADC.h"
#include "Timer.h"
#include "UART.h"

#define SENSOR_PERIOD_MS    (3000)
#define SENSOR_CHANNEL      (1)

static tWord sensor;

void sensor_init(void)
{
    ADC_Init(ADC_FOSC_BY_8);
}

void sensor_update(void)
{
    /*
    -waits its period
    -read ADC reading
    -set slider value
    */
    char buffer[4];
    static sensor_period = 0;
    sensor_period += TMR_TICK_MS;
    if(sensor_period != SENSOR_PERIOD_MS)
    {
        return;
    }
    sensor_period = 0;
    sensor = ADC_Read(SENSOR_CHANNEL,ADC_ADJUST_RESULT_LEFT);
    itoa(sensor, buffer);
    UART_tx_str(buffer);
}

tWord get_sensor(void)
{
    return sensor;
}

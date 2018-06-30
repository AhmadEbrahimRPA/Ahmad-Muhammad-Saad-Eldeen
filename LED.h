#ifndef __LED_H__
#define __LED_H__


typedef enum
{
   LED_OFF = 0,
   LED_ON
}tLED_State;

void LED_Init(void);
void LED_Toggle(void);
tLED_State LED_GetState(void);
#endif

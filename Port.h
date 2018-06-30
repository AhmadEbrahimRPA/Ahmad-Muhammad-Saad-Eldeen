/*File abstract PCB */

#ifndef __PORT_H__
#define __PORT_H__

#include "Main.h"


/* LED PIN */
#define LED_PORT_DR   (GPIO_PORTB_DATA)
#define LED_PORT_CR   (GPIO_PORTB_DIRECTION)
#define LED_PIN       (GPIO_PIN_2)


/* Switch PIN */
#define SW_PORT_DR   (GPIO_PORTB_DATA)
#define SW_PORT_CR   (GPIO_PORTB_DIRECTION)
#define SW_PIN       (GPIO_PIN_1)


#endif // __PORT_H__

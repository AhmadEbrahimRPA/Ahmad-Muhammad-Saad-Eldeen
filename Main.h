/*File abstract micro controller PIC16f877a*/

#ifndef __MAIN_H__
#define __MAIN_H__

#include <pic16f877a.h>

/* GPIO definitions */

/* GPIO Pins */

#define GPIO_PIN_0              (0)
#define GPIO_PIN_1              (1)
#define GPIO_PIN_2              (2)
#define GPIO_PIN_3              (3)
#define GPIO_PIN_4              (4)
#define GPIO_PIN_5              (5)
#define GPIO_PIN_6              (6)
#define GPIO_PIN_7              (7)

/* GPIO Port Registers redefinition */
#define GPIO_PORTA_DATA         (PORTA)
#define GPIO_PORTA_DIRECTION    (TRISA)

#define GPIO_PORTB_DATA         (PORTB)
#define GPIO_PORTB_DIRECTION    (TRISB)

#define GPIO_PORTC_DATA         (PORTC)
#define GPIO_PORTC_DIRECTION    (TRISC)

#define GPIO_PORTD_DATA         (PORTD)
#define GPIO_PORTD_DIRECTION    (TRISD)

#define GPIO_PORTE_DATA         (PORTE)
#define GPIO_PORTE_DIRECTION    (TRISE)

/* GPIO direction setting */
#define GPIO_OUT                (0)
#define GPIO_IN                 (1)

/* GPIO port operations */
#define GPIO_InitPort(CONTROL, DIRECTION)   ((CONTROL) = (DIRECTION)?(~GPIO_OUT):(GPIO_OUT))
#define GPIO_WritePort(PORT, DATA)          ((PORT) = (DATA))
#define GPIO_ReadPort(PORT)                 (PORT)

/* GPIO port pin operations */
#define GPIO_InitPortPin(CONTROL, PIN, DIRECTION)   ((CONTROL) = (CONTROL & (~(1 << PIN)))|(DIRECTION << PIN))
#define GPIO_WritePortPin(PORT, PIN, DATA)          ((PORT) = (PORT & (~(1 << PIN)))|(DATA << PIN))
#define GPIO_ReadPortPin(PORT, PIN)                 (((PORT) & (1 << PIN)) >> (PIN))

/* Timer 0 macros */

#define TMR_SET_PRESCALER_256	PS2 = 1;\
								PS1 = 1;\
								PS0 = 1;\
								PSA = 0

#define TMR_GET_FLAG			(TMR0IF)
#define TMR_CLEAR_FLAG			(TMR0IF = 0)

#define TMR_UPDATE_REGISTER(TIME)		(TMR0 = 256 - ((TIME) * 8))

#define TMR_ENABLE_INTERRUPT	(TMR0IE = 1)
#define GLOBAL_INTERRUPT_ENABLE	(GIE = 1)

#define TMR_ENABLE_CLOCK		(T0CS = 0)
#define TMR_DISABLE_CLOCK		(T0CS = 1)


/* ADC macros */
#define ADC_FOSC_BY_2   (0)
#define ADC_FOSC_BY_8   (1)
#define ADC_FOSC_BY_32  (2)
#define ADC_FRC_L       (3)
#define ADC_FOSC_BY_4   (4)
#define ADC_FOSC_BY_16  (5)
#define ADC_FOSC_BY_64  (6)
#define ADC_FRC_H       (7)

#define ADC_ADJUST_RESULT_LEFT      (0)
#define ADC_ADJUST_RESULT_RIGHT     (1)

#define ADC_OFF (ADON = 0)
#define ADC_ON  (ADON = 1)

#define ADC_SELECT_CLOCK(clock)     (ADCS2 = ((clock) & 0x4) >> 2);\
                                    (ADCS1 = ((clock) & 0x2) >> 1);\
                                    (ADCS0 = ((clock) & 0x1))

#define ADC_CONFIGURE_PORT          PCFG0 = 0; PCFG1 = 1; PCFG2 = 0
#define ADC_ADJUST_RESULT(adjustment)   (ADFM = adjustment)

#define ADC_SELECT_CHANNEL(channel)     (CHS2 = ((channel) & 0x4) >> 2);\
                                        (CHS1 = ((channel) & 0x2) >> 1);\
                                        (CHS0 = ((channel) & 0x1))
#define ADC_START_CONVERSION    (GO = 1)
#define ADC_WAIT_FOR_RESULT     while(GO == 1)
#define ADC_READ_RESULT(adjustment) ((adjustment)? ((((tWord)(ADRESH)) << 8 ) | (ADRESL)) : ((((tWord)(ADRESH)) <<2) | (ADRESL >> 6)))


/*UART macros */
#define EIGHT_BITS_MODE         TX9 = 0, RX9 = 0
#define ENABLE_TRANSMISSION     (TXEN = 1)
#define ASYNC_MODE              (SYNC = 0)
#define HIGH_BAUD_RATE          (BRGH = 1)
#define ENABLE_SERIAL_PORT      (SPEN = 1)
#define CONTINUOUS_RECIEVING    (CREN = 1)
#define BUAD_RATE_9600_4MH      (SPBRG = 25)
#define UART_TX_GET_FLAG		(TXIF)
#define UART_TX_CLEAR_FLAG		(TXIF = 0)
#define UART_TX_REGISTER_STATUS (TRMT)
#define UART_TX_REGISTER        (TXREG)
#define UART_RX_GET_FLAG        (RCIF)
#define UART_RX_CLEAR_FLAG      (RCIF = 0)
#define UART_RX_REGISTER        (RCREG)


/* Standard data types */
typedef unsigned char tByte;
typedef unsigned int tWord;

#endif // __MAIN_H__

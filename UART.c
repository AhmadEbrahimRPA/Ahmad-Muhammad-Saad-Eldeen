#include "UART.h"
#include "Main.h"



void UART_init(void)
{
    // Configure serial port
    // 8 bits tx
    // enable transmission
    // asynchronous mode
    // high baud rate
    // enable serial port - rx
    // 8 bits tx
    // Continuous receiving
    //baud rate is  9600 - 4MHz
    EIGHT_BITS_MODE;
    ENABLE_TRANSMISSION;
    ASYNC_MODE;
    HIGH_BAUD_RATE;
    ENABLE_SERIAL_PORT;
    CONTINUOUS_RECIEVING;
    BUAD_RATE_9600_4MH;
}

void UART_tx(const unsigned char val)
{
    // Send val to serial port
    while(!(UART_TX_REGISTER_STATUS)); // wait till Transmit Shift Register Status bit is empty
    UART_TX_REGISTER = val; // send data
    while(UART_TX_GET_FLAG == 0); // wait till The USART transmit buffer is empty
}

void UART_tx_str(const char* val)
{
    unsigned char i=0;
    while( val[i] )
    {
        UART_tx(val[i]);
        i++;
    }
}


void itoa(unsigned int val, char* str )
{
  str[0]=((val%1000)/100)+0x30;
  str[1]=((val%100)/10)+0x30;
  str[2]=(val%10)+0x30;
  str[3] = '\0';
}


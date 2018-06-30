#ifndef _UART_H_
#define _UART_H_



void UART_init(void);
void UART_tx(const unsigned char val);
void UART_tx_str(const char* val);
void itoa(unsigned int val, char* str );


#endif // _UART_H_

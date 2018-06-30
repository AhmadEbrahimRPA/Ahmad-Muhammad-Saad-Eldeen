#ifndef _ADC_H_
#define _ADC_H_

#include"Main.h"

#define ADC_MAX_VALUE    1023

void ADC_Init(tByte clock);
tWord ADC_Read(tByte channel,tByte adjustment);

#endif // _ADC_H_

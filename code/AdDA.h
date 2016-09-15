#ifndef __ADDA_H_
#define __ADDA_H_

#include"global.h"

sbit ADC_ALE=P2^5;
sbit ADC_B=P2^4;
sbit ADC_A=P2^3;
sbit ADC_EOC=P2^7;
sbit ADC_OE=P2^6;

sbit DAC_CS=P2^0;
sbit DAC_CLK=P2^1;
sbit DAC_DIN=P2^2;

extern unsigned char _daval;
extern unsigned char _adval;
extern void AdDAInit();
extern void AdDaCallBack();
extern unsigned char ADC_count(void);
extern void DAC_count(unsigned int dat_in);

#endif
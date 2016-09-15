#include"seg.h"

unsigned char code dula[16]={0x28,0xEE,0x32,0xA2,0xE4,0xA1,0x21,
				0xEA,0x20,0xA0,0x60,0x25,0x39,0x26,0x31,0x71};
unsigned char code wela[4]={0x70,0xb0,0xd0,0xe0};

unsigned char _displaybuff[4]={1,2,3,4};
unsigned char _weindex=0;
char _keyval=0;

void seginit()
{
	_weindex=0;
	 WE=wela[0];
	 DU=dula[0];
	 CreateTimer(5,segCallback,&segTimer);
}

void SegDisply(char displaybuff[4])
{	
     DU=0xff;
	 _weindex=++_weindex%4;
	 WE=0xf0&wela[_weindex];
	 DU=dula[displaybuff[_weindex]];
	 _displaybuff[0]=_moduleselect;
	_displaybuff[1]=_parameter[_moduleselect]/100;
	_displaybuff[2]=(_parameter[_moduleselect]%100)/10;
	_displaybuff[3]=(_parameter[_moduleselect])%10;
}
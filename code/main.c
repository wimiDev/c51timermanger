#include"global.h"

//c51定时资源初始化
void C51Timer0Init()
{
    TMOD = 0x01;
    TH0 = 0x0F6;
    TL0 = 0x3C;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}
//整个框架的初始化
void init(TimerCallBack yourProjectinit)
{	
	C51Timer0Init();
	TimerMangerInit();
	yourProjectinit(); 
}

void main()
{
	init(waterctrlinit);
	while(1)
	{
	 ClockDistributer();
	}
}	
 void Timer0Interrupt(void) interrupt 1
{
    TH0 = 0x0FE;
    TL0 = 0x0C;
	 AddCount();
}
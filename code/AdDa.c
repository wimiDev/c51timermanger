 #include"AdDa.h"

 unsigned char _daval;
 unsigned char _adval;

void AdDAInit()
{
  _daval=0;

}

void AdDaCallBack()
{
	_adval=ADC_count();
	 _parameter[0]=_adval;
	converTobi(_adval,&_parameter[1]);
	DAC_count(4*_parameter[6]);			
}

unsigned char ADC_count(void)
{
	unsigned char dat_out;
	ADC_A=0;
	ADC_B=1;
	ADC_OE=0;
	ADC_ALE=0;
	ADC_ALE=1;
	ADC_ALE=0;
	P0=0xff;
	if(!ADC_EOC)
	{
		ADC_OE=1;
		dat_out=P0;
	}
	return dat_out;
}

void DAC_count(unsigned int dat_in)
{
 unsigned char index;
	 dat_in <<= 6;
	 DAC_CS=0;
	 DAC_CLK=0; 
	 for(index=0;index<12;index++) 
	 { 
			DAC_DIN=(bit)(dat_in & 0x8000);   
			DAC_CLK=1;
			dat_in <<=1; 
			DAC_CLK=0;
	 }
	 DAC_CS=1; 
	 DAC_CLK=0; 
}

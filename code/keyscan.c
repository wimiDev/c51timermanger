#include"keyscan.h"


unsigned char _keybuff;
char _keystat;


void keyscaninit()
{
   _keystat=0;
   _keybuff=0;
   CreateTimer(200,keyscancallback,&_keyScanTimer);
}
unsigned char keyscan(void)
{
	unsigned char key_temp=0;
	unsigned char key_value=0;
	DU=0xff;
	KEY0=0;KEY1=0;SMG_KEY0=0;SMG_KEY1=1;SMG_KEY2=1;SMG_KEY3=1;
	if(KEY0) key_temp= 5;
	else if(KEY1) key_temp= 1;
	KEY0=0;KEY1=0;SMG_KEY0=1;SMG_KEY1=0;SMG_KEY2=1;SMG_KEY3=1;
	if(KEY0) key_temp= 6;
	else if(KEY1) key_temp= 2;
	KEY0=0;KEY1=0;SMG_KEY0=1;SMG_KEY1=1;SMG_KEY2=0;SMG_KEY3=1;
	if(KEY0) key_temp= 7;
	else if(KEY1) key_temp= 3;
	KEY0=0;KEY1=0;SMG_KEY0=1;SMG_KEY1=1;SMG_KEY2=1;SMG_KEY3=0;
	if(KEY0) key_temp= 8;
	else if(KEY1) key_temp= 4;
	return key_temp;
}
void keyscancallback()
{
	char _keyval=keyscan();
//	_displaybuff[0]=_keyval;
	 if(_keyval>0)
	{
	 _keybuff=_keyval;
	}
	if(_keyval==0)
	{
	 keycallback(_keybuff);
	}
}
//加/减100处理
void addHaner(char add_cut)
{
	if(add_cut==1)
	{
  	 //百位+
	 	if(_parameter[_moduleselect]/100<2)
	 	{
	  	_parameter[_moduleselect]+=100;	
	 	}
	 	else
		 {
	 		_parameter[_moduleselect]-=200;
	 	 }
	}
	else if(add_cut==0)
	{
	//百位-
	  if(_parameter[_moduleselect]/100>=1)
	 {
	  _parameter[_moduleselect]-=100;
	 }
	 else
	 {
	   _parameter[_moduleselect]+=200;
	 }
	}
}
//加/减10处理
void addten(char add_cut)
{  
	if(add_cut==1)
 	 {
  		if((_parameter[_moduleselect]%100)/10<9)
		{
   			_parameter[_moduleselect]+=10;
   		}
		else
		{
		   _parameter[_moduleselect]-=90;
		}
  	 }
   	else	if(add_cut==0)
  	 {
		  if((_parameter[_moduleselect]%100)/10>0)
		  {
		 _parameter[_moduleselect]-=10;
	 	 }
	 	 else
	 	 {
	  		 _parameter[_moduleselect]+=90;
	  	}
  	 }
}
//加/减1处理
void addone(char add_cut)
{
		if(add_cut==1)
 	 {
  		if((_parameter[_moduleselect])%10<9)
		{
   			_parameter[_moduleselect]+=1;
   		}
		else
		{
		   _parameter[_moduleselect]-=9;
		}
  	 }
   	else	if(add_cut==0)
  	 {
		  if((_parameter[_moduleselect])%10>0)
		  {
		 _parameter[_moduleselect]-=1;
	 	 }
	 	 else
	 	 {
	  		 _parameter[_moduleselect]+=9;
	  	}
  	 }
}
void keycallback(unsigned char keyval)
{	
  switch(keyval)
  {
  	case 3:
	{
	 //模式选择 +
	ModuleSelect_1(1);
	}break;
	case 7:
	{
	 //模式选择 - 
	ModuleSelect_1(0);
	}break;
	case 4:
	{
	  addHaner(1);
	}break;
	case 8:
	{
	 addHaner(0);
	}break;
	case 1:
	{
	 //十位+
	 addten(1);
	 }break;
	case 5:
	{
	 //十位-
	 addten(0);
	}break;

	case 2:
	{
	  //各位+
	  addone(1);
	}break;
	case 6:
	{
	  //各位-
	  addone(0);
	}break;
  }
  _keybuff=0;
}
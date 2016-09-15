#include"waterctrl.h"

TIMER segTimer;

TIMER _updateTimer;

TIMER _keyScanTimer;

unsigned char _moduleselect=0;

int _parameter[10]={0,0,0,10,0,0,0,0};
								


void waterctrlinit()
{	
	seginit();
	keyscaninit();
	AdDAInit();
	PidInit();
	_moduleselect=8;
	CreateTimer(3000,update,&_updateTimer);
}

void segCallback()
{
	SegDisply(_displaybuff);
}
void ModuleSelect_1(char add_cut)
{
	 if(add_cut==1)
	 {
		_moduleselect=++_moduleselect%10;
	 }
	 else if(add_cut==0)
	 {	
	 	_moduleselect-=1;
		if(_moduleselect < 0 || _moduleselect>10)
	  	{
		 	_moduleselect = 9;	
	  	}
	}
}
void bipos()
 {
	int err=0;
	int adval=0;
	 converToadval(_parameter[2],&adval);
	 err=adval-_parameter[0]; 
//	_parameter[8]=err;
 	if ( err > 3)
	{
		//Һλδ�ﵽ�趨ֵ
		_parameter[6]=255;
	//	_parameter[9]=1;
	}
	else if(err < -3)
	{
		 //Һλ�����趨ֵ
		_parameter[6]=0;
	//	_parameter[9]=2;
	}
	else
	{
		//�ڷ�Χ��
		_parameter[6] = 80;
	//	_parameter[9]=3;	
	}
 }
void update()
 {	
 	int adval=0;
	AdDaCallBack();
	//pid�Լ�Һλ����
	 converToadval(_parameter[2],&adval);
	if(_parameter[7]==0)
	{
	_parameter[6]=(unsigned char)(PidRealize(adval,_parameter[0]));
	}
	else
	{
		bipos();
	}
 }
void converTobi(int adval,int* out)
{	
	char base=50;
	*out=(int)((adval-base)*10/4);
	if(*out<0)
	{
		*out=0;
	}		
}
void converToadval(int waterval,int* out)
{  
	char base=50;
	*out=(int)(50+(waterval/10*4));
}
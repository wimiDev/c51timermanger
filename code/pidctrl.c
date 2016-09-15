#include"pidctrl.h"

PID _pid;

void PidInit()
{
	_pid._setPoint=0;//设置值
	_pid._actualPoint=0;//当前值
	_pid._err=0;
	_pid._errNext=0;
	_pid._errLast=0;
	_pid._kp=_parameter[3];
	_pid._ki=_parameter[4];
	_pid._kd=_parameter[5];
}
int PidRealize(int setPoint,int actual)
{
	int _increment=0;

	 _pid._kp=_parameter[3];
	_pid._ki=_parameter[4];
	_pid._kd=_parameter[5];
	_pid._setPoint=setPoint;

	_pid._err=_pid._setPoint - actual;

	_increment=_pid._kp*(_pid._err-_pid._errNext)+_pid._ki*_pid._err+_pid._kd*(_pid._err-2*_pid._errNext+_pid._errLast);

	_pid._actualPoint+=_increment;

	_pid._errNext=_pid._err;

	_pid._errLast=_pid._errNext;
	if(_increment>200)
	{
		_increment=200;
	}
	if(_increment<0)
	{
		_increment=0;
	}
	_parameter[8]= _pid._err;
	_parameter[9]=_increment;
	return _increment;
}
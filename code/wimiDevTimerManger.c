#include"wimiDevTimerManger.h"

TIMERMANGER _timerManger;
 void TimerMangerInit()
 {	
 	unsigned char index=0;
	_timerManger._size=0;
	_timerManger._count=0;
	_timerManger._maxcount=0;
	_timerManger._clock=0;
	for(index=0;index<_TIMERPOOL_MAXSIZE;++index)
	{
		_timerManger._TIMERPOOL[index]._time=0;
		_timerManger._TIMERPOOL[index]._timeNow=0;
		_timerManger._TIMERPOOL[index]._enable=0;
	    _timerManger._TIMERPOOL[index]._islive=0;
	    _timerManger._TIMERPOOL[index]._callback=0;
	}
 }
 void AddCount()
 {
 	_timerManger._clock=1;
 	_timerManger._count++;
 }
 void ClockDistributer()
 {
	 if( _timerManger._clock && 
	 _timerManger._count>=_timerManger._maxcount)
	 {
	 	_timerManger._count=0;
		TimerEventDistributer();
	 }
 }
void TimerEventDistributer()
{
	unsigned char index=0;
				
	for(index=0;index<_timerManger._size;++index)
	{  
		if(_timerManger._TIMERPOOL[index]._enable==1)
		{
	  	 _timerManger._TIMERPOOL[index]._timeNow++;
		 if( _timerManger._TIMERPOOL[index]._timeNow >=
		 	 _timerManger._TIMERPOOL[index]._time
	  		)
	   		{
		  		_timerManger._TIMERPOOL[index]._timeNow=0;	
	   	  		_timerManger._TIMERPOOL[index]._callback();
	   		}
	    }
	}
}

 TIMER* CreateTimer(unsigned int time,TimerCallBack callback,TIMER* timerout)
 {	
	timerout=&_timerManger._TIMERPOOL[_timerManger._size];
	if(_timerManger._size<_TIMERPOOL_MAXSIZE)
	{
		_timerManger._size+=1;
	}
	timerout->_time=time;
	timerout->_islive=1;
	timerout->_enable=1;
	timerout->_callback= callback;
	return &timerout; 	
 }
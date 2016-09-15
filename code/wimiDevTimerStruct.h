#ifndef __WIMIDEVTIMERSTRUCT_H_
#define __WIMIDEVTIMERSTRUCT_H_


	typedef  void (*TimerCallBack)();

	typedef struct{
			unsigned char _enable;
			unsigned char _islive;
	  		unsigned int _time;
			unsigned int _timeNow;
			TimerCallBack _callback;
	}TIMER;

#endif
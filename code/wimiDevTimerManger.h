#ifndef __WIMIDEVTIMERMANGER_H_
#define __WIMIDEVTIMERMANGER_H_

#include"global.h"

#define _TIMERPOOL_MAXSIZE 3

//定时器管理结构
typedef struct 
{
  unsigned char _size;	//定时器池当前大小
  unsigned int _count;
  unsigned int _maxcount;
  bit _clock;
 TIMER _TIMERPOOL[_TIMERPOOL_MAXSIZE];//定时器池
}TIMERMANGER;

//定时器管理实例
extern TIMERMANGER _timerManger;

//定时器管理初始化
extern void TimerMangerInit();
//
extern void AddCount();
//定时分发器
extern void ClockDistributer();
//定时器池管理，定时触发
extern void TimerEventDistributer();

//*创建一个定时器
//参数：_time 定时时间，时间到之后触发
// _callback 时间到之后执行该方法
// timerout（输出参数），将申请的定时器通过该参数返回
// ！！！注意：注意定时器个数不能超过定时池大小 
extern TIMER* CreateTimer(unsigned int _timer,TimerCallBack _callback,TIMER* timerout);
#endif
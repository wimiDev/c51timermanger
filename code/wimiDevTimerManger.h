#ifndef __WIMIDEVTIMERMANGER_H_
#define __WIMIDEVTIMERMANGER_H_

#include"global.h"

#define _TIMERPOOL_MAXSIZE 3

//��ʱ������ṹ
typedef struct 
{
  unsigned char _size;	//��ʱ���ص�ǰ��С
  unsigned int _count;
  unsigned int _maxcount;
  bit _clock;
 TIMER _TIMERPOOL[_TIMERPOOL_MAXSIZE];//��ʱ����
}TIMERMANGER;

//��ʱ������ʵ��
extern TIMERMANGER _timerManger;

//��ʱ�������ʼ��
extern void TimerMangerInit();
//
extern void AddCount();
//��ʱ�ַ���
extern void ClockDistributer();
//��ʱ���ع�����ʱ����
extern void TimerEventDistributer();

//*����һ����ʱ��
//������_time ��ʱʱ�䣬ʱ�䵽֮�󴥷�
// _callback ʱ�䵽֮��ִ�и÷���
// timerout�������������������Ķ�ʱ��ͨ���ò�������
// ������ע�⣺ע�ⶨʱ���������ܳ�����ʱ�ش�С 
extern TIMER* CreateTimer(unsigned int _timer,TimerCallBack _callback,TIMER* timerout);
#endif
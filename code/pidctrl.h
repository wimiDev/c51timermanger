#ifndef __PIDCTRL_H_
#define __PIDCTRL_H_ 
#define _MAXPOINT 253
#define _MINIPOINT 0
#include"global.h"
typedef struct
{
 int _setPoint;//设置值
 int _actualPoint;//当前值
 int _err;
 int _errNext;
 int _errLast;
 int _kp;
 int _ki;
 int _kd;
}PID; 

extern PID _pid;

extern void PidInit();
extern int PidRealize(int setPoint,int actual);
#endif
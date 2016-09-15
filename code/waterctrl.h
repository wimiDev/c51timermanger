#ifndef __WATERCTRL_H_
#define __WATERCTRL_H_
#include"global.h"

//0--AD输入
//1--AD标称
//2--设定值
//3--p
//4--i
//5--d
//6--输出
//7--模式
extern int _parameter[10];

//模式选择
extern unsigned char _moduleselect;
//时刻刷新定时器
extern TIMER _updateTimer;
//工程初始化
extern void waterctrlinit();
//显示刷新定时器
extern TIMER segTimer;
extern TIMER _keyScanTimer;
//显示回调
extern void segCallback();
//模式选择，1+，0-
extern void ModuleSelect_1(char add_cut);
//时刻刷新
extern void update();
extern void bipos();
extern void converTobi(int adval,int* out);
extern void converToadval(int waterval,int* out); 
#endif
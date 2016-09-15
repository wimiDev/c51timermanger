#ifndef __KEYSCAN_H_
#define __KEYSCAN_H_

#include"global.h"
sbit ROW1=P3^3;
sbit ROW2=P3^2;
sbit KEY0=P3^2;
sbit KEY1=P3^3;
sbit SMG_KEY0=P3^7;
sbit SMG_KEY1=P3^4;
sbit SMG_KEY2=P3^5;
sbit SMG_KEY3=P3^6;

//键值
extern char _keystat;
//键值
extern unsigned char _keybuff;
//按键初始化
extern void keyscaninit();
extern unsigned char keyscan();
extern void keyscancallback();
//按键处理
extern void keycallback(unsigned char keyval);
//加/减100处理
extern void addHaner(char add_cut);
//加/减10处理
extern void addten(char add_cut);
//加/减1处理
extern void addone(char add_cut);
#endif
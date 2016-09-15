#ifndef __SEG_H_
#define __SEG_H_
#include"global.h"

#define DU P1
#define WE P3

//段码
extern unsigned char code dula[16];
//位码
extern unsigned char code wela[4];
//显示缓存
extern unsigned char _displaybuff[4];
//位显示引索
extern unsigned char _weindex;
//显示初始化
extern void seginit();
//显示在数码管
extern void SegDisply(char displaybuff[4]);

#endif
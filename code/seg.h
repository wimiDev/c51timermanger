#ifndef __SEG_H_
#define __SEG_H_
#include"global.h"

#define DU P1
#define WE P3

//����
extern unsigned char code dula[16];
//λ��
extern unsigned char code wela[4];
//��ʾ����
extern unsigned char _displaybuff[4];
//λ��ʾ����
extern unsigned char _weindex;
//��ʾ��ʼ��
extern void seginit();
//��ʾ�������
extern void SegDisply(char displaybuff[4]);

#endif
#ifndef __WATERCTRL_H_
#define __WATERCTRL_H_
#include"global.h"

//0--AD����
//1--AD���
//2--�趨ֵ
//3--p
//4--i
//5--d
//6--���
//7--ģʽ
extern int _parameter[10];

//ģʽѡ��
extern unsigned char _moduleselect;
//ʱ��ˢ�¶�ʱ��
extern TIMER _updateTimer;
//���̳�ʼ��
extern void waterctrlinit();
//��ʾˢ�¶�ʱ��
extern TIMER segTimer;
extern TIMER _keyScanTimer;
//��ʾ�ص�
extern void segCallback();
//ģʽѡ��1+��0-
extern void ModuleSelect_1(char add_cut);
//ʱ��ˢ��
extern void update();
extern void bipos();
extern void converTobi(int adval,int* out);
extern void converToadval(int waterval,int* out); 
#endif
#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"

sbit Motor=P1^0;

unsigned char Counter,Compare;
unsigned char KeyNum,Speed;

void main ()
{
		Timer0Init();
    while(1)
	{
	     	KeyNum=Key();
				if(KeyNum==1)
				{
					Speed++;
					Speed%=4;
					if(Speed==0){Compare=0;}//���ñȽ�ֵ���ı�PWMռ�ձ�
					if(Speed==1){Compare=50;}
					if(Speed==2){Compare=75;}
					if(Speed==3){Compare=100;}
				}
				Nixie(1,Speed);//�ڵ�һ���������ʾ
	}		
}

void Timer0_Routine() interrupt 1
{

	TL0 = 0x50;		
	TH0 = 0xFB;	
	Counter++;
	Counter%=100;//����ֵ�仯��Χ������0-99
	if(Counter<Compare)//����ֵС�ڱȽ�ֵ
	{
		Motor=1;
	}
	else
	{
		Motor=0;
	}
}
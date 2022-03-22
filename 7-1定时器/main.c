#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"

unsigned char Sec,Min,Hour;

void main ()
{
	LCD_Init();//LCD��ʼ��
	Timer0Init();//Timer0��ʼ��
	LCD_ShowString(1,1,"LOCK");
	LCD_ShowString(2,1,"  :  :");

    while(1)
		{
			LCD_ShowNum(2,1,Hour,2);
			LCD_ShowNum(2,4,Min,2);
			LCD_ShowNum(2,7,Sec,2);
		}		
}
//�жϺ���
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;//�ֲ���̬�������������֮��ñ�����������
	T0Count++;
	//���¸���ֵ
	TH0=64535/256;//��λ
	TL0=64535%256;//��λ
	
	if(T0Count>=1000)
	{
		T0Count=0;//����
//		P2_0=0;//��֤�ж��Ƿ�ִ�У�����Ѿ��ж���LED1����
//		P2_0=~P2_0;//ȡ����LED1��˸
		Sec++;//ÿ��һ��++
		if(Sec>=60)
		{
			Sec=0;
			Min++;
			if(Min>=60)
			{
				Min=0;
				Hour++;
				if(Hour>=24)
				{
					Hour=0;
				}
			}
		}
		
	}

}
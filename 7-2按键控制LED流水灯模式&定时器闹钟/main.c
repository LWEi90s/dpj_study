#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.h> //cror/crol��ѭ������/����

unsigned char KeyNum,LEDMode;

void main()
{
		Timer0Init();//��ʱ����ʼ��
    while(1)
	{
	    KeyNum=Key();
			if(KeyNum)
			{
//				if(KeyNum==1)P3_1=~P3_1;//���Ϊ1�����һ��LED��˸
//				if(KeyNum==2)P3_2=~P3_2;//���Ϊ2�����һ��LED��˸
//				if(KeyNum==3)P3_3=~P3_3;//���Ϊ3�����һ��LED��˸
//				if(KeyNum==4)P3_4=~P3_4;//���Ϊ4�����һ��LED��˸
				if(KeyNum==1)
				{
					LEDMode++;
					if(KeyNum>=2)LEDMode=0;
				}
			}
			
	}		
}

//��ʱ��
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;//�ֲ���̬�������������֮��ñ�����������
	T0Count++;
	//���¸���ֵ
	TH0=64535/256;//��λ
	TL0=64535%256;//��λ
	
	if(T0Count>=500)
	{
		T0Count=0;//����
//		P2_0=0;//��֤�ж��Ƿ�ִ�У�����Ѿ��ж���LED1����
//		P2_0=~P2_0;//ȡ����LED1��˸
		if(LEDMode==0)
		{
			P2=_crol_(P2,1);//����1λ
		}
		if(LEDMode==1)
		{
			P2=_cror_(P2,1);//����1λ
		}
	}

}

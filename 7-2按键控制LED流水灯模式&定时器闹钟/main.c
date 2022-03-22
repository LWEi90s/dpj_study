#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.h> //cror/crol：循环右移/左移

unsigned char KeyNum,LEDMode;

void main()
{
		Timer0Init();//定时器初始化
    while(1)
	{
	    KeyNum=Key();
			if(KeyNum)
			{
//				if(KeyNum==1)P3_1=~P3_1;//如果为1，则第一个LED闪烁
//				if(KeyNum==2)P3_2=~P3_2;//如果为2，则第一个LED闪烁
//				if(KeyNum==3)P3_3=~P3_3;//如果为3，则第一个LED闪烁
//				if(KeyNum==4)P3_4=~P3_4;//如果为4，则第一个LED闪烁
				if(KeyNum==1)
				{
					LEDMode++;
					if(KeyNum>=2)LEDMode=0;
				}
			}
			
	}		
}

//定时器
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;//局部静态变量，程序结束之后该变量继续保存
	T0Count++;
	//重新赋初值
	TH0=64535/256;//高位
	TL0=64535%256;//低位
	
	if(T0Count>=500)
	{
		T0Count=0;//清零
//		P2_0=0;//验证中断是否执行，如果已经中断则LED1会亮
//		P2_0=~P2_0;//取反，LED1闪烁
		if(LEDMode==0)
		{
			P2=_crol_(P2,1);//左移1位
		}
		if(LEDMode==1)
		{
			P2=_cror_(P2,1);//右移1位
		}
	}

}

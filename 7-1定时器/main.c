#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"

unsigned char Sec,Min,Hour;

void main ()
{
	LCD_Init();//LCD初始化
	Timer0Init();//Timer0初始化
	LCD_ShowString(1,1,"LOCK");
	LCD_ShowString(2,1,"  :  :");

    while(1)
		{
			LCD_ShowNum(2,1,Hour,2);
			LCD_ShowNum(2,4,Min,2);
			LCD_ShowNum(2,7,Sec,2);
		}		
}
//中断函数
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;//局部静态变量，程序结束之后该变量继续保存
	T0Count++;
	//重新赋初值
	TH0=64535/256;//高位
	TL0=64535%256;//低位
	
	if(T0Count>=1000)
	{
		T0Count=0;//清零
//		P2_0=0;//验证中断是否执行，如果已经中断则LED1会亮
//		P2_0=~P2_0;//取反，LED1闪烁
		Sec++;//每隔一秒++
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
#include <REGX52.H>

/**
  * @brief  定时器
  * @param  |
  * @param  |
  * @param  |
  * @retval 无
  */
void Timer0Init()
{
//	TMOD=0x01;//0000 0001
	TMOD=TMOD&0xF0;//把TMOD的低四位清零，高四位不变；在高四位 1&任何一个数=1   低四位0&任何一个数=0
	TMOD=TMOD&0xF1;//把TMOD的最低位置1，高四位不变
	TF0=0;
	TR0=1;
	TH0=64535/256;//高位
	TL0=64535%256;//低位
	ET0=1;//允许中断
	EA=1;//允许中断
	PT0=0;//低优先级
}

/*定时器中断函数模板
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
		P2_0=~P2_0;//取反，LED1闪烁
	}

}

*/

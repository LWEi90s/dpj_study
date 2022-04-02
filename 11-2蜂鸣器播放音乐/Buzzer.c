#include <REGX52.H>
#include <INTRINS.H>

//蜂鸣器端口
sbit Buzzer=P1^5;
unsigned int i;
/**
  * @brief  蜂鸣器私有延时函数，延时500us
  * @param  |
  * @param  |
  * @param  |
  * @retval 无
  */
void Buzzer_Delay500us()		//@12.000MHz
{
	unsigned char i;

	_nop_();
	i = 247;
	while (--i);
}

/**
  * @brief  蜂鸣器发生，
  * @param  毫秒ms 发生的时间时长
  * @param  |
  * @param  |
  * @retval ��
  */
void Buzzer_Time(unsigned int ms)
{
	for(i=0;i<ms*2;i++)
			{
				Buzzer=!Buzzer;
				uzzer_Delay500us();
		}
}
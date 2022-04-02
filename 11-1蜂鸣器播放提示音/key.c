#include <REGX52.H>
#include "Delay.h"

/**
  * @brief  获取独立按键键码
  * @param  无
  * @param  |
  * @param  |
  * @retval 按下按键的键码。范围：0~4； 无按键按下时返回值为0
  */
unsigned char Key()
{
	unsigned char KeyNumber=0;
	//按键检测
	if(P3_1==0)
	{
		Delay(20);
		while(P3_1==0);
		Delay(20);
		KeyNumber=1;
	}
	if(P3_2==0)
	{
		Delay(20);
		while(P3_2==0);
		Delay(20);
		KeyNumber=1;
	}
	if(P3_3==0)
	{
		Delay(20);
		while(P3_3==0);
		Delay(20);
		KeyNumber=1;
	}
	if(P3_4==0)
	{
		Delay(20);
		while(P3_4==0);
		Delay(20);
		KeyNumber=1;
	}
	return KeyNumber;
}
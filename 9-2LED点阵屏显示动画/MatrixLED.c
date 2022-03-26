#include <REGX52.H>
#include "Delay.h"

#define MATRIX_LED_PORT P0

//74HC595
sbit RCK=P3^5;//位声明P35RCLK
sbit SCK=P3^6;//串行时钟P36SRCLK
sbit SER=P3^4;//P34SER

/**
  * @brief  74HC595写入一个字节
  * @param  要写入的字节
  * @param  |
  * @param  |
  * @retval 无
  */
void _74HC595_WriteByte(unsigned char Byte)
{
	//赋值
	unsigned char i;
	for(i=0;i<8;i++)
	{
			SER=Byte&(0x80>>i);//向右移动i位
			SCK=1;
			SCK=0;
	}
			RCK=1;//上升沿
			RCK=0;
	
}

/**
  * @brief  LED点阵屏显示一列数据
  * @param  coloum 要选择的列，范围0-7   0在最左边
  * @param  d
  * @param  |
  * @retval 无
  */
void MatrixLED_ShowColumn(unsigned char Column,Data )
{
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT=~(0x80>>Column);//0x80为1；当coloumn=0时，P0=0；当coloumn=1,p0=1;
	Delay(1);
	MATRIX_LED_PORT=0xFF;
}


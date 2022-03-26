#include <REGX52.H>
#include "Delay.h"

#define MATRIX_LED_PORT P0

//74HC595
sbit RCK=P3^5;//λ����P35RCLK
sbit SCK=P3^6;//����ʱ��P36SRCLK
sbit SER=P3^4;//P34SER

/**
  * @brief  74HC595д��һ���ֽ�
  * @param  Ҫд����ֽ�
  * @param  |
  * @param  |
  * @retval ��
  */
void _74HC595_WriteByte(unsigned char Byte)
{
	//��ֵ
	unsigned char i;
	for(i=0;i<8;i++)
	{
			SER=Byte&(0x80>>i);//�����ƶ�iλ
			SCK=1;
			SCK=0;
	}
			RCK=1;//������
			RCK=0;
	
}

/**
  * @brief  LED��������ʾһ������
  * @param  coloum Ҫѡ����У���Χ0-7   0�������
  * @param  d
  * @param  |
  * @retval ��
  */
void MatrixLED_ShowColumn(unsigned char Column,Data )
{
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT=~(0x80>>Column);//0x80Ϊ1����coloumn=0ʱ��P0=0����coloumn=1,p0=1;
	Delay(1);
	MATRIX_LED_PORT=0xFF;
}


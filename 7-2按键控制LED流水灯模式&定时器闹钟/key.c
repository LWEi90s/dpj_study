#include <REGX52.H>
#include "Delay.h"

/**
  * @brief  ��ȡ������������
  * @param  ��
  * @param  |
  * @param  |
  * @retval ���°����ļ��롣��Χ��0~4�� �ް�������ʱ����ֵΪ0
  */
unsigned char Key()
{
	unsigned char KeyNumber=0;
	//�������
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
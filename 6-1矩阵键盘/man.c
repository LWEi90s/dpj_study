#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.H"
#include "MatrixKey.h"

unsigned char KeyNum=0;
void main()
{
	while(1)
	{
		KeyNum = MatrixKey();
		if(KeyNum!=0)
		{
			LCD_ShowNum(2,1,KeyNum,2);
		}
	}
}

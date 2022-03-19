#include <REGX52.H>

//延时函数
void Delay(unsigned int xms)		//@12.000MHz 1ms
{
	unsigned char i, j;
	while(xms)
	{
				i = 2;
			j = 239;
			do
			{
				while (--j);
			} while (--i);
			xms--;
  }
}

void main()
{
	//自定义变量
	unsigned char LEDNum=0;
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			LEDNum++;
			P2=~LEDNum;
			
			
		}
	}
	
}
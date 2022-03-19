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

unsigned char LEDNum;//定义个全局变量，在main里面就是局部变量

void main()
{

	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);//检测松手
			while(P3_1==0);
			Delay(20);
			
			LEDNum++;
			if(LEDNum>=8)
			{
				LEDNum=0;
			}
			P2=~(0x01<<LEDNum);//给0是灭所以取反	
		}
		//第二个按钮
		if(P3_0==0)
				{
					Delay(20);//检测松手
					while(P3_0==0);
					Delay(20);
					
					if(LEDNum==0)
					{
						LEDNum=7;
					}
					else
					{
						LEDNum--;
					}
					P2=~(0x01<<LEDNum);//给0是灭所以取反	
				}		
	}
	
}
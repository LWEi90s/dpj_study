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
//定义一个数组：0-9个元素
unsigned char NixieTable []={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
//定义一个数码管函数
void Nixie(unsigned char Location,Number)
{
	switch(Location)//亮的是哪个数码管
	{
		case 1://亮LED8
			P2_2=1;	P2_3=1;P2_4=1;break;
		case 2://亮LED7
			P2_2=1;	P2_3=1;P2_4=0;break;
		case 3://亮LED6
			P2_2=1;	P2_3=0;P2_4=1;break;
		case 4://亮LED5
			P2_2=1;	P2_3=0;P2_4=0;break;
		case 5://亮LED4
			P2_2=0;	P2_3=1;P2_4=1;break;
		case 6://亮LED3
			P2_2=0;	P2_3=1;P2_4=0;break;
		case 7://亮LED2
			P2_2=0;	P2_3=0;P2_4=1;break;
		case 8://亮LED1
			P2_2=0;	P2_3=0;P2_4=0;break;		
	}
		P0=NixieTable[Number];
		//消影	
		Delay(1);
		P0=0x00;
}



void main()
{

	while(1)
	{
		Nixie(1,0);
//		Delay(20);
		Nixie(2,1);
//	  Delay(20);
		Nixie(3,2);	
//		Delay(20);
	}
}
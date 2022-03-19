#include <REGX52.H>

void main()
{
//	P2=0xFE;
	while(1)
	{
		//读寄存器
		if(P3_1==0)
		{
			P2_0=0;//点亮，按下去
		}
		else
		{
			P2_0=1;//熄灭，松手
		}
	}
}
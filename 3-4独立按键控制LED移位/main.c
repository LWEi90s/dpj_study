#include <REGX52.H>

//��ʱ����
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

unsigned char LEDNum;//�����ȫ�ֱ�������main������Ǿֲ�����

void main()
{

	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);//�������
			while(P3_1==0);
			Delay(20);
			
			LEDNum++;
			if(LEDNum>=8)
			{
				LEDNum=0;
			}
			P2=~(0x01<<LEDNum);//��0��������ȡ��	
		}
		//�ڶ�����ť
		if(P3_0==0)
				{
					Delay(20);//�������
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
					P2=~(0x01<<LEDNum);//��0��������ȡ��	
				}		
	}
	
}
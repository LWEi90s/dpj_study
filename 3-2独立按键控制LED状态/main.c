#include <REGX52.H>

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
	while(1)
	{
//		P2_0=0;//����
//		Delay(500);
//		P2_0=1;//Ϩ��
//		Delay(500);
		
		if(P3_1==0)//����������
		{
			Delay(20);//����
			while(P3_1==0)//�������
			{
			}
			Delay(20);//���ֶ�������
			
			P2_0=~P2_0;//��λȡ��
			
		}
	}
}

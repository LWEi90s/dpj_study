#include <REGX52.H>
/**
  * @brief  ���ڳ�ʼ�� 4800bps@12.000MHz
  * @param  |
  * @param  |
  * @param  |
  * @retval ��
  */
void UART_Init()//4800bps@12.000MHz
{
	SCON=0x40;//0100 0000
	PCON=0;
	TMOD=TMOD&0x0F;//��TMOD�ĵ���λ���㣬����λ���䣻�ڸ���λ 1&�κ�һ����=1   ����λ0&�κ�һ����=0
	TMOD=TMOD&0xF1;//��TMOD�����λ��1������λ����
	TF0=0;
	TR0=1;
	TH0=64535/256;//��λ
	TL0=64535%256;//��λ
	ET0=1;//�����ж�
	EA=1;//�����ж�
	PT0=0;//�����ȼ�
}
/**
  * @brief  ���ڷ���һ���ֽ�����
  * @param  byte Ҫ���͵�һ���ֽ�����
  * @param  |
  * @param  |
  * @retval ��
  */
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	//����Ƿ����
	while(TI==0);
	TI=0;
	
}
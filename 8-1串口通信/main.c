#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char Sec;

void main ()
{
	UART_Init();

    while(1)
	{	
		
	}		
}

//�жϷ����Ӻ���  interrupt 4�жϺ������������
void UART_Rountine() interrupt 4
{
	if(RI==1)
	{
		P2=SBUF;//��ȡ����
		UART_SendByte(SBUF);
		RI=0;
	}
}

//�����жϺ���ģ��
//void UART_Rountine() interrupt 4
//{
//	if(RI==1)
//	{
//		
//		RI=0;
//	}
//}
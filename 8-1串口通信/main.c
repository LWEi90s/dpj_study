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

//中断服务子函数  interrupt 4中断后跳到这个函数
void UART_Rountine() interrupt 4
{
	if(RI==1)
	{
		P2=SBUF;//读取数据
		UART_SendByte(SBUF);
		RI=0;
	}
}

//串口中断函数模板
//void UART_Rountine() interrupt 4
//{
//	if(RI==1)
//	{
//		
//		RI=0;
//	}
//}
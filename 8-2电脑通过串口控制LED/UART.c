#include <REGX52.H>
/**
  * @brief  串口初始化 4800bps@12.000MHz
  * @param  |
  * @param  |
  * @param  |
  * @retval 无
  */
void UART_Init()//4800bps@12.000MHz
{
	SCON=0x40;//0100 0000
	PCON=0;
	TMOD=TMOD&0x0F;//把TMOD的低四位清零，高四位不变；在高四位 1&任何一个数=1   低四位0&任何一个数=0
	TMOD=TMOD&0xF1;//把TMOD的最低位置1，高四位不变
	TF0=0;
	TR0=1;
	TH0=64535/256;//高位
	TL0=64535%256;//低位
	ET0=1;//允许中断
	EA=1;//允许中断
	PT0=0;//低优先级
}
/**
  * @brief  串口发生一个字节数据
  * @param  byte 要发送的一个字节数据
  * @param  |
  * @param  |
  * @retval 无
  */
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	//检测是否完成
	while(TI==0);
	TI=0;
	
}
#include <REGX52.H>

//定义引脚
sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;

#define DS1302_SECOND 0x80
#define DS1302_MINUTE 0x82
#define DS1302_HOUR 0x84
#define DS1302_DATE 0x86
#define DS1302_MONTH 0x88
#define DS1302_DAY 0x8A
#define DS1302_YEAR 0x8C
#define DS1302_WP 0x8E




unsigned char DS1302_Time[]={19,11,16,12,59,55,6};

//初始化
void DS1302_Init(void)
{
	DS1302_CE=0;
	DS1302_SCLK=0;
	
}

//单字节写，无返回值
void DS1302_WriteByte(unsigned char Command,Data)
{
	unsigned char i;
	DS1302_CE=1;
	
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);//把第i位取出来 0000 0001
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	for(i=0;i<8;i++)
	{
		DS1302_IO=Data&(0x01<<i);//把第i位取出来 0000 0001
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	
	DS1302_CE=0;
}

//单字节读，有返回值
unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i,Data=0x00;
	Command|=0x01;
	DS1302_CE=1;
	
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);//把第i位取出来 0000 0001
		DS1302_SCLK=0;
		DS1302_SCLK=1;
	}
	
	for(i=0;i<8;i++)
	{
		DS1302_SCLK=1;
		DS1302_SCLK=0;
		if(DS1302_IO){Data|=(0x01<<i);}// |是用来置i，&是用来清零
	}
	
	DS1302_CE=0;	
	DS1302_IO=0;
	return Data;
}

void DS1302_SetTime(void)
{
	DS1302_WriteByte(DS1302_WP,0x00);//关闭写保护
	DS1302_WriteByte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);
	DS1302_WriteByte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS1302_WriteByte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS1302_WriteByte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	DS1302_WriteByte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	DS1302_WriteByte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	DS1302_WriteByte(DS1302_WP,0x80);//打开写保护
}

void DS1302_ReadTime(void)
{
	unsigned char Temple;
	
	Temple=DS1302_ReadByte(DS1302_YEAR);
	DS1302_Time[0]=Temple%16*10+Temple%16;//读年 
	Temple=DS1302_ReadByte(DS1302_MONTH);
	DS1302_Time[1]=Temple%16*10+Temple%16;
	Temple=DS1302_ReadByte(DS1302_DATE);
	DS1302_Time[2]=Temple%16*10+Temple%16;
	Temple=DS1302_ReadByte(DS1302_HOUR);
	DS1302_Time[3]=Temple%16*10+Temple%16;
	Temple=DS1302_ReadByte(DS1302_MINUTE);
	DS1302_Time[4]=Temple%16*10+Temple%16;
	Temple=DS1302_ReadByte(DS1302_SECOND);
	DS1302_Time[5]=Temple%16*10+Temple%16;
	Temple=DS1302_ReadByte(DS1302_DAY);
	DS1302_Time[6]=Temple%16*10+Temple%16;
}
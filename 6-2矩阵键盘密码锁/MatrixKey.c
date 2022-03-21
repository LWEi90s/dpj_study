#include <REGX52.H>
#include "Delay.h"

/**
  * @brief 矩阵键盘函数,按列扫描 
  * @param  |
  * @param  |
  * @param  |
  * @retval  KeyNumber 按下按键的键码值
  如果按键按下不放，程序会停留在此函数，松手一瞬间，返回按键键码，没有按键按下时，返回0
  */

unsigned char MatrixKey()//有返回值无参数
{
	unsigned char KeyNumber=0;
	
	P1=0xFF;//将P1接口的都设置为1高电平
	P1_3=0;
	if(P1_7==0)//S1的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=1;	
			}
	if(P1_6==0)//S5的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=5;	
			}
	if(P1_5==0)//S9的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=9;	
			}
	if(P1_4==0)//S13的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=13;	
			}		
		
P1=0xFF;//将P1接口的都设置为1高电平
	P1_2=0;
	if(P1_7==0)//S2的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=2;	
			}
	if(P1_6==0)//S6的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=6;	
			}
	if(P1_5==0)//S10的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=10;	
			}
	if(P1_4==0)//S14的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=14;	
			}

P1=0xFF;//将P1接口的都设置为1高电平
	P1_2=0;
	if(P1_7==0)//S3的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=3;	
			}
	if(P1_6==0)//S7的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=7;	
			}
	if(P1_5==0)//S11的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=11;	
			}
	if(P1_4==0)//S15的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=15;	
			}

P1=0xFF;//将P1接口的都设置为1高电平
	P1_0=0;
	if(P1_7==0)//S4的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=4;	
			}
	if(P1_6==0)//S8的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=8;	
			}
	if(P1_5==0)//S12的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=12;	
			}
	if(P1_4==0)//S16的检测
		{
			Delay(20);//消抖 
			while(P1_7==0);//检测松手，如果还是按下的就一直循环
			Delay(20);//消抖
			KeyNumber=16;	
			}			
	return KeyNumber;
}
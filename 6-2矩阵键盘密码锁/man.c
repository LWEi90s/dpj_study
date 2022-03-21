#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.H"
#include "MatrixKey.h"

unsigned char KeyNum=0;
unsigned int Password;
unsigned int count=0;

void main()
{
	while(1)
	{
		KeyNum = MatrixKey();//格式化
		LCD_ShowString(1,1,"Password:");//显示字符串Password:
		if(KeyNum!=0)
		{
			if(KeyNum<=10)//s1-s10按下，输入密码,超出的则无意义
			{
				if(count<4)//如果输入次数<4
				{
					Password*=10;//密码左移一位
					Password+=KeyNum%10;//（对10取余为0，1-9取余则不变）获取一位密码
					count++;//计次+1				
				}
				LCD_ShowNum(2,1,Password,4);	//更新显示			
			}
			if(KeyNum==11)//如果s11按键按下，确认
			{
				if(Password==1234)//如果密码等于正确密码，则显示ok
				{
					LCD_ShowString(1,14," ok");
					Password=0;//密码清零
					count=0;//计次清零
					LCD_ShowNum(2,1,Password,4);	//更新显示
				}
				else
				{
					LCD_ShowString(1,14,"err");//错误显示error
					Password=0;//密码清零
					count=0;//计次清零
					LCD_ShowNum(2,1,Password,4);	//更新显示
				}
			}
			if(KeyNum==12)//如果s12按键按下，取消
			{
				Password=0;//密码清零
				count=0;//计次清零
				LCD_ShowNum(2,1,Password,4);	//更新显示
			}
		}
	}
}

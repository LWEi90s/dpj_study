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
		KeyNum = MatrixKey();//��ʽ��
		LCD_ShowString(1,1,"Password:");//��ʾ�ַ���Password:
		if(KeyNum!=0)
		{
			if(KeyNum<=10)//s1-s10���£���������,��������������
			{
				if(count<4)//����������<4
				{
					Password*=10;//��������һλ
					Password+=KeyNum%10;//����10ȡ��Ϊ0��1-9ȡ���򲻱䣩��ȡһλ����
					count++;//�ƴ�+1				
				}
				LCD_ShowNum(2,1,Password,4);	//������ʾ			
			}
			if(KeyNum==11)//���s11�������£�ȷ��
			{
				if(Password==1234)//������������ȷ���룬����ʾok
				{
					LCD_ShowString(1,14," ok");
					Password=0;//��������
					count=0;//�ƴ�����
					LCD_ShowNum(2,1,Password,4);	//������ʾ
				}
				else
				{
					LCD_ShowString(1,14,"err");//������ʾerror
					Password=0;//��������
					count=0;//�ƴ�����
					LCD_ShowNum(2,1,Password,4);	//������ʾ
				}
			}
			if(KeyNum==12)//���s12�������£�ȡ��
			{
				Password=0;//��������
				count=0;//�ƴ�����
				LCD_ShowNum(2,1,Password,4);	//������ʾ
			}
		}
	}
}

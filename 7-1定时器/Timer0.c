#include <REGX52.H>

/**
  * @brief  ��ʱ��
  * @param  |
  * @param  |
  * @param  |
  * @retval ��
  */
void Timer0Init()
{
//	TMOD=0x01;//0000 0001
	TMOD=TMOD&0xF0;//��TMOD�ĵ���λ���㣬����λ���䣻�ڸ���λ 1&�κ�һ����=1   ����λ0&�κ�һ����=0
	TMOD=TMOD&0xF1;//��TMOD�����λ��1������λ����
	TF0=0;
	TR0=1;
	TH0=64535/256;//��λ
	TL0=64535%256;//��λ
	ET0=1;//�����ж�
	EA=1;//�����ж�
	PT0=0;//�����ȼ�
}

/*��ʱ���жϺ���ģ��
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;//�ֲ���̬�������������֮��ñ�����������
	T0Count++;
	//���¸���ֵ
	TH0=64535/256;//��λ
	TL0=64535%256;//��λ
	
	if(T0Count>=1000)
	{
		T0Count=0;//����
//		P2_0=0;//��֤�ж��Ƿ�ִ�У�����Ѿ��ж���LED1����
		P2_0=~P2_0;//ȡ����LED1��˸
	}

}

*/

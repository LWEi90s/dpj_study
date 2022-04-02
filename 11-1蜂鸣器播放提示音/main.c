#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Buzzer.h"

sbit Buzzer=P1^5;

#define SPEED 500

unsigned int FreqTable[]={
0,
	63628,63731,63835,63928,64021,64103,64185,64260,64331,64400,64463,64528,
	64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030,
	65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283,
};

unsigned char Music[]={};

unsigned char FreqSelect,MusicSelect;	
	
void main ()
{
	Timer0Init()
  while(1)
	{
			FreSelect=Music[MusicSelect];
	    MusicSelect++;
			Delay(SPEED/4*Music[MusicSelect]);
			TR0=0;
			Delay(5);
			TR0=1;
	}		
}

void Timer0_Routine() interrupt 1
{
	if(FreqTable[FreqSelect])
	{
		TH0=FreqTable[FreqSelect]/256;//¸ßÎ»
		TL0=FreqTable[FreqSelect]%256;//µÍÎ»
		Buzzer=!Buzzer;
	}
}
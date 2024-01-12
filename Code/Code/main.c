#include "GPIO.h"
#include "Key.h"
#include "stdio.h"

sbit LED=P3^7; 
sbit SPEAKER = P3^4; //������

unsigned int code Freqtab[] = { 	//��ʱ�����ڵĳ�ʼֵ
     64021,64103,64260,64400,      //����3 4 5 6
     64524,64580,64684,64777,      //����7,����1 2 3
     64820,64898,64968,65030,      //����4 5 6 7
     65058,65110,65157,65178};     //����1 2 3 4

unsigned int FreqTemp;

void main()
{
	GPIO_init();//GPIO��ʼ��
	LED = 0;
	
	while(1)
	{
		if(Key_Read() < 12)
			LED = 0;
		else if(Key_Read() >= 12 && Key_Read() < 15)
			LED = 1;
	}
	
}

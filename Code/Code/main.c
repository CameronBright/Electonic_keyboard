#include "GPIO.h"
#include "Key.h"
#include "stdio.h"
//#include "Timer.h"

sbit LED=P3^7; 
sbit SPEAKER = P3^4; //������

void keyscan();
void Timer0_Init(void);		//19΢��@11.0592MHz
void Delay10ms();		//@11.0592MHz

unsigned key_value;

                             //0   1     2     3     4     5     6     7     8     9    10   11     12
unsigned int code yindiao[13]={0,63778,63873,63969,64054,64140,64215,64292,64360,64426,64489,64548,64603};
unsigned char yd;																	
		 
void main()
{
	GPIO_init();//GPIO��ʼ��
	Timer0_Init(); //��ʱ����ʼ��
	
	LED = 0;
	while(1)
	{
		keyscan();
	}
}

void keyscan()														
{
	key_value = Key_Read();
	
	if(key_value >= 0 && key_value <= 14)													
	{
		Delay10ms();				//����									
		if(key_value >= 0 && key_value <= 14)													
		{	
			switch (key_value)													
			{
				case 0:yd = 1;TR0 = 1;break;		//key0
				case 1:yd = 2;TR0 = 1;break;		//key1
				case 2:yd = 3;TR0 = 1;break;		//key2
				case 3:yd = 4;TR0 = 1;break;		//key3
				case 4:yd = 5;TR0 = 1;break;		//key4	
				case 5:yd = 6;TR0 = 1;break;		//key5
				case 6:yd = 7;TR0 = 1;break;		//key6
				case 7:yd = 8;TR0 = 1;break;		//key7
				case 8:yd = 9;TR0 = 1;break;		//key8
				case 9:yd = 10;TR0 = 1;break;		//key9
				case 10:yd = 11;TR0 = 1;break;		//key10
				case 11:yd = 12;TR0 = 1;break;		//key11	
				default:break;
			}
		}
		
	}
	if(key_value == 15) TR0 = 0;	//ֹͣ��ʱ
							
}

void T0_INT(void) interrupt 1
{
		TH0 = yindiao[yd]/256;										//����???������3?��??��
		TL0 = yindiao[yd]%256;										//����???������3?��??��
		SPEAKER = ~SPEAKER;											//??����?�¦�???��-��a
}

void Timer0_Init(void)		//19΢��@11.0592MHz
{
	TMOD |= 0x01;														//����???������?��?�꨺?
	TL0 = 0x8B;															//����???������3?��??��
	TH0 = 0xF8;															//����???������3?��??��
	TR0 = 0;																//?������?��0?a��???����
	ET0 = 1;																//?������?��0?D??��1?��
	EA = 1;																	//����?D??��1?��
}

void Delay10ms()		//@11.0592MHz
{
	unsigned char data i, j;

	i = 108;
	j = 145;
	do
	{
		while (--j);
	} while (--i);
}
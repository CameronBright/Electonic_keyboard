#include "GPIO.h"
#include "Key.h"
#include "stdio.h"
//#include "Timer.h"

sbit LED=P3^7; 
sbit SPEAKER = P3^4; //扬声器

void keyscan();
void Timer0_Init(void);		//19微秒@11.0592MHz
void Delay10ms();		//@11.0592MHz

unsigned key_value;

                             //0   1     2     3     4     5     6     7     8     9    10   11     12
unsigned int code yindiao[13]={0,63778,63873,63969,64054,64140,64215,64292,64360,64426,64489,64548,64603};
unsigned char yd;																	
		 
void main()
{
	GPIO_init();//GPIO初始化
	Timer0_Init(); //定时器初始化
	
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
		Delay10ms();				//消抖									
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
	if(key_value == 15) TR0 = 0;	//停止计时
							
}

void T0_INT(void) interrupt 1
{
		TH0 = yindiao[yd]/256;										//éè???¨ê±3?ê??μ
		TL0 = yindiao[yd]%256;										//éè???¨ê±3?ê??μ
		SPEAKER = ~SPEAKER;											//??éù?÷μ???·-×a
}

void Timer0_Init(void)		//19微秒@11.0592MHz
{
	TMOD |= 0x01;														//éè???¨ê±?÷?￡ê?
	TL0 = 0x8B;															//éè???¨ê±3?ê??μ
	TH0 = 0xF8;															//éè???¨ê±3?ê??μ
	TR0 = 0;																//?¨ê±?÷0?aê???ê±
	ET0 = 1;																//?¨ê±?÷0?D??ê1?ü
	EA = 1;																	//×ü?D??ê1?ü
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
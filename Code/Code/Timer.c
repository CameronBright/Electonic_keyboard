#include "Timer.h"

//void Timer0_Init(void)		//19微秒@11.0592MHz
//{
//	AUXR |= 0x80;			//定时器时钟1T模式
//	TMOD &= 0xF0;			//设置定时器模式
//	TL0 = 0x2E;				//设置定时初始值
//	TH0 = 0xFF;				//设置定时初始值
//	TF0 = 0;				//清除TF0标志
//	TR0 = 1;				//定时器0开始计时
//	
//	EA = 1;
//}

//void Delay10ms()		//@11.0592MHz
//{
//	unsigned char data i, j;

//	i = 108;
//	j = 145;
//	do
//	{
//		while (--j);
//	} while (--i);
//}




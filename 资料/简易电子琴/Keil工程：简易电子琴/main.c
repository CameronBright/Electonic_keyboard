//		@布丁橘长 20220711
//		51单片机简易电子琴
//		7个按键对应7个音调，给定时器0不同装载值，生成不同频率方波，扬声器发出对应声音
//		PNP三极管（8550）驱动扬声器，STC89C52RC，11.0592MHz

#include <reg51.h>												//51通用头文件

#define uchar unsigned char								//unsigned char 类型用uchar表示
#define uint unsigned int									//unsigned int 	类型用uint 表示
	
sbit Speaker = P1^0;											//蜂鸣器/扬声器引脚

void delayms(uint ms);
void Timer0Init(void);
void keyscan();
                  //音调  1    2     3     4     5     6     7
uint code yindiao[8]={0,63778,63969,64140,64215,64360,64489,64603};//音调对应的定时器装载值
uchar yd;																	//音调变量（取数组yindiao[]对应的音调）
void main()
{
	Timer0Init();														//定时器0初始化
	while(1)
	{
		keyscan();														//循环扫描按键
	}
}

void delayms(uint ms)											//1毫秒*ms简单延时函数
{
	uint msi,msj;
	for(msi = 0;msi < ms;msi++)
		for(msj = 0;msj < 112;msj++);					//@11.0592MHz
}

void Timer0Init(void)											//19微秒@11.0592MHz
{
	TMOD |= 0x01;														//设置定时器模式
	TL0 = 0x8B;															//设置定时初始值
	TH0 = 0xF8;															//设置定时初始值
	TR0 = 0;																//定时器0开始计时
	ET0 = 1;																//定时器0中断使能
	EA = 1;																	//总中断使能
}
void keyscan()														//按键扫描函数
{
	if(P2 != 0xFF)													//判断是否有按键
	{
		delayms(10);													//延时去抖
		if(P2!= 0xFF)													//再次判断是否有按键
		{
			switch (P2)													//判断哪个按键
			{
				case 0xFE:yd = 1;TR0 = 1;break;		//key1
				case 0xFD:yd = 2;TR0 = 1;break;		//key2
				case 0xFB:yd = 3;TR0 = 1;break;		//key3
				case 0xF7:yd = 4;TR0 = 1;break;		//key4
				case 0xEF:yd = 5;TR0 = 1;break;		//key5	
				case 0xDF:yd = 6;TR0 = 1;break;		//key6
				case 0xBF:yd = 7;TR0 = 1;break;		//key7
				default:break;
			}
		}
		if(P2 == 0xFF) TR0 = 0;								//停止计时
	}
}

void Tmr0isr() interrupt 1								//定时器0中断函数
{	
	TH0 = yindiao[yd]/256;										//设置定时初始值
	TL0 = yindiao[yd]%256;										//设置定时初始值
	Speaker = ~Speaker;											//扬声器电平翻转
}
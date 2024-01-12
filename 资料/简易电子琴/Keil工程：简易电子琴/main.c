//		@�����ٳ� 20220711
//		51��Ƭ�����׵�����
//		7��������Ӧ7������������ʱ��0��ͬװ��ֵ�����ɲ�ͬƵ�ʷ�����������������Ӧ����
//		PNP�����ܣ�8550��������������STC89C52RC��11.0592MHz

#include <reg51.h>												//51ͨ��ͷ�ļ�

#define uchar unsigned char								//unsigned char ������uchar��ʾ
#define uint unsigned int									//unsigned int 	������uint ��ʾ
	
sbit Speaker = P1^0;											//������/����������

void delayms(uint ms);
void Timer0Init(void);
void keyscan();
                  //����  1    2     3     4     5     6     7
uint code yindiao[8]={0,63778,63969,64140,64215,64360,64489,64603};//������Ӧ�Ķ�ʱ��װ��ֵ
uchar yd;																	//����������ȡ����yindiao[]��Ӧ��������
void main()
{
	Timer0Init();														//��ʱ��0��ʼ��
	while(1)
	{
		keyscan();														//ѭ��ɨ�谴��
	}
}

void delayms(uint ms)											//1����*ms����ʱ����
{
	uint msi,msj;
	for(msi = 0;msi < ms;msi++)
		for(msj = 0;msj < 112;msj++);					//@11.0592MHz
}

void Timer0Init(void)											//19΢��@11.0592MHz
{
	TMOD |= 0x01;														//���ö�ʱ��ģʽ
	TL0 = 0x8B;															//���ö�ʱ��ʼֵ
	TH0 = 0xF8;															//���ö�ʱ��ʼֵ
	TR0 = 0;																//��ʱ��0��ʼ��ʱ
	ET0 = 1;																//��ʱ��0�ж�ʹ��
	EA = 1;																	//���ж�ʹ��
}
void keyscan()														//����ɨ�躯��
{
	if(P2 != 0xFF)													//�ж��Ƿ��а���
	{
		delayms(10);													//��ʱȥ��
		if(P2!= 0xFF)													//�ٴ��ж��Ƿ��а���
		{
			switch (P2)													//�ж��ĸ�����
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
		if(P2 == 0xFF) TR0 = 0;								//ֹͣ��ʱ
	}
}

void Tmr0isr() interrupt 1								//��ʱ��0�жϺ���
{	
	TH0 = yindiao[yd]/256;										//���ö�ʱ��ʼֵ
	TL0 = yindiao[yd]%256;										//���ö�ʱ��ʼֵ
	Speaker = ~Speaker;											//��������ƽ��ת
}
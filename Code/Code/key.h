#ifndef __KEY_H
#define __KEY_H

#include "main.h"

sbit key0 = P2^2; 
sbit key1 = P2^3; 
sbit key2 = P2^4; 
sbit key3 = P2^5; 
sbit key4 = P2^6; 
sbit key5 = P2^7; 
sbit key6 = P0^0; 
sbit key7 = P0^1; 
sbit key8 = P0^2; 
sbit key9 = P0^3; 
sbit key10 = P1^0; 
sbit key11 = P1^1;

sbit switch1 = P1^3; 
sbit switch2 = P1^7; 
sbit switch3 = P1^6; 

unsigned char Key_Read(void);

#endif

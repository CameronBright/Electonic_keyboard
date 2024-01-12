#include "key.h" 
	
unsigned char Key_Read(void)
{
	unsigned char key_value;
	
	if(key0 == 1) key_value = 0;
	else if(key1 == 1) key_value = 1;
	else if(key2 == 1) key_value = 2;
	else if(key3 == 1) key_value = 3;
	else if(key4 == 1) key_value = 4;
	else if(key5 == 1) key_value = 5;
	else if(key6 == 1) key_value = 6;
	else if(key7 == 1) key_value = 7;
	else if(key8 == 1) key_value = 8;
	else if(key9 == 1) key_value = 9;
	else if(key10 == 1) key_value = 10;
	else if(key11 == 1) key_value = 11;
	
	else if(switch1 == 1) key_value = 12;
	else if(switch2 == 1) key_value = 13;
	else if(switch3 == 1) key_value = 14;
	else key_value = 15;
	
	return key_value;
}

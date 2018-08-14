/**
LCD1602?? 12345
**/
#include <reg51.h>

typedef unsigned char uchar;
typedef unsigned int uint;

sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;
//?????,??????
void Read_Busy()
{
	uchar busy;
	P0 = 0xff;
	RS = 0;
	RW = 1;
	do
	{
		EN = 1;
		busy = P0;
		EN = 0;
	}while(busy & 0x80);
}
//?LCD1602??????
void Write_Cmd(uchar cmd)
{
	Read_Busy();//???
	RS = 0;
	RW = 0;
	P0 = cmd;
	EN = 1;
	EN = 0;
}
//???????
void Write_Dat(uchar dat)
{
	Read_Busy();
	RS = 1;
	RW = 0;
	P0 = dat;
	EN = 1;
	EN = 0;
}
void main()
{
	Write_Cmd(0x38);//??16*2??
	Write_Cmd(0x0f);//??? ????,????
	Write_Cmd(0x01);//??

	Write_Cmd(0x06);//????????
	Write_Cmd(0x80 | 0x06);//????

	Write_Dat(1 + '0');
	Write_Dat(2 + '0');
	Write_Dat(3 + '0');
	Write_Dat(4 + '0');
	Write_Dat(5 + '0');
	while(1);
}
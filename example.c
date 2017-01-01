#include <stdio.h>
#include "serialport.h"
int main(void)
{
	HANDLE h = openSerialPort("COM7",B115200,one,off);
	int i = 0;
	char saddr[3];
	unsigned short retval;
	//write test
	saddr[0] = 'r';
	for(i = 0; i < 0x80; i++)
	{
		saddr[1] = i & 0xff;
		saddr[2] = (i >> 8) & 0xff;
		writeToSerialPort(h,saddr,strlen(saddr));
		readFromSerialPort(h,&retval,2);
		printf("0x%04x:%02x\n", i, retval&0xff);
	}
	closeSerialPort(h);
    return 0;
}
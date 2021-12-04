#include<lpc21xx.h>
#define delay for(int i=0; i<100000;i++);

int main()
{
	unsigned int a[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	PINSEL0= 0x00000000;
	PINSEL1= 0x00000000;
	IO0DIR |= 0xFFFFFFFF;
	IO0DIR |= (0<<16);
	
	if(IO0PIN & (1<<16))
	{
		for(int j=0; j<10;j++)
		{
			IO0SET = a[j];
			delay;
			IO0CLR = a[j];
		}
	}
	else
	{

		for(int j=9; j>=0;j--)
		{
			IO0SET = a[j];
			delay;
			IO0CLR = a[j];
		}
	}
	return 0;
}


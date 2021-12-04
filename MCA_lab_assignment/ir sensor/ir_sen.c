#include<lpc214x.h>

#define bit(x) (1<<x)
#define delay for(i=0;i<7000;i++);

unsigned int i;

void lcd_int();
void dat(unsigned char);
void cmd(unsigned char);
void string(unsigned char *);

void main()
{
    IO0DIR =0XFFFFFFFF;
		IO1DIR = 0x0;
    lcd_int();
		cmd(0x80);
    string("EMBETRONICX.COM ");
			
    while(1) {
			if((IO1PIN & (1<<24)))
				{
					string("Obstacle Detcted");
				}
				else
					{
					string("Obstacle not Detcted");
				}
			delay;
			delay;
        cmd(0x01);
        
    }
}

void lcd_int()
{
    cmd(0x38);
    cmd(0x0c);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);
}

void cmd(unsigned char a)
{
    IO0PIN&=0x00;
    IO0PIN|=(a<<0);
    IO0CLR|=bit(8);                
    IO0CLR|=bit(9);                
    IO0SET|=bit(10);               
    delay;
    IO0CLR|=bit(10);               
}

void dat(unsigned char b)
{
    IO0PIN&=0x00;
    IO0PIN|=(b<<0);
    IO0SET|=bit(8);                
    IO0CLR|=bit(9);                
    IO0SET|=bit(10);               
    delay;
    IO0CLR|=bit(10);               
}

void string(unsigned char *p)
{
    while(*p!='\0') {
        dat(*p++);
    }
}
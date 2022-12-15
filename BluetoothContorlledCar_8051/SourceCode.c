#include <reg51.h>
//Motor Connections
sbit m1p = P2^0;
sbit m1n = P2^1;
sbit m2p = P2^2;
sbit m2n = P2^3;
unsigned char x ;
void main()
{
//Initialising Serial Communication
SCON = 0x50;
TMOD = 0x20;
TH1 = -3;
TR1 =1 ;

while(1)
{
//Continue the execution of Program until simulation/power is Stoped

	while (RI==0); //Monitor any data recived, whenever RI == 1 means data is ready in SBUF
	x = SBUF ; //Move Data/Character recieved to a temporary variable
	RI = 0; //Reset, so next character can be recived
	
	//For simulation
	//So the Input character is visible on the Proteus terminal
	SBUF = x ;
	while (TI ==0)
	TI = 0;
	//Movement of Robots motors and hence the wheels
	if (x == 'f')
	{
		//Rotate both motors in clockwise direction
		m1p = 1;
		m1n = 0;
		m2p = 1 ;
		m2n = 0;
	}

	if (x == 'b')
	{
		//Rotate both motors in Anticlockwise direction
		m1p = 0;
		m1n = 1;
		m2p = 0;
		m2n = 1;
	}

	if (x == 'l')
	{
		//Rotate First motor (Front wheels) Clockwise
		//Rotate Second motor (Back wheels) AntiClockwise
		m1p = 1;
		m1n = 0;
		m2p = 0 ;
		m2n = 1;
	}

	if (x == 'r')
	{
		//Rotate First motor (Front wheels) AntiClockwise
		//Rotate Second motor (Back wheels) Clockwise
		m1p = 0;
		m1n = 1;
		m2p = 1 ;
		m2n = 0;
	}
	if (x == 's')
	{
		//Stop movement of all the motors
		m1p = 0;
		m1n = 0;
		m2p = 0 ;
		m2n = 0;

	}
}

}

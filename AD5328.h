#include <Arduino.h>

#define CH1		  0		// CH1
#define CH2		  1		// CH2
#define CH3		  2		// CH3
#define CH4		  3		// CH4
#define CH5		  4		// CH5
#define CH6		  5		// CH6
#define CH7		  6		// CH7
#define CH8		  7		// CH8

class AD5328
{

public:
	AD5328 (unsigned int, unsigned int);					// CK,MOSI
	void Write(unsigned int, unsigned int, unsigned int );

};


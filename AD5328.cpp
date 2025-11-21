#include "AD5328.h"

unsigned int CLK_DAC;
unsigned int DATA_SER;

AD5328::AD5328(unsigned int CK,unsigned int MOSI) {
	pinMode(CK, OUTPUT);       
  	pinMode(MOSI, OUTPUT);       
	CLK_DAC = CK;
	DATA_SER = MOSI;
}

void AD5328::Write(unsigned int data,unsigned int ch,unsigned int AD)
{	
	uint8_t SYNC_DAC = AD;

	digitalWrite(CLK_DAC, HIGH);	
	delayMicroseconds(63);
	digitalWrite(SYNC_DAC,LOW);		
	delayMicroseconds(63);
	digitalWrite(SYNC_DAC,HIGH);	
	delay(5);
	digitalWrite(SYNC_DAC,LOW);		
	delayMicroseconds(63);

	digitalWrite(CLK_DAC, HIGH);
	digitalWrite(DATA_SER,LOW);		
	delay(1); 
	digitalWrite(CLK_DAC, LOW);	
	delay(1);
	
for(int loop=2;loop>-1;loop--) 			
{

	digitalWrite(CLK_DAC, HIGH);	
	digitalWrite(DATA_SER,((ch>>loop) & 1)); 
	delay(1);
	digitalWrite(CLK_DAC, LOW);    
	delay(1); 
}

for(int loop=11;loop>0;loop--)
{
	digitalWrite(CLK_DAC, HIGH);			
	digitalWrite(DATA_SER,((data>>loop) & 1)); 
	delay(1);
	digitalWrite(CLK_DAC, LOW);			
	delay(1); 
}

	digitalWrite(CLK_DAC, HIGH);			 
	digitalWrite(DATA_SER,(data & 0X01));	
	delay(1);  
	digitalWrite(CLK_DAC,LOW);			
	delay(1); 	
	digitalWrite(SYNC_DAC,HIGH);	
	delay(1); 	
	delayMicroseconds(500);

}



#include <AD5328.h>

AD5328 AD5328;

void setup() {
  
  pinMode(8, OUTPUT);       // CLOCK
  pinMode(9, OUTPUT);       // MOSI
  pinMode(10, OUTPUT);      // CHIP SELECT 
  
  AD5328.Write(32,CH1);      // Set the output A to VCC/128
  AD5328.Write(64,CH2);      // Set the output B to VCC/64 
  AD5328.Write(128,CH3);     // Set the output C to VCC/32 
  AD5328.Write(256,CH4);     // Set the output D to VCC/16   
  AD5328.Write(512,CH5);     // Set the output E to VCC/8
  AD5328.Write(1024,CH6);    // Set the output F to VCC/4  
  AD5328.Write(2048,CH7);    // Set the output G to VCC/2
  AD5328.Write(4095,CH8);    // Set the output H to VCC  
    
}

void loop() {
  

}


// Voltage controlled AC dimmer with ATtiny85

#include <avr/io.h>
#include <avr/interrupt.h>

#define DETECT 2      //zero cross detect, interrupt 0, is physical pin 7
#define GATE 3        //triac gate is physical pin 2

int value;

void setup()
{
  digitalWrite(DETECT, INPUT_PULLUP);  //enable pull-up resistor
  pinMode(GATE, OUTPUT);       //triac gate control
  digitalWrite(4, INPUT_PULLUP);

  attachInterrupt(0,zeroCrossingInterrupt, FALLING);   
} 

void zeroCrossingInterrupt()
{
  delayMicroseconds(value); digitalWrite(GATE,HIGH); 
  delayMicroseconds(100); digitalWrite(GATE,LOW);
}

void loop(){
  value = map(analogRead(A2), 0,1024, 8000, 0);
}

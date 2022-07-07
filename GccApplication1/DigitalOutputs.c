/*
 * Function Definitions
 */
#include "DigitalOutputs.h"
#include <avr/io.h>




void initDigitalOutputs()
{
//   pinMode(YELLOW_LED, OUTPUT);
//   pinMode(GREEN_LED, OUTPUT);
//   pinMode(BLUE_LED, OUTPUT);
     DDRD = 0xE0;
   
}

void blinkGreenled(void)
{
  //digitalWrite(BLUE_LED, digitalRead(BLUE_LED) ^ 1);   // toggle LED pin
  PORTD ^= 0x20;
  
}
void blinkYellowled(void)
{
  //digitalWrite(GREEN_LED, digitalRead(GREEN_LED) ^ 1);   // toggle LED pin
  PORTD ^= 0x40;
  
}
void blinkBlueled(void)
{
  //digitalWrite(YELLOW_LED, digitalRead(YELLOW_LED) ^ 1);   // toggle LED pin
  PORTD ^= 0x80;
}
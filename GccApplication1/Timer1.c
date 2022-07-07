/*
 * Timer1.c
 *
 * Created: 12/20/2021 6:36:10 PM
 *  Author: Ricardo
 */ 
#include "Timer1.h"
#include "common.h"
#include "DigitalOutputs.h"
#include "OperatingSystem.h"
#include <avr/io.h>
#include <avr/interrupt.h>



/*
 * OS TIck
 * Description: This number defines the time the Timer interrupt will be
 *              interrupting the main program
 */
#define OSTICK ((U16BIT)625)   //10 ms

/*
 * Global definitions
 */

extern U16BIT task[];

/*
 * 
 */
void InitTimer1(void)
{
  // initialize timer1 
  cli();          // disable all interrupts
  TCCR1A = 0;

  TCCR1B = 0;

  TCNT1  = 0;
  
  OCR1A = OSTICK;            // compare match register 16MHz/256/100Hz
  TCCR1B |= (1 << WGM12);   // CTC mode, resets the TCNT1
  /* 
  CS12 CS11 CS10 Description
  0      0   0   No clock source (Timer/Counter stopped).
  0     0    1   clkI/O/1 (no prescaling)
  0     1    0   clkI/O/8 (from prescaler)
  0     1    1   clkI/O/64 (from prescaler)
  1     0    0   clkI/O/256 (from prescaler)
  1     0    1   clkI/O/1024 (from prescaler)
  */
  TCCR1B |= (1 << CS12);    // CS12: 256 prescaler 
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  
  sei();             //interrupts()---> enable all interrupts
}




ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
   //PORTD ^= 0x10;  //witness
   for(int i = 0; i < N_TASKS; i++)
  {
    if(task [i] > RUN_IMMEDIATE)
    {
      task[i]--;
    }
  }
  
}
 
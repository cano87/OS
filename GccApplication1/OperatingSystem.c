/*
 * GccApplication1.c
 *
 * Created: 12/20/2021 6:12:06 PM
 * Author : Ricardo
 */ 

#include <avr/io.h>

#include "common.h"
#include "Timer1.h"
#include "DigitalOutputs.h"
#include "OperatingSystem.h"



const task_t TaskTable[] =
{
	{blinkBlueled, OS_100MS},
	{blinkGreenled, OS_100MS},
	{blinkYellowled, OS_500MS}
};



U16BIT task[N_TASKS];



int main(void)
{
    /* Replace with your application code */
	
	  // initialize digital pin LED_BUILTIN as an output.
	  initDigitalOutputs();


	  InitTimer1();
	  
	 ScheduleTask(BLINK_BLUE_LED,OS_100MS);
	  ScheduleTask(BLINK_GREEN_LED,OS_100MS);
	  ScheduleTask(BLINK_YELLOW_LED,OS_100MS);
    while (1) 
    {
		  task_t *ttp = &TaskTable[0];
		  for(U8BIT i = 0; i < N_TASKS; i++)
		  {
			  if(task [i] == RUN_IMMEDIATE)
			  {
				  ScheduleTask((task_ID)i,ttp->reload);
				  ttp -> ptr_fun();
				  //        ScheduleTask((task_ID)i,(TaskTable + i)-> reload);
				  //        (TaskTable + i) -> ptr_fun();
			  }
			  ttp++;
		  }
    }
}



void ScheduleTask(task_ID ID, U8BIT period)
{
	task[ID] = period;
}

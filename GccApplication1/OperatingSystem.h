/*
 * OperatingSystem.h
 *
 * Created: 12/20/2021 6:35:12 PM
 *  Author: Ricardo
 */ 


#ifndef OPERATINGSYSTEM_H_
#define OPERATINGSYSTEM_H_

/*
 * Operating System Definitions
 */


typedef struct 
{
  void (*ptr_fun)(void);   //pointer to function, that return a void and receives a void
  U16BIT reload;            //Predefined time the task will be executed
}task_t;

typedef enum
{
  BLINK_BLUE_LED,
  BLINK_GREEN_LED,
  BLINK_YELLOW_LED,
  N_TASKS
}task_ID;

enum
{
 OS_100MS = 10,
 OS_200MS = 20,
 OS_300MS = 30,
 OS_500MS = 50,
 OS_1S = 100,
 OS_2S = 200,
 OS_3S = 300,
 
};

enum
{
  CANCEL_TASK,
  RUN_IMMEDIATE
};

void ScheduleTask(task_ID ID, U8BIT period);




#endif /* OPERATINGSYSTEM_H_ */
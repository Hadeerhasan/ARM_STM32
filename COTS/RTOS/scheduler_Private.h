#ifndef SCHEDULER_PRIVATE_H
#define SCHEDULER_PRIVATE_H

typedef struct 
{
  void(*pf)(void);
  u32 Frist_Delay;
  u32 Periodicity; 
}TCB_t;

TCB_t Task_Arr[No_Of_Task]={NULL};

static void RTO_Scheduler(void);



#endif
#ifndef SCHEDULER_INTERFACE_H
#define SCHEDULER_INTERFACE_H

void RTO_StartOS(void);
void RTO_voidCreatTask(u32 Copy_u32TaskId,u32 Copy_u32Periodicity,u32 Copy_u32FirstDelay,void(*pf)(void));





#endif
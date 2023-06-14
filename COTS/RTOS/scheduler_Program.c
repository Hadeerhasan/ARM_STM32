#include "LSTD_TYPE.h"
#include "LBIT_MATH.h"

#include "scheduler_Private.h"
#include "scheduler_Config.h"
#include "scheduler_Interface.h"

static void RTO_Scheduler(void)
{
    u8 local_u8Count=0;
    for(local_u8Count=0;local_u8Count<No_Of_Task;local_u8Count++)
    {
        if ((Task_Arr[local_u8Count].First_Delay==0)&&(Task_Arr[local_u8Count].pf!=NULL))
        {
            Task_Arr[local_u8Count].PF();
            Task_Arr[local_u8Count].Frist_Delay=Task_Arr[local_u8Count].Periodicity-1;
        }
        else
        {
            Task_Arr[local_u8Count].Frist_Delay--;
        }
    }
}

void RTO_StartOS(void)
{
    //STK INT
    //enable interrupt->STATE
    //CALL BACK
    //STK START ->2000
}
void RTO_voidCreatTask(u32 Copy_u32TaskId,u32 Copy_u32Periodicity,u32 Copy_u32FirstDelay,void(*pf)(void))
{
    if( Copy_u32TaskId<No_Of_Task)
    {
        Task_Arr[Copy_u32TaskId].Periodicity=Copy_u32Periodicity;
        Task_Arr[Copy_u32TaskId].FirstDelay=Copy_u32FirstDelay;
        Task_Arr[Copy_u32TaskId].pf=pf;
    }
}




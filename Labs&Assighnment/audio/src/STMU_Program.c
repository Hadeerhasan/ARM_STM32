/*
 * STMU_Program.c
 *
 *  Created on: Aug 29, 2022
 *      Author: ahmed.hammad
 */

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include "MSTK_Interface.h"


/*#####################################################################################################*/
/*#####################################################################################################*/



#include"STMU_Config.h"
#include"STMU_Interface.h"
#include"STMU_Private.h"

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/


/*Create Task*/
void STMU_voidCreateTask(u8 Copyu8TaskID,u32 Copy_u32Periodicity , void(*Fptr)(void),u32 Copy_u32FirstDelay)
{
	Task_Array[Copyu8TaskID].Periodicity = Copy_u32Periodicity ;
	Task_Array[Copyu8TaskID].FuncPtr =  Fptr  ;
	Task_Array[Copyu8TaskID].FirstDelay = Copy_u32FirstDelay ;
	Task_Array[Copyu8TaskID].State = TASK_READY ;
}


void STMU_voidStart(void)
{
	/*Initialize Systick to determine tick time */
	MSTK_voidInit() ;
	/*Set Function callback*/
	MSTK_voidCallBack(STMU_voidScheuler) ;
	/*Interrupt Enable */
	MSTK_voidCtrlIntState(MSTK_INT_ENABLE) ;
	/*When HSI = 16 MHz , Tick Time = 1ms*/
	MSTK_voidStart(2000) ;
}

/*Start Scheduling*/
static void STMU_voidScheuler(void)
{

  for(u8 i = 0 ;  i <NO_OF_TASKS ; i++ )
  {
	  /*check is ready not suspended or Deleted*/
	  if( Task_Array[i].State == TASK_READY  && Task_Array[i].FuncPtr != NULL )
	  {

		  if(Task_Array[i].FirstDelay == 0)
		  {
			  Task_Array[i].FirstDelay = Task_Array[i].Periodicity - 1  ;
			  Task_Array[i].FuncPtr() ;
		  }
		  else
		  {
			  Task_Array[i].FirstDelay--;
		  }
	  }
  }
}


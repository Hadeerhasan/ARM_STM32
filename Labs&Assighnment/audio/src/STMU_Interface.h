/*
 * STMU_Interface.h
 *
 *  Created on: Aug 29, 2022
 *      Author: ahmed.hammad
 */

#ifndef STMU_INTERFACE_H_
#define STMU_INTERFACE_H_


/*Create Task*/
void STMU_voidCreateTask(u8 Copyu8TaskID,u32 Copy_u32Periodicity , void(*Fptr)(void),u32 Copy_u32FirstDelay) ;


/*Start Scheduling*/

void STMU_voidStart(void) ;

/*Suspend Task*/
void STMU_voidSuspendTask(u8 Copy_u8TaskId) ;

/*Delete Task*/
void STMU_voidDeleteTask(u8 Copy_u8TaskId) ;

/*Resume Task*/
void STMU_voidResumeTask(u8 Copy_u8TaskId) ;




#endif /* STMU_INTERFACE_H_ */

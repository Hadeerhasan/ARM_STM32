/*
 * STMU_Private.h
 *
 *  Created on: Aug 29, 2022
 *      Author: ahmed.hammad
 */

#ifndef STMU_PRIVATE_H_
#define STMU_PRIVATE_H_


typedef struct
{
	void(*FuncPtr)(void) ;
	u32 Periodicity      ;
	u32 FirstDelay       ;
	u8  State            ;
}Task_t;

Task_t   Task_Array[NO_OF_TASKS] = {NULL} ;

static void STMU_voidScheuler(void)  ;


#define TASK_READY       1

#define TASK_SUSPENDED   2

#endif /* STMU_PRIVATE_H_ */

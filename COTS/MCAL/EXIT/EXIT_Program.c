#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


static void (*EXTI_CallBack ) (void) =  NULL ;
void EXTI_voidInit()
{
	#if		EXTI_SENSE_CONTROL	== FALLING_EDGE
			SET_BIT(EXTI -> FTSR, EXTI_LINE);
			CLR_BIT(EXTI -> RTSR, EXTI_LINE);
	#elif	EXTI_SENSE_CONTROL	== RISING_EDGE
			CLR_BIT(EXTI -> FTSR, EXTI_LINE);
			SET_BIT(EXTI -> RTSR, EXTI_LINE);
	#elif	EXTI_SENSE_CONTROL	== ON_CHANGE
			SET_BIT(EXTI -> FTSR, EXTI_LINE);
			SET_BIT(EXTI -> RTSR, EXTI_LINE);
	#else
			#error "Not a valid Configuration!"
	#endif

	
}

void EXTI_voidSetEXTI_Line_Enable(u8 Copy_u8LineId)
{
	SET_BIT(EXTI -> IMR, Copy_u8LineId);
}


void EXTI_voidSetEXTI_Line_Disable(u8 Copy_u8LineId)
{
	CLR_BIT(EXTI -> IMR, Copy_u8LineId);
}


void EXTI_voidSetSenseControl(u8 Copy_u8SenseControl, u8 Copy_u8LineId)
{
	switch(Copy_u8SenseControl)
	{
		case FALLING_EDGE:	SET_BIT(EXTI -> FTSR, Copy_u8LineId);
							CLR_BIT(EXTI -> RTSR, Copy_u8LineId);
							break;
		case RISING_EDGE:	CLR_BIT(EXTI -> FTSR, Copy_u8LineId);
							SET_BIT(EXTI -> RTSR, Copy_u8LineId);
							break;
		case ON_CHANGE:		SET_BIT(EXTI -> FTSR, Copy_u8LineId);
							SET_BIT(EXTI -> RTSR, Copy_u8LineId);
							break;
		default:			break;
	}
}

void EXTI_voidSetEXTIpinConfig(u8 Copy_u8PortId, u8 Copy_u8LineId)
{
	if(Copy_u8LineId <= EXTI_LINE3)
	{
		switch(Copy_u8PortId)
		{
			case EXTI_PA:	SYSCFG->EXTICR1 = ((0b0000) << (Copy_u8LineId*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR1 = ((0b0001) << (Copy_u8LineId*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR1 = ((0b0010) << (Copy_u8LineId*4));
							break;
			default:		break;
		}
	}
	else if (Copy_u8LineId <= EXTI_LINE7)
	{
		switch(Copy_u8PortId)
		{
			case EXTI_PA:	SYSCFG->EXTICR2 = ((0b0000) << ((Copy_u8LineId-4)*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR2 = ((0b0001) << ((Copy_u8LineId-4)*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR2 = ((0b0010) << ((Copy_u8LineId-4)*4));
							break;
			default:		break;
		}
	}
	else if (Copy_u8LineId <= EXTI_LINE11)
	{
		switch(Copy_u8PortId)
		{
			case EXTI_PA:	SYSCFG->EXTICR3 = ((0b0000) << ((Copy_u8LineId-8)*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR3 = ((0b0001) << ((Copy_u8LineId-8)*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR3 = ((0b0010) << ((Copy_u8LineId-8)*4));
							break;
			default:		break;
		}
	}
	else
	{
		switch(Copy_u8PortId)
		{
			case EXTI_PA:	SYSCFG->EXTICR4 = ((0b0000) << ((Copy_u8LineId-12)*4));
							break;
			case EXTI_PB:	SYSCFG->EXTICR4 = ((0b0001) << ((Copy_u8LineId-12)*4));
							break;
			case EXTI_PC:	SYSCFG->EXTICR4 = ((0b0010) << ((Copy_u8LineId-12)*4));
							break;
			default:		break;
		}
	}
}
void EXTI_voidSetCallBack( void (*ptr) (void))
{

	EXTI0_CallBack =ptr  ;
}

void EXTI0_IRQHandler(void)

{

	EXTI0_CallBack();
	SET_BIT( EXTI->PR , 0 );  //clear pendig bit

}


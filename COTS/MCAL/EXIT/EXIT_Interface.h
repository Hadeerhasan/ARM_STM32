#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void EXTI_voidInit();
void EXTI_voidSetEXTI_Line_Enable(u8 Copy_u8LineId);
void EXTI_voidSetEXTI_Line_Disable(u8 Copy_u8LineId);
void EXTI_voidSetSenseControl(u8 Copy_u8SenseControl, u8 Copy_u8LineId);
void EXTI_voidSetEXTIpinConfig(u8 Copy_u8PortId, u8 Copy_u8LineId);
void EXTI_voidSetCallBack( void (*ptr) (void));
void EXTI_IRQHandler(void);




#endif

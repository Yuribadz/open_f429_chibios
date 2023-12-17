#ifndef MOCK_SWO_REGS_H
#define MOCK_SWO_REGS_H

#include <stdint.h>



extern volatile uint32_t Mock_ITM_STIM_U32;
extern volatile char Mock_ITM_STIM_U8;
extern volatile uint32_t Mock_ITM_ENA;
extern volatile uint32_t Mock_ITM_TCR;

#define ITM_STIM_U32 Mock_ITM_STIM_U32
#define ITM_STIM_U8  Mock_ITM_STIM_U8
#define ITM_ENA      Mock_ITM_ENA
#define ITM_TCR      Mock_ITM_TCR

extern uint32_t SWO_ReadITM_TCR(void);
extern uint32_t SWO_ReadITM_ENA(void);
extern uint32_t SWO_ReadITM_STIM_U8(void);
extern void SWO_WriteITM_STIM_U8(char c);

#endif // MOCK_SWO_REGS_H
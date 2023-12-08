#ifndef MOCK_SWO_H
#define MOCK_SWO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

extern volatile uint32_t Mock_ITM_STIM_U32;
extern volatile char Mock_ITM_STIM_U8;
extern volatile uint32_t Mock_ITM_ENA;
extern volatile uint32_t Mock_ITM_TCR;

#define ITM_STIM_U32 Mock_ITM_STIM_U32
#define ITM_STIM_U8  Mock_ITM_STIM_U8
#define ITM_ENA      Mock_ITM_ENA
#define ITM_TCR      Mock_ITM_TCR
extern void SWO_PrintChar(char c);
extern void SWO_PrintString(const char *s);

#ifdef __cplusplus
}
#endif

#endif // MOCK_SWO_H
 
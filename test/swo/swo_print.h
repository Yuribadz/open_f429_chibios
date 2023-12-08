#ifndef MOCK_SWO_H
#define MOCK_SWO_H

#ifdef __cplusplus
extern "C" {
#endif

extern volatile unsigned int Mock_ITM_STIM_U32;
extern volatile char Mock_ITM_STIM_U8;
extern volatile unsigned int Mock_ITM_ENA;
extern volatile unsigned int Mock_ITM_TCR;

// Replace hardware macros with mock variables
#define ITM_STIM_U32 Mock_ITM_STIM_U32
#define ITM_STIM_U8  Mock_ITM_STIM_U8
#define ITM_ENA      Mock_ITM_ENA
#define ITM_TCR      Mock_ITM_TCR

// Function prototypes remain the same
void SWO_PrintChar  (char c);
void SWO_PrintString(const char *s);

#ifdef __cplusplus
}
#endif

#endif // MOCK_SWO_H
 
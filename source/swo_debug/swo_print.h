/*********************************************************************
*
*       Prototypes (to be placed in a header file such as SWO.h)
*/
void SWO_PrintChar  (char c);
void SWO_PrintString(const char *s);

/*********************************************************************
*
*       Defines for Cortex-M debug unit
*/
/* Stimulus Port Register word access */
#define ITM_STIM_U32 (*(volatile unsigned int*)0xE0000000)
/* Stimulus Port Register word access */
#define ITM_STIM_U8  (*(volatile         char*)0xE0000000)
/* Trace Enable Ports Register */
#define ITM_ENA      (*(volatile unsigned int*)0xE0000E00)
/* Trace control register */
#define ITM_TCR      (*(volatile unsigned int*)0xE0000E80)
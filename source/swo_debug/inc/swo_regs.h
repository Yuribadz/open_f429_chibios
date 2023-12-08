
/* Stimulus Port Register word access */
#define ITM_STIM_U32 (*(volatile unsigned int*)0xE0000000)
/* Stimulus Port Register word access */
#define ITM_STIM_U8  (*(volatile         char*)0xE0000000)
/* Trace Enable Ports Register */
#define ITM_ENA      (*(volatile unsigned int*)0xE0000E00)
/* Trace control register */
#define ITM_TCR      (*(volatile unsigned int*)0xE0000E80)

/*********************************************************************
* 
*       Accessor Functions
*
*********************************************************************/

/**
 * Read from ITM Trace Control Register (ITM_TCR)
 *
 * @return Value of ITM_TCR register
 */
uint32_t SWO_ReadITM_TCR(void);

/**
 * Read from ITM Trace Enable Ports Register (ITM_ENA)
 *
 * @return Value of ITM_ENA register
 */
uint32_t SWO_ReadITM_ENA(void);

/**
 * Read from ITM Stimulus Port Register U8 (ITM_STIM_U8)
 *
 * @return Value of ITM_STIM_U8 register
 */
uint32_t SWO_ReadITM_STIM_U8(void);

/**
 * Write to ITM Stimulus Port Register U8 (ITM_STIM_U8)
 *
 * @param c Character to be written to ITM_STIM_U8 register
 */
void SWO_WriteITM_STIM_U8(char c);
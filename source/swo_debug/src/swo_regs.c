#include "swo_regs.h"

uint32_t SWO_ReadITM_TCR() {
    return ITM_TCR;
}

uint32_t SWO_ReadITM_ENA() {
    return ITM_ENA;
}

uint32_t SWO_ReadITM_STIM_U8() {
    return (uint32_t)ITM_STIM_U8;
}

void SWO_WriteITM_STIM_U8(char c) {
    ITM_STIM_U8 = c;
}
#include "endianness.h"


/* Implementation of Functions */

uint32_t reverseBits(uint32_t num) {
    uint32_t result;
    __asm__("RBIT %0, %1" : "=r" (result) : "r" (num));
    return result;
}
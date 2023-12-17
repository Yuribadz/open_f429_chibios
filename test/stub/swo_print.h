#ifndef MOCK_SWO_H
#define MOCK_SWO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "swo_regs.h"
extern void SWO_PrintChar  (char c);
extern void SWO_PrintString(const char *s);

#ifdef __cplusplus
}
#endif

#endif // MOCK_SWO_H
 
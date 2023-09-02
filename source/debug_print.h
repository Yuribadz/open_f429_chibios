/*
 * shell_usart1_serial.h
 *
 *  Created on: Aug 14, 2023
 *      Author: yuriy badziuk
 */

#ifndef DEBUG_PRINT_H
#define DEBUG_PRINT_H

#include "ch.h"
#include "hal.h"
#include "chprintf.h"

extern BaseSequentialStream *dbs;
extern const SerialConfig config;
extern bool init_debug(void);
extern bool print_hal_conf(void);

#endif /* DEBUG_PRINT_H */
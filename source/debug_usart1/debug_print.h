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

/**
 * @brief Stream that is used to print debug output with STM32F429IGT6 USART1
 * hal driver.
 * 
 */
extern BaseSequentialStream *dbs;

/**
 * @brief Configuration for the USARTV1 Driver of ChibiOS HAL
 * 
 */
extern const SerialConfig config;

/**
 * @brief Initialize USARTv1 ChibiOS Driver. Use USART1 and speed 115200
 * 
 * @return HAL_SUCCESS Driver initialized.
 * @return HAL_FAILED  sdInit returned error;
 */
extern bool init_debug(void);

/**
 * @brief Display configured system information:
 * 1. RCC config
 * 
 */
extern void print_hal_conf(void);

#endif /* DEBUG_PRINT_H */
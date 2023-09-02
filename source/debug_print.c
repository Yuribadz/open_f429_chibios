/*
 * usart1cfg.c
 *
 *  Created on: Aug 14, 2023
 *      Author: yuriy badziuk
 */

#include "debug_print.h"
#define MHZ 1000000U

BaseSequentialStream *dbs = NULL;
const SerialConfig config = { .speed = 115200 };

bool init_debug(void)
{
	dbs = (BaseSequentialStream *)&SD1;
	sdStart(&SD1, &config);
	return HAL_SUCCESS;
}
bool print_hal_conf(void)
{
	chprintf(dbs, "Pll Source Clock HSE Frequency %u MHz\r\n",
		 STM32_PLLSRCCLK / MHZ);
	chprintf(dbs, "/ by PLLM divider value %u\r\n", STM32_PLLM_VALUE);
	chprintf(dbs, "* by PLLN multiplier value %u\r\n", STM32_PLLN_VALUE);
	chprintf(dbs, "Results in SYSCLK Value %u MHz\r\n", STM32_SYSCLK / MHZ);
	chprintf(dbs, "SYSCLK divided by 1 results in %u MHz AHB\r\n",
		 STM32_HCLK / MHZ);
	chprintf(dbs, "SystemCoreClock variable value equals %u\r\n",
		 SystemCoreClock);
	chprintf(dbs, "APB1 Prescaler divisor value %u, APB1 Freq is %u\r\n", 4,
		 (STM32_SYSCLK / MHZ) / 4);
	chprintf(dbs, "APB1 Prescaler divisor value %u, APB1 Freq is %u\r\n", 2,
		 (STM32_SYSCLK / MHZ) / 2);
	chprintf(dbs, "Audio and LCD PLL(PLLSAI)\r\n");
	uint32_t lcdFreq = ((((STM32_PLLSRCCLK / MHZ) / STM32_PLLM_VALUE) *
			     STM32_PLLSAIN_VALUE) /
			    STM32_PLLSAIR_VALUE) /
			   2;

	chprintf(dbs, "LCD Clock frequency is %u MHz\r\n", lcdFreq);
	return HAL_SUCCESS;
}

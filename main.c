/*
 ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#include "ch.h"
#include "hal.h"
#include "debug_print.h"
#include "swo_print.h"
#include "thread_registry.h"

/*
 * Red LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg)
{
    (void)arg;
    chRegSetThreadName("blinker1");
    while (true) {
        palClearPad(GPIOF, 6U);
        chThdSleepMilliseconds(500);
        palSetPad(GPIOF, 6U);
        chThdSleepMilliseconds(500);
    }
}

/*
 * Green LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread2, 128);
static THD_FUNCTION(Thread2, arg)
{
    (void)arg;
    chRegSetThreadName("blinker2");
    while (true) {
        palClearPad(GPIOF, 7U);
        chThdSleepMilliseconds(500);
        palSetPad(GPIOF, 7U);
        chThdSleepMilliseconds(500);
    }
}

/*===========================================================================*/
/* Initialization and main thread.                                           */
/*===========================================================================*/

/*
 * Application entry point.
 */
int main(void)
{
    /*
     * System initializations.
     * - HAL initialization, this also initializes the configured device drivers
     *   and performs the board-specific initializations.
     * - Kernel initialization, the main() function becomes a thread and the
     *   RTOS is active.
     */
    halInit();
    chSysInit();
    init_debug();
    /*
     * Creating the blinker threads.
     */
    palSetPadMode(GPIOF, 6U, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOF, 7U, PAL_MODE_OUTPUT_PUSHPULL);

    led1_thread = chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO + 10,
              Thread1, NULL);
    led2_thread = chThdCreateStatic(waThread2, sizeof(waThread2), NORMALPRIO + 10,
              Thread2, NULL);
    print_hal_conf();
    /*
     * Normal main() thread activity, spawning shells.
     */
    while (true) {
        chThdSleepSeconds(5);
        print_hal_conf();
    }
}

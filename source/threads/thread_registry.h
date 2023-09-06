#ifndef THREAD_REGISTRY_H
#define THREAD_REGISTRY_H

#include "ch.h"

/*
 * @brief Pointer to LED 1 thread
 */
extern thread_t *led1_thread;
/*
 * @brief Pointer to LED 2 thread
 */
extern thread_t *led2_thread;
/*
 * @brief Pointer to LED 3 thread
 */
extern thread_t *led3_thread;
/*
 * @brief Pointer to LED 4 thread
 */
extern thread_t *led4_thread;

#endif
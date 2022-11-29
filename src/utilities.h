#ifndef _UTILITIES_H
#define _UTILITIES_H

#include "Arduino.h"

// REdefine variable to const
#define LED1 16
#define LED_RED_1 17
#define BUTTON_PIN 14
#define uS_TO_S_FACTOR 1000000 /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP 4        /* Time that ESP32 will go to sleep (in seconds) */

RTC_DATA_ATTR int bootCount = 0;

/*************************************************
 * Custom Delay function to replace the native one
 *
 */

void delay_bis(int del);

/*************************************************
 * Function to handle button events
 *
 */

void button_events(int pin);

/*************************************************
 * Function to manage light sleep mode
 * with timer
 */
void light_sleep_mode_timer(int periode);

/*************************************************
 * Function to manage light sleep mode
 *with signal
 */
void light_sleep_mode_signal(gpio_num_t periode);

/*************************************************
 * Function to manage deep sleep mode
 */
void deep_sleep_mode();

#endif
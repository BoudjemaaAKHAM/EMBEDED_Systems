#ifndef _UTILITIES_H
#define _UTILITIES_H

#include "Arduino.h"

// REdefine variable to const
#define LED1 16
#define LED_RED_1 17
#define BUTTON_PIN 14

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
 *
 */
void light_sleep_mode(int periode);

#endif
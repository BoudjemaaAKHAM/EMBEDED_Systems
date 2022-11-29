#include "utilities.h"

void delay_bis(int del)
{
    unsigned long prev_millis = millis();
    unsigned long current_millis = prev_millis;
    while (current_millis - prev_millis <= del)
    {
        current_millis = millis();
    }
}

void button_events(int pin)
{
    Serial.println("Handling button events :");
    int button_state = digitalRead(pin);

    Serial.println(button_state);

}
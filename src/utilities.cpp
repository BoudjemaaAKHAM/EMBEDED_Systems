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

void light_sleep_mode(int periode)
{
    esp_sleep_enable_timer_wakeup(periode);
    int ret = esp_light_sleep_start();
    if (ret == 0)
    {
        Serial.print("light_sleep mode réussi. Code : ");
        Serial.println(ret);
    }
    else
    {
        Serial.print("light_sleep mode échoué. Code : ");
        Serial.println(ret);
    }
}
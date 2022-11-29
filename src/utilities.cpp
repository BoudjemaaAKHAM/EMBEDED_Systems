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

void light_sleep_mode_timer(int periode)
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

void light_sleep_mode_signal(gpio_num_t pin)
{
    esp_sleep_enable_ext0_wakeup(pin, HIGH);
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

void deep_sleep_mode()
{
    if (bootCount == 0)
    {
        Serial.print("First time going to deep sleep");
        digitalWrite(LED1, HIGH);
        delay_bis(300);
        digitalWrite(LED1, LOW);
        delay_bis(10);
        bootCount = bootCount + 1;
    }
    else
    {
        bootCount++;
        Serial.print("Getting back from deep sleep. Time --> ");
        Serial.println(bootCount);
        digitalWrite(LED1, HIGH);
        delay_bis(200);
        digitalWrite(LED1, LOW);
        delay(100);
    }
    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
    esp_deep_sleep_start();
}
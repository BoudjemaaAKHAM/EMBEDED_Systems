
#include "utilities.h"

int currentState;

struct Button
{
  const uint8_t PIN;
  uint32_t numberKeyPresses;
  bool pressed;
};

Button button1 = {27, 0, false};

void IRAM_ATTR isr()
{
  button1.numberKeyPresses++;
  button1.pressed = true;
}
void setup()
{
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED_RED_1, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  pinMode(button1.PIN, INPUT_PULLUP);
  attachInterrupt(button1.PIN, isr, CHANGE);
}
void loop()
{
  /*******************************************
   *  Utilisation du delay classique
   *
  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  delay(500);
  ********************************************/

  /*******************************************
   *  Utilisation du delay classique
   *******************************************/
  digitalWrite(LED1, HIGH);
  delay_bis(500);
  digitalWrite(LED1, LOW);
  delay_bis(100);

  // button_events(BUTTON_PIN);

  digitalWrite(LED_RED_1, LOW);
  
  if (button1.pressed)
  {
    Serial.printf("Button has been pressed %u times\n", button1.numberKeyPresses);
    button1.pressed = false;

    digitalWrite(LED_RED_1, HIGH);
  }
}

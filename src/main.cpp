
#include "utilities.h"

int currentState;

struct Button
{
  const uint8_t PIN;
  uint32_t numberKeyPresses;
  bool pressed;
};

Button button1 = {14, 0, false};

IRAM_ATTR void isr()
{
  Serial.print("Button Clicked");
  button1.numberKeyPresses++;
  button1.pressed = true;
}
void setup()
{
  Serial.begin(115200);
  Serial.println("*** setup  ***");
  pinMode(LED1, OUTPUT);
  pinMode(LED_RED_1, OUTPUT);
  // pinMode(BUTTON_PIN, INPUT_PULLUP);

  pinMode(button1.PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button1.PIN), isr, RISING);
}
void loop()
{
  /*******************************************
   * Utilisation du delay classique
   ********************************************/
  /* digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  delay(500); */

  /*******************************************
   * Utilisation du delay classique
   *******************************************/
  /* digitalWrite(LED1, HIGH);
  delay_bis(500);
  digitalWrite(LED1, LOW);
  delay_bis(100); */

  // button_events(BUTTON_PIN);

  /*******************************************
   * Utilisation des interuptions
   *******************************************/
  if (button1.pressed)
  {
    Serial.printf("Button has been pressed %u times\n", button1.numberKeyPresses);
    button1.pressed = false;
  }

  /*******************************************
   * Utilisation du mode light sleep avec un
   * timer pour le réveil (5 secondes)
   * et réveil externe par signal
   *******************************************/
  // light_sleep_mode_timer(5000000);
  // light_sleep_mode_signal(GPIO_NUM_14);

  /*******************************************
   * Utilisation du mode deep sleep
   *******************************************/
  deep_sleep_mode();
}

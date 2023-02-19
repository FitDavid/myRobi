#include "LEDs.h"

LEDs::LEDs() :
last_time(millis()),
led_state(HIGH)
{
  pinMode(LED_pin_g, OUTPUT);
  pinMode(LED_pin_r, OUTPUT);
}

void LEDs::light_up(enum movement state)
{
   switch(state)
   {
    case FWARD: digitalWrite(LED_pin_g, HIGH); digitalWrite(LED_pin_r, LOW);
    break;
    case BWARD: digitalWrite(LED_pin_g, LOW); digitalWrite(LED_pin_r, HIGH);
    break;
    case ROTATE_L: square_signal(250); digitalWrite(LED_pin_g, LOW); digitalWrite(LED_pin_r, led_state);
    break;
    case ROTATE_R: square_signal(250); digitalWrite(LED_pin_g, led_state); digitalWrite(LED_pin_r, LOW);
    break;
   }
    
}

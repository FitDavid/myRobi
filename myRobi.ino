
#include "Motion_control.h"
#include "Sound.h"
#include "Sound_pitches.h"
#include "LEDs.h"

// pin layout
#define LED_pin_g  A0
#define LED_pin_r  A1
#define ping_pin A3
#define echo_pin  A5
#define sound_pin  2

Motion_control m_control;
Sound sound;
LEDs leds;

void setup() 
{
  Serial.begin(9600); // Open serial monitor at 9600 baud to see debugging messages
  Serial.println("Setup done.");
}

void loop() 
{
  m_control.sonar();
  m_control.run();
  sound.play(m_control.get_motion());
  leds.light_up(m_control.get_motion());
}

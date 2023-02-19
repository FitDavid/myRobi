#include "Motion_control.h"
#include <AFMotor.h>

Motion_control::Motion_control():  
motor3(3),  
motor4(4), 
motion(VOID), 
last_turn(VOID),
last_ping_time(millis()),
last_motion_change(0),
obstacle(false)
{
  pinMode(ping_pin, OUTPUT);
  pinMode(echo_pin,INPUT);
  motor3.setSpeed(SPEED_MIN_3);
  motor3.run(RELEASE);
  motor4.setSpeed(SPEED_MIN_4);
  motor4.run(RELEASE);
}

void Motion_control::sonar()
{
  unsigned long now = millis();
  if( now - last_ping_time < 333UL) return;
  last_ping_time = now;
  digitalWrite(ping_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(ping_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(echo_pin, LOW);
  unsigned long duration = pulseIn(echo_pin, HIGH, 30000);
  if(duration < 882UL && obstacle == false) // 2 x 15 cm-re van akadály
  {
      if(prng.getRndByte() < 200)
      {
        motion = ROTATE_L;
        Serial.println("ROTATE LEFT");
      }
      else
      {
       motion = ROTATE_R; 
       Serial.println("ROTATE RIGHT");
      }
      obstacle = true;
  }
  Serial.print(duration/29/2);
  Serial.print(" cm");
  Serial.println();
  return;
}

void Motion_control::run()
{
  if(motion == VOID) return;
  unsigned long now = millis();
  if(last_motion_change == 0) last_motion_change = now;
  if(motion == FWARD) // rewrite to switch{}
  {
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    if(now - last_motion_change > 5000)
    {
      motion = BWARD;
      last_motion_change = now;
      Serial.println("BACKWARD");
    }
  }
  else if(motion == BWARD)
  {
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    if(now - last_motion_change > 3000)
    {
      motion = FWARD;
      last_motion_change = now;
      Serial.println("FORWARD");
    }
  }
  else if(motion == ROTATE_L)
  {
    motor3.run(BACKWARD);
    motor4.run(FORWARD);
    if(now - last_motion_change > 1000)
    {
      motion = FWARD;
      last_motion_change = now;
      obstacle = false;
      Serial.println("FORWARD");
    }
  }
  else
  {
    motor3.run(FORWARD);
    motor4.run(BACKWARD);
    if(now - last_motion_change > 1000)
    {
      motion = FWARD;
      last_motion_change = now;
      obstacle = false;
      Serial.println("FORWARD");
    }
  }
  return;
}

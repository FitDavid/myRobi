#include "Motor.h"
#include <AFMotor.h>

Motor::Motor():  motor3(3),  motor4(4)
{
  motor3.setSpeed(SPEED_MIN_3);
  motor3.run(RELEASE);
  motor4.setSpeed(SPEED_MIN_4);
  motor4.run(RELEASE);
}

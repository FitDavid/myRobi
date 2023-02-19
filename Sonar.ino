#include "Sonar.h"

Sonar::Sonar()
{
     pinMode(ping_pin, OUTPUT);
  pinMode(echo_pin,INPUT);
}

Sonar::~Sonar()
{
    //dtor
}

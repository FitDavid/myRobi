#ifndef MOTOR_H
#define MOTOR_H

#include <AFMotor.h>

enum motions 
{
VOID,
FWARD,
BWARD,
ROTATE_L,
ROTATE_R };


class Motor
{
    public:
        Motor();
        
    private:
    AF_DCMotor motor3;
    AF_DCMotor motor4;
   
};

#endif // MOTOR_H

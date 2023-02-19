#ifndef MOTION_CONTROL_H
#define MOTION_CONTROL_H
#include "pRNG.h"

#include <AFMotor.h>

//motorspeeds
#define SPEED_MIN_3 200
#define SPEED_MAX_3 255 
#define SPEED_MIN_4 200
#define SPEED_MAX_4 235

#define RUN_TIME 60000ul
#define TURN_TIME 800ul

enum movement 
{
VOID,
FWARD,
BWARD,
ROTATE_L,
ROTATE_R };


class Motion_control
{
    public:
        Motion_control();
        enum movement get_motion(){return motion;}
        void sonar();
        void run();
        
    private:
    AF_DCMotor motor3;
    AF_DCMotor motor4;
    enum movement motion;
    unsigned long last_ping_time;
    unsigned long last_motion_change;
    enum movement last_turn;
    bool obstacle;
    pRNG prng;
   
};

#endif // MOTION_CONTROL_H

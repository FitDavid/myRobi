#ifndef SONAR_H
#define SONAR_H


class Sonar
{
    public:
        Sonar();
        ~Sonar();
        enum motions get_current_motion(){return current_motion;}

    private:
     enum motions current_motion;
};

#endif // SONAR_H

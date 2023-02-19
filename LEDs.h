#ifndef LEDS_H
#define LEDS_H


class LEDs
{
    public:
        LEDs();
        void light_up(enum movement state);
        void square_signal(unsigned int interval)
        {
          unsigned long now = millis();
          if(now - last_time > interval)
          {
            if(led_state = HIGH) led_state = LOW;
            else led_state = HIGH;
          }
        }

    protected:

    private:
    unsigned long last_time;
    byte led_state;
};

#endif // LEDS_H

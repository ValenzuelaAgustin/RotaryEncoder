#ifndef ROTARYENCODER_HPP
#define ROTARYENCODER_HPP
#include <Arduino.h>

class RotaryEncoder
{
public:
    RotaryEncoder(byte A_pin, byte B_pin);
    void begin(void(*ISR)());
    void checkPosition();

    volatile int position;

private:
    enum {A = 0, B = 1, CW = 75, CCW = 135};
    volatile byte pin[2];
    volatile byte AB;
    volatile byte ab;
};

#endif
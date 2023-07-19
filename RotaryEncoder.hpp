#ifndef ROTARYENCODER_HPP
#define ROTARYENCODER_HPP
#include <Arduino.h>

#ifndef byte
#define byte unsigned char
#endif

class RotaryEncoder
{
public:
    RotaryEncoder(byte A_pin, byte B_pin);
    void begin(void(*ISR)());

    void checkPosition();

    volatile int position = 0;

private:
    enum {A = 0, B = 1};
    byte pin[2];
    byte AB;
};

#endif
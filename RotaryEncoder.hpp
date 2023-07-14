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
    int getPosition();
    void setPosition(int position);

private:
    enum {CCW = 0, CW = 1};
    enum {A = 0, B = 1};

    byte pin[2];
    bool last[2];
    bool changed_signal;

    int position = 0;

    bool getDirection();
    void isRotating();

    void Achanged();
    void Bchanged();
};

#endif
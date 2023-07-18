#ifndef ROTARYENCODER_HPP
#define ROTARYENCODER_HPP
#include <Arduino.h>

#ifndef byte
#define byte unsigned char
#endif

enum {A = 0, B = 1};

void change();

class RotaryEncoder
{
public:
    RotaryEncoder(byte A_pin, byte B_pin);

    void checkPosition();

    int position = 0;

private:
    byte pin[2];
    byte AB;
};

RotaryEncoder* ptr_RE = 0;

#endif
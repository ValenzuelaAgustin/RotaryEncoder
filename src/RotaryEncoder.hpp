#ifndef ROTARYENCODER_HPP
#define ROTARYENCODER_HPP
#include <Arduino.h>

class RotaryEncoder
{
public:
    RotaryEncoder(uint8_t A_pin, uint8_t B_pin);
    void begin(void(*ISR)());
    void checkPosition();

    volatile int16_t position = 0;

private:
    enum {A = 0, B = 1, CW = 75, CCW = 135};
    volatile uint8_t pin[2];
    volatile uint8_t AB = 0xff;
    volatile uint8_t ab = 0;
};

#endif
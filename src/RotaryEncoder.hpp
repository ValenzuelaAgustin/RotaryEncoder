#ifndef ROTARYENCODER_HPP
#define ROTARYENCODER_HPP
#include <Arduino.h>

class RotaryEncoder
{
public:
    RotaryEncoder(uint8_t A_pin, uint8_t B_pin);
    void begin(void(*ISR)());
    void checkPosition();

    volatile uint8_t position;

private:
    enum {A = 0, B = 1, CW = 75, CCW = 135};
    volatile uint8_t pin[2];
    volatile uint8_t AB;
    volatile uint8_t ab;
};

#endif
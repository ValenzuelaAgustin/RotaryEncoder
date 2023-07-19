#include "RotaryEncoder.hpp"

RotaryEncoder::RotaryEncoder(byte A_pin, byte B_pin)
{
    pin[A] = A_pin;
    pin[B] = B_pin;
    pinMode(pin[A], INPUT_PULLUP);
    pinMode(pin[B], INPUT_PULLUP);
}

void RotaryEncoder::begin(void(*ISR)())
{
    attachInterrupt(digitalPinToInterrupt(pin[A]), ISR, CHANGE);
    attachInterrupt(digitalPinToInterrupt(pin[B]), ISR, CHANGE);
}

void RotaryEncoder::checkPosition()
{
    AB <<= 2;
    if (digitalRead(pin[A])) AB |= 0x02;
    if (digitalRead(pin[B])) AB |= 0x01;
    switch (AB)
    {
    case 75:
        ++position;
        break;
    
    case 135:
        --position;
        break;
    }
}

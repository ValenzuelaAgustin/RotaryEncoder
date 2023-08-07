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
    ab = 0;
    if (digitalRead(pin[A])) ab |= 0x02;
    if (digitalRead(pin[B])) ab |= 0x01;
    if ((AB & 0x03) == ab) return;
    AB <<= 2;
    AB |= ab;
    switch (AB)
    {
    case CW:
        ++position;
        break;
    case CCW:
        --position;
        break;
    }
}
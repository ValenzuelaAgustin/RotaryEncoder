#include "RotaryEncoder.hpp"

RotaryEncoder::RotaryEncoder(byte A_pin, byte B_pin)
{
    pin[A] = A_pin;
    pin[B] = B_pin;
    pinMode(pin[A], INPUT_PULLUP);
    pinMode(pin[B], INPUT_PULLUP);
    if (digitalRead(pin[A])) AB |= 0x02;
    if (digitalRead(pin[B])) AB |= 0x01;
}

void RotaryEncoder::begin(void(*ISR)())
{
    attachInterrupt(digitalPinToInterrupt(pin[A]), ISR, CHANGE);
    attachInterrupt(digitalPinToInterrupt(pin[B]), ISR, CHANGE);
}

void RotaryEncoder::checkPosition()
{
    AB <<= 2;
    AB &= 0x0f;
    if (digitalRead(this->pin[A])) AB |= 0x02;
    if (digitalRead(this->pin[B])) AB |= 0x01;
    if ((AB % 3) == 0 || (AB % 5) == 0) return;
    switch (AB)
    {
    case 2:
        ++position;
        break;
    case 4:
        ++position;
        break;
    case 11:
        ++position;
        break;
    case 13:
        ++position;
        break;
    default:
        --position;
        break;
    }
}
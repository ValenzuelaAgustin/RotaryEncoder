#include "RotaryEncoder.hpp"

RotaryEncoder::RotaryEncoder(byte A_pin, byte B_pin)
{
    pin[A] = A_pin;
    pin[B] = B_pin;
    pinMode(pin[A], INPUT_PULLUP);
    pinMode(pin[B], INPUT_PULLUP);
    if (digitalRead(pin[A])) AB |= 0x02;
    if (digitalRead(pin[B])) AB |= 0x01;
    attachInterrupt(digitalPinToInterrupt(pin[A]), change, CHANGE);
    attachInterrupt(digitalPinToInterrupt(pin[B]), change, CHANGE);
}

void RotaryEncoder::checkPosition()
{
    AB <<= 2;
    AB &= 0x0f;
    if (digitalRead(this->pin[A])) AB |= 0x02;
    if (digitalRead(this->pin[B])) AB |= 0x01;
    if ((AB % 3) == 0 || (AB % 5) == 0) return;
    if (AB == 2 || AB == 4 || AB == 11 || AB == 13) ++position;
    else --position;
}

void change()
{
    if (ptr_RE == 0) return;
    ptr_RE->checkPosition();
}
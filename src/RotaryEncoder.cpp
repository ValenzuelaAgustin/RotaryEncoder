#include "RotaryEncoder.hpp"

RotaryEncoder::RotaryEncoder(uint8_t A_pin, uint8_t B_pin)
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
    ab = (bool)digitalRead(pin[A]) * 0x02 + (bool)digitalRead(pin[B]) * 0x01;
    if ((AB & 0x0c) == ab) AB >>= 2; // Checks if the encoder has stepped back.
    if ((AB & 0x03) == ab) return;   // Checks if the encoder is in the same step as before.
    AB <<= 2;
    AB |= ab;
    position += (AB == CW) - (AB == CCW);
}
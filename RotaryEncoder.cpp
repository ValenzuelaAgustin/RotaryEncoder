#include "RotaryEncoder.hpp"

RotaryEncoder::RotaryEncoder(byte A_pin, byte B_pin)
{
    pin[A] = A_pin;
    pin[B] = B_pin;
    last[A] = digitalRead(A_pin);
    last[B] = digitalRead(B_pin);
    attachInterrupt(pin[A], &Achanged, CHANGE);
    attachInterrupt(pin[B], &Bchanged, CHANGE);
}

int RotaryEncoder::getPosition()
{
    return position;
}

int RotaryEncoder::setPosition(int position)
{
    this->position = position;
}

bool RotaryEncoder::getDirection()
{
    switch (changed_signal)
    {
    case A:
        switch (last[A])
        {
        case 0:
            return last[B];
            break;
        
        case 1:
            return !last[B];
            break;
        }
        break;
    
    case B:
        switch (last[B])
        {
        case 0:
            return !last[A];
            break;
        
        case 1:
            return last[A];
            break;
        }
        break;
    }
}

void RotaryEncoder::isRotating()
{
    switch (getDirection())
    {
    case CW:
        ++position;
        break;
    
    case CCW:
        --position;
        break;
    }
}

void RotaryEncoder::Achanged()
{
    changed_signal = A;
    isRotating();
    last[A] = !last[A];
}

void RotaryEncoder::Bchanged()
{
    changed_signal = B;
    isRotating();
    last[B] = !last[B];
}
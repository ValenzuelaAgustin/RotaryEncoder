#include "RotaryEncoder.hpp"

RotaryEncoder RE1(2, 3);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.print(RE1.getPosition());
}
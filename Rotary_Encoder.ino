#include "RotaryEncoder.hpp"

RotaryEncoder RE1(13, 12);
int last = 0;

void setup()
{
    Serial.begin(115200);
    ptr_RE = &RE1;
}

void loop()
{
  if (last != RE1.position)
  {
    last = RE1.position;
    Serial.print("Rotary Encoder Pos: ");
    Serial.println(last);
  }
}
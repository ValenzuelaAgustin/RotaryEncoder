#include "RotaryEncoder.hpp"

int last = 0;
RotaryEncoder RE(13, 12);
RotaryEncoder* ptr_RE = &RE;
void ISR()
{
    ptr_RE->checkPosition();
}

void setup()
{
    Serial.begin(115200);
    RE.begin(ISR);
}

void loop()
{
  if (last != RE.position)
  {
    last = RE.position;
    Serial.print("Rotary Encoder Pos: ");
    Serial.println(last);
  }
}
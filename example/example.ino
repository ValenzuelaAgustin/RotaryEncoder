#include <PushButton.hpp>
#include <RotaryEncoder.hpp>

/*
https://wokwi.com/projects/370517415324581889
*/

int counter = 0;

RotaryEncoder RE(15, 2);
PushButton REButton(4, INPUT_PULLUP);

void ISR()
{
    RE.checkPosition();
}

void setup()
{
    Serial.begin(115200);
    RE.begin(ISR);
}

void loop()
{
  if (!REButton.Read())
  {
    Serial.print("You selected the number: ");
    Serial.println(counter);
    counter = 0;
    RE.position = 0;
  }

  if (counter != RE.position)
  {
    counter = RE.position;
    Serial.print("Rotary Encoder Pos: ");
    Serial.println(counter);
  }
}
#include <Arduino.h>
#include "EasyLED"

EasyLED led(25);

void setup() {
  led.begin();

  led.toggle();
  delay(1000);
  led.toggle();
}

void loop() {
  delay(1);
}
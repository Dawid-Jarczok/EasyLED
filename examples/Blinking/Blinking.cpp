#include <Arduino.h>
#include "EasyLED.h"

EasyLED led(25);

void setup() {
  led.begin();

  led.blink(10.0);
}

void loop() {
  led.handle();
}
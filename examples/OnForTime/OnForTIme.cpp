#include <Arduino.h>
#include "EasyLED.h"

EasyLED led(25);

void setup() {
  led.begin();
  led.on(2000); // Turn on led and turn off after 2 seconds
}

void loop() {
  led.handle();
}
#include <Arduino.h>
#include "EasyLED.h"

EasyLED led(25);

void setup() {
  led.begin();
  led.blink(2.0, 2000); // Blinking at 2Hz for 2 seconds (led should be on 4 times)
}

void loop() {
  led.handle();
}
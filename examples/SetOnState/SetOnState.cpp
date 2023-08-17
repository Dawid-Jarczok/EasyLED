#include <Arduino.h>
#include "EasyLED.h"

EasyLED led(25);

void setup() {
  Serial.begin(115200);
  led.begin();

  Serial.println("Setting LED ON - control anode");
  led.on();
  delay(2000);
  Serial.println("Setting LED OFF - control anode");
  led.off();
  delay(2000);

  Serial.println("Setting LED ON - control cathode");
  led.setOnState(LOW);
  led.on();
  delay(2000);
  Serial.println("Setting LED OFF - control cathode");
  led.off();
}

void loop() {
}
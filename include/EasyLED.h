#pragma once

#include "Arduino.h"

class EasyLED {
  public:
    EasyLED(uint8_t _pin);

    typedef enum {
        STATIC, BLINKING,
    } LedStates;

    void begin();
    void handle();
    void on();
    void on(uint16_t time);
    void off();
    void toggle();
    void blink(float freq = 1.0);
    void blink(float freq, uint16_t time);

    inline bool getState() {
      return this->state;
    }

    inline EasyLED::LedStates getStatus() {
      return this->status;
    }

  private:
    uint8_t pin;
    LedStates status = STATIC;
    bool state = false;
    uint16_t blinkingHalfPeriod = 500;
    uint32_t offMillis;
    bool timerStatus = false;
};
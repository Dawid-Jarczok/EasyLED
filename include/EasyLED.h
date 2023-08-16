#pragma once

#include "Arduino.h"

class EasyLED {
  public:
    EasyLED(uint8_t _pin);

    typedef enum {
        OFF = 0, ON = 1, BLINKING
    } LedStates;

    void begin();
    void handle();
    void toggle();
    void toggle(bool _state);
    void toggleFor(uint16_t time);
    void toggleBlinking(float freq = 1.0);
    void toggleBlinkingFor(float freq, uint16_t time);

    inline bool getState() {
      return this->state;
    }

    inline EasyLED::LedStates getStatus() {
      return this->status;
    }

  private:
    uint8_t pin;
    LedStates status = OFF;
    bool state = OFF;
    uint16_t blinkingHalfPeriod = 500;
    uint32_t offMillis;
};
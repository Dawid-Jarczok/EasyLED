#pragma once

#include "Arduino.h"

class EasyLED {
  public:
    EasyLED(uint8_t pin);
    EasyLED();

    ~EasyLED();

    typedef enum {
        STATIC, BLINKING,
    } LedStates;

    void begin();
    void begin(uint8_t pin);
    void setOnState(bool onState);
    void handle();
    void on();
    void on(uint16_t time);
    void off();
    void toggle();
    void toggle(bool state);
    void blink(float freq = 1.0);
    void blink(float freq, uint16_t time);

    
    // @return Actual led state.
    inline bool getState() {
      return this->state;
    }

    // @return Pin state when led is on.
    inline bool getOnState() {
      return this->onState;
    }

    // @return Actual led status.
    inline EasyLED::LedStates getStatus() {
      return this->status;
    }

  private:
    uint8_t pin;
    bool onState = HIGH;
    LedStates status = STATIC;
    bool state = false;
    uint16_t blinkingHalfPeriod = 500;
    uint32_t offMillis;
    bool timerStatus = false;
};
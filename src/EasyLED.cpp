#include "EasyLED.h"

EasyLED::EasyLED(uint8_t _pin) {
    this->pin = _pin;
}

void EasyLED::begin() {
    pinMode(this->pin, OUTPUT);
}

void EasyLED::handle() {
    static uint32_t lastMillis;
    if (this->status == EasyLED::BLINKING) {
        if (millis() - lastMillis >= this->blinkingHalfPeriod) {
            lastMillis= millis();
            this->toggle();
        }   
    }

    if (millis() > this->offMillis) this->toggle(false);
}

void EasyLED::toggle()  {
    this->toggle(!this->state);
}

void EasyLED::toggle(bool _state)  {
    if (this->state != _state) digitalWrite(this->pin, this->state);
    this->state = _state;
    this->status = (EasyLED::LedStates)_state;
}

void EasyLED::toggleBlinking(float freq = 1.0) {
    if (freq == 0.0) {
        toggle(OFF);
        return;
    }
    float Buff = 500.0;
    Buff /= freq;
    this->blinkingHalfPeriod = Buff;
    this->status = BLINKING;
}

void EasyLED::toggleFor(uint16_t time) {
    this->toggle(EasyLED::ON);
    this->offMillis = millis() + time;
}

void EasyLED::toggleBlinkingFor(float freq = 1.0, uint16_t time) {
    this->toggleBlinking(freq);
    this->offMillis = millis() + time;
}

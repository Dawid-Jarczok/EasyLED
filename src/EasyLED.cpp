#include "EasyLED.h"

EasyLED::EasyLED(uint8_t _pin) {
    this->pin = _pin;
}

void EasyLED::begin() {
    pinMode(this->pin, OUTPUT);
}

void EasyLED::handle() {
    static uint32_t lastMillis;
    if (this->status == EasyLED::BLINKING && millis() - lastMillis >= this->blinkingHalfPeriod) {
        lastMillis= millis();
        this->toggle();
    }

    if (this->timerStatus && millis() > this->offMillis) this->off();
}

void EasyLED::on() {
    digitalWrite(this->pin, true);
    this->state = true;
    this->status = EasyLED::STATIC;
}

void EasyLED::on(uint16_t time) {
    this->on();
    this->offMillis = millis() + time;
    this->timerStatus = true;
}

void EasyLED::off() {
    digitalWrite(this->pin, false);
    this->state = false;
    this->status = EasyLED::STATIC;
    this->timerStatus = false;
}

void EasyLED::toggle()  {
    this->state = !this->state;
    digitalWrite(this->pin, this->state);
}

void EasyLED::blink(float freq) {
    if (freq == 0.0) {
        this->off();
        return;
    }
    float Buff = 500.0;
    Buff /= freq;
    this->blinkingHalfPeriod = Buff;
    this->status = this->status = EasyLED::BLINKING;
}

void EasyLED::blink(float freq, uint16_t time) {
    this->blink(freq);
    this->offMillis = millis() + time;
    this->timerStatus = true;
}

#include "EasyLED.h"

/*
    @brief  Constructor.
    @param  pin
            Controlled pin.
    */
EasyLED::EasyLED(uint8_t pin) {
    this->pin = pin;
}

/*
    @brief  Deconstructor.
*/
EasyLED::~EasyLED() {

}

/*
    @brief  Set pin mode and turning off that pin.
*/
void EasyLED::begin() {
    pinMode(this->pin, OUTPUT);
    this->off();
}

/*
    @brief  Set state in which led is on.
    @param  onState
            Pin state when led is on.
            By default HIGH.
*/
void EasyLED::setOnState(bool onState) {
    if (this->onState == onState) return;
    this->onState = onState;
}

/*
    @brief  Used in loop to handle non blocking blinking or off timer.
*/
void EasyLED::handle() {
    static uint32_t lastMillis;
    if (this->status == EasyLED::BLINKING && millis() - lastMillis >= this->blinkingHalfPeriod) {
        lastMillis= millis();
        this->toggle();
    }

    if (this->timerStatus && millis() > this->offMillis) this->off();
}

/*
    @brief  Turn on led.
*/
void EasyLED::on() {
    if (this->state) return;
    digitalWrite(this->pin, this->onState);
    this->state = true;
    this->status = EasyLED::STATIC;
}

/*
    @brief  Turn on led for a certain time.
    @param  time
            Time in ms after which led is turned off.
*/
void EasyLED::on(uint16_t time) {
    this->on();
    this->offMillis = millis() + time;
    this->timerStatus = true;
}

/*
    @brief  Turn off led.
*/
void EasyLED::off() {
    this->timerStatus = false;
    this->status = EasyLED::STATIC;
    if (!this->state) return;
    digitalWrite(this->pin, !this->onState);
    this->state = false;
}

/*
    @brief  Toggle led state.
*/
void EasyLED::toggle()  {
    this->state = !this->state;
    digitalWrite(this->pin, this->state);
}

/*
    @brief  Set led state depending of input parameter.
    @param  state
            New led state.
*/
void EasyLED::toggle(bool state) {
    if (this->state == state) return;
    this->state = state;
    digitalWrite(this->pin, !(this->onState ^ this->state));
}

/*
    @brief  Turn on blinking at specified frequency
    @param  freq
            Blinking frequency.
            0 to turn off.
*/
void EasyLED::blink(float freq) {
    if (freq == 0.0) {
        this->off();
        return;
    }
    this->blinkingHalfPeriod = 500.0 / freq;
    this->status = EasyLED::BLINKING;
}

/*
    @brief  Turn on blinking at specified frequency for certain time.
    @param  freq
            Blinking frequency.
            0 to turn off.
    @param  time
            Time in ms after which led is turned off.

*/
void EasyLED::blink(float freq, uint16_t time) {
    this->blink(freq);
    this->offMillis = millis() + time;
    this->timerStatus = true;
}

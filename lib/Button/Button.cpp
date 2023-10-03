#include "Button.h"
#include <Arduino.h>

Button::Button(int pin, bool buttonDown) : _pin(pin), _buttonDown(buttonDown), _lastDebounceTime(0), _lastButtonState(HIGH) {}

void Button::setup(long startTime) {
    pinMode(_pin, INPUT_PULLUP);
    _buttonState = Off;
}

void Button::update(long now) {
    int reading = digitalRead(_pin);
    Serial.print("Reading: ");
    Serial.println(reading);

    if (reading != _lastButtonState) {
        _lastDebounceTime = now;
    }

    if (now - _lastDebounceTime > _debounceDelay) {
        if (reading != _lastButtonState) {
            if ((reading == LOW && _buttonDown) || (reading == HIGH && !_buttonDown)) {
                _buttonState = Push;
                _nextChangeTime = now + _noiseCancelTimer;
            }
        }
    }

    _lastButtonState = reading;

    switch (_buttonState) {
        case Off:
            return;
        case Push:
            if (now < _nextChangeTime)
                return;
            _buttonState = On;
            break;
        case On:
            if (reading == _lastButtonState)
                return;
            _buttonState = Release;
            _nextChangeTime = now + _noiseCancelTimer;
            break;
        case Release:
            if (now < _nextChangeTime)
                return;
            _buttonState = Off;
            break;
    }
     Serial.print("Button State: ");
    Serial.println(_buttonState);
}

bool Button::GetButtonState() {
    return _buttonState == On || _buttonState == Push;
}

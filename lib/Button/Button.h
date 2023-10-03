#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
public:
    Button(int pin, bool buttonDown);
    void setup(long startTime);
    void update(long now);
    bool GetButtonState();

private:
    enum ButtonState { Off, Push, On, Release };
    const static long _noiseCancelTimer = 10;
    int _pin;
    bool _buttonDown;
    ButtonState _buttonState;
    long _nextChangeTime;
    int _lastButtonState;
    const static long _debounceDelay = 50; // Adjust the debounce delay as needed
    long _lastDebounceTime;
};

#endif // BUTTON_H

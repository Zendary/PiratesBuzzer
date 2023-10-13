#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
public:
    Button(int pin, bool buttonDown);
    void setup(long startTime);
    void update(long now);
    bool GetButtonState();
    int _pin;

private:
    enum ButtonState { Off, Push, On, Release };
    const static long _noiseCancelTimer = 10;
    
    bool _buttonDown;
    ButtonState _buttonState;
    long _nextChangeTime;
    int _lastButtonState;
};

#endif // BUTTON_H

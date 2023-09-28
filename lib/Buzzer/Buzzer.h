// Buzzer.h
#include <Arduino.h>
#ifndef BUZZER_H
#define BUZZER_H

class Buzzer
{
private:
    int *notes;
    int *durations;
    int noteSize;

    unsigned long previousMillis;
    int currentNote;
    bool isPlaying;

    int buzzerPin;
    float songSpeed;

public:
    Buzzer(int pin, float speed, const int notesArray[], const int durationsArray[], int size);
    void playNote();
    void update();
};

#endif // BUZZER_H

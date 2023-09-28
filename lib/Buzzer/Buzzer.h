#ifndef BUZZER_H
#define BUZZER_H

class Buzzer
{
private:
    int *notes;
    int *durations;
    int noteSize;
    int currentNote;
    bool isPlaying;
    const int buzzerPin;
    float songSpeed;
    unsigned long previousMillis;
    unsigned long nextNoteTime;

public:
    Buzzer(int pin, int *notesArray, int *durationsArray, int arraySize, float speed = 1.0);

    void playNote();
    void start();
    void update();
};

#endif

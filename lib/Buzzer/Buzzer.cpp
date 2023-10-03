#include "Buzzer.h"
#include <Arduino.h>

Buzzer::Buzzer(int pin, int *notesArray, int *durationsArray, int arraySize, float speed)
    : buzzerPin(pin), notes(notesArray), durations(durationsArray), noteSize(arraySize), songSpeed(speed), isPlaying(false), currentNote(0), previousMillis(0)
{
}

void Buzzer::playNote()
{
    if (currentNote < noteSize)
    {
        int noteDuration = songSpeed * durations[currentNote];
        if (notes[currentNote] != 0)
        {
            tone(buzzerPin, notes[currentNote]);
        }
        else
        {
            noTone(buzzerPin);
        }
        previousMillis = millis();
        nextNoteTime = previousMillis + noteDuration;
        currentNote++;
    }
    else
    {
        currentNote = 0;
        isPlaying = false;
    }
}

void Buzzer::start()
{
    isPlaying = true;
    currentNote = 0;
    playNote();
}

void Buzzer::update()
{
    if (isPlaying && millis() >= nextNoteTime)
    {
        playNote();
    }
}

void Buzzer::stop()
{
    isPlaying = false;
    noTone(buzzerPin);
}

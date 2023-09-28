// Buzzer.cpp
#include "Buzzer.h"
#include <Arduino.h>

Buzzer::Buzzer(int pin, float speed, const int notesArray[], const int durationsArray[], int size)
    : buzzerPin(pin), songSpeed(speed), noteSize(size), previousMillis(0), currentNote(0), isPlaying(false)
{

    notes = new int[noteSize];
    durations = new int[noteSize];

    // Copy notes and durations to class arrays
    for (int i = 0; i < noteSize; i++)
    {
        notes[i] = notesArray[i];
        durations[i] = durationsArray[i];
    }
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

void Buzzer::update()
{
    if (isPlaying && millis() >= nextNoteTime)
    {
        playNote();
    }
}

void Buzzer::start()
{
    isPlaying = true;
    currentNote = 0;
    playNote();
}

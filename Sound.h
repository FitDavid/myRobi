#ifndef SOUND_H
#define SOUND_H
#include "Motion_control.h"
#include "Sound_pitches.h"

extern const unsigned char sound_pin;

#define TUNE_LENGTH 4

// Tones
const int on_notes[8] = {NOTE_C4, NOTE_E4, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_G4, NOTE_C5, 0 };
const int on_durations[8] = {125, 125, 125, 125,125, 125, 125, 250 }; 
const int off_notes[8] = {NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4}; // notes in the melody:
const int off_durations[8] = {250, 125, 125, 250,250,250,250,250, }; // note durations: 4 = quarter note, 8 = eighth note, etc.:
const int rot_rev_notes[TUNE_LENGTH] = {NOTE_C5, NOTE_C5,NOTE_C5, NOTE_C5};
const int rot_rev_durations[TUNE_LENGTH] = {125, 125,125,125 };
const int rot_right_notes[TUNE_LENGTH] = {NOTE_F5, NOTE_A5,NOTE_F5, NOTE_A5};
const int rot_right_durations[TUNE_LENGTH] = {125, 125,125,125 };
const int rot_left_notes[TUNE_LENGTH] = { NOTE_A5, NOTE_F5,NOTE_A5, NOTE_F5};
const int rot_left_durations[TUNE_LENGTH] = {125, 125,125,125 };



class Sound
{
    public:
        Sound();
        ~Sound();
        void play(enum movement tune);
    private:
        const int *tune_notes[3];
        const int *tune_durations[3];
        unsigned char current_note;
        unsigned long note_start_time;
};

#endif // SOUND_H

#include "Sound.h"

Sound::Sound():    
    current_note(0), // 0 means first note in array
    note_start_time(0), // 0 means invalid data, no tune playing
    tune_notes{rot_rev_notes, rot_right_notes, rot_left_notes},
    tune_durations{rot_rev_durations, rot_right_durations, rot_left_durations}
{
    for(int current_note = 0; current_note < 8; current_note++) //every tune consists of 8 notes
    {
        tone(sound_pin, on_notes[current_note],on_durations[current_note]);
        int pause = on_durations[current_note] * 1.30; // to distinguish the notes, set a minimum time between them. the note's duration + 30% seems to work well:
        delay(pause);
    }
}

Sound::~Sound()
{
    for(int current_note = 0; current_note < 8; current_note++) //every tune consists of 8 notes
    {
        tone(sound_pin, off_notes[current_note],off_durations[current_note]);
        int pause = off_durations[current_note] * 1.30; // to distinguish the notes, set a minimum time between them. the note's duration + 30% seems to work well:
        delay(pause);
    }
    noTone(sound_pin); // stop the tone playing:
}



void Sound::play(enum movement tune) // every motion state corresponds to a tune
{
     if(note_start_time == 0) note_start_time = millis();
     unsigned int elapsed_time = millis() - note_start_time;
     if(tune = VOID)return;
     if(elapsed_time < tune_durations[tune][current_note])
     {
         tone(sound_pin, tune_notes[tune][current_note]);
         
     }
     else if(elapsed_time < 1.3*tune_durations[tune][current_note])
     {
        noTone(sound_pin);
        
     }
     else
     {
        if(current_note < TUNE_LENGTH)
        {
            current_note++;
            note_start_time += elapsed_time;
        }
        else 
        {
          current_note = 0;
          note_start_time = 0;
          tune = VOID;
        }
        
     }
}

/*
  Melody

  Plays a Show Yourself (Frozen 2) first half melody

  circuit:
  - 8 ohm speaker on digital pin 8

  Base source code by Tom Igoe
  Melody, note, and some codes adjustment by Handy Wijaya
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_GS4, NOTE_FS4, 0,
  NOTE_FS4, NOTE_FS4, NOTE_GS4, NOTE_FS4, NOTE_B4, NOTE_AS4, NOTE_GS4, NOTE_FS4, 0,
  
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_GS4, NOTE_GS4, NOTE_FS4, 0,
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_GS4, NOTE_FS4, NOTE_B4, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, 0,
  
  NOTE_FS4, NOTE_CS5, NOTE_CS5, NOTE_AS4, NOTE_AS4, 0,
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_AS4, NOTE_B4, NOTE_AS4, NOTE_AS4, NOTE_FS4, NOTE_AS4, NOTE_GS4, 0,
  
  NOTE_FS4, NOTE_CS5, NOTE_CS5, NOTE_FS4, 0,
  NOTE_FS4, NOTE_AS4, NOTE_B4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_CS5, NOTE_B4, NOTE_AS4, NOTE_GS4, 0,
  
  NOTE_CS4, NOTE_FS4, NOTE_F4, NOTE_CS4, NOTE_CS4, NOTE_DS4, NOTE_F4, NOTE_AS3, 0,
  NOTE_F4, NOTE_F4, NOTE_FS4, NOTE_DS4, NOTE_CS4, NOTE_DS4, 0,
  
  NOTE_A3, NOTE_CS4, NOTE_DS4, NOTE_E4, NOTE_E4, 0,
  NOTE_E4, NOTE_E4, NOTE_FS4, NOTE_FS4, NOTE_GS4, NOTE_GS4, 0,
  
  NOTE_GS4, NOTE_FS4, NOTE_FS4, 0,
  NOTE_FS4, NOTE_FS4, NOTE_DS4, NOTE_CS4, NOTE_CS4, NOTE_F4, 0,
  
  NOTE_GS4, NOTE_FS4, NOTE_FS4, 0,
  NOTE_FS4, NOTE_DS4, NOTE_AS3, 0,
  
  NOTE_AS3, NOTE_GS3, NOTE_AS3, NOTE_CS4, NOTE_AS3, NOTE_CS4, NOTE_DS4, NOTE_CS4, NOTE_AS3, NOTE_FS3, NOTE_GS3, NOTE_AS3, NOTE_CS4, NOTE_FS4, NOTE_F4, NOTE_GS4,
  
  NOTE_B4, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, 0,
  NOTE_FS4, NOTE_FS4, NOTE_F4, NOTE_FS4, NOTE_DS4, 0,
  
  NOTE_FS4, NOTE_F4, NOTE_FS4, NOTE_DS4, 0,
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_E4, 0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
float noteDurations[] = {
  // Every inch of me is trembling
  3, 3, 3, 3, 3, 3, 1, 1,
  // But not from the cold
  3, 3, 2, 3, 1, 3.5, 4, 1, 2,
  
  // Something is familiar
  3, 3, 3, 3, 3, 1, 1, 
  // Like a dream I can reach but not quite hold  
  3, 3, 3, 2.7, 2, 1.5, 3, 2, 1.5, 0.75, 1,
  
  // I can sense you there  
  3, 3, 3, 3, 1, 1,
  // Like a friend I've always know
  3, 3, 3, 2, 2, 3, 2, 3, 3, 1, 1,
  
  // I'm arriving
  3, 3, 2, 1, 1,
  // But it feels like I am home
  3, 3, 3, 3, 3, 3, 0.75, 3, 3, 1, 1,
  
  // I have always been a fortress
  3, 3, 2, 3, 2.5, 3, 2, 1, 1,
  // Cold secrets deep inside
  2, 3, 2, 2, 2, 1, 1,
  
  // You have secrets too
  3, 2, 2, 1.5, 1, 1.5,
  // But you don't have to hide
  2.5, 2.5, 1.5, 2, 1.5, 1, 1,
  
  // Show yourself
  3, 3, 0.75, 1.5,
  // I'm dying to meet you
  3, 1.5, 3, 3, 1.5, 1, 1,
  
  // Show yourself
  3, 3, 0.75, 1.5,
  // It's your turn
  3, 1, 1, 1.5,
  
  // Are you the one I've been looking for all of my life
  3, 3, 3, 2, 3, 3, 2, 3, 2, 2.2, 2.2, 3, 1, 2, 1, 1,
  
  // Show yourself
  2, 3, 1.5, 3, 1, 2,
  // I'm ready to learn
  3, 2, 2.5, 2.7, 0.75, 3,
  
  // Aa-aa
  2.7, 1, 2.7, 1, 1,
  // Aa-aa
  2, 1, 8, 8, 1, 1
};

void setup() {  
  // iterate over the notes of the melody:
  int lastNote = 0;
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++) {
    int currentNote = melody[thisNote];
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int multiplier = lastNote == currentNote ? 1 : 1.30;
    int pauseBetweenNotes = noteDuration * multiplier;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}

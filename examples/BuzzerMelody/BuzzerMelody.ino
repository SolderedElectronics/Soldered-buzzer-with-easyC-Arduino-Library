/**
 **************************************************
 *
 * @file        BasicBuzzer.ino
 * @brief       Example for the buzzer board with easyC.
 *
 *              For this example, you will need any Dasduino, a USB-c cable, an easyC cable, and a buzzer with easyC.
 *              Don't have Dasduino? Get it here: https://soldered.com/categories/dasduino-arduino/dasduino-boards/
 *              Don't have easyC cable? Get it here: https://soldered.com/categories/easyc-2/easyc-cables-adapters/
 *
 *              This example will show you how to play a melody using the buzzer with easyC.
 *              Connect the buzzer board with easyC to Dasduino and upload this code.
 *              The buzzer will play the melody.
 *
 * @link        solde.red/333186
 *
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

// Include Soldered library for buzzer with easyC
#include "Buzzer-easyC-SOLDERED.h"

// Include defined notes
#include "notes.h"

// Create a buzzer object from the library
Buzzer buzzer;

// Notes in the melody (0 means a pause):
int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

// Note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup()
{
    // Initialize buzzer on the default address (0x30)
    buzzer.begin();

    // If you want another I2C address, enter it in the bracket.
    // You can set another I2C address (0x31 - 0x37) by changing address switches on the breakout.
    // NOTE: You have to restart breakout to apply the address change by unplugging and plugging
    // the easyC or USB-c from the Dasduino
    // buzzer.begin(0x31);

    // Iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 8; thisNote++)
    {
        // To calculate the note duration, take one second divided by the note type.
        // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[thisNote];
        buzzer.tone(melody[thisNote], noteDuration);

        // To distinguish the notes, set a minimum time between them.
        // The note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);

        // Stop the tone playing:
        buzzer.noTone();
    }
}

void loop()
{
    // No need to repeat the melody.
}

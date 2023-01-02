/**
 **************************************************
 *
 * @file        BasicBuzzer.ino
 * @brief       Example for the buzzer board with easyC.
 * 
 *              For this example you will need Dasduino, easyC cable, and buzzer with easyC board.
 *              Connect the buzzer board with easyC to Dasduino and upload this code.
 *              The buzzer will turn on and off every 200ms.
 * 
 * @link        solde.red/333186
 *
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

#include "Buzzer-easyC-SOLDERED.h"

Buzzer buzzer;

void setup()
{
    // Initialize buzzer
    buzzer.begin();

    // Set the buzzer volume
    buzzer.setVolume(200);
}

void loop()
{
    // Turn on the buzzer with the preset volume
    // It's also possible to turn on the buzzer with the buzzer.on(volume); The volume is from 0 to 254
    buzzer.on();
    delay(100);

    // Turn off the buzzer
    buzzer.off();
    delay(100);
}

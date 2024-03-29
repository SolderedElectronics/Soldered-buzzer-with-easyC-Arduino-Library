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
 *              This example will show you how to control the buzzer with easyC.
 *              Connect the buzzer board with easyC to Dasduino and upload this code.
 *              The buzzer will turn on and off every 2 second.
 *
 * @link        solde.red/333186
 *
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

// Include Soldered library for buzzer with easyC
#include "Buzzer-easyC-SOLDERED.h"

// Create a buzzer object from the library
Buzzer buzzer;

void setup()
{
    // Initialize buzzer on the default address (0x30)
    buzzer.begin();

    // If you want another I2C address, enter it in the bracket.
    // You can set another I2C address (0x31 - 0x37) by changing address switches on the breakout.
    // NOTE: You have to restart breakout to apply the address change by unplugging and plugging
    // the easyC or USB-c from the Dasduino
    // buzzer.begin(0x31);
}

void loop()
{
    // All these functions are similar to the classic tone() function but without a pin parameter
    // Arduino tone() - https://reference.arduino.cc/reference/en/language/functions/advanced-io/tone/

    // Let's make a tone with a frequency of 700 Hz, and duration of 500 ms
    buzzer.tone(700); // Start producing a tone with a frequency of 700 Hz
    delay(500);       // Wait 500 ms
    buzzer.noTone();  // Stop producing the tone

    // Wait a bit
    delay(2000);

    // Now let's do the same thing, but using the duration parameter of the tone() function
    buzzer.tone(700, 500);

    // Wait again
    delay(2000);
}

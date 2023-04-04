/**
 **************************************************
 *
 * @file        Buzzer-easyC-SOLDERED.cpp
 * @brief       Functions for buzzer with easyC board.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

#include "Buzzer-easyC-SOLDERED.h"
#include "Arduino.h"


/**
 * @brief                   Constructor for buzzer with easyC.
 */
Buzzer::Buzzer()
{
    native = 0;
}

/**
 * @brief                   Overloaded function for virtual in base class to initialize buzzer.
 */
void Buzzer::initializeNative()
{
}

/**
 * @brief                           Generates a square wave of the specified frequency (and 50% duty cycle)
 *
 * @param uint16_t frequency        the frequency of the tone in hertz
 */
void Buzzer::tone(uint16_t frequency)
{
    uint8_t *frequencyForSend = (uint8_t *)&frequency;
    sendData(frequencyForSend, 2);
}

/**
 * @brief                           Generates a square wave of the specified frequency (and 50% duty cycle).
 *
 * @param uint16_t frequency        The frequency of the tone in hertz.
 *
 * @param uint32_t duration         The duration of the tone in milliseconds.
 */
void Buzzer::tone(uint16_t frequency, uint32_t duration)
{
    uint8_t *frequencyForSend = (uint8_t *)&frequency;
    uint8_t *durationForSend = (uint8_t *)&duration;

    Wire.beginTransmission(address);
    Wire.write(frequencyForSend, 2);
    Wire.write(durationForSend, 4);
    Wire.endTransmission();
}

/**
 * @brief                           Stops the generation of a square wave triggered by tone(). Has no effect if no tone
 *                                  is being generated.
 */
void Buzzer::noTone()
{
    byte flag = 170;
    sendData(&flag, 1);
}

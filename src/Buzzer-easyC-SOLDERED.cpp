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

/**
 * @brief                   Buzzer native constructor.
 *
 * @param int _pin          Pin on which the buzzer is connected.
 */
Buzzer::Buzzer(int _pin)
{
    pin = _pin;
    native = 1;
}

/**
 * @brief                   Constructor for buzzer with easyC.
 */
Buzzer::Buzzer()
{
    native = 0;
}

/**
 * @brief                   Overloaded function for virtual in base class to initialize Buzzer specific.
 */
void Buzzer::initializeNative()
{
    pinMode(pin, OUTPUT);
}

/**
 * @brief                   Turn off the buzzer.
 */
void Buzzer::off()
{
    byte data = 0;
    sendData(&data, 1);
}

/**
 * @brief                   Turn the buzzer on with the volume parameter.
 *
 * @param byte _volume      The intensity of the buzzer sound from 0 to 255.
 */
void Buzzer::on(byte _volume)
{
    volume = _volume;
    sendData(&volume, 1);
}

/**
 * @brief                   Turn on the buzer with the preset volume.
 */
void Buzzer::on()
{
    sendData(&volume, 1);
}

/**
 * @brief                   Set buzzer volume.
 *
 * @param byte _volume      Buzzer volume from 0 to 255.
 */
void Buzzer::setVolume(byte _volume)
{
    volume = _volume;
}

/**
 **************************************************

   @file        attiny_firmware.ino
   @brief       Firmware for attiny404.


   @authors     Karlo Leksic for soldered.com
 ***************************************************/

#include "easyC.h"
#include <Wire.h>

int addr = DEFAULT_ADDRESS; // 0x30

#define BUZZ_PIN PA5 // Buzzer is connected to the pin PA5

void setup()
{
    // Set address switches as inputs, and get the I2C address
    initDefault();
    addr = getI2CAddress();

    // Init I2C communication
    Wire.begin(addr);
    Wire.onReceive(receiveEvent);

    // Set buzzer pin as output
    pinMode(BUZZ_PIN, OUTPUT);
}

void loop()
{
    // Nothing...
}

// This function will be executed when Dasduino sends data to the breakout
void receiveEvent(int howMany)
{
    // Arrays for the raw data
    uint8_t rawFrequency[2];
    uint8_t rawDuration[4];

    // Variables for real data
    uint16_t frequency = 0;
    uint32_t duration = 1000;

    // If 1 byte is received
    if(Wire.available() == 1)
    {
       // Read a byte that represents the flag for stopping the tone
      byte flag = Wire.read();

      // If the flag is equal to 170, stop the tone
      if(flag == 170)
      {
        // Stop the tone
        noTone(BUZZ_PIN);
      }
    }
    
    // If 2 bytes are received
    if (Wire.available() == 2)
    {
        // Read 2 bytes which represents the frequency
        Wire.readBytes(rawFrequency, 2);

        // Converts this value into uint16_t
        frequency = *(uint16_t *)rawFrequency;

        // Play one tone until calling noTone()
        tone(BUZZ_PIN, frequency);
    }

    // If 6 bytes are received
    if (Wire.available() == 6)
    {
        // Read 2 bytes which represents the frequency
        Wire.readBytes(rawFrequency, 2);

        // Converts this value into uint16_t
        frequency = *(uint16_t *)rawFrequency;

        // Read 4 bytes which represents the duration
        Wire.readBytes(rawDuration, 4);

        // Converts this value into uint16_t
        duration = *(uint32_t *)rawDuration;

        // Play a tone and stop it
        tone(BUZZ_PIN, frequency, duration);
    }
}

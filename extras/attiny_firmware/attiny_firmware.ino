/**
 **************************************************

   @file        attiny_firmware.ino
   @brief       Firmware for attiny404.



   @authors     Karlo Leksic for soldered.com
 ***************************************************/

#include "easyC.h"
#include <Wire.h>

int addr = DEFAULT_ADDRESS;

#define BUZZ_PIN PA5

byte buzzValue = 0;

void setup()
{
  initDefault();
  addr = getI2CAddress();

  Wire.begin(addr);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

  pinMode(BUZZ_PIN, OUTPUT);
}

void loop()
{
  analogWrite(BUZZ_PIN, buzzValue);
}


void receiveEvent(int howMany)
{
  if (Wire.available() == 1)
  {
    buzzValue = Wire.read();
  }
}

void requestEvent()
{

}

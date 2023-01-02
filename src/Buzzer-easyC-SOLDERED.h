/**
 **************************************************
 *
 * @file        Buzzer-easyC-SOLDERED.h
 * @brief       Header file for Buzzer with easyC code.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

#ifndef __BUZZER__
#define __BUZZER__

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.hpp"

class Buzzer : public EasyC
{
  public:
    Buzzer(int _pin);
    Buzzer();
    void off();
    void on();
    void on(byte _volume);
    void setVolume(byte _volume);

  protected:
    void initializeNative();

  private:
    int pin;
    byte volume;
};

#endif

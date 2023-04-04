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
    Buzzer();
    void tone(uint16_t frequency);
    void tone(uint16_t frequency, uint32_t duration);
    void noTone();

  protected:
    void initializeNative();

  private:
};

#endif

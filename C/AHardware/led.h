#ifndef LED_H
#define LED_H

#include "samd51j19a.h"
#include "utils.h"

typedef struct sPort
{
  PortGroup *pPort;
  unsigned char pin;

}tPort;

void ToggleLed(tPort *pLed) {
  TOGGLE_BIT(pLed->pPort->OUT.reg, pLed->pin);
}

//void SwitchOnLed(tPort *pLed) {
//  SET_BIT(pLed->pPort->OUT.reg, pLed->pin);
//}

//void SwitchOffLed(tPort *pLed) {
//   CLEAR_BIT(pLed->pPort->OUT.reg, pLed->pin);
//}

#endif
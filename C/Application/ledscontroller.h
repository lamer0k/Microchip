#ifndef LEDSCONTROLLER_H
#define LEDSCONTROLLER_H

#include "led.h"

#define LEDS_COUNT  (int) 4

typedef enum
{
  LM_Tree = 0,
  LM_Chess = 1,
  LM_All = 2,
  LM_End = 2
} tLedMode;




void SwitchOnAllLed(tPort *pLed, int size) {
  for (int i = 0; i < size; i++) {
    SET_BIT(pLed->pPort->OUT.reg, pLed->pin);
    pLed++;
  }
}

void ToggleAllLed(tPort *pLed, int size) {
  for (int i = 0; i < size; i++) {    
    //ToggleLed(pLed);
    TOGGLE_BIT(pLed[i].pPort->OUT.reg, pLed[i].pin);    
  }
}


void SwitchChessLed(tPort *pLed, int size) {
  for (int i = 0; i < size; i++) {
    if ((i % 2) == 0) {
     // SwitchOnLed(&pLed[i]) ;
      SET_BIT(pLed[i].pPort->OUT.reg, pLed[i].pin);
    } else {
      //SwitchOffLed(&pLed[i]) ;
      CLEAR_BIT(pLed[i].pPort->OUT.reg, pLed[i].pin);
    }    
  }
}

void SetLedsBeginState(tLedMode mode, tPort *leds) {
  switch(mode) {
    case LM_Tree: 
    case LM_All:
      SwitchOnAllLed(leds,LEDS_COUNT);
    break;
    case LM_Chess:
      SwitchChessLed(leds,LEDS_COUNT);
    break;
    default:
      break;  
  }
}


void Update(tLedMode mode, tPort *leds, int curLed) {
  switch(mode) {
      case LM_Tree:
        ToggleLed(&leds[curLed]) ;       
      break;      
      case LM_All: 
      case LM_Chess:
        ToggleAllLed(leds,LEDS_COUNT);
      break;
      default:
      break;
     }
}

#endif
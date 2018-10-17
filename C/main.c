#include "samd51j19a.h"
#include "led.h"
#include "utils.h"
#include "ledscontroller.h"

#define DFLL_24MHZ (uint32_t) 2

#define BUTTON_PIN (unsigned int) 31U

int __low_level_init(void) 
{
 GCLK->GENCTRL[0].reg = (GCLK_GENCTRL_SRC(GCLK_GENCTRL_SRC_DFLL_Val) |
                         GCLK_GENCTRL_DIV(DFLL_24MHZ) | GCLK_GENCTRL_GENEN); //internal clock 24 MHz
  while(GCLK->SYNCBUSY.reg & GCLK_SYNCBUSY_GENCTRL(0));
  PORT->Group[1].PINCFG[31].reg = PORT_PINCFG_INEN | PORT_PINCFG_PULLEN ;
  REG_PORT_OUTSET1 = PORT_PB31; //button
  REG_PORT_DIRSET1 = PORT_PB14 | PORT_PB07 | PORT_PB01 | PORT_PB08;
    
    return 1; /* if return 0, the data sections will not be initialized */ 
}

inline void Delay(unsigned int mSec) {
  for (unsigned int i = 0U; i < mSec * 500U; i++) {
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
  };    
}

int main(void) 
{
  tPort Leds[] = { { &PORT->Group[1], 7U },{ &PORT->Group[1], 1U },
                   { &PORT->Group[1], 8U },{ &PORT->Group[1], 14U } };
  tPort Button = {&PORT->Group[1], BUTTON_PIN};
  tLedMode Mode = LM_Tree;
  int currentLed = 0;
  
  SwitchOnAllLed(Leds, LEDS_COUNT);
  
  for(;;) 
  { 
    if (!CHECK_BIT(Button.pPort->IN.reg, BUTTON_PIN)) 
    {
      Mode = (Mode < LM_All)? (tLedMode)(Mode + 1U) : LM_Tree;
      currentLed = 0;      
      SetLedsBeginState(Mode, Leds);
    } else
    {
      RunCurrentMode(Mode, Leds, currentLed);
      currentLed = (currentLed < (LEDS_COUNT - 1)) ? (currentLed + 1) : 0;
    }
    Delay(1000U);
  } 
 
}
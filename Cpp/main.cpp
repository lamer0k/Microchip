#include <samd51j19a.h>
#include "ledscontroller.hpp"
#include "button.hpp"
#include "utils.hpp"

constexpr unsigned int DFLL_24MHZ = 2U ;
constexpr unsigned int BUTTON_PIN = 31U ;

extern "C"
{
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
  
  inline void Delay(unsigned int mSec)
  {
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
}

int main(void) 
{
  LedsController leds;
  Button<BUTTON_PIN> buttonUser{PORT->Group[1]};
  for(;;)
  {
    if (buttonUser.IsPressed()) 
    {
      leds.NextMode();
    } else
    {
      leds.Update();
    }
    Delay(1sec);
  }
}



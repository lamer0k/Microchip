#ifndef BUTTON_H
#define BUTTON_H
#include "utils.hpp"

template <unsigned int pin>
class Button
{
  public:
    inline Button(PortGroup &portName): port(portName) {};
      inline bool IsPressed() { 
        return !utils::checkBit(port.IN.reg, pin);
      }
  private:
    PortGroup &port;
    //unsigned int pin;
};
#endif
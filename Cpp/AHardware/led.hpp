#ifndef LED_H
#define LED_H
#include "utils.hpp"


class Led
{
  public:
    inline Led(PortGroup &portName, unsigned int pinNum): port(portName),
      pin(pinNum) {};
    inline void Toggle() { utils::toggleBit(port.OUT.reg, pin); }
    inline void SwitchOn() { utils::setBit(port.OUT.reg, pin); }
    inline void SwitchOff() { utils::clearBit(port.OUT.reg, pin); }
  private:
    PortGroup &port;
    unsigned int pin;
};
#endif
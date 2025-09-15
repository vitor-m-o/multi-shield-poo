#include "Led.h"
#include <Arduino.h> 

Led::Led(uint8_t pinout)
{
  this->_pinout = pinout;
  pinMode(this->_pinout, OUTPUT);
}

void Led::ligar()
{
  digitalWrite(this->_pinout, _ledLigado);
}

void Led::desligar()
{
  digitalWrite(this->_pinout, _ledDesligado);
}

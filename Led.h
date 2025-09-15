#ifndef LED_H
#define LED_H

#include <Arduino.h> 

class Led {
  private:
    uint8_t _pinout;
    bool _ledLigado = false, _ledDesligado = true;

  public:
    Led(uint8_t pinout);
    void ligar();
    void desligar();

};

#endif
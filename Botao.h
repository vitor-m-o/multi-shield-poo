#ifndef BOTAO_H
#define BOTAO_H

#include <Arduino.h> 

class Botao {
  private:
    uint8_t _pinout;
    bool _valorLido, _ultimoValor, _estadoBotao, _leituraBotao;
    long _ultimoClique, _ultimaVariacao;
    const bool _botaoPressionado = false;

  public:
    Botao(uint8_t pinout);
    void ler();
    bool pressionado();

};

#endif
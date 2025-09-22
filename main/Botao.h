#ifndef BOTAO_H
#define BOTAO_H

#include <Arduino.h> 

class Botao {
  private:
    uint8_t _pinout;
    bool _valorLido, _ultimoValor, _estadoBotao, _leituraBotao;
    long _ultimoClique = 50, _ultimaVariacao;
    const bool _botaoPressionado = false;

  public:
    Botao(uint8_t pinout);
    void ler();
    void detectarBorda();
    bool pressionado();

};

#endif
#include "Botao.h"
#include <Arduino.h> 

Botao::Botao(uint8_t pinout)
{
  this->_pinout = pinout;
  pinMode(this->_pinout, INPUT);
}

void Botao::ler()
{
  this->_valorLido = digitalRead(this->_pinout);
  
  if (this->_valorLido != this->_ultimoValor)
  {
    this->_ultimaVariacao = millis();
  }

  if ((millis() - this->_ultimaVariacao) > this->_ultimoClique)
  {
    if (this->_valorLido != this->_estadoBotao)
    {
      this->_estadoBotao = this->_valorLido;
      if (this-> _estadoBotao == _botaoPressionado)
      {
        this->_leituraBotao = true;
      }
      else
      {
        this->_leituraBotao = false;
      }
    }
  }

  if (this->_leituraBotao != this->_ultimoValor)
  {
    if (this->_leituraBotao)
    {
      this->_retorno = true;
    }
    else
    {
      this->_retorno = false;
    }
  }

}

void Botao::detectarBorda()
{
  this->_ultimoValor = this->_leituraBotao;
}

bool Botao::pressionado()
{
  return this->_leituraBotao;
}
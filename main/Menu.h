#ifndef MENU_H
#define MENU_H

#include <Arduino.h> 

class Menu {
  private:
    unsigned short _setaCursor = 1, _nivelMenu = 0;
    bool _ledLigado = false, _ledDesligado = true, _estadoCursor = false, _interagiu = true;

  public:
    Menu();
    void inicializar();
    void cursorDireita();
    void cursorEsquerda();
    void cursorSelecionar();
    void imprimirInicial();
    void imprimirMenu();

};

#endif
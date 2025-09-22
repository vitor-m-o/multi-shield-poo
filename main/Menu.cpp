#include "Menu.h"
#include <Arduino.h> 

Menu::Menu()
{
}

void Menu::inicializar()
{
  
}

void Menu::cursorDireita()
{
  if (_setaCursor < 4)
  {
    _setaCursor++;
  }
  else
  {
    _setaCursor = 1;
  }
  _interagiu = true;
}

void Menu::cursorEsquerda()
{
  if (_setaCursor > 1)
  {
    _setaCursor--;
  }
  else
  {
    _setaCursor = 4;
  }
  _interagiu = true;
}

void Menu::cursorSelecionar()
{
}

void Menu::imprimirInicial()
{
  Serial.print("[ MENU SELECAO | ");

  for (int i = 1; i <= 4; i++)
  {
    if (_setaCursor == i)
    {
      Serial.print("->");
    }
    Serial.print("|Opcao ");
    Serial.print(i);
    Serial.print("| ");

  }
  Serial.println("]");
}

void Menu::imprimirMenu()
{
  if (_interagiu)
  {
    switch (_nivelMenu)
    {
      case 0: // Tela Inicial
        imprimirInicial();
        break;

      case 1: // Tela Cronometro
        break;

      case 2: // Tela 
        break;
      
      case 3: // Tela Controle LEDS
        break;

      case 4: // Tela
        break;

      default:
        break;
    }
    _interagiu = false;
  }
}


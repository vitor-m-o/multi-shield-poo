//=====TITLE:=====//

// ARDUINO MULTIFUNCTIONAL SHIELD ALL FUNCTIONS CODE //

//====CREATOR:=====//

// VITOR MAZIERO OLIVEIRA //
// GitHub: vitor-m-o //
// IFSUL: TAI2V //

//=====LIBRARIES:=====//

// none, for now... //

//=====PINOUT:=====//

// The 3 Buttons Pins
#define botao_esquerda A1
#define botao_central A2
#define botao_direita A3

// The 4 LEDS pins
#define primeiroLED 13
#define segundoLED 12
#define terceiroLED 11
#define quartoLED 10

// Buzzer pin
#define buzzer 3

//=====CLASSES OF THE PROJECT=====//

#include "Botao.h"

Botao botaoEsquerda(botao_esquerda);
Botao botaoCentral(botao_central);
Botao botaoDireita(botao_direita);

#include "Led.h"

Led ledPrimeiro(primeiroLED);
Led ledSegundo(segundoLED);
Led ledTerceiro(terceiroLED);
Led ledQuarto(quartoLED);

#include "Menu.h"

Menu menuShield;

// Classe para Millis()

// Classe para Display

//=====CONTROL VARIABLES:=====//

// Variable to be able to select each led with the menu
int ledSelecionado = 1;

// 7 Segment display pins
int CLOCK_7SEG = 7;
int LATCH_7SEG = 4;
int DATA_7SEG = 8;

// Variables to be able to write on the 7 segment display 
int numero_selecionado = 1000, ultimo_numero_selecionado = 0;

//=====CODE:=====//

//=====INITIAL PART THE SETUP=====//

void setup() 
{
  //=====INITIALIZATION OF FUNCTIONS=====//

  // The fastest speed possible for arduino, to make the 7 segment display look the best
  Serial.begin(115200);

  // Activate the millis counting to be able to count the time from begining
  millis();

  //=====DEFINITION OF PINS FUNCTION=====//

  // Define the 7 segment display pins function to OUTPUT
  pinMode(CLOCK_7SEG, OUTPUT);
  pinMode(LATCH_7SEG, OUTPUT);
  pinMode(DATA_7SEG, OUTPUT);

  // Define the 4 LEDS pins function to OUTPUT
  pinMode(primeiroLED, OUTPUT);
  pinMode(segundoLED, OUTPUT);
  pinMode(terceiroLED, OUTPUT);
  pinMode(quartoLED, OUTPUT);
                                          
  // Define the buzzer pins function to OUTPUT                         
  pinMode(buzzer, OUTPUT);
  // Turn OFF the buzzer (its pull up)
  digitalWrite(buzzer, HIGH);

  //=====INITIAL COMMUNICATION WITH SERIAL=====//
  menuShield.inicializar();
}

void loop() 
{
  botaoEsquerda.ler();
  botaoCentral.ler();
  botaoDireita.ler();

  if (botaoEsquerda.pressionado())
  {
    menuShield.cursorEsquerda();
  }
  else if (botaoCentral.pressionado())
  {
    menuShield.cursorDireita();
  }

  menuShield.imprimirMenu();

  botaoEsquerda.detectarBorda();
  botaoCentral.detectarBorda();
  botaoDireita.detectarBorda();
}

// Function to write each number on each display of the 7 segment display
void Imprimir_Numero_Display(int Numero, int Display)
{
  // Array with each code for numbers and displays
  static const byte Tabela_Numeros[]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xD8, 0x80, 0x90, 0x88, 0x7f};
  static const byte Tabela_Display[]={0xF1,0xF2,0xF4,0xF8};
 
  // Verify if the arguments were given correctly
  if ((Display < 4) && (Numero < 11))
  {
    // Make the ST_CP port LOW so the chip can be ready
    digitalWrite(LATCH_7SEG,LOW);
    // Send the number
    shiftOut(DATA_7SEG,CLOCK_7SEG,MSBFIRST,Tabela_Numeros[Numero]);
    // Select which display should turn on
    shiftOut(DATA_7SEG,CLOCK_7SEG,MSBFIRST,Tabela_Display[Display]);
    // Return the pin ST_CP to HIGH
    digitalWrite(LATCH_7SEG,HIGH);
  }

  // The minimun time that its needed for the display to be turned on
  delay(1);
}

// Function to write all 4 numbers to the 7 segment display
void Display_7_Segmentos(int Numero)
{
  // Filter to make all 4 numbers function on each display
  int D1, D2, D3, D4;
  D1 = Numero / 1000;
  D2 = (Numero / 100) % 10;
  D3 = (Numero / 10) % 10;
  D4 = Numero % 10;
 
  // Write all the 4 digits on the display
  Imprimir_Numero_Display(D2, 1);
  Imprimir_Numero_Display(D3, 2);
  Imprimir_Numero_Display(D4, 3);
  Imprimir_Numero_Display(D1, 0);
}

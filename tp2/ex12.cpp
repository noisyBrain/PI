/*

  Escribir una variante del programa anterior en la que, en lugar de informar la cantidad de veces que apareció
  cada dígito, se informe si apareció o no cada dígito en todos los números ingresados.
  Analizar cómo puede resolverse este ejercicio evitando contabilizar la cantidad de dígitos.

  Ejemplo: Si el usuario ingresa los números 44, 1, 710, 15, se debe informar que el 0 apareció, el 1 apareció, el 2
  no apareció, el 3 no apareció, el 4 apareció, el 5 apareció, etc.

*/

#include<iostream>
#include "resources.h"

using namespace std;

bool oneCounter = false, twoCounter = false, threeCounter = false,
    fourCounter = false, fiveCounter = false, sixCounter = false,
    sevenCounter = false, eightCounter = false, nineCounter = false;


int takeUserPrompt() {
  int inputNumber = 0;

  cout << "Ingresá un número: ";
  cin >> inputNumber;

  return inputNumber;
}

void numCounter(int number) {
  switch (number) {
    case 1:
      oneCounter = true;
      break;
    case 2:
      twoCounter = true;
      break;
    case 3:
      threeCounter = true;
      break;
    case 4:
      fourCounter = true;
      break;
    case 5:
      fiveCounter = true;
      break;
    case 6:
      sixCounter = true;
      break;
    case 7:
      sevenCounter = true;
      break;
    case 8:
      eightCounter = true;
      break;
    case 9:
      nineCounter = true;
      break;
    default:
      false;
      break;
  }
}

void startProgram() {
  cout << "Para salir, presioná 0 (por eso no se contabilizará), sino \n" << endl;

  int number = takeUserPrompt();
  int auxNumber = number;

  do {
    while (auxNumber != 0) {
      int lastDigit = auxNumber % 10;
      numCounter(lastDigit);

      auxNumber /= 10;
    }

    number = takeUserPrompt();
    auxNumber = number;
  } while(number != 0);
}

void printResult() {
  oneCounter ? cout << "El 1 apareció." << endl : cout << "El 1 no apareció..." << endl;
  twoCounter ? cout << "El 2 apareció." << endl : cout << "El 2 no apareció..." << endl;
  threeCounter ? cout << "El 3 apareció." << endl : cout << "El 3 no apareció..." << endl;
  fourCounter ? cout << "El 4 apareció." << endl : cout << "El 4 no apareció..." << endl;
  fiveCounter ? cout << "El 5 apareció." << endl : cout << "El 5 no apareció..." << endl;
  sixCounter ? cout << "El 6 apareció." << endl : cout << "El 6 no apareció..." << endl;
  sevenCounter ? cout << "El 7 apareció." << endl : cout << "El 7 no apareció..." << endl;
  eightCounter ? cout << "El 8 apareció." << endl : cout << "El 8 no apareció..." << endl;
  nineCounter ? cout << "El 9 apareció." << endl : cout << "El 9 no apareció..." << endl;
}

int main () {
  startProgram();
  printResult();
  
  return 0;
}

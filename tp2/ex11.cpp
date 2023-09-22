/*

  Escribir un programa que permita al usuario ingresar números enteros positivos
  (los números ingresados no deben almacenarse). 
  Al finalizar, informar la cantidad de veces que apareció cada dígito (del 0 al 9)
  en todos los números.

  Ejemplo: Si el usuario ingresa los números 1156, 23, 73364, 988, 1003, 5, se debe informar que el 0 apareció 2
  veces, el 1 apareció 3 veces, el 2 apareció 1 vez, el 3 apareció 4 veces, etc.

*/

#include<iostream>
#include "resources.h"

using namespace std;

int ceroCounter = 0, oneCounter = 0,
    twoCounter = 0, threeCounter = 0,
    fourCounter = 0, fiveCounter = 0,
    sixCounter = 0, sevenCounter = 0,
    eightCounter = 0, nineCounter = 0;


int takeUserPrompt() {
  int inputNumber = 0;

  cout << "Ingresá un número: ";
  cin >> inputNumber;

  return inputNumber;
}

void numCounter(int number) {
  switch (number) {
    case 0:
      ceroCounter++;  
      break;
    case 1:
      oneCounter++;  
      break;
    case 2:
      twoCounter++;  
      break;
    case 3:
      threeCounter++;  
      break;
    case 4:
      fourCounter++;  
      break;
    case 5:
      fiveCounter++;  
      break;
    case 6:
      sixCounter++;  
      break;
    case 7:
      sevenCounter++;  
      break;
    case 8:
      eightCounter++;  
      break;
    case 9:
      nineCounter++;  
      break;
    default:
      break;
  }
}

void startProgram() {
  cout << "Para salir, presioná 0, sino \n" << endl;

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
  cout << "\nLa cantidad de 0 ingresados fue de: " << ceroCounter << endl;
  cout << "La cantidad de 1 ingresados fue de: " << oneCounter << endl;
  cout << "La cantidad de 2 ingresados fue de: " << twoCounter << endl;
  cout << "La cantidad de 3 ingresados fue de: " << threeCounter << endl;
  cout << "La cantidad de 4 ingresados fue de: " << fourCounter << endl;
  cout << "La cantidad de 5 ingresados fue de: " << fiveCounter << endl;
  cout << "La cantidad de 6 ingresados fue de: " << sixCounter << endl;
  cout << "La cantidad de 7 ingresados fue de: " << sevenCounter << endl;
  cout << "La cantidad de 8 ingresados fue de: " << eightCounter << endl;
  cout << "La cantidad de 9 ingresados fue de: " << nineCounter << endl;
}


int main () {
  startProgram();
  printResult();
  
  return 0;
}

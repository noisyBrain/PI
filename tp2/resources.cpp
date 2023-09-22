#include "resources.h"
#include<iostream>
#include<unistd.h>

using namespace std;

void printArray(int array[], int ld) {
  for (int i = 0; i < ld; i++) {
    if (i + 1 == ld) {
      cout << array[i] << endl;

    } else {
      cout << array[i] << ", ";
    }
  }
}


void clearScreen() {
  cout << "\033[2J\033[1;1H";
}

void clearAfterEnter() {
  cin.ignore();
  cout << "\nApretá enter para continuar..." << endl;
  cin.get();
  clearScreen();
}

void showEndProgram() {
  cout << "Finalizando..." << endl;
  sleep(1);

  cout << "\n// -------------------------------- //" << endl;
  cout << "\t¡Programa Finalizando!" << endl;
  cout << "// -------------------------------- //" << endl;
}

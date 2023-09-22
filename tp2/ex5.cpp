/*

Implementar una función llamada mas_uno que tiene como parámetro un arreglo estático de enteros y que
incrementa en uno el valor de cada elemento de dicho arreglo. Añadir otros parámetros que se necesiten.

*/

#include<iostream>
#include "resources.h"

using namespace std;

const int PD = 5;

void plusOne(int arr[], int ld) {
  for (int i = 0; i < ld; i++) {
    arr[i]++;
  }
}

int main () {
  int ld = 5;
  int arr[PD] = {1, 2, 3, 4, 5};

  cout << "Los números en el array antes de aumentarlos son: " << endl;
  printArray(arr, ld);

  plusOne(arr, ld);

  cout << "\nLos números en el array después de aumentarlos son: " << endl;
  printArray(arr, ld);
  
  return 0;
}

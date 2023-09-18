/* 

  Escribir una función que, dado un arreglo de int y su dimensión lógica,
  invierta los elementos del arreglo.

  Ejemplos: Si el arreglo contiene los elementos [1,2,3,4,5] deberá quedar [5,4,3,2,1].
  Si el arreglo contiene [10,20] deberá quedar [20,10].

*/

#include<iostream>

using namespace std;

const int PD = 10;

void reverseArray(int arr[], int ld) {
  int half = ld / 2;

  for (int i = 0; i < half; i++) {
    int aux = arr[ld - 1];

    arr[ld - 1] = arr[i];
    arr[i] = aux;

    ld--;
  }
}

void printNumbers(int array[], int ld) {
  cout << "Estos son los números invertidos: " << endl;

  for (int k = 0; k < ld; k++) {
    if (k + 1 == ld) {
      cout << array[k] << endl;

    } else {
      cout << array[k] << ", ";
    }
  }
}

int main () {

  int array[PD] = {2, 3};
  int ld = 2;

  reverseArray(array, ld);
  printNumbers(array, ld);
  
  return 0;
}

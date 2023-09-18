/*

Implementar una función llamada mas_uno que tiene como parámetro un arreglo estático de enteros y que
incrementa en uno el valor de cada elemento de dicho arreglo. Añadir otros parámetros que se necesiten.

*/

#include<iostream>

using namespace std;

void plusOne(int array[], int PD) {
  for (int i = 0; i < PD; i++) {
    array[i]++;
  }
}

void takeNumbersToEnter(int &PD) {
  cout << "¿Cuántos números vas a ingresar? " << endl;
  cin >> PD;
}

int takeNewNumber() {
  int userInput = 0;

  cout << "Ingresá un número: " << endl;
  cin >> userInput;

  return userInput;
}

void insertInArray(int array[], int PD, int ld) {
  int newNumber = takeNewNumber();

  while (ld < PD) {
    array[ld] = newNumber;
    ld++;

    if (ld < PD) {
      newNumber = takeNewNumber();
    }
  }
}

void printResult(int array[], int PD) {
  for (int k = 0; k < PD; k++) {
    cout << "Este es el número " << array[k] << " en la posición " << k << endl;
  }
}

int main () {
  int ld = 0; // Logic Dimension
  int pd = 0; // Physical Dimension

  /*
     Permitir al usuario ingresar
     la cantidad de números que quiera
  */
  takeNumbersToEnter(pd);
  int array[pd];

  insertInArray(array, pd, ld);
  plusOne(array, pd);
  printResult(array, pd);
  
  return 0;
}

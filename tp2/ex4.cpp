/*

  Cargar un arreglo con 20 números enteros ingresados por teclado de manera que el arreglo siempre se
  encuentre ordenado en forma ascendente. El arreglo se cargará por completo.
  Hacer tres variantes, suponiendo que el usuario carga los datos de las siguientes formas:
  a) El usuario ingresa los números en orden ascendente.
  b) El usuario ingresa los números en orden descendente.
  c) El usuario ingresa los números sin un orden en particular.

*/

#include<iostream>

using namespace std;

const int PD = 5;

int insertInOrder(int array[], int ld, int newData) {
  int i = 0;

  while(i < ld && array[i] < newData) {
    i++;
  }

  for (int j = ld; j > i; j--) {
    array[j] = array[j-1];
  }

  array[i] = newData;
  return ld+1;
}

int insertInArray(int array[], int ld) {
  int newNumber = 0;

  while (ld < PD) {
    cout << "Ingresá otro número: " << endl;
    cin >> newNumber;

    if (ld < PD) {
      ld = insertInOrder(array, ld, newNumber);
    }
  }

  return ld;
}

void printNumbers(int array[]) {
  cout << "Estos son los números ordenados: " << endl;

  for (int k = 0; k < PD; k++) {
    if (k + 1 == PD) {
      cout << array[k] << endl;

    } else {
      cout << array[k] << ", ";
    }
  }
}

int main () {
  int arrayOfNumbers[PD];
  int logicDimension = 0;

  insertInArray(arrayOfNumbers, logicDimension);
  printNumbers(arrayOfNumbers);

  return 0;
}

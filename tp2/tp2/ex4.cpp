/*

  Cargar un arreglo con 20 números enteros ingresados por teclado de manera que el arreglo siempre se
  encuentre ordenado en forma ascendente. El arreglo se cargará por completo.
  Hacer tres variantes, suponiendo que el usuario carga los datos de las siguientes formas:
  a) El usuario ingresa los números en orden ascendente.
  b) El usuario ingresa los números en orden descendente.
  c) El usuario ingresa los números sin un orden en particular.

*/

#include <algorithm>
#include<iostream>
#include<algorithm>

using namespace std;

int main () {
  int aux = 0;
  int promptUser = 0;
  int arrayLength = 5;
  int arrayOfNumbers[arrayLength];

  for (int i = 0; i < 5; i++) {
    cout << "Ingresá el número: " << endl;
    cin >> promptUser;

    arrayOfNumbers[i] = promptUser;
  }

  std::sort(arrayOfNumbers, arrayOfNumbers + arrayLength);

  cout << "\nLos números ordenados son: \n" << endl;
  for (int i = 0; i < arrayLength; i++) {
    cout << arrayOfNumbers[i] << endl;
  }

  return 0;
}

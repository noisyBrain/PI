/*
  Escribir una función llamada cantidad_ocurrencias que reciba como parámetro un arreglo de tipo int, 
  un parámetro con la dimensión lógica del arreglo y un parámetro con un valor de tipo int.
  La función debe retornar la cantidad de ocurrencias del valor int encontradas en el arreglo.

  Nota: como en todo algoritmo, se debe probar si la función hace lo esperado pasándole como argumentos
  diferentes casos posibles, por ejemplo: 
    1. arreglo vacío 
    2. arreglo con un solo elemento 
    3. arreglo donde todos los elementos coinciden con el buscado 
    4. arreglo donde no se encuentra el elemento buscado 
    5. arreglo donde el elemento se encuentra al principio y al final 
    6. arreglo con repeticiones del elemento en posiciones consecutivas.

  Como ejemplo, se puede utilizar el siguiente programa para probar la función:

  int A[MAX] = { 2,8,5,2,2,7,2,7,4,2 };
  int B[MAX];
  int C[MAX] = { 2 };
  int D[MAX] = { 2,2,2 };
  int E[MAX] = { 1,3,5,7,9 };
  int dlA=10, dlB=0, dlC=1, dlD=3, dlE=5;

  cout << cantidad_ocurrencias(A, dlA, 2) << endl;
  cout << cantidad_ocurrencias(B, dlB, 2) << endl;
  cout << cantidad_ocurrencias(C, dlC, 2) << endl;
  cout << cantidad_ocurrencias(D, dlD, 2) << endl;
  cout << cantidad_ocurrencias(E, dlE, 2) << endl;
*/

#include <iostream>
#include <string>

using namespace std;
const int MAX = 10;

//Colocar acá la función cantidad_ocurrencias
int cantidad_ocurrencias(int arr[], int ld, int ocurrenceToFind) {
  if (ld == 0) return 0;

  int i = 0, counter = 0;
  while (i < ld) {
    if (arr[i] == ocurrenceToFind) counter++;

    i++;

    if (ld < MAX) ld++;
  }

  return counter;
}

int main() {
  int A[MAX] = { 2,8,5,2,2,7,2,7,4,2 };
  int B[MAX];
  int C[MAX] = { 2 };
  int D[MAX] = { 2,2,2 };
  int E[MAX] = { 1,3,5,7,9 };
  int dlA=10, dlB=0, dlC=1, dlD=3, dlE=5;

  cout << cantidad_ocurrencias(A, dlA, 2) << endl;
  cout << cantidad_ocurrencias(B, dlB, 2) << endl;
  cout << cantidad_ocurrencias(C, dlC, 2) << endl;
  cout << cantidad_ocurrencias(D, dlD, 2) << endl;
  cout << cantidad_ocurrencias(E, dlE, 2) << endl;
}

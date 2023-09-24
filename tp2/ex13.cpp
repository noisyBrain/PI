/*

  Dado un arreglo bidimensional de tipo float de 7 filas y 10 columnas, describir las sentencias para:

  a) Asignar el valor 105 a la posición que se encuentra en la segunda fila, quinta columna.
  b) Asignar en todas las posiciones de la cuarta fila el valor 1.5.
  c) Imprimir todos los valores de la matriz, colocando cada fila en una nueva línea.
  d) Permutar las columnas 3 y 5.
  e) Sumar todos los elementos de las filas 2 y 6.
  f) Imprimir todos los valores de la tercera columna.
  g) Hallar en qué fila y columna se encuentra almacenado el mayor elemento.

*/

#include<iostream>

using namespace std;

const int ROWS = 7;
const int COLS = 10;

int main () {
  float myArray[ROWS][COLS] = {
      { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0},
      {11.1, 12.2, 13.3, 14.4, 15.5, 16.6, 17.7, 18.8, 19.9, 20.0},
      {21.1, 22.2, 23.3, 24.4, 25.5, 26.6, 27.7, 28.8, 29.9, 30.0},
      {31.1, 32.2, 33.3, 34.4, 35.5, 36.6, 37.7, 38.8, 39.9, 40.0},
      {41.1, 42.2, 43.3, 44.4, 45.5, 46.6, 47.7, 48.8, 49.9, 50.0},
      {51.1, 52.2, 53.3, 54.4, 55.5, 56.6, 57.7, 58.8, 59.9, 60.0},
      {61.1, 62.2, 63.3, 64.4, 65.5, 66.6, 67.7, 68.8, 69.9, 70.0}
  };

  // a
  myArray[2][5] = 105;

  // b
  for (int i = 0; i < 10; i++) {
    myArray[4][i] = 1.5;
  }

  // c
  for (int j = 0; j < 7; j++) {
    for (int k = 0; k < 10; k++) {
      cout << "Esto es la fila " << j << " que tiene el valor: " << myArray[j][k] << endl;
    }
    
  }

  // d
  for (int p = 0; p < ROWS; p++) {
    float temp = myArray[p][2];
    myArray[p][2] = myArray[p][4];
    myArray[p][4] = temp;
  }

  // e
  float rowsSum = 0.0;
  for (int l = 0; l < ROWS; l++) {
        cout << "\nEsto es la col en fila 2: " << myArray[1][l] << endl;
        rowsSum += myArray[1][l];

        cout << "\nEsto es la col en fila 6: " << myArray[5][l] << endl;
        rowsSum += myArray[5][l];
    }
    
  cout << "\n\nLa suma de las filas 2 y 6 es: " << rowsSum << endl;

  // f

  for (int m = 0; m < ROWS; m++) {
    cout << "\nEsta es el número de la columna 3 en la fila " << m << ": " << myArray[m][2] << ", ";
  }

  // g
  float biggest = 0;
  for (int n = 0; n < ROWS; n++) {
    for (int o = 0; o < COLS; o++) {
      if (myArray[n][o] > biggest) {
        biggest = myArray[n][o];
      }
    }
  }

  cout << "El número más grande es: " << biggest << endl;

  return 0;
}

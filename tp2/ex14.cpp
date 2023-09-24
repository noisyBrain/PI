/*

  Una matriz cuadrada A se dice que es simétrica si A(i,j) = A(j,i) para todo i, j. Escribir un programa que decida si
  una matriz de 3 x 3 dada es o no simétrica.

*/

#include<iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

bool checkMatrix(float arr[ROWS][COLS], float otherArr[ROWS][COLS]) {
  bool isSymmetrical = false;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (arr[i][j] == otherArr[i][j]) {
        isSymmetrical = true;

      } else {
        return isSymmetrical = false;
      }
    }
  }

  return isSymmetrical;
}

void printResult(bool result) {
  result
    ? cout << "Es simétrica!" << endl
    : cout << "No es simétrica" << endl;
}

int main () {
  float myArray[ROWS][COLS] = {
      { 1.0, 2.2, 3.3 },
      { 11.1, 12.2, 13.3 },
      { 21.1, 22.2, 23.3 }
  };

  float myOtherArray[ROWS][COLS] = {
      { 1.0, 2.2, 3.3 },
      { 11.1, 12.2, 13.3 },
      { 21.1, 22.2, 23.3 }
  };

  printResult(checkMatrix(myArray, myOtherArray));
  
  return 0;
}

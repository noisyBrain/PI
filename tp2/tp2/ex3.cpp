#include<iostream>

using namespace std;

int en_desorden (int arreglo[], int dimension) {
  for (int indice = 0; indice < dimension; indice++) {
    if (arreglo[indice] > arreglo[indice + 1]) {
      return indice + 1;
    }
    return -1;
  }
}

int main () {
  // int array[5] = { 2, 3, 5, 9, 1 };
  int array[5] = { 2, 3, 4, 5, 6 };
  int foo = en_desorden(array, 1);

  cout << foo << endl;

  return 0;
}

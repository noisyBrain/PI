#include "resources.h"
#include<iostream>

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


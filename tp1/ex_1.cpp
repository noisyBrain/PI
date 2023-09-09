/*

Escribir un programa que imprima los números del 1 al 100, mostrando de a cinco por renglón.

*/

#include<iostream>

using namespace std;

int main () {
  int total = 100; 

  for (int i = 1; i <= total; i++) {
    if (i % 5 == 0) {
      cout << i << '\n';

    } else {
      cout << i << ", ";
    }
  }

  return 0;
}
//foo

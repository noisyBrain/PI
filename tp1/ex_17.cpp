/*

Escribir un programa que determine si un año es bisiesto.
Nota: un año es bisiesto si es múltiplo de 4. Los años múltiplos de 100 no son bisiestos, excepto que también
sean múltiplos de 400.
Ejemplo: 2000 es bisiesto, 1800 no lo es.

*/

#include<iostream>

using namespace std;

int main () {
  int year;

  cout << "Ingresá un año par saber si es bisiesto: " << endl;
  cin >> year;

  bool isLeapYear = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);

  if (isLeapYear) {
    cout << "Es bisiesto" << endl;

  } else {
    cout << "No es bisiesto" << endl;
  }
  
  return 0;
}

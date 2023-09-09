/*

Escribir un programa que lea una fecha en el formato numérico AAAAMMDD y la informe con el formato
DD/MM/AAAA.
Precondición: los valores ingresados corresponden a una fecha válida

*/

#include <iostream>

using namespace std;

int main() {
  int date;
  int year;
  int month;
  int day;

  string outputDate; 

  cout << "Ingresá una fecha válida en formato AAAAMMDD: " << endl;
  cin >> date;

  year = date / 10000;
  date = date % 10000;
  month = date / 100;
  day = date % 100;

  cout << "Tu fecha convertida es: " << day << "/" << month << "/" << year << "\n";

  return 0;
}


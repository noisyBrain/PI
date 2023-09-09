/*

Escribir un programa que, dado un año y una cantidad de días transcurridos desde el 1 de enero, muestre la
fecha en formato dd/mm/aaaa. Validar que la cantidad de días dada sea válida (entre 1 y 365 ó entre 1 y 366).
Para esto se debe considerar si el año es bisiesto o no.
Ejemplos: en el año 2019, el día número 256 corresponde al 13/09/2019.
En el año 2000 (bisiesto), el día número 60 corresponde a la fecha 29/02/2000.
En el año 2014, el día número 366 no es válido ya que 2014 tuvo 365 días.

*/

/*

 Qué tiene que hacer el programa?
   1. Tomar dos inputs numéricos. ✅
    1.1. El primero será el año a considerar. El segundo será la cantidad de días transcurridos de ese año. ✅
   2. Debe dar la fecha en formato dd/mm/aaaa de ese día en el año.
   3. Debe tener en cuenta si el año es bisiesto o no.

*/


#include<iostream>
#include<string>

using namespace std;

int calculateDay(int firstDayOfMonth, int fromFirstDayOfYear) {
  int dayToReturn = 1;

  while (firstDayOfMonth <= fromFirstDayOfYear) {
    firstDayOfMonth++;
    dayToReturn++;
  }

  return dayToReturn;
}

int calculateFirstDay(int)

int calculateMonth(int fromFirstDayOfYear) {
  if (fromFirstDayOfYear >= 1 && fromFirstDayOfYear < 31) {
    return 1;
  }

  if (fromFirstDayOfYear >= 31 && fromFirstDayOfYear < 59) {
    return 2;
  }

  if (fromFirstDayOfYear >= 59 && fromFirstDayOfYear < 90) {
    return 3;
  }

  if (fromFirstDayOfYear >= 90 && fromFirstDayOfYear < 120) {
    return 4;
  }

  if (fromFirstDayOfYear >= 120 && fromFirstDayOfYear < 151) {
    return 5;
  }

  if (fromFirstDayOfYear >= 151 && fromFirstDayOfYear < 181) {
    return 6;
  }

  if (fromFirstDayOfYear >= 181 && fromFirstDayOfYear < 212) {
    return 7;
  }

  if (fromFirstDayOfYear >= 213 && fromFirstDayOfYear < 243) {
    return 8;
  }

  if (fromFirstDayOfYear >= 243 && fromFirstDayOfYear < 273) {
    return 9;
  }

  if (fromFirstDayOfYear >= 273 && fromFirstDayOfYear < 303) {
    return 10;
  }

  if (fromFirstDayOfYear >= 303 && fromFirstDayOfYear < 332) {
    return 11;
  }

  if (fromFirstDayOfYear >= 332 && fromFirstDayOfYear < 365) {
    return 12;
  }

  // WARN: tener en cuenta año bisiesto
  return 0;
}

int main () {
  int year = 0;
  int daysFromFirstDayOfYear = 0;

  int january = 1;
  int febrary = 31;
  int march = 59;
  int april = 90;
  int may = 120;
  int june = 151;
  int july = 181;
  int august = 212;
  int september = 243;
  int october = 273;
  int november = 303;
  int december = 333;


  cout << "Ingresá el año que queres procesar: " << endl;
  cin >> year;
  cout << "Ingresá la cantidad de días: " << endl;
  cin >> daysFromFirstDayOfYear;

  int month = calculateMonth(daysFromFirstDayOfYear);

  calculateDay();

  
  return 0;
}

/*

  bool isLeapYear = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);

  if (!isLeapYear && daysFromFirstDayOfYear > 365) {
    cout << "Tenes que ingresar un número menor a 365..." << endl;
    return 1;
  }

  if (isLeapYear && daysFromFirstDayOfYear > 366) {
    cout << "Tenes que ingresar un número menor a 366!!!!" << endl;
    return 1;
  }

*/

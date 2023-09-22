/*

Escribir un programa que permita al usuario gestionar los pagos de la cuota de un club.
  a) Para ello, almacenar en un arreglo los números de DNI de los socios que pagaron.
  El club no tiene más de 200 socios.

  b) Permitir al usuario buscar un DNI en el arreglo y, si el DNI está en el arreglo, imprimir "Cuota al día".
  Si no está, imprimir "Socio con deuda".

  c) También se debe permitir al usuario eliminar un DNI del arreglo, en caso de haberlo ingresado erróneamente.

  d) Finalmente, imprimir todo el arreglo.

*/

#include<iostream>
#include "resources.h"

using namespace std;

const int PD = 200; // Physical Dimension

void prinMenu() {
  cout << "*** Gestión de cuotas ***" << endl;
  cout << "[0] Para salir" << endl;
  cout << "[1] Para agregar un DNI de socio" << endl;
  cout << "[2] Para buscar un socio" << endl;
  cout << "[3] Para eliminar el DNI de un socio" << endl;
}

int takeOption() {
  int option = 5;
  cin >> option;

  return option;
}

int askForDNI() {
  int DNI = 0;

  cout << "Ingresá tu DNI (todo junto, sin puntos): ";
  cin >> DNI;

  return DNI;
}

void insertInArray(int array[], int &ld) {
  int DNI = askForDNI();

  if (ld < PD) {
    array[ld] = DNI;
    ld++;

    if (ld < PD) {
      DNI = askForDNI();
    }
    clearAfterEnter();
    prinMenu();
    option = takeOption();
  }
}

int main () {
  int ld = 0; // logic dimension;
  int membersWhoPaid[PD];

  insertInArray(membersWhoPaid, PD, ld);
  
  return 0;
}

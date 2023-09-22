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

  cout << "\nIngresá alguna de las opciones del menú: ";
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
    cout << "Socio con DNI: " << DNI << " agregado correctamente." << endl;
    return;
  }

  cout << "Espacio lleno..." << endl;
}

void searchInArray(int array[], int ld) {
  int searchedDNI = 0;

  cout << "Ingrese el DNI a buscar: " << endl;
  cin >> searchedDNI;

  if (ld == 0) {
    cout << "No hay socios registrados..." << endl;;
    return;
  }

  for (int i = 0; i < ld; i++) {
    if (array[i] == searchedDNI) {
      cout << "Cuota al día!" << endl;
      return;
    }
  }

  cout << "Socio en deuda!" << endl;
}

void deleteFromArray(int arr[], int &ld) {
  int i = 0;
  int DNI = askForDNI();

  if (ld == 0) {
    cout << "No hay socios registrados..." << endl;
    return;
  }

  while (i < ld && arr[i] != DNI) {
    i++;
  }

  if (arr[i] == DNI) {
    for (int j = i; j < ld - 1; j++) {
      arr[j] = arr[j+1];
    }

    ld--;
  }

  cout << "Socio con DNI: " << DNI << " eliminado correctamente." << endl;
}

void startProgram(int arr[], int PD, int &ld) {
  clearScreen();
  prinMenu();

  int option = takeOption();

  while (option != 0) {

    switch (option) {
      case 1:
        insertInArray(arr, ld);
        break;

      case 2:
        searchInArray(arr, ld);
        break;

      case 3:
        deleteFromArray(arr, ld);
        break;

      default:
        cout << "\nIngresaste una opción inválida, volvé a intentarlo..." << endl;
        break;
    }

    clearAfterEnter();
    prinMenu();
    option = takeOption();
  }
}

void printMembersWhoPaid(int membersWhoPaid[], int ld) {
  if (ld > 0) {
    cout << "\nEstos son los socios que pagaron: " << endl;
    printArray(membersWhoPaid, ld);
    return;
  }

  cout << "\nNo existen socios registrados\n" << endl;
}

int main () {
  int ld = 0; // logic dimension;
  int membersWhoPaid[PD];

  startProgram(membersWhoPaid, PD, ld);
  printMembersWhoPaid(membersWhoPaid, ld);
  showEndProgram();
  
  return 0;
}

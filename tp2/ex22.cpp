/*

  Realizar un programa que almacene en un arreglo la lista de invitados a una fiesta.
  El salón donde se realizará tiene capacidad máxima para 150 personas.
  De cada invitado se conoce nombre, apellido, sexo y edad.
  Se ingresarán datos hasta que el nombre sea igual a “ZZZ” o hasta que la capacidad del salón esté completa.
  Una vez finalizada la carga:

  a) Informar la cantidad de invitados que asistirán a la fiesta.
  b) Realizar una función que liste los nombres de las mujeres cuya edad sea <= 20.
  c) Realizar una función que, dado un apellido y nombre, permita eliminar un invitado en caso de no poder
  asistir.

*/

#include<iostream>
#include<string>
#include "resources.h"

using namespace std;

const int MAX_CAP = 150; // physic dimension

struct Guest {
  string firstName;
  string lastName;
  string gender;
  int age;
};

struct GuestToDelete {
  string firstName;
  string lastName;
};

void printWelcome() {
  clearScreen();
  cout << "\t *** Lista de Invitados ***\n";
}

bool isFull(int ld) { return ld == MAX_CAP; }

void addGuest(Guest guests[], Guest newGuest, int &ld) {
    if (isFull(ld)) {
      cout << "¡La lista de invitados está llena!" << endl;
      return;
    }

    guests[ld] = newGuest;
    ld++;
}

void promptNewGuest(Guest &newGuest) {
  clearAfterEnter();
  cout << "Ingresá el nombre del invitado. [ZZZ] para terminar" << endl;
  getline(cin >> ws, newGuest.firstName);
}

void startProgram(Guest guests[], int &ld) {
  Guest newGuest;

  printWelcome();
  promptNewGuest(newGuest);

  while(newGuest.firstName != "ZZZ") {
    cout << "Ingrese el apellido del invitado: ";
    getline(cin >> ws, newGuest.lastName);

    cout << "Ingrese el género del invitado: ";
    cin >> newGuest.gender;

    cout << "Ingrese la edad del invitado: ";
    cin >> newGuest.age;

    addGuest(guests, newGuest, ld);

    cin.ignore();
    promptNewGuest(newGuest);
  }
}

void printGuests(Guest guests[], int ld) {
  for (int i = 0; i < ld; i++) {
      cout << guests[i].firstName << ", ";
      cout << guests[i].lastName << ", ";
      cout << guests[i].age << ", ";
      cout << guests[i].gender << endl;
      cout << "\n" << endl;
  }
}

void countGuests(int ld) {
  cout << "La cantidad de invitados es de: "<< ld << endl;
}

void listWomenSub20(Guest guests[], int ld) {
  cout << "Listado de nombres de mujeres <= 20 años: ";
  for (int i = 0; i < ld; i++) {
    if (guests[i].age <= 20 && guests[i].gender == "FEM") {
      cout << "\n " << guests[i].firstName;

    } else {
      cout << "Ninguna\n";
    }
  }
}

int main () {
  int ld = 0; // logic dimension
  Guest guests[MAX_CAP];

  startProgram(guests, ld);
  printGuests(guests, ld);
  countGuests(ld);
  listWomenSub20(guests, ld);

  showEndProgram();
  
  return 0;
}

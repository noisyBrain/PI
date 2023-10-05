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

void printOptions(int &option) {
  cout << "[0] Para salir" << endl;
  cout << "[1] Para agregar un invitado" << endl;
  cout << "[2] Para eliminar un invitado" << endl;
  cin >> option;
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

void deleteGuest(Guest guests[], GuestToDelete guest, int &ld) {
  int i = 0;

  while (
      i < ld &&
      guests[i].firstName != guest.firstName &&
      guests[i].lastName != guest.lastName
  ) i++;

  bool guestExists = guests[i].firstName == guest.firstName && guests[i].lastName == guest.lastName;

  if (!guestExists) {
    cout << "\n¡El invitado buscado no existe en la lista!\n" << endl;
    return;
  }

  for (int j = i; j < ld; j++) {
    guests[j] = guests[j+1];
  }

  ld--;

  cout << "\n¡El invitado "<< guest.firstName << " fue eliminado con éxito!\n" << endl;
}

void promptNewGuest(Guest &newGuest) {
  clearAfterEnter();
  cout << "Ingresá el nombre del invitado (ZZZ para terminar): ";
  getline(cin >> ws, newGuest.firstName);
}

void takeNewGuest(Guest guests[], int &ld) {
  Guest newGuest;

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

GuestToDelete promtGuestToDelete() {
  clearScreen();

  GuestToDelete guestToDelete;

  cout << "Ingresá el nombre de la persona a eliminar: ";
  getline(cin >> ws, guestToDelete.firstName);

  cout << "Ingresá el apellido de la persona a eliminar: ";
  getline(cin >> ws, guestToDelete.lastName);

  return guestToDelete;
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

  if (ld == 0) {
    cout << "Ninguna\n";
    return;
  }

  for (int i = 0; i < ld; i++) {
    if (guests[i].age <= 20 && guests[i].gender == "FEM") {
      cout << "\n " << guests[i].firstName;

    } else {
      cout << "Ninguna\n";
    }
  }
}


void chooseOption(int &option, Guest guests[], int &ld) {
  printWelcome();
  printOptions(option);

  while (option != 0) {
    switch (option) {
      case 0:
        break;

      case 1:
        takeNewGuest(guests, ld);
        break;

      case 2: {
        GuestToDelete guest = promtGuestToDelete();
        deleteGuest(guests, guest, ld);
        break;
      }

      default:
        cout << "Opción incorrecta, volvé a intentarlo..." << endl;
        printOptions(option);
        break;
    }

    printOptions(option);
  }
}

int main () {
  int ld = 0; // logic dimension
  int option = 0;
  Guest guests[MAX_CAP];

  chooseOption(option, guests, ld);
  printGuests(guests, ld);
  countGuests(ld);
  listWomenSub20(guests, ld);

  showEndProgram();
  
  return 0;
}

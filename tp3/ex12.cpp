/*

  Generar una lista enlazada simple con la nómina de artículos de un supermercado. De cada artículo se conoce:
  código, descripción, precio y stock. La carga finaliza con el código -1. Se solicita:
    A. Leer de teclado un porcentaje e incrementar el precio de todos los artículos en esa cantidad.
    B. Incrementar el stock de un artículo. Se lee de teclado el código y la cantidad con la que se debe
       incrementar el stock. Si no existe el artículo en la lista se debe informar.
    C. Eliminar de la lista los artículos que no tienen stock.

*/

#include<iostream>
#include<string>

using namespace std;

struct Article {
  int code;
  string description;
  int price;
  int stock;
};

struct Node {
  Article data;
  Node *next;
};

void printMenu() {
  cout << "\t\tSeleccioná una opción (-1 para salir): \n\n";
  cout << "1. Para incrementar el precio de un artículo: \n";
  cout << "2. Para incrementar el stock de un artículo: \n";
  cout << "3. Para eliminar de la lista los artículos que no tengan stock: \n";
}

void takeUserPrompt(int &option) {
  printMenu();

  cin >> option;
}

void takeOption() {
  int option = 0;

  printMenu();
  takeUserPrompt(option);

  do {
    switch (option) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;

      default:
        cout << "Opción incorrecta, volvé a intentarlo...\n";
        break;
    }
  } while (option > 0);
}

int main () {
  

  return 0;
}

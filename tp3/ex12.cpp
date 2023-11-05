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

void getUserOption(int &option) {
  printMenu();

  cin >> option;
}

void showEndProgram() {
  cout << "Finalizando..." << endl;
  sleep(1);

  cout << "\n// -------------------------------- //" << endl;
  cout << "\t¡Programa Finalizando!" << endl;
  cout << "// -------------------------------- //" << endl;
}

void performMenuAction(Node *&head) {
  int option = 0;

  do {
    getUserOption(option);

    switch (option) {
      case -1:
        showEndProgram();
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

void printList(Node *head) {
  for (Node *aux = head; aux != nullptr; aux = aux->next) {
    cout << "code: " << aux->data.code << "\n";
    cout << "price: " << aux->data.price << "\n";
    cout << "stock: " << aux->data.stock << "\n";
    cout << "description: " << aux->data.description << "\n";
    cout << "\n";
  }

  cout << endl;
}

int main () {
  performMenuAction();

  return 0;
}

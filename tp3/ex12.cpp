/*

  Generar una lista enlazada simple con la nómina de artículos de un supermercado. De cada artículo se conoce:
  código, descripción, precio y stock. La carga finaliza con el código -1. Se solicita:
    A. Leer de teclado un porcentaje e incrementar el precio de todos los artículos en esa cantidad. ✅
    B. Incrementar el stock de un artículo. Se lee de teclado el código y la cantidad con la que se debe
       incrementar el stock. Si no existe el artículo en la lista se debe informar. ✅
    C. Eliminar de la lista los artículos que no tienen stock.

*/

#include<iostream>
#include<string>
#include<unistd.h>

using namespace std;

struct Article {
  int code;
  string description;
  double price;
  int stock;
};

struct Node {
  Article data;
  Node *next;
};

Node* getNodeData() {
  Node *newNode = new Node();
  newNode->next = nullptr;

  cout << "Ingresá el código del producto: ";
  cin >> newNode->data.code;

  cout << "Ingresá el precio del producto: ";
  cin >> newNode->data.price;

  cout << "Ingresá el stock del producto: ";
  cin >> newNode->data.stock;

  cout << "Ingresá la descripción del producto: ";
  getline(cin >> ws, newNode->data.description);

  return newNode;
}

void addToList(Node *&head) {
  Node *newNode = getNodeData();

  if (head == nullptr) {
    head = newNode;
    return;
  }

  Node *aux = head;
  while (aux->next != nullptr) {
    aux = aux->next;
  }

  aux->next = newNode;
}

void increaseStockByCode(Node *head) {
  int articleCode;

  cout << "Ingresá el código del producto: ";
  cin >> articleCode;

  Node *current = head;
  while (current->next != nullptr && current->data.code != articleCode) {
    current = current->next;
  }

  if (!(current->data.code == articleCode)) {
    cout << "No se encontró el producto buscado\n";
    return;
  }

  cout << "\nEl stock anterior del artículo era de: " << current->data.stock << "\n";
  cout << "Ingresá la nueva cantidad de stock del artículo: ";
  cin >> current->data.stock;

  cout << "\nProducto actualizado correctamente!\n";
}

void increasePrices(Node *head) {
  double percentage;

  cout << "Ingresá el porcentaje a incrementar los precios: %";
  cin >> percentage;

  for (Node *aux = head; aux != nullptr; aux = aux->next) {
    aux->data.price += aux->data.price * (percentage / 100.0);
  }

  cout << "\nLos precios fueron actualizados correctamente!\n";
}

void printMenu() {
  cout << "\n\t\tSeleccioná una opción (-1 para salir): \n\n";
  cout << "1. Para agregar un nuevo artículo: \n";
  cout << "2. Para incrementar el precio de un artículo: \n";
  cout << "3. Para incrementar el stock de un artículo: \n";
  cout << "4. Para eliminar de la lista los artículos que no tengan stock: \n";
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

      case 1: {
        addToList(head);
        break;
      }

      case 2:
        increasePrices(head);
        break;

      case 3:
        increaseStockByCode(head);
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
  Node *head = nullptr;

  performMenuAction(head);
  printList(head);

  return 0;
}

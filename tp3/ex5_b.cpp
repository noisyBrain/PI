/*

  Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
  debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
  versiones, insertando en cada una con diferente criterio, a saber:
  b) Al final de la lista.

  Finalmente, imprimir la lista.

*/

#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

Node* insertAtTheEnd(Node *init, int value) {
  Node *newNode = new Node();
  newNode->data = value;
  newNode->next = nullptr;

  if (init == nullptr) {
    init = newNode;

  } else {
    Node *aux = init;

    while (aux->next != nullptr) {
      aux = aux->next;
    }

    aux->next = newNode;
  }

  return init;
}

Node* createList() {
  Node *head = nullptr;
  int number;

  cout << "Ingrese un número entero (0 para terminar): ";
  cin >> number;

  while (number != 0) {
    head = insertAtTheEnd(head, number);

    cout << "Ingrese otro número entero (0 para terminar): ";
    cin >> number;
  }

  return head;
}

int main() {
  Node *head = createList();

  return 0;
}


/*

  Se lee de teclado una secuencia de números que finaliza con la primera ocurrencia de un número negativo, el
  cual no debe ser procesado. Los números deben ser almacenados en una lista enlazada simple. Se solicita:

  A. Leer de teclado un número e informar si existe en la lista.
  B. Leer de teclado un número e informar la cantidad de ocurrencias del número en la lista.
  C. Implementar una función que reciba la lista de números y genere dos nuevas listas, una con los
     números pares y otra con los impares. Las nuevas listas deberán estar formadas con los nodos de la lista
     original, la que quedará vacía después de invocar a la función. Imprimir las listas resultantes.

*/

#include<iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

Node* insertNumberAtTheEnd(Node *head, int number) {
  Node *newNode = new Node();

  newNode->data = number;
  newNode->next = nullptr;

  if (head == nullptr) {
    head = newNode;

  } else {
    Node *aux = head;

    while (aux->next != nullptr) {
      aux = aux->next;
    }

    aux->next = newNode;
  }

  return head;
}

Node* takeInput(Node *head) {
  char option = ' ';
  int number = -1;

  cout << "Ingresá algunas de las opciones: ";
  cin >> option;

  while (option != 'd' && option != 'D' && number != 0) {
    switch (option) {
      case 'a':
        cout << "Ingresá un número: ";
        cin >> number;

        head = insertNumberAtTheEnd(head, number);
        break;

      case 'b':
        break;

      case 'c':
        break;

      default:
        cout << "Opción inválida, volvé a intentarlo...\n";
        break;
    }

    cout << "Ingresá algunas de las opciones: ";
    cin >> option;
  }

  return head;
}

void printMenu() {
  cout << "[a] para agregar números\n";
  cout << "[b] para confirmar si existe un número en la lista\n";
  cout << "[c] para confirmar la cantidad de ocurrencias de un número\n";
  cout << "[d] para salir\n";
}

void printList(Node *head) {
  cout << "\nLista final: ";

  for (Node *aux = head; aux != nullptr; aux = aux->next) {
    cout << aux->data << ", ";
  }

  cout << endl;
}

int main () {
  Node *head = nullptr;

  printMenu();
  head = takeInput(head);

  printList(head);

  return 0;
}

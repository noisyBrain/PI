/*

  Se lee de teclado una secuencia de números que finaliza con la primera ocurrencia de un número negativo, el
  cual no debe ser procesado. Los números deben ser almacenados en una lista enlazada simple. Se solicita:

  A. Leer de teclado un número e informar si existe en la lista. ✅
  B. Leer de teclado un número e informar la cantidad de ocurrencias del número en la lista. ✅
  C. Implementar una función que reciba la lista de números y genere dos nuevas listas, una con los
     números pares y otra con los impares. Las nuevas listas deberán estar formadas con los nodos de la lista
     original, la que quedará vacía después de invocar a la función. Imprimir las listas resultantes. ✅

*/

#include<iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

Node* insertNodeAtTheEnd(Node *head, Node* newNode) {
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

void existsInList(Node *head, int number) {
  Node *aux = head;

  while (aux != nullptr && aux->data != number) {
    aux = aux->next;
  }

  if (aux == nullptr || aux->data != number) {
    cout << "No se encontró el elemento\n";

  } else {
    cout << "El elemento se encuentra en la lista!\n";
  }
}

void countOcurrences(Node *head, int numberToSearch) {
  if (head == nullptr) {
    cout << "La lista está vacía";
  }

  Node *aux = head;
  int counter = 0;

  while (aux != nullptr) {
    if (aux->data == numberToSearch) {
      counter++;
    }

    aux = aux->next;
  }

  cout << "La cantidad de ocurrencias del número " << numberToSearch << " es de: " << counter << endl;
}

Node* devideList(Node *head, Node *&evenHead, Node *&oddHead) {
  if (head == nullptr) {
    cout << "La lista está vacía!\n";
    return head;
  }

  Node *aux;

  // WARN: I should not use head. Always use an aux pointer
  while (head != nullptr) {
    aux = head;
    head = head->next;

    // NOTE: I could use aux = aux->next after else statement
    aux->next = nullptr;

    if (aux->data % 2 == 0) {
      evenHead = insertNodeAtTheEnd(evenHead, aux);

    } else {
      oddHead = insertNodeAtTheEnd(oddHead, aux);
    }
  }

  return head;
}

void printList(Node *head) {
  cout << "\nLista final: ";

  for (Node *aux = head; aux != nullptr; aux = aux->next) {
    cout << aux->data << ", ";
  }

  cout << endl;
}

Node* takeInput(Node *head) {
  char option = ' ';
  int number = -1;

  cout << "Ingresá algunas de las opciones: ";
  cin >> option;

  // TODO: improve data charge
  while (option != 'e' && option != 'E' && number != 0) {
    cout << "Ingresá un número: ";
    cin >> number;

    switch (option) {
      case 'a': {
        Node *newNode = new Node();
        newNode->data = number;
        newNode->next = nullptr;

        head = insertNodeAtTheEnd(head, newNode);
        break;
      }

      case 'b':
        existsInList(head, number);
        break;

      case 'c':
        countOcurrences(head, number);
        break;

      case 'd': {
        char confirmation = ' ';
        cout << "Estás seguro que querés dividir la lista?\nLos cambios son irreversibles (s/n)" << endl;
        cin >> confirmation;

        if (confirmation == 'n' || confirmation == 'N') {
          break;
        }

        Node *evenList = nullptr;
        Node *oddList = nullptr;

        head = devideList(head, evenList, oddList);

        printList(oddList);
        printList(evenList);
        break;
      }

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
  cout << "[d] para dividir la lista en dos, según pares e impares\n";
  cout << "[e] para salir\n";
}

int main () {
  Node *head = nullptr;

  printMenu();
  head = takeInput(head);

  printList(head);

  return 0;
}

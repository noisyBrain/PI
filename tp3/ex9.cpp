/*

Desarrollar un programa que realice las siguientes operaciones en listas enlazadas simples de números enteros.
  A. Cargar una lista insertando los elementos ordenados en forma descendente. Finaliza luego de ingresar 
     el cero, que también se debe agregar a la lista. ✅
  B. Eliminar las ocurrencias de los números que son múltiplos de 3.
  C. Imprimir la lista antes y después de la eliminación.

*/

#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

Node *deleteOcurrences(Node *head, int number) {
  if (head == nullptr) {
    cout << "La lista está vacía!" << endl;
    return head;
  }

  Node *toDelete;
  Node *aux = head;

  while (aux != nullptr) {
    if (aux->data == number) {
      toDelete = head;
      head = head->next;
      aux = head;
      delete toDelete;

    } else {
      if (aux->next != nullptr && aux->next->data == number) {
        toDelete = aux->next;
        aux->next = toDelete->next;
        delete toDelete;

      } else {
        aux = aux->next;
      }
    }
  }

  return head;
}

Node* insertInDescendingOrder(Node *head, int number) {
  Node *newNode = new Node();
  newNode->data = number;

  if (head == nullptr || head->data < number) {
    newNode->next = head;
    head = newNode;

  } else {
    Node *aux = head;

    while (aux != nullptr && aux->next->data > number) {
      aux = aux->next;
    }

    newNode->next = aux->next;
    aux->next = newNode;
  }

  return head;
}

Node* takeUserPrompt(Node *head) {
  int number = 0;

  cout << "Ingrese un número entero (0 para salir): ";
  cin >> number;

  while (number != 0) {
    head = insertInDescendingOrder(head, number);

    cout << "Ingrese otro número entero (0 para salir): ";
    cin >> number;
  }

  return head;
}

Node* takePromptToDeleteOcurrences(Node *head) {
  int number = 0;

  cout << "Ingrese el número que desea elminar: ";
  cin >> number;

  head = deleteOcurrences(head, number);

  return head;
}

int main () {
  Node *head = nullptr;

  head = takeUserPrompt(head);
  cout << "\nDespués de agregar los elementos: \n\n";

  head = takePromptToDeleteOcurrences(head);
  cout << "\nDespués de eleminar las ocurrencias: \n\n";

  return 0;
}

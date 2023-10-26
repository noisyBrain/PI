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

int main () {
  Node *head = nullptr;

  head = takeUserPrompt(head);

  return 0;
}

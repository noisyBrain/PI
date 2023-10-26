/*

  Implementar una función que reciba dos parámetros: 
    - una lista enlazada simple de números enteros 
    - un número entero. 
  La función debe eliminar todas las ocurrencias del número indicado en el segundo parámetro.
  Retornar la cantidad de ocurrencias eliminadas. 

  Nota: se debe pasar una sola vez por cada uno de los elementos de la lista.

*/

#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

Node* deleteOcurrences(Node* head, int numberToDelete){
  Node* toDelete;
  Node* aux = head;

  while (aux != nullptr) {
    if (head->data == numberToDelete) {
      toDelete = head;
      head = head->next;
      aux = head;
      delete toDelete;

    } else {
      if (aux->next != nullptr && aux->next->data == numberToDelete) {
        toDelete = aux->next;
        aux->next = toDelete->next;
        delete toDelete;

      } else
        aux = aux->next;
      }
  }

  return head;
}

void printList(Node *head) {
  for (Node *aux = head; aux != nullptr; aux = aux->next) {
    cout << "aux->data: " << aux->data << "\n";
  }

  cout << endl;
}

int main () {
  int number = 0;

  Node *firstNode = new Node();
  Node *head = firstNode;
  firstNode->data = 3;
  firstNode->next = new Node();
  firstNode->next->data = 4;
  firstNode->next->next = new Node();
  firstNode->next->next->data = 5;
  firstNode->next->next->next = new Node();
  firstNode->next->next->next->data = 3;

  printList(head);

  cout << "Ingresá un número para eliminar todas las ocurrencias de la lista: ";
  cin >> number;

  head = deleteOcurrences(head, number);

  printList(head);

  return 0;
}

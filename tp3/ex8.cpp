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

int main () {
  int number = 0;
  Node *head = nullptr;

  cout << "Ingresá un número para eliminar todas las ocurrencias de la lista: ";
  cin >> number;

  head = deleteOcurrences(head, number);

  return 0;
}

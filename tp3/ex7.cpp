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

int main () {
  Node *head = nullptr;

  return 0;
}

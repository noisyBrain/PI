/*

  Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
  debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
  versiones, insertando en cada una con diferente criterio, a saber:
  c) En la posición correcta para que la lista quede ordenada de menor a mayor. Si el número a insertar ya
     se encontraba en la lista, deberá quedar antes que todas sus repeticiones.

  Finalmente, imprimir la lista.

*/

#include<iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

Node* insertSorted(Node *head, int number) {
  Node *newNode = new Node();
  newNode->data = number;

  if (head == nullptr || head->data > newNode->data) {
    newNode->next = head;
    head = newNode;

  } else {
    Node *aux = head;

    while (aux->next != nullptr && aux->next->data < number) {
      aux = aux->next;
    }

    newNode->next = aux->next;
    aux->next = newNode;
  }

  return head;
}

Node* createList() {
  Node *head = nullptr;
  int number = -1;

  cout << "Ingrese un número entero (0 para salir): ";
  cin >> number;

  while (number != 0) {
    head = insertSorted(head, number);

    cout << "Ingrese otro número entero (0 para salir): ";
    cin >> number;
  }

  return head;
}

void printLinkedList(Node *head) {
  cout << "Así quedo la lista enlazada: " << endl;

  for (Node *aux = head; aux != nullptr; aux = aux->next) {
    cout << aux->data << ' ';
  }

  cout << endl;
}

int main () {
  Node *head = createList();

  printLinkedList(head);

  return 0;
}

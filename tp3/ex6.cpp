/*

  Permitir al usuario guardar en una lista enlazada simple los nombres de los alumnos de un curso,
  insertando al final de la lista y cortando la carga cuando se inserte como nombre "x",
  ya sea en mayúscula o en minúscula (el  cual no debe insertarse en la lista).

*/

#include <iostream>

using namespace std;

struct Node {
  string data;
  Node *next;
};

Node* insertAtTheEnd(Node *head, string studentName) {
  Node *newNode = new Node();
  newNode->data = studentName;
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

Node* createNode() {
  Node *head = new Node();
  string studentName = "";

  cout << "Ingresá el nombre del alumno ('x' para finalizar): ";
  cin >> studentName;

  while (studentName != "x" && studentName != "X") {
    head = insertAtTheEnd(head, studentName);

    cout << "Ingresá otro nombre de alumno ('x' para finalizar): ";
    cin >> studentName;
  }

  return head;
}

int main () {
  Node *head = createNode();

  return 0;
}

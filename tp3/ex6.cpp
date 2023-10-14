/*

  Permitir al usuario guardar en una lista enlazada simple los nombres de los alumnos de un curso,
  insertando al final de la lista y cortando la carga cuando se inserte como nombre "x",
  ya sea en mayúscula o en minúscula (el  cual no debe insertarse en la lista).
  A continuación, solicitar al usuario el nombre de un alumno e informar si se encuentra en la lista o no.
  Por último, eliminar a la alumna "Josefina Ortega" de la lista (se asume que no se han almacenado nombres
  repetidos).

*/

#include<iostream>
#include<string>

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
  Node *head;
  string studentName = "";

  cout << "Ingresá el nombre del alumno ('x' para finalizar): ";
  getline(cin >> ws, studentName);

  while (studentName != "x" && studentName != "X") {
    head = insertAtTheEnd(head, studentName);

    cout << "Ingresá otro nombre de alumno ('x' para finalizar): ";
    getline(cin >> ws, studentName);
  }

  return head;
}

void searchInList(Node *head, string studentName) {
  for (Node *aux = head; aux != nullptr; aux = aux->next) {
    if (aux->data == studentName) {
      cout << studentName << " se encuentra en la lista!" << endl;
      return;
    }
  }

  cout << "No se encontró al alumno" << endl;
}

void deleteFromList(Node*& head, string studentName) {
  if (head == nullptr) {
    cout << "La lista está vacía. No se puede eliminar el estudiante.\n";
    return;
  }

  Node* current = head;
  Node* prev = nullptr;

  while (current != nullptr) {
    if (current->data == studentName) {

      if (prev == nullptr) {
        head = current->next;

      } else {
        prev->next = current->next;
      }

      delete current;
      cout << "Estudiante eliminado correctamente\n";

      return;
    }

    prev = current;
    current = current->next;
  }

  cout << "No se encontró el estudiante en la lista.\n";
}

void printList(Node *head) {
  cout << "\nLista final: ";

  for (Node *aux = head; aux != nullptr; aux = aux->next) {
    cout << aux->data << ", ";
  }

  cout << endl;
}

int main () {
  Node *head = createNode();
  string studentToSearch = "Tomas Arregui Bellino";

  printList(head);

  searchInList(head, studentToSearch);

  deleteFromList(head, studentToSearch);

  printList(head);

  return 0;
}

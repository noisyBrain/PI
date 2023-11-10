/*
  Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
  debe insertarse). Los números leídos deberán ser almacenados en una lista circular. Hacer dos versiones,
  insertando en cada una con diferente criterio, a saber:
    a) Al inicio de la lista.
    b) Al final de la lista.
  Finalmente, imprimir la lista.
*/

#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

Node* insertAtTheBeggining(Node* end, Node* newNode) {
  if (end == nullptr) {
    newNode->next = newNode;
    return newNode;
  }

  newNode->next = end->next;
  end->next = newNode;

  return end;
}

Node* createNewNode(Node* end, int data) {
  Node* newNode = new Node();
  newNode->data = data;

  end = insertAtTheBeggining(end, newNode);

  return end;
}

Node* takeUserPrompt(Node* end) {
  int number = 1;

  cout << "Ingresá un número entero (0 para salir): ";
  cin >> number;

  while (number != 0) {
    end = createNewNode(end, number);

    cout << "Ingresá otro número entero (0 para salir): ";
    cin >> number;
  }

  return end;
}

void printList(Node* end) {
  cout << "\n";
  if (end == nullptr) cout << "La lista está vacía!\n"; return;

  for (Node *current = end->next; current != end; current = current->next) {
    cout << "current->data: " << current->data << "\n";
  }

  cout << endl;
}

int main () {
  Node* end = nullptr;

  end = takeUserPrompt(end);
  printList(end);

  return 0;
}

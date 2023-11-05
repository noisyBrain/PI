/*

Cargar una lista enlazada simple con palabras ingresadas por el usuario, las cuales deben almacenarse en
minúsculas independientemente de cómo las ingrese. Luego, a partir de esa lista, generar una nueva lista con
las palabras que se encuentran repetidas. Finalmente, imprimir ambas listas.

*/

#include<iostream>
#include<string>

using namespace std;

struct Node {
  string data;
  Node *next;
};

void printList(Node *head) {
  for (Node *aux = head; aux != nullptr; aux = aux->next) {
    cout << "aux->data: " << aux->data << "\n";
  }

  cout << endl;
}

Node* insertInList(Node *head, Node *newNode) {
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

bool isRepeated(Node *head, string word) {
  Node *aux = head;

  while (aux != nullptr) {
    if (aux->data == word) {

      return true;
    }
    aux = aux->next;
  }

  return false;
}

Node* checkRepeated(Node *head) {
  Node *headNewList = nullptr;

  for (Node *aux = head; aux != nullptr; aux = aux->next) {
    if (isRepeated(aux->next, aux->data)) {
      Node *newNode = new Node();
      newNode->next = nullptr;
      newNode->data = aux->data;

      headNewList = insertInList(headNewList, newNode);
    }
  }

  return headNewList;
}


void normalizeWord(string &word) {
  for (int i = 0; i < word.length(); i++) {
    word[i] = tolower(word[i]);
  }
}

Node* takeUserPrompt(Node *head) {
  string word = " ";

  cout << "Ingresá una palabra: ";
  cin >> word;

  normalizeWord(word);

  while (word != "x" && word != "X") {
    Node *newNode = new Node();
    newNode->data = word;
    newNode->next = nullptr;

    head = insertInList(head, newNode);

    cout << "Ingresá otra palabra: ";
    cin >> word;
  }

  return head;
}

int main () {
  Node *head = nullptr;
  Node *secondListHead = nullptr;

  head = takeUserPrompt(head);
  printList(head);

  secondListHead = checkRepeated(head);

  cout << "Esta es la lista de las palabras repetidas" << endl;
  printList(secondListHead);

  return 0;
}

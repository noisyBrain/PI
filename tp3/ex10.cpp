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

void printList(Node *head) {
  for (Node *aux = head; aux != nullptr; aux = aux->next) {
    cout << "aux->data: " << aux->data << "\n";
  }

  cout << endl;
}

int main () {
  Node *head = nullptr;

  head = takeUserPrompt(head);
  printList(head);

  return 0;
}

/*

   Implementar una función que reciba dos listas enlazadas simples con datos de tipo string ordenadas según el
   alfabeto y retorne una tercera lista ordenada por el mismo criterio, conformada por todos los elementos de las
   listas originales (merge). Agregar las funciones auxiliares que sean necesarias para cumplir con este propósito.

*/

#include<iostream>
#include<string>

using namespace std;

struct Node {
  string data;
  Node *next;
};

Node* insertAtTheEnd(Node *mergedListHead, Node *newNode) {
  if (mergedListHead == nullptr) {
    return newNode;
  }

  Node *aux = mergedListHead;
  while (aux->next != nullptr) {
    aux = aux->next;
  }

  aux->next = newNode;

  return mergedListHead;
}

Node* gotoNextNode(Node *&listToMerge, Node *&newList) {
  while (listToMerge != nullptr) {
    Node *previousNode = listToMerge;

    previousNode = listToMerge;
    listToMerge = listToMerge->next;
    newList = insertAtTheEnd(newList, previousNode);
  }

  return newList;
}

Node* merge(Node *list1, Node *list2) {
  Node *mergedList = nullptr;

  while (list1 != nullptr && list2 != nullptr) {
    if (list1->data <= list2->data) {
      mergedList = insertAtTheEnd(mergedList, list1);
      list1 = list1->next;

    } else {
      mergedList = insertAtTheEnd(mergedList, list2);
      list2 = list2->next;
    }
  }

  // TODO: ask for this
  mergedList = insertAtTheEnd(mergedList, list2);

  return mergedList;
}

void printList(Node *head) {
  for (Node *aux = head; aux != nullptr; aux = aux->next) {
    cout << "aux->data: " << aux->data << "\n";
  }

  cout << endl;
}

int main () {
  Node *firstList = new Node {"hola", nullptr};
  Node *secondList = new Node {"chau", nullptr};
  
  firstList->next = new Node {"partido", nullptr};
  secondList->next = new Node {"arbol", nullptr};

  Node *mergedList = merge(firstList, secondList);

  cout << "merged List... \n";
  printList(mergedList);

  return 0;
}

/*

  Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
  debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
  versiones, insertando en cada una con diferente criterio, a saber:
  a) Al inicio de la lista.

  Finalmente, imprimir la lista.

*/

#include<iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

Node* addToStart(Node* head, Node* newNode) {
  /*
     ahora el next de newNode apunta a HEAD, es decir:
     - Para el caso de que sea el primer nodo, apuntará
       a `nullptr`
     - Para el caso de que sea a partir del segundo nodo
     insertado, apuntará al nodo que está antes de él
  */
  newNode->next = head;
  return newNode;
}

Node* getUserPrompt(Node* init) {
  int number;
  Node* newNode;

  cout << "Ingresar un número (0 para cortar): ";
  cin >> number;

  while (number != 0) {
    /*
       newNode va a contener la dirección de
       la memoria HEAP que se acaba de reservar
    */
    newNode = new Node();

    /*
       el campo data del nuevo nodo que creamos (newNode)
       va a contener el dato que ingrese el usuario
    */
    newNode->data = number;

    /*
       en init se guarda la dirección de memoria del
       nuevo nodo creado tal que ahora, el primer nodo
       de la lista, sea el último que se creó
    */
    init = addToStart(init, newNode);

    cout << "Ingresar un número (0 para cortar): ";
    cin >> number;
  }

  return init;
}

int main () {
  Node *head = nullptr;

  head = getUserPrompt(head);

  for (Node* aux = head; aux != nullptr; aux = aux->next) {
    cout << aux->data << endl;
  }

  return 0;
}

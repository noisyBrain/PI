/*

  "The Golden Gate Bridge" es el puente más famoso de la ciudad de San Francisco (California). Cuenta con una
  longitud aproximada de 1280 metros y posee tres radares de toma de velocidad. Por cada móvil que se
  desplaza por las vías principales se registra la siguiente información: sensor que lo captó (puede ser "norte",
  "sur" o "medio"), patente (no tiene un formato único ya que difiere de un estado a otro y pueden transitar
  autos extranjeros, aunque se sabe que están formadas sólo por letras y números) y velocidad en km/h.

  A. Cargar las lecturas que hacen los sensores en una lista enlazada simple ordenando por patente y, para
     la misma patente, ordenando por sensor (ya que un mismo automóvil puede ser captado por más de un
     sensor). Finaliza con la patente "aaa99", que no se debe ingresar.

  B. Dada la lista generada en el inciso anterior, armar tres listas: una por cada sensor (el orden de los
     elementos tiene que ser el mismo que en la lista original). Luego, imprimir las tres listas.

*/

#include<iostream>
#include<string>

using namespace std;

struct BridgeSensorData {
  string sensorLocation;
  string licencePlate;
  float speed;
};

struct Node {
  BridgeSensorData data;
  Node *next;
};

void printList(Node* head) {
  cout << "\n";

  for (Node *current = head; current != nullptr; current = current->next) {
    cout << "current->data.licencePlate: " << current->data.licencePlate << "\n";
    cout << "current->data.sensorLocation: " << current->data.sensorLocation << "\n";
    cout << "current->data.speed: " << current->data.speed << "\n";
  }

  cout << endl;
}

Node* insertSorted(Node*& head, Node* newNode) {
  if (head == nullptr || head->data.licencePlate >= newNode->data.licencePlate) {
    newNode->next = head;
    head = newNode;
    return head;
  }

  Node *current = head;
  while (current->next != nullptr) {
    bool isNewPlateGreater = current->next->data.licencePlate < newNode->data.licencePlate;
    bool samePlateDifferentLocation = !isNewPlateGreater &&
                                      current->next->data.licencePlate == newNode->data.licencePlate &&
                                      current->next->data.sensorLocation < newNode->data.sensorLocation;

    if (isNewPlateGreater || samePlateDifferentLocation) {
      break;
    }

    current = current->next;
  }

  newNode->next = current->next;
  current->next = newNode;

  return head;
}

Node* createNewNode(Node* head, BridgeSensorData sensorInfo) {
  Node* sensorInformationNode = new Node();

  sensorInformationNode->data.speed = sensorInfo.speed;
  sensorInformationNode->data.licencePlate = sensorInfo.licencePlate;
  sensorInformationNode->data.sensorLocation = sensorInfo.sensorLocation;

  head = insertSorted(head, sensorInformationNode);
  return head;
}

Node* takeUserPrompt(Node* head) {
  BridgeSensorData sensorInfo;

  cout << "Ingresá la patente del auto: ";
  cin >> sensorInfo.licencePlate;

  while (sensorInfo.licencePlate != "aaa99") {
    cout << "Ingresá la localización del sensor ('norte', 'sur', 'medio'): ";
    cin >> sensorInfo.sensorLocation;

    cout << "Ingresá la velocidad del vehículo: ";
    cin >> sensorInfo.speed;

    head = createNewNode(head, sensorInfo);

    cout << "Ingresá la patente de otro auto: ";
    cin >> sensorInfo.licencePlate;
  }

  return head;
}

int main () {
  Node *head = nullptr;

  head = takeUserPrompt(head);
  printList(head);

  return 0;
}

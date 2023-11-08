/*

  Generar una lista con los datos personales de los alumnos de un colegio 
   - legajo, 
   - apellido y nombre
   - DNI) 

  y las notas de tres materias: 
   - matemática,
   - literatura 
   - geografía (para cada alumno se cargarán las tres materias). 

  Las notas pueden ir de 1 a 10 y se debe validar que el usuario no ingrese notas incorrectas,
  volviendo a pedir una nueva nota cada vez que ingrese una incorrecta, hasta que ingrese un valor
  en el rango indicado. Se pide informar la cantidad de alumnos que aprobaron las tres materias
  (se aprueba con 7) y el porcentaje que representan los aprobados sobre el total de alumnos.

*/

#include <iostream>
#include "../../explanations/merge/utils.cpp"

using namespace std;

struct Subject {
  int maths;
  int literature;
  int geography;
};

struct Student {
  string name;
  int DNI;
  int studentRecord;
  Subject subjects;
};

bool compareStudentByRecord(const Student &student1, const Student &student2) {
  return student1.studentRecord < student2.studentRecord;
}

void printList(Node<Student> *head) {
  for (Node<Student> *aux = head; aux != nullptr; aux = aux->next) {
    cout << "aux->data.name: " << aux->data.name << "\n";
    cout << "aux->data.DNI: " << aux->data.DNI << "\n";
    cout << "aux->data.studentRecord: " << aux->data.studentRecord << "\n";
    cout << "aux->data.maths: " << aux->data.subjects.maths << "\n";
    cout << "aux->data.literatura: " << aux->data.subjects.literature << "\n";
    cout << "\n";
  }

  cout << endl;
}

int main () {

  return 0;
}

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
  int maths = -1;
  int literature = -1;
  int geography = -1;
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
    cout << "aux->data.geography: " << aux->data.subjects.geography << "\n";
    cout << "\n";
  }

  cout << endl;
}

void addStudentMark(string subjectName, int &mark) {
  do {
    cout << subjectName;
    cin >> mark;
    
  } while(mark < 1 || mark > 10);
}

Student addFields(Student newStudent) {
  cout << "Ingresá nombre y apellido: ";
  cin >> newStudent.name;

  cout << "Ingresá DNI: ";
  cin >> newStudent.DNI;

  cout << "Ingresá el legajo del estudiante: ";
  cin >> newStudent.studentRecord;

  cout << "Ingresá las notas (entre 1 y 10) para ";
  addStudentMark("Matemática: ", newStudent.subjects.maths);
  addStudentMark("Literatura: ", newStudent.subjects.literature);
  addStudentMark("Geografía: ", newStudent.subjects.geography);

  return newStudent;
}

Node<Student>* addStudentToList(Node<Student> *head) {
  int shouldFinish = 1;

  while (shouldFinish != 0) {
    Student newStudent;
    newStudent = addFields(newStudent);
    head = insertSorted(head, createNewNode<Student>(newStudent), compareStudentByRecord);

    cout << "Ingrese 1 para continuar la carga o 0 para finalizar: ";
    cin >> shouldFinish;
  }

  return head;
}

void countApprovedStudents(Node<Student> *head) {
  int studentsApprobedCounter = 0;

  for (Node<Student> *current = head; current != nullptr; current = current->next) {
    int average = (current->data.subjects.geography + current->data.subjects.literature + current->data.subjects.maths) / 3;

    if (average >= 7) studentsApprobedCounter++;
  }

  cout << "La cantidad de alumnos que aprobaron las tres materias es de: " << studentsApprobedCounter << endl;
}

int main () {
  Node<Student> *studentsList = nullptr;
  
for (int i = 0; i < 10; i++) {
    Student student;
    student.name = "Estudiante " + to_string(i);
    student.DNI = 1000000 + i;
    student.studentRecord = 40000 + i;
    student.subjects.maths = i + 1;
    student.subjects.literature = i + 2;
    student.subjects.geography = i + 3;

    studentsList = insertSorted(studentsList, createNewNode<Student>(student), compareStudentByRecord);
}
  cout << "First List: " << endl;
  printList(studentsList);
  cout << endl;

  studentsList = addStudentToList(studentsList);
  printList(studentsList);

  countApprovedStudents(studentsList);

  return 0;
}

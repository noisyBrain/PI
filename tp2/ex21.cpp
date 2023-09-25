/*

  Escribir un programa que almacene en un arreglo los datos de los alumnos de una escuela
  luego de finalizado el año académico.
  Como máximo, puede haber 5000 alumnos. De cada alumno se debe guardar el nombre y la
  calificación obtenida en el primer, segundo y tercer trimestre del año académico.
  Imprimir el listado de nombres de alumnos mostrando un mensaje de "APTO" si el alumno
  supera o iguala la calificación de 5 para todas las notas o "NO APTO" si no lo alcanza.
  Utilizar un arreglo como campo del struct para almacenar las tres calificaciones.

*/

/*

   1. almacenar un arreglo de alumnos (max 5000)
   2. guardar nombre y calificación (1er, 2do y 3er trimestre)
   3. imprimir los nombres de los alumnos seguido de:
    3.1 apto si supera el promedio de 5 entre los 3 trimestres
    3.2 no apto si no supera el promedio de 5 entre los 3 trimestres

*/

#include<iostream>
#include<string>

using namespace std;

const int QUARTERS = 3;
const int MAX_STUDENTS = 5000;

struct Student {
  string name;
  int grades[QUARTERS];
};

void isApproved(int average) {
  average >= 5
    ? cout << "APTO" << endl
    : cout << "NO APTO" << endl;
}

void averageGrade(int grades[]) {
  int totalSum = 0;

  for (int i = 0; i < QUARTERS; i++) {
    totalSum += grades[i];
  }

  int average = totalSum / QUARTERS;
  cout << "ESTE ES EL AVERGE: " << average << endl;

  isApproved(average);
}

void printGrades(int grades[]) {
  for (int i = 0; i < QUARTERS; i++) {
    if (i + 1 == QUARTERS) cout << grades[i] << endl;
    else cout << grades[i] << ", ";
  }
}

void printStudents(Student students[], int ld) {
  for (int j = 0; j < ld; j++) {
    cout << "Nombre: " << students[j].name << endl;
    printGrades(students[j].grades);
    averageGrade(students[j].grades);
  }
}

void insertStudent(Student students[], Student newStudent, int &ld) {
  if (ld < MAX_STUDENTS) {
    students[ld] = newStudent;
    ld++;
  }
}

void promptStudent(Student students[], int &ld) {
  Student newStudent;

  cout << "Ingresá el nombre del alumno (x para salir): ";
  getline(cin >> ws, newStudent.name);
  
  while (newStudent.name != "x") {
    for (int k = 0; k < QUARTERS; k++) {
      cout << "Ingresá, de a una, las calificaciones del alumno: ";
      cin >> newStudent.grades[k];
    }

    insertStudent(students, newStudent, ld);

    cout << "Ingresá el nombre del alumno: ";
    getline(cin >> ws, newStudent.name);
  }
}

int main () {
  Student students[MAX_STUDENTS];
  int ld = 0;

  promptStudent(students, ld);
  printStudents(students, ld);

  return 0;
}

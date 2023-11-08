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

struct Node {
  Student data;
  Node *next;
};

int main () {

  return 0;
}

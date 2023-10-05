/*

  La universidad posee información histórica sobre los estudiantes (no más de 1000) de una materia determinada. 
  De cada uno almacena: nombre y apellido, legajo, cantidad de inasistencias a clase, calificación obtenida. 
  Almacenar esta información en un arreglo de structs. Se pide:

  a) Imprimir nombre y apellido de los alumnos que tuvieron más de 5 inasistencias.
  b) Imprimir número de legajo de los alumnos cuya calificación promedio sea mayor o igual a la calificación
      promedio total (requiere calcular un promedio de las calificaciones de todos los alumnos en el listado).
  c) Imprimir el número de legajo de aquellos alumnos que tienen promedio mayor o igual a nueve.
  d) Dado el legajo de un alumno, eliminarlo del listado.

Nota: analizar si es posible reutilizar código en más de uno de los incisos.

*/

#include<iostream>
#include<string>

using namespace std;

const int MAX = 1000;

struct Student {
  string firstName;
  string lastName;
  string studentRecord;
  int absences;
  float average;
};

float totalAverageGrades(Student students[], int ld) {
  float totalAverage = 0;

  for (int i = 0; i < ld; i++) {
    totalAverage += students[i].average;
  }

  return totalAverage / ld;
}

void printStudents(Student students[], int ld) {
  float totalAverage = 0;

  for (int j = 0; j < ld; j++) {
    totalAverage += students[j].average;

    if (students[j].absences > 5) {
      cout << "\nEstudiantes con más de 5 inasistencias: " << endl;
      cout << "Nombre: " << students[j].firstName << endl;
      cout << "Apellido: " << students[j].lastName << endl;
      cout << "\n" << endl;
    }

    if (students[j].average >= 9) {
      cout << "\nLegajo de alumnos con promedio mayor a 9: " << students[j].studentRecord << endl;
    }

  }

  totalAverage /= ld;

  for (int k = 0; k < ld; k++) {
    if (students[k].average >= totalAverage) {
      cout << "\nLegajo de alumnos con promedio mayor a la media: " << students[k].studentRecord << endl;
    }
  }

}

int main () {
  Student students[MAX];
  int ld = 100;

  students[0] = {"Juan", "Perez", "0001", 4, 8.5};
  students[1] = {"Maria", "Gomez", "0002", 2, 9.2};
  students[2] = {"Carlos", "Lopez", "0003", 7, 7.8};
  students[3] = {"Ana", "Rodriguez", "0004", 3, 8.9};
  students[4] = {"Pedro", "Fernandez", "0005", 6, 6.5};
  students[5] = {"Luisa", "Martinez", "0006", 1, 9.7};
  students[6] = {"Sergio", "Torres", "0007", 8, 7.1};
  students[7] = {"Laura", "Sanchez", "0008", 0, 9.8};
  students[8] = {"Diego", "Rios", "0009", 5, 6.9};
  students[9] = {"Elena", "Chavez", "0010", 2, 9.5};
  students[10] = {"Miguel", "Garcia", "0011", 4, 8.0};
  students[11] = {"Carolina", "Luna", "0012", 6, 7.4};
  students[12] = {"Roberto", "Silva", "0013", 3, 9.0};
  students[13] = {"Julia", "Ortega", "0014", 7, 6.2};
  students[14] = {"Eduardo", "Diaz", "0015", 1, 9.9};
  students[15] = {"Patricia", "Vargas", "0016", 5, 7.7};
  students[16] = {"Hector", "Reyes", "0017", 0, 9.6};
  students[17] = {"Isabel", "Mendoza", "0018", 8, 6.7};
  students[18] = {"Javier", "Hernandez", "0019", 4, 8.3};
  students[19] = {"Olga", "Lopez", "0020", 2, 9.3};
  students[20] = {"Alejandra", "Ramirez", "0021", 5, 7.2};
  students[21] = {"Andres", "Gonzalez", "0022", 3, 8.8};
  students[22] = {"Fernanda", "Diaz", "0023", 1, 9.9};
  students[23] = {"Ricardo", "Gutierrez", "0024", 7, 6.3};
  students[24] = {"Lucia", "Fernandez", "0025", 0, 9.7};
  students[25] = {"Gabriel", "Silva", "0026", 4, 8.4};
  students[26] = {"Natalia", "Lopez", "0027", 6, 7.0};
  students[27] = {"Martin", "Perez", "0028", 2, 9.6};
  students[28] = {"Valentina", "Torres", "0029", 8, 6.1};
  students[29] = {"David", "Martinez", "0030", 4, 8.2};
  students[30] = {"Sofia", "Ortega", "0031", 6, 7.5};

  printStudents(students, ld);
  
  return 0;
}

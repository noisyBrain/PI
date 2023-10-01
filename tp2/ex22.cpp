/*

  Realizar un programa que almacene en un arreglo la lista de invitados a una fiesta.
  El salón donde se realizará tiene capacidad máxima para 150 personas.
  De cada invitado se conoce nombre, apellido, sexo y edad.
  Se ingresarán datos hasta que el nombre sea igual a “ZZZ” o hasta que la capacidad del salón esté completa.
  Una vez finalizada la carga:

  a) Informar la cantidad de invitados que asistirán a la fiesta.
  b) Realizar una función que liste los nombres de las mujeres cuya edad sea <= 20.
  c) Realizar una función que, dado un apellido y nombre, permita eliminar un invitado en caso de no poder
  asistir.

*/

#include<iostream>
#include<string>

using namespace std;

const int MAX_CAP = 150;

struct Guest {
  string firstName;
  string lastName;
  string gender;
  int age;
};

int main () {
  Guest guests[MAX_CAP];

  
  return 0;
}

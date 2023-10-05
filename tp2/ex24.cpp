/*

  Implementar un programa que almacene en un arreglo estático los datos de los ciudadanos que solicitaron un
  certificado de antecedentes en el Registro Nacional de las Personas.
  De cada ciudadano se conoce: 
    nombre y apellido,
    fecha de nacimiento (tipo long: formato AAAAMMDD),
    dirección,
    número de documento,
    tipo de documento (tipo int: 1 -DNI-, 2 -Pasaporte-, 3 -Otro-),
    sexo (tipo char: 'M', 'F').

  a) Hacer un módulo de carga del arreglo, utilizando una condición de corte adecuada. Se debe validar el
  tipo de documento (1, 2 ó 3) y dejar al usuario en un bucle mientras ingrese un número inválido.

  b) Imprimir el listado, con el siguiente formato de ejemplo:
    Nombre y apellido: Juan Perez
    Dirección: Levalle 132
    Fecha de nacimiento: 27/10/1979
    Tipo de documento: DNI
    Número de documento: 27439221
    Sexo: masculino
  - La fecha debe mostrarse en formato dd/mm/aa. El tipo de documento debe mostrarse con su
  nombre. El género debe mostrar la palabra completa.

  c) Implementar un módulo que, dado el arreglo original, cargue en otro arreglo los ciudadanos de sexo
  masculino únicamente. Imprimir este nuevo arreglo.

  d) Hacer lo mismo que en el punto anterior pero obteniendo sólo las mujeres. Modularizar para no repetir
  código.

*/

#include<iostream>
#include<string>

using namespace std;

struct Citizen {
  string firstName;
  string lastName;
  string birthDate;
  string address;
  int documentType;
  string documentNumber;
  char gender;
};

int main () {
  
  return 0;
}

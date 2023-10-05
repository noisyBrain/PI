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
  - La fecha debe mostrarse en formato dd/mm/aa.
  - El tipo de documento debe mostrarse con su nombre. 
  - El género debe mostrar la palabra completa.

  c) Implementar un módulo que, dado el arreglo original, cargue en otro arreglo los ciudadanos de sexo
  masculino únicamente. Imprimir este nuevo arreglo.

  d) Hacer lo mismo que en el punto anterior pero obteniendo sólo las mujeres. Modularizar para no repetir
  código.

*/

#include<iostream>
#include<string>

using namespace std;

struct Citizen {
  string name;
  string birthDate;
  string address;
  int documentType;
  string documentNumber;
  char gender;
};

void searchCitizen(Citizen citizens[], int ld) {
  int documentType = 0;
  string documentNumber = "";

  do {
    cout << "[1] DNI\n";
    cout << "[2] Pasaporte\n";
    cout << "[3] Otro\n";
    cout << "\nIngrese el Tipo de Documento...";
    cin >> documentType;

    if (documentType < 1 || documentType > 3) {
      cout << "Tipo de documento inválido, intente nuevamente..." << endl;
    }

  } while(documentType < 1 || documentType > 3);


  cout << "Ingresá el número de documento todo junto, sin puntos: ";
  cin >> documentNumber;

  for (int i = 0; i < ld; i++) {
    if (citizens[i].documentNumber == documentNumber) {
      cout << "Nombre y apellido: " << citizens[i].name << "\n";
      cout << "Dirección: " << citizens[i].address << "\n";
      cout << "Fecha de nacimiento: " << citizens[i].birthDate << "\n"; // TODO: normalize birthdate
      cout << "Tipo de documento: " << citizens[i].documentType << "\n";
      cout << "Numero de documento: " << citizens[i].documentNumber << "\n";
      cout << "Sexo: " << citizens[i].gender << "\n";
    }
  }

  cout << "No se encontró el ciudadano" << endl;
}

/*
  @PRE -> assumes that the array is already filled with citizens
*/
int main () {
  Citizen citizens[100];
  int ld = 10;

  citizens[0] = {"John Smith", "19900115", "123 Main St", 1, "123456789", 'M'};
  citizens[1] = {"Jane Doe", "19851210", "456 Elm St", 1, "987654321", 'F'};
  citizens[2] = {"Michael Johnson", "19780325", "789 Oak St", 2, "AB123456", 'M'};
  citizens[3] = {"Emily Davis", "19950903", "101 Pine St", 1, "456123789", 'F'};
  citizens[4] = {"Robert Wilson", "19801020", "222 Maple St", 1, "789654123", 'M'};
  citizens[5] = {"Sarah Lee", "19870408", "333 Birch St", 2, "CD987654", 'F'};
  citizens[6] = {"David Brown", "20021205", "444 Cedar St", 1, "654321987", 'M'};
  citizens[7] = {"Laura Garcia", "19980214", "555 Redwood St", 1, "321987654", 'F'};
  citizens[8] = {"William Taylor", "19821030", "666 Spruce St", 3, "XYZ123", 'M'};
  citizens[9] = {"Olivia Martinez", "20000607", "777 Sequoia St", 1, "987123456", 'F'};
  
  searchCitizen(citizens, ld);

  return 0;
}

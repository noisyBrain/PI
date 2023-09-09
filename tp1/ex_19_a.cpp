/*

Sin modificar el código existente, completar las líneas punteadas en cada uno de los programas mostrados a
continuación. Suponer que en cada uno se han importado los encabezados necesarios y se usa el espacio de
nombres estándar:

*/

// PROGRAMA 1

#include <iostream>
#include <string>

using namespace std;


string nombreEnMayusculas(string cadena) {
  for (int i = 0; i < cadena.length(); i++) {
    cadena[i] = toupper(cadena[i]);
  }

  return cadena;
}

int main() {
  string nombre;

  cout << "Cuál es tu nombre?: ";
  getline(cin>>ws, nombre);

  nombreEnMayusculas(nombre);

  cout << "Hola, " << nombre << "!" << endl;
  return 0;
}


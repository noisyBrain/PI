/* 

Dado el siguiente programa cuya función main está completa, implementar las funciones que falten para que
compile y realice las tres operaciones indicadas en el menú.

*/

#include <iostream>
#include <string>

using namespace std;

int cantidadVocales(string cadena) {
  int contadorVocales = 0;
  string vocales = "aeiou";

  for (int i = 0; i < cadena.length(); i++) {
    for (int j = 0; j < vocales.length(); j++) {

      if (vocales[j] == tolower(cadena[i])) {
        contadorVocales++;
      }
    }
  }

  return contadorVocales;
}

int contar(string cadena, char caracter) {
  int contadorCaracter = 0;

  for (int i = 0; i < cadena.length(); i++) {
    if (cadena[i] == caracter) {
      contadorCaracter++;
    }
  }

  return contadorCaracter;
}

string caracteresPares(string cadena) {
  string caracterPar = "";

  for (int i = 0; i < cadena.length(); i++) {
    if (i % 2 == 0) {
      caracterPar += cadena[i];
    }
  }

  return caracterPar;
}

int main() {
 int opcion;

 do {
   string cadena;
   cout << "Ingresar frase: ";

   getline(cin>>ws, cadena);

   cout << "MENÚ: " << endl;
   cout << "1. Cantidad total de vocales (mayúsculas y minúsculas)." << endl;
   cout << "2: Contar cuántas veces aparece un carácter." << endl;
   cout << "3: Mostrar caracteres en posiciones (índice) pares." << endl;
   cout << "0: Salir." << endl;
   cout << "Opción elegida: ";
   cin >> opcion;

   switch (opcion) {
     case 1:
       cout << "Cantidad de vocales: " << cantidadVocales(cadena) << endl;
       break;

     case 2:
       cout << "Ingresar carácter a contar: ";
       char caracter;
       cin >> caracter;
       cout << "Cantidad encontrada: " << contar(cadena, caracter) << endl;
       break;

     case 3:
       cout << caracteresPares(cadena) << endl;
       break;

     case 0:
       break;

     default:
      cout << "Opción no válida" << endl;
       break;
   }
 } while (opcion != 0);

  return 0;
}

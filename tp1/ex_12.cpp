/*

Leer una frase de teclado e informar la longitud de la última palabra. Se considera al espacio como separador
de palabras.
Precondición: el string no finaliza con espacios.

*/

#include <string>
#include<iostream>

using namespace std;

int main () {
  string promptUser = "";
  string aux = "";
  int counter = 0;

  cout << "Ingresá una cadena: " ;
  getline(cin >> ws, promptUser);

  for (int i = 0; i < promptUser.length(); i++) {
    aux += promptUser[i]; 

    if (promptUser[i] == ' ') {
      aux = "";
    }
  }

  cout << "La última palabra tiene: " << aux.length() << " caracteres" << endl;

  return 0;
}

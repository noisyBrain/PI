/*

Implementar un programa que solicite una palabra y verifique si es palíndromo. Una palabra es palíndromo si
puede leerse igual de izquierda a derecha que de derecha a izquierda.
Precondición: todos los caracteres son minúsculas y no se ingresarán vocales acentuadas ni diéresis.

*/

#include<string>
#include<iostream>

using namespace std;

int main () {
  string promptUser = "";
  string invertedString = "";

  cout << "Ingresá una palabra para saber si es palíndromo: " << endl;
  cin >> promptUser;

  for (int i = promptUser.length() - 1; i >= 0; i--) {
    invertedString += promptUser[i];
  }

  if (promptUser == invertedString) {
    cout << promptUser << " es palíndromo!" << endl;

  } else {
    cout << promptUser << " no es palíndromo :(" << endl;
  }
  
  return 0;
}

/*

Leer una cadena de caracteres de teclado e, independientemente de cómo ha sido ingresada, convertir la
primera letra a mayúscula y el resto a minúsculas. Considerar que la cadena puede estar vacía.
Nota: la función toupper(carácter) convierte un carácter a mayúscula si éste es una letra de la A a la Z (si es
cualquier otro carácter, incluso letras acentuadas, no hace nada). De la misma forma, tolower(carácter) convierte
a minúscula.
Precondición: si la cadena no está vacía, el primer carácter es una letra.
Ejemplo: si se ingresa la cadena “EsTO ES UNa cadENA de Texto”, el resultado debería ser “Esto es una cadena
de texto”

*/

#include <cctype>
#include<string>
#include<iostream>

using namespace std;

int main () {
  string promptUser = "";
  string aux = "";

  cout << "Ingresá un texto para procesarlo: " << endl;
  getline(cin >> ws, promptUser);

  for (int i = 0; i < promptUser.length(); i++) {
    if (i == 0) {
      aux = toupper(promptUser[i]);
      continue;
    }

    aux += tolower(promptUser[i]);
  }

  cout << "El texto formateado es: " << aux << endl;
  
  return 0;
}

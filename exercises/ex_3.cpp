/*
  Leer tres letras desde teclado e indicar cuál de ellas
  viene primero en el alfabeto.
*/

#include <iostream>
#include <string>

using namespace std;

int main () {

  char letters[3];

  cout << "Ingresá tres letras juntas: ";
  cin >> letters[0] >> letters[1] >> letters[2];

  if (letters[0] < letters[1] && letters[0] < letters[2]) {
      cout << "La primera letra en el alfabeto es: " << letters[0] << endl;

  } else if (letters[1] < letters[2]) {
      cout << "La primera letra en el alfabeto es: " << letters[1] << endl;

  } else {
      cout << "La primera letra en el alfabeto es: " << letters[2] << endl;
  }

  return 0;
}

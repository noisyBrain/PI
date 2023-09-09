/*

Leer una cadena de caracteres (string) de teclado e imprimirla en orden inverso

*/

#include<string>
#include<iostream>

using namespace std;

int main () {
  string promptUser = "";
  string invertedString = "";

  cout << "Ingresá una cadena de texto para imprimirla al revés: " << endl;
  getline(cin >> ws, promptUser);

  for (int i = promptUser.length() - 1; i >= 0; i--) {
    invertedString += promptUser[i];
  }

  cout << "La cadena invertida es: " << invertedString << endl;

  return 0;
}

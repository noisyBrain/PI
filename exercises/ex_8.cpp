/*

Leer una secuencia de caracteres que finaliza con la letra minúscula 'n', la cual debe ser procesada. Contabilizar
la cantidad de cada una de las letras vocales minúsculas. También informar la cantidad de caracteres leídos en
total y el porcentaje de letras vocales minúsculas encontradas en la secuencia.

*/

/*

¿Qué tiene que hacer el programa?
1. Leer una secuencia de caracteres. La secuencia finaliza con 'n'.
2. Contabilizar las vocales minúsculas.
3. Informar cantidad de caracteres leídos en total.
4. Informar el porcentaje de vocales minúsculas.

*/

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string userInput;
  string vowels = "aeiou";
  
  int lastChar; 
  int vowelsCounter = 0;

  // Validation: Prompt for input until last character is 'n'
  do {
    cout << "Ingresá una cadena de caracteres terminada en 'n': " << endl;
    cin >> userInput;

    lastChar = userInput.length() - 1;
  } while(userInput[lastChar] != 'n');

  for (int i = 0; i < userInput.length(); i++) {
    for (int j = 0; j < vowels.length(); j++) {

      if (tolower(userInput[i]) == vowels[j]) {
        vowelsCounter++;
      }
    }
  }

  float averageOfVowels = (100 * vowelsCounter) / static_cast<float>(userInput.length());

  cout << "La cantidad de vocales en el texto es de: " << vowelsCounter << endl;
  cout << "La cantidad de caracteres leídos es de: " << userInput.length() << endl;
  cout << "El promedio de vocales en el texto es de: " << averageOfVowels << '%' << endl;

  return 0;
}

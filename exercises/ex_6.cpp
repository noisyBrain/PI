/*

Escribir un programa que calcule la suma de una determinada cantidad de elementos de la serie armónica:
1/1 + 1/2 + 1/3 + … + 1/n, donde n se especifica por el usuario

*/

#include<iostream>

using namespace std;

int main () {
  int userInput;
  float result = 0;

  cout << "Ingresá la cantidad de números que querés calcular de la serie armónica: ";
  cin >> userInput;

  for (float i = 1; i <= userInput; i++) {
    result += 1 / i;
  }

  cout << "Tu resultado es: " << result << endl;
  
  return 0;
}

/*

Escribir un programa que visualice el más grande, el más pequeño y el promedio de N números enteros. El valor
de N se solicita al usuario al comienzo del programa y luego se le permite introducir los números.

*/

#include<iostream>

using namespace std;

int main () {
  int userInput = 0;
  int biggestNumber = 0;
  int smallestNumber = 0;
  int totalSum = 0;

  float totalNumbers = 0;
  float average = 0;

  cout << "Ingresá la cantidad de números que querés calcular: " << endl;
  cin >> totalNumbers;

  cout << "Ahora ingresá un número: " << endl;
  cin >> userInput;

  smallestNumber = userInput;
  biggestNumber = userInput;
  totalSum += userInput;

  for (int i = 1; i < totalNumbers; i++) {
    cout << "Ahora ingresá un número: " << endl;
    cin >> userInput;

    totalSum += userInput;

    if (userInput > biggestNumber) {
      biggestNumber = userInput;
    }  

    if (userInput < smallestNumber) {
      smallestNumber = userInput;
    }
    
  }

  average = totalSum / totalNumbers;

  cout << "El mayor número ingresado es: " << biggestNumber << endl;
  cout << "El menor número  ingresado es: " << smallestNumber << endl;
  cout << "El promedio es: " << average << endl;
  
  return 0;
}

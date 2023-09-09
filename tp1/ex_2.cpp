/*
  Contar la cantidad de números negativos leídos desde teclado.
  La serie termina con el valor cero (0), el cual no debe procesarse.
  ¿Qué cambiaría si debiera procesarse también el último número ingresado (0)?
*/

#include <iostream>

using namespace std;

int main() {
  int number = 0;
  int negativeCounter = 0;

  do {
    cout << "Ingresá un número: ";
    cin >> number;

    if (number < 0) {
      negativeCounter++;
    }
    
  } while(number != 0);

  cout << "La cantidad de números negativos que ingresaste fue: "
       << negativeCounter << '\n';

  return 0;
}

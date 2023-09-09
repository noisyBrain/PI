/*

Escribir un programa que, dado un número (entero largo) expresado en segundos, informe el equivalente en
horas, minutos y segundos

*/

#include <iostream>

using namespace std;

int main() {

  long totalSeconds;
  int hours, minutes, seconds;

  cout << "Ingresá los segundo: ";
  cin >> totalSeconds;

  hours = totalSeconds / 3600;       // 3600 = 1 hour
  totalSeconds %= 3600;

  minutes = totalSeconds / 60;
  seconds = totalSeconds % 60;
  
  cout << "Equivalente en horas: " << hours << ":" << minutes << ":" << seconds << '\n';

  return 0;
}

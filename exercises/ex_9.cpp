/*

Escribir un bucle para validar lo ingresado por el usuario: se debe solicitar el ingreso de un carácter y sólo se debe
interrumpir el bucle cuando el usuario haya ingresado el carácter 's' o el carácter 'n'. La solicitud de ingreso del
dato debe hacerse al menos una vez antes de evaluar si el bucle debe interrumpirse o no. No utilizar "while true"
como condición. A continuación, si el usuario ingresó la letra 's', imprimir "usted eligió SÍ" y, si ingresó la 'n'
imprimir "usted eligió NO".
Nota: para evaluar la condición de corte del bucle considerando mayúsculas y minúsculas es posible utilizar las
funciones toupper(carácter) y tolower(carácter), que convierten el carácter pasado por parámetro a mayúscula
o a minúscula respectivamente (si el carácter no es una letra, no se modifica).

*/

#include <cctype>
#include <iostream>
using namespace std;

int main () {
  char userInput;

  do {
    cout << "Ingrese 's' para 'Sí' y 'n' para 'No'... " << endl;
    cin >> userInput;

  } while(tolower(userInput) != 'n' && tolower(userInput) != 's');

  userInput == 's' 
    ? cout << "Elegiste 'Sí'!" << endl
    : cout << "Elegiste 'No'!" << endl;
  
  return 0;
}

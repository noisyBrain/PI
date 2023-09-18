/*

Escribir un programa que permita al usuario gestionar los pagos de la cuota de un club.
  a) Para ello, almacenar en un arreglo los números de DNI de los socios que pagaron.
  El club no tiene más de 200 socios.

  b) Permitir al usuario buscar un DNI en el arreglo y, si el DNI está en el arreglo, imprimir "Cuota al día".
  Si no está, imprimir "Socio con deuda".

  c) También se debe permitir al usuario eliminar un DNI del arreglo, en caso de haberlo ingresado erróneamente.

  d) Finalmente, imprimir todo el arreglo.

*/

#include<iostream>

using namespace std;

const int PD = 200; // Physical Dimension

bool didUserPaid() {
  char userResponse = ' ';

  do {
    cout << "Desea pagar la cuota? s/n..." << endl;
    cin >> userResponse;

    bool invalidInput = tolower(userResponse) != 'y' && tolower(userResponse) != 'n';

    if (invalidInput) {
      cout << "Entrada inválida, volvé a intentarlo!\n";
    }

  } while(tolower(userResponse) != 'y' && tolower(userResponse) != 'n');

  return userResponse == 'y';

};


int main () {
  int ld = 0; // logic dimension;

  didUserPaid();
  
  return 0;
}

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

int prinMenu() {
  cout << "*** Gestión de cuotas ***" << endl;
  cout << "[0] Para salir" << endl;
  cout << "[1] Para agregar un DNI de socio" << endl;
  cout << "[2] Para buscar un socio" << endl;
  cout << "[3] Para eliminar el DNI de un socio" << endl;
}

int askForDNI() {
  int DNI = 0;

  cout << "Ingresá tu DNI (todo junto, sin puntos): ";
  cin >> DNI;

  return DNI;
}

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

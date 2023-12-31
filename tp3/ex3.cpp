/*

  Dados los siguientes punteros a char:

  char* x = new char;
  char* z = x;

  Escribir y ejecutar las instrucciones para hacer lo siguiente:
    a) Almacenar el carácter 'M' en el espacio de memoria apuntado por x.
    b) Imprimir el carácter apuntado por x.
    c) Almacenar el carácter 'P' en el espacio de memoria apuntado por z.
    d) Imprimir el carácter apuntado por z y luego el apuntado por x.
      ¿Qué carácter crees que imprimirá cada una y por qué?
    e) Eliminar el dato apuntado por x.
      ¿Qué sucedería si a continuación se intentara imprimir *z y por qué?
    f) Obtener un nuevo espacio de memoria para un char, almacenando su dirección en x.
    g) Permitir al usuario ingresar un char por teclado y almacenarlo en el nuevo espacio apuntado por x.
    h) Si el carácter ingresado por el usuario en el inciso anterior es '*', imprimir "asterisco".

*/

#include<iostream>

using namespace std;

int main () {
  char *x = new char;
  char *z = x;

  *x = 'M';
  cout << "Caracter almacenado en x: " << *x << endl;

  *z = 'P';
  /*
     ambos imprimirán 'P' porque los dos están apuntando a la misma dirección de memoria,
     por lo que cuando a *z se le asignó 'P' también se modificó en 'x'
  */
  cout << "Caracter almacenado en z: " << *z << endl;
  cout << "Caracter almacenado en X: " << *x << endl;

  delete x;
  /*
     z queda como un 'dangling pointer' por lo que cuando se intente imprimir, pueden ocurrir
     comportamientos inesperados porque el SO pudo haber reemplazado ese dato por otro en ese momento
  */
  cout << "Imprimir z: " << *z << endl;

  x = new char;

  cout << "Ingresá un caracter: ";
  cin >> *x;

  if (*x == '*') cout << "asterisco" << endl;

  
  return 0;
}

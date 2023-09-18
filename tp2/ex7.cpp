/*

A pesar de que el programa a continuación no tiene errores de sintaxis, sí tiene varios otros problemas. ¿Cuáles
son? ¿Cómo podrían corregirse?

*/

// FIXME: no se incluyeron las cabeceras <iostream> y std
// (las incluí yo para que no me tire error)

#include<iostream>

using namespace std;

// WARN: "airear" el código (darle espacio para mejor legibilidad)
const int MAX=3;

int cargar(float arreglo[], int dl){
  for (int i=0; i<MAX; i++){
    cout << "Número para almacenar: ";
    cin >> arreglo[i];
  }
  // WARN: ¿es necesario el return?
  return dl;
}

int main(){
  // FIXME: mejorar el naming para numeros
  // siendo que es un array de floats (arrayDeFloats, por ejemplo)
  float numeros[MAX];

  // FIXME: mejorar naming para cantidad
  // siendo que hace referencia a la dimensión lógica (dimensiónLógica, por ejemplo)
  int cantidad = 0;

  cargar(numeros, cantidad);

  // BUG: falta la finalización del programa (return 0)
}

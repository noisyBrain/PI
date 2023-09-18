/*

  Considerar la definición de función dos():

*/

void dos(int a[], int cuantos) {
    for (int indice = 0; indice < cuantos; indice++) {
    a[indice] = 2;
  }
}

int main () {
  // ¿Cuáles de las siguientes son llamadas de función aceptables?

  int mi_arreglo[29]; // -> declaración del array

  dos(mi_arreglo, 29); // -> ✅ porque le paso el arreglo y la cantidad (toda) de elementos a iterar
  dos(mi_arreglo[], 29); // -> 🚫 porque le estoy pasando un array sin declarar la posición, no es válido
  dos(mi_arreglo, 10); // -> ✅ porque le paso el arreglo y la cantidad de elementos a iterar (menor a la dimensión física)
  dos(mi_arreglo, 55); // -> 🚫 porque 59 es mayor a la dimensión física y se saldría del arreglo

  int tu_arreglo[100]; // -> declaración de tu_arreglo

  dos(tu_arreglo, 100); // -> ✅ es válido

  dos(mi_arreglo[3], 29); // -> 🚫 la función espera un array y se le está pasando un int (el valor en la 3 posción del array)
  
  return 0;
}

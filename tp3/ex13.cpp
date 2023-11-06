/*

  Dos sucursales de Fiestísima disponen cada una de una lista enlazada simple con el detalle de las ventas
  realizadas. De cada venta se conoce: 
    - código de producto 
    - cantidad vendida (un producto pudo haber sido vendido 0, 1 o más veces en la misma sucursal). 
  Las listas de ventas están ordenadas de menor a mayor por código de producto. 
  Realizar una función que reciba las dos listas y retorne una nueva lista unificando todas las
  ventas, ordenada por el mismo criterio. Utilizar un algoritmo destructivo (que reutilice los nodos de las listas
  originales). Agregar las funciones auxiliares que sean necesarias.

*/

#include<iostream>
#include<string>
#include "../../explanations/merge/resources_ex13.cpp"

int main () {
  Node *firstList = nullptr;
  Node *secondList = nullptr;
  
  firstList = insertSorted(firstList, createNewNode(1, 5));
  firstList = insertSorted(firstList, createNewNode(2, 3));
  firstList = insertSorted(firstList, createNewNode(3, 10));
  firstList = insertSorted(firstList, createNewNode(4, 150));
  firstList = insertSorted(firstList, createNewNode(5, 23));

  secondList = insertSorted(secondList, createNewNode(3, 121));
  secondList = insertSorted(secondList, createNewNode(5, 180));
  secondList = insertSorted(secondList, createNewNode(111, 83));
  secondList = insertSorted(secondList, createNewNode(1, 10));

  cout << "First List: " << endl;
  printList(firstList);
  cout << endl;
  cout << "Second List:" << endl;
  printList(secondList);

  cout << endl;
  cout << "Merged List:" << endl;
  Node* mergedList = merge(firstList, secondList);
  printList(mergedList);

  return 0;
}

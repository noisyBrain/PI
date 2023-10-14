/*

  Dados los siguientes structs:

  struct Producto {
    string descripcion;
    float precio;
  };

  struct Venta {
    Producto producto;
    int cantidad;
  };

  Escribir y luego ejecutar las instrucciones necesarias para:
  a) Declarar una variable puntero a Venta y reservar memoria.
  b) Pedir al usuario que ingrese una cantidad vendida, descripción de producto y precio de producto,
    almacenando los datos en la Venta apuntada por el puntero declarado en el inciso anterior.
  c) Restar un 15% al precio del Producto guardado en la Venta apuntada por el puntero.
  d) Imprimir la descripción del producto dentro de la Venta y monto total (precio del producto * cantidad).

*/

#include<iostream>
#include<string>

using namespace std;

struct Product {
  string description;
  float price;
};

struct Sale {
  Product product;
  int quantity;
};

int main () {
  Sale *salePointer = new Sale;

  cout << "Ingresá la cantidad vendida: ";
  cin >> salePointer->quantity;

  cout << "Ingresá la descripción del producto: ";
  getline(cin >> ws, salePointer->product.description);

  cout << "Ingresá el precio del producto: ";
  cin >> salePointer->product.price;

  float priceOff = salePointer->product.price - (salePointer->product.price * 0.15);
  cout << "El precio con el 15% de descuento es de: " << priceOff << endl;

  cout << "Descripción: " << salePointer->product.description << endl;
  cout << "Precio final: " << salePointer->product.price * salePointer->quantity << endl;
  
  return 0;
}

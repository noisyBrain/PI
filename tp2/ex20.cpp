/*

  Realizar un algoritmo que almacene información de, como máximo, 500 libros en un arreglo estático.
  Un libro se define como un struct con los siguientes campos: titulo, autor, ISBN, editorial, cantidadHojas.
  El algoritmo finaliza luego de cargar el libro "El hobbit", el cual debe procesarse o cuando
  ya no quede espacio en el arreglo (lo que suceda primero).
  Finalmente, imprimir el arreglo resultante mostrando todos los datos de cada libro.

*/

#include<iostream>
#include<string>

using namespace std;

const int MAX_BOOKS = 500; // Physic dimension

struct Book {
  string author;
  string publisher;
  string title;
  int pages;
  long ISBN;
};

void printBooks(Book arr[], int ld) {
  for (int i = 0; i < ld; i++) {
    cout << "\nTitulo: " << arr[i].title << endl;
    cout << "Autor: " << arr[i].author << endl;
    cout << "Editorial: " << arr[i].publisher << endl;
    cout << "Cantidad de páginas: " << arr[i].pages << endl;
    cout << "ISBN: " << arr[i].ISBN << endl;
  }
}

void insertInArray(Book arr[], Book newBook, int &ld) {
  if (ld < MAX_BOOKS) {
    arr[ld] = newBook;
    ld++;
  } else cout << "Almacenamiento lleno..." << endl;
}

void promptNewBook(Book arr[], int ld) {
  Book newBook;

  do {
    cout << "\nIngresá el título del libro: " << '\n';
    getline(cin >> ws, newBook.title);

    cout << "\nIngresá el autor del libro: " << '\n';
    getline(cin >> ws, newBook.author);

    cout << "\nIngresá la editorial del libro: " << '\n';
    getline(cin >> ws, newBook.publisher);

    cout << "\nIngresá la cantidad de páginas del libro: " << '\n';
    cin >> newBook.pages;

    cout << "\nIngresá el ISBN del libro: " << '\n';
    cin >> newBook.ISBN;

    insertInArray(arr, newBook, ld);

  } while(newBook.title != "EL HOBBIT");
    printBooks(arr, ld);

}

int main (int argc, char *argv[]) {
  int ld = 0; // Logic dimension
  Book books[MAX_BOOKS];

  promptNewBook(books, ld);

  return 0;
}

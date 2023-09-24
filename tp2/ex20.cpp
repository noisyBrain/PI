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
    cout << arr[i].title << endl;
    cout << arr[i].author << endl;
    cout << arr[i].publisher << endl;
    cout << arr[i].pages << endl;
    cout << arr[i].ISBN << endl;
    cout << '\n' << endl;
  }
}

void insertInArray(Book arr[], Book newBook, int &ld) {
  if (ld < MAX_BOOKS) {
    arr[ld] = newBook;
    ld++;
  } else cout << "Cartón lleno.." << endl;
}

void promptNewBook(Book arr[], int ld) {
  Book newBook;

  do {
    cout << "Ingresá el título del libro: " << endl;
    getline(cin >> ws, newBook.title);

    cout << "Ingresá el autor del libro: " << endl;
    getline(cin >> ws, newBook.author);

    cout << "Ingresá la editorial del libro: " << endl;
    getline(cin >> ws, newBook.publisher);

    cout << "Ingresá la cantidad de páginas del libro: " << endl;
    cin >> newBook.pages;

    cout << "Ingresá el ISBN del libro: " << endl;
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

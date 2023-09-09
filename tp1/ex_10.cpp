/*

Escribir un programa que imprima el menú mostrado a continuación y solicite al usuario elegir una opción, la
cual se debe ejecutar para luego volver a mostrar el menú repetidas veces, hasta que el usuario decida salir:
‘A’: Invertir número.
‘B’: Sumatoria de dígitos.
‘C’: Decir si son múltiplos.
‘D’: Salir.
Dependiendo del carácter ingresado por el usuario, realizar la acción indicada en el menú:

- A: leer un número e invertir sus dígitos para luego imprimirlo en orden inverso;
- B: solicitar un número e imprimir la suma de sus dígitos;
- C: solicitar el ingreso de dos números y decir si el primero es múltiplo del segundo;
- D: terminar el programa.

Si el usuario ingresa un carácter que no es la opción D, se debe ejecutar lo que corresponda y volver a mostrar
el menú para permitirle elegir otra opción. Si el carácter ingresado por el usuario no es A, B, C ni D, mostrarle un
mensaje de error y continuar mostrándole el menú y solicitando una opción hasta que ingrese una que sea válida.

*/

#include <cctype>
#include<iostream>
#include <unistd.h>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void clearScreen() {
  cout << "\033[2J\033[1;1H";
}

void clearAfterEnter() {
  cin.ignore();
  cin.get();
  clearScreen();
}

void showMenu() {
  cout << "// ---------------- Elegí tu opción: ---------------- // \n " << endl;
  cout << "A: Leer un número e invertir sus dígitos para luego imprimirlo en orden inverso." << endl;
  cout << "B: Sumatoria de dígitos." << endl;
  cout << "C: Decir si son múltiplos." << endl;
  cout << "D: Salir." << endl;
}

void showEndProgram() {
  cout << "Finalizando..." << endl;
  sleep(1);

  cout << GREEN << "\n// -------------------------------- //" << RESET << endl;
  cout << GREEN << "\t¡Programa Finalizando!" << RESET << endl;
  cout << GREEN << "// -------------------------------- //" << RESET << endl;
}

void startProgram(char &option) {

  clearScreen();
  showMenu();
  cin >> option;

  clearScreen();
}

void invertNumber(int &inputNumber) {
  int invertedNumber = 0;
  int aux = 0;

  while (inputNumber != 0) {
    aux = inputNumber % 10;
    invertedNumber = (invertedNumber * 10) + aux;
    inputNumber /= 10;
  }

  cout << CYAN << "\nTu número invertido es: " << RESET << invertedNumber << endl;
}

void sumDigits(int &inputNumber) {
  int aux = inputNumber;
  int lastDigit = 0;
  int digitsSum = 0;

  while (aux > 0) {
    lastDigit = aux % 10;
    digitsSum += lastDigit;
    aux /= 10;
  }

  cout << YELLOW << "\nLa suma de los dígitos es: " << RESET  << digitsSum << endl;
}

void isMultipleOf(int &firstNumber, int &secondNumber) {
  if (secondNumber % firstNumber == 0) {
    cout << firstNumber << MAGENTA << " es múltiplo de " << RESET << secondNumber << endl;

    clearAfterEnter();
    return;
  }

  cout << firstNumber << MAGENTA << " no es múltiplo de " << RESET << secondNumber << endl;
  clearAfterEnter();
}

int main () {
  char option = 'x';

  startProgram(option);

  while (toupper(option) != 'D') {
    switch (toupper(option)) {

      case 'A': {
        int promptNumber = 0;

        cout << CYAN << "\nIngresá un número para invertir sus dígitos..." << RESET << endl;
        cin >> promptNumber;

        invertNumber(promptNumber);

        clearAfterEnter();
        break;
      }

      case 'B': {
        int promptNumber = 0;

        cout << YELLOW << "\nIngresá un número para sumar todos sus dígitos..." << RESET << endl;
        cin >> promptNumber;

        sumDigits(promptNumber);

        clearAfterEnter();
        break;
       }

      case 'C': {
        int firstNumber = 0;
        int secondNumber = 0;

        cout << MAGENTA << "\nIngresá el primer número: " << RESET << endl;;
        cin >> firstNumber;
        cout << MAGENTA << "\nIngresá el segundo número: " << RESET << endl;
        cin >> secondNumber;

        isMultipleOf(firstNumber, secondNumber);
        break;
       }

      default:
        cout << RED << "\nIngresaste una opción inválida, volvé a intentarlo..." << RESET << endl;
        break;
    }

    showMenu();
    cin >> option;
    clearScreen();
  }

  showEndProgram();

  return 0;
}

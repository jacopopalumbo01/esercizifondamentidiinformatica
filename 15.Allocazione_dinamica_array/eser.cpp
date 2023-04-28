/*
Scrivere un programma che costruisca una matrice di dimensioni definite dall'utente. Tale matrice
deve essere riempita di zeri e poi distrutta.
*/
#include <iostream>
#include <iomanip>

using namespace std;

void createMatrix(int, int, int ** &);
void writeMatrix(int, int, int, int ** &);
void printMatrix(int, int, int ** &);
void deleteMatrix(int, int ** &);

int main(int argc, char const *argv[]) {
  int x, y, ** matrix;
  cout << "Inserire le dimensioni della matrice." << endl;
  cout << "x: ";
  cin >> x;
  cout << endl << "y: ";
  cin >> y;
  cout << endl;

  cout << "The address of the matrix is " << &matrix << endl;

  createMatrix(x, y, matrix);
  writeMatrix(x, y, 0, matrix);
  printMatrix(x, y, matrix);
  deleteMatrix(x, matrix);
  return 0;
}

void createMatrix(int x, int y, int ** &matrix){
  cout << "Check address = " << &matrix << endl;
  matrix = new int * [x];

  for(int a = 0; a < x; a++){
    matrix[a] = new int [y];
  }
  matrix[0][0] = 1;
  cout << "Matrix Created" << endl;
}

void writeMatrix(int x, int y, int val, int ** &matrix){
  cout << "Check address = " << &matrix << endl;
  for(int a = 0; a < x; a++){
    for(int b = 0; b < y; b++){
      matrix[a][b] = 0;
    }
  }
  cout << "All values are 0." << endl;
}

void printMatrix(int x, int y, int ** &matrix){
  cout << "Check address = " << &matrix << endl;
  cout << "Printing matrix: " << endl;
  for(int a = 0; a < x; a++){
    for(int b = 0; b < y; b++){
      cout << setw(5) << matrix[a][b];
    }
    cout << endl;
  }
}

void deleteMatrix(int x, int ** &matrix){
  cout << "Check address = " << &matrix << endl;
  for(int a = 0; a < x; a++){
    delete[] matrix[a];
  }
  delete[] matrix;
  cout << "Matrix deleted";
}

/*
  Determinare punto di sella di una matrice
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {
  int getPosMin(int arr[], int);

  const int x = 4, y = 3;
  //int matrice[x][y] = {{5, 17, 9},{91, 4, 19},{82, 12, 7}, {6, 20, 33}};   //PUNTO DI SELLA NON ESISTE
  int matrice[x][y] = {{33, 7, 71},{19, 12, 83},{29, 4, 15}, {39, 2, 91}}; //PUNTO DI SELLA 12
  int temp, pos, esistenza = 0;
  int xPunto, yPunto;

  for(int a = 0; a < x; a++){
    pos = getPosMin(matrice[a], y);
    temp = 1;
    for(int b = 0; b < x; b++){
      if(b != a && matrice[a][pos] < matrice[b][pos]) temp = 0;
    }
    if(temp){
      esistenza++;
      xPunto = a;
      yPunto = pos;
    }
  }

  for(int a = 0; a < x; a++){
    for(int b = 0; b < y; b++){
      cout << setw(5) << matrice[a][b];
    }
    cout << endl;
  }

  if(esistenza){
    cout << "Il punto di sella è: " << matrice[xPunto][yPunto] << endl;
    cout << "Riga: " << xPunto + 1 << endl;
    cout << "Colonna: " << yPunto + 1 <<endl;
  }else{
    cout << "Non esiste un punto di sella";
  }
  return 0;
}


int getPosMin(int arr[], int dim){
  int min = arr[0];
  int pos = 0;
  for(int a = 1; a < dim; a++){
    if(arr[a] < min){
      min = arr[a];
      pos = a;
    }

  }
  return pos;
}

/*
 ESEMPIO MATRICE

     0,0  0,1  0,2  0,3  0,4
     1,0  1,1  1,2  1,3  /1,4
     2,0  2,1  2,2  /2,3  2,4
     3,0  3,1  /3,2  3,3  3,4
     4,0  /4,1  4,2  4,3  4,4

DIMENSIONE = 5
NUMERO DIAGONALI = (DIMENSIONE * 2) - 1 = 9

Triangolo superiore:

-> tutte diagonali iniziano con colonna = 0, riga = 0 + k
-> proseguono poi con colonna = 0 + x, riga = 0 - x
-> finiscono con riga = 0

Triangolo inferiore:

-> Tutte le diagonali iniziano con riga = DIMENSIONE - 1, colonna = 1 + k
-> Proseguono poi riga = (DIMENSIONE - 1) - k, colonna = (1 + k) + 1
-> Finiscono con colonna = (DIMENSIONE - 1)

*/

#include <iostream>

#define DIM 5

using namespace std;

int main(int argc, char const *argv[]) {

  int matrice[DIM][DIM] = {
    {1, 5, 3, 4, 6},
    {2, 3, 5, 4, 2},
    {3, 7, 0, 1, 2},
    {4, 6, 9, 1, 9},
    {1, 2, 5, 3, 2}
  };

  int numDiagonali = (DIM * 2) - 1;
  int sumDiagonali[numDiagonali];
  int sup = (numDiagonali / 2) + 1; //Il numero di diagonali sarà sempre dispari per definizione. Il triangolo superiore include anche quella centrale.
  int inf = numDiagonali - sup;

  int b, c; //Variabili temporanee utilizzate per incrementare e decrementare gli indici del vettore durante la somma delle diagonali

  int getMax(int[], int); //PROTOTIPO FUNZIONE -> input array, dimensione array. output massimo

  //Triangolo superiore
  for(int a = 0; a < sup; a++){
    b = a;
    c = 0;
    sumDiagonali[a] = matrice[b][c];

    while(b != 0){
      b--;
      c++;
      sumDiagonali[a] += matrice[b][c];
    }
  }

  //Triangolo inferiore
  for(int a = 0; a < inf; a++){
    b = DIM - 1;
    c = 1 + a;
    sumDiagonali[sup + a] = matrice[b][c]; //Si continua a salvare da dove è arrivata la funzione di salvataggio per il triangolo superiore

    while(c != DIM - 1){
      b--;
      c++;
      sumDiagonali[sup + a] += matrice[b][c];
    }
  }

  //STAMPA RISULTATO
  cout << "Il valore massimo delle somme dei valori lungo le diagonali è: " << getMax(sumDiagonali, numDiagonali);

  return 0;
}

int getMax(int arr[], int dim){
  int max = arr[0];
  for(int i = 1; i < dim; i++){
    if(arr[i] > max) max = arr[i];
  }
  return max;
}

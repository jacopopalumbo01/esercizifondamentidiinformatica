#include <iostream>
#include <iomanip>

#define WIDTH 8
#define HEIGHT 6

using namespace std;

void individuaTipoSottomatrici(int[HEIGHT][WIDTH], int);

int main() {
  int matrix[HEIGHT][WIDTH] = {
  {0, 5, 7, 9, 3, 4, 0, 0},
  {4, 0, 3, 8, 9, 0, 0, 0},
  {0, 0, 8, 4, 3, 9, 5, 3},
  {7, 3, 0, 6, 5, 7, 0, 0},
  {5, 9, 0, 0, 8, 0, 9, 0},
  {1, 9, 3, 6, 7, 0, 0, 5}
  };


  individuaTipoSottomatrici(matrix, 3);

  return 0;
}

void individuaTipoSottomatrici(int matrice[HEIGHT][WIDTH], int n){
  if(n < 2){
    cout << "N è minore di 2!";
    return;
  }
  for(int h = 0; (h + n) <= HEIGHT; h++){
    for(int w = 0; (w + n) <= WIDTH; w++){

      int a = h;
      int l = w + 1; // w+1 perchè nella prima cella della matrice inizia la diagonale e quindi non va considerata
      int sup = 1, inf = 1; //Se non vengono modificati in 0 sono verificate le condizioni

      for(int i = 0; i < n; i++){ //Determina le righe della matrice

        int y = a + i, x = l + i; // y è la riga e rimane costante durante il ciclo di analisi di ogni singola cella della riga, analizzate tramite incremento di x

        while(x < WIDTH){
          if(matrice[y][x] != 0) sup = 0;
          x++;
        }

        for(int b = 0; b < i; b++){
          if(matrice[y][w + b] != 0) inf = 0;
        }
      }

      if(inf && sup){
        cout << "Sottomatrice diagonale a partire dalla cella di coordinate (" << h << ", " << w << ")" << endl;
      }else if(inf){
        cout << "Sottomatrice triangolare inferiore a partire dalla cella di coordinate (" << h << ", " << w << ")" << endl;
      }else if(sup){
        cout << "Sottomatrice triangolare superiore a partire dalla cella di coordinate (" << h << ", " << w << ")" << endl;
      }


    }
  }
}

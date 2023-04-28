/*
Calcolo mediada di un numero dispari di numeri
*/

#include <iostream>
#define DIM 11

using namespace std;

int main(int argc, char const *argv[]) {

  int numeri[DIM];
  int estremi = (DIM - 1)/2;
  int mediana = 0;
  int estrD, estrS;

  cout << "Programma che calcola la mediana di " << DIM << " numeri." << endl;

  for(int a = 0; a < DIM; a++){
    cout << "Inserire il valore numero " << (a + 1) << ": ";
    cin >> numeri[a];
  }

  for(int i = 0; i < DIM; i++){
    estrD = 0;
    estrS = 0;

    for(int b = 0; b < DIM; b++){
      if(numeri[b] < numeri[i]) estrS++;
      if(numeri[b] > numeri[i]) estrD++;
    }

    if(estrS == estrD){
      mediana = numeri[i];
      break;
    }
  }

  cout << "La mediana è: " << mediana;

  return 0;
}

/*
      ESERCITAZIONE NUMERO 1 - MCD FRA DUE NUMERI UTILIZZANDO ALGORITMO DI EUCLIDE

      In input due numeri interi x e y. Calcolare e mostrare a video il loro MCD.

      Secondo algoritmo di Euclide, dati due numeri interi:

      MCD(x, x) = x
      Se x > y MCD(x, y) = MCD(x - y, y)
      Se x < y MCD(x, y) = MCD(x, y - x)
*/
#include <iostream>
using namespace std;

int main(){
  int x, y; // I due valori interi digitati dall'utente
  int mcd; // Il massimo comun denominatore

  cout << "Calcolo del MCD. Inserire due valori interi separati da uno spazio e premere invio..." << endl;
  cin >> x >> y; // Valori di input vengono memorizzati nelle variabili

  while(x != y){
    if(x > y) // Primo caso algoritmo
      x -= y;
    else     // Secondo caso algoritmo
      y -= x;
  }

  cout << "Il Massimo Comun Denominatore è: " << x;



}

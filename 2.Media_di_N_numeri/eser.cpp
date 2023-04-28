/*
      ESERCITAZIONE NUMERO 2 - MEDIA FRA n NUMERI. n DEFINITO DALL'UTENTE
*/

#include <iostream>
using namespace std;

int main(){
  int n; //il numero dei numeri desiderati
  float temp, somma, media; //Dichiarazione variabile temporanea, somma e media. Sono di tipo Float

  do{
    cout << "Calcolo della media. Digitare la quantità di numeri desiderata n: ";
    cin >> n;
    cout << endl;

    if(n == 0)
      cout << "Inserire un numero valido di numeri.";
  }while(n == 0); //se n è pari a 0 la media non esiste!


  somma = 0; //Valore base somma

  for(int a = 1; a <= n; a++){
    cout << "Inserire numero " << a << ": ";
    cin >> temp;
    cout << endl;

    somma += temp;
    temp = 0;
    }

  media = somma / n;
  cout << "La media dei " << n << " numeri inseriti vale: " << media;
}

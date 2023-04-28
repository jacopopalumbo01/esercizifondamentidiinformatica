/*
      ESERCITAZIONE NUMERO 3
      Trovare il massimo di n numeri interi positivi, n non definito a priori. Numero terminatore = 0
*/
#include <iostream>

using namespace std;

int main(){
  int in, max; //in utilizzata per memorizzare dato in ingresso, max per salvare il massimo
  cout << "Calcolo del massimo. Inserire i numeri interi positivi di cui si vuole determinare il MAX. Il carattere terminatore è lo 0." << endl;

  max = 0;
  do{
    cin >> in;
    if(in > max)
      max = in;
  }while(in);

  cout << "Inserito carattere terminatore 0" << endl;

  if(max == 0) //se max è pari a 0 non sono stati inseriti numeri!
    cout << "Hai inserito 0 numeri, non è possibile trovarne il massimo.";
  else
    cout << "Il massimo dei numeri inserito è: " << max;
}

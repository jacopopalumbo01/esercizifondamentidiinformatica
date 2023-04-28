/*

        ESERCITAZIONE 5: CALCOLO DELLA LUNGHEZZA DI UN PERIODO
        input un testo con periodi separati da ":" ";" ".". Carattere terminatore $
        output numero caratteri periodo con più caratteri e numero parole periodo con più parole
*/

#include <iostream>

using namespace std;

bool isCarattere(char c){
  if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    return true;

  return false;
}

int main(){
  int numParole = 0 , numCaratteri = 0 , numMaxParole = 0 , numMaxCaratteri = 0 ;
  char carattere, prec = ' ';

  cout << "Inserire un testo con più periodi. Carattere terminatore $" << endl;

  cin >> noskipws >> carattere;

  while(carattere != '$'){
    numCaratteri++;
    if(isCarattere(carattere) && !isCarattere(prec))
      numParole++;
    else if(carattere == '.' || carattere == ';' || carattere == ':'){
      if(numParole > numMaxParole)
        numMaxParole = numParole;
      if(numCaratteri > numMaxCaratteri)
        numMaxCaratteri = numCaratteri;
      numCaratteri = 0;
      numParole = 0;
    }
    prec = carattere;
    cin >> noskipws >> carattere;
  }

  cout << "Numero massimo di parole: " << numMaxParole << endl;
  cout << "Numero massimo caratteri: " << numMaxCaratteri << endl;
}

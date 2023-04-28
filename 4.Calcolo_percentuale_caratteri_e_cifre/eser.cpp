/*
      ESERCITAZIONE 4: CALCOLO PERCENTUALE CARATTERI E NUMERI
      Input un testo che termina con il carattere $
      Output la percentuale di caratteri minuscoli e di numeri
*/
#include <iostream>

using namespace std;


int main(){
  float numeriTot = 0, minuscoleTot = 0, caratteriTot = 0; // dichiarazione ed inizializzazione variabili -> si utilizza float per poter eseguire poi la divisione (si otterranno valori del tipo 0.x)
  float percentualeNumeri, percentualeMinuscole;
  char carattere;

  /*cin.unset(ios::skipws); DEPRECATO !

    Nella soluzione dell'esercitazione è consigliata questa istruzione per 'forzare' l'oggetto cin a non 'saltare' il carattere spazio,
    permettendone il conteggio per il calcolo finale della percentuale (in un testo anche lo spazio viene considerato carattere).
    Tuttavia questa istruzione è deprecata quindi il compilatore non compilerà il programma e darà errore (girando su vari forum online
    ho notato che questa istruzione dava problemi già nel 2005 :) ).
    Ho cercato nella documentazione (http://www.cplusplus.com/reference/ios/noskipws/) ed ho trovato l'utilizzo della nuova funzione,
    che non da errori.
    Sostanzialmente va 'fatto passare' il testo acquisito da cin da 'noskipws' (do not skip whitespaces). Così facendo anche lo spazio
    viene contato come carattere ed il calcolo di caratteri totali sarà corretto.
    UTILIZZO:
    cin << noskipws << nomeVariabile;
*/

  cout << "Calcolo percentuale di minuscole e numeri di un testo. Carattere terminatore $. Inserire il testo: ";
  cin >> noskipws >>carattere;

  while(carattere != '$'){

    if(carattere >= 'a' && carattere <= 'z')
      minuscoleTot++;

    if(carattere >= '0' && carattere <= '9')
      numeriTot++;

    caratteriTot++;

    cin >> noskipws >> carattere;
  }
  /*
    cout << "Caratteri: " << caratteriTot << " Minuscole: " << minuscoleTot << " Numeri: " << numeriTot;
    Non serve più. Utilizzata per verificare con output a video il corretto funzionamento dei vari conteggi.
  */

  percentualeMinuscole = (minuscoleTot / caratteriTot)*100;
  percentualeNumeri    = (numeriTot    / caratteriTot)*100;

  cout << "Sono stati inseriti " << caratteriTot << " caratteri." << endl
  << "Percentuale minuscole: " << percentualeMinuscole << "%" << endl
  << "Percentuale numeri:    " << percentualeNumeri    << "%" << endl;

}

#include <iostream>

#define MAX 40

using namespace std;

int main(int argc, char const *argv[]) {
  char in[MAX], out[MAX];
  int totSpaces = 0, words = 0, spaces = 0, resto = 0;
  int c = 0;

  cout << "Giustificazione di un testo." << endl << "Inserire il testo: ";

  for(int a = 0; a < MAX; a++){
    in[a] = ' ';
    out[a] = ' ';
  }


  for(int i = 0; i < MAX; i++){
    cin >> noskipws >> in[i];


    if(in[i] == ' ') totSpaces++;
    if((in[i] == ' ' || in[i] == '\n') && in[i-1] != ' ') words++;
    if(in[i] == '\n'){
      totSpaces += MAX - i;
      break;
    }
  }

  spaces = totSpaces / (words - 1);
  resto  = totSpaces % (words - 1);

  //cout << "Spazi: " << totSpaces << " Parole: " << words << " Spaces: " << spaces << " resto: " << resto << endl;
  cout << "Giustificazione in corso..." << endl;

  while(in[c] == ' ') c++;

  for(int d = 0; d < MAX; d++){
    if(in[c] != ' ') out[d] = in[c];

    if(in[c] == ' ' && in[c-1] != ' '){
      for(int e = 0; e < spaces; e++){
        out[d] = ' ';
        d++;
      }
      if(resto){
        out[d] = ' ';
        resto--;
        d++;
      }
      d--;
    }
    c++;
  }

  for(int f = 0; f < MAX; f++){
    cout << out[f];
  }

  return 0;
}

/*
RICERCA DI UN NUMERO IN UN ARRAY CON TRE METODI:
1. ALGORITMO DI RICERCA IN UN VETTORE NON ORDINATO
2. ALGORITMO DI RICERCA IN UN VETTORE ORDINATO
3. ALGORITMO DI RICERCA BINARIA IN UN VETTORE ORDINATO
*/


#include <iostream>

#define DIM 10

using namespace std;

int main(int argc, char const *argv[]) {

  void readArray(int[], int);
  void printArray(int[], int);
  int searchArray(int, int[], int, int);

  int array[DIM];
  int command, num;

  cout << "Inserire 10 valori separati da uno spazio: " << endl;
  readArray(array, DIM);

  cout << "Inserire metodo desiderato per ricerca e numero da cercare. Inserire 0 per uscire." << endl;
  printArray(array, DIM);
  while(1){
    cout << "Metodo di ricerca: ";
    cin >> command;
    cout << endl;
    if(command == 0){
      break;
    }else{
      cout << "Numero da cercare: ";
      cin >> num;
      cout << "Il numero " << num << " ha indice: " << searchArray(command, array, DIM, num) << endl;
    }
  }
  return 0;
}

void readArray(int arr[], int dim){
  for(int a = 0; a < dim; a++){
    cin >> arr[a];
  }
}

void printArray(int arr[], int dim){
  for(int a = 0; a < dim; a++){
    cout << arr[a] << " ";
  }
  cout << endl;
}

int searchArray(int method, int arr[], int dim, int key){
  int index, i, s, m;
  index = -1;
  switch(method){
    case 1:
      for(int a = 0; a < dim; a++){
        if(arr[a] == key){
          index = a;
          break;
        }
      }
      break;
    case 2:
      for(int a = 0; a < dim; a++){
        if(arr[a] == key){
          index = a;
          break;
        }
        if(arr[a] > key){
          index = -1;
          break;
        }
      }
      break;
    case 3:
      i = 0;
      s = dim - 1;
      while(i <= s){
        m = (i+s)/2;
        if(arr[m] < key) i = m+1;
        else if(arr[m] > key) s = m-1;
        else{
          index = m;
          break;
        }
      }
      break;
    default:
      index = -1;
      break;
  }
  return index;
}

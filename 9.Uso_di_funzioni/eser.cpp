/*
Calcolo massimo mediana di due vettori di int con n dispari
*/
#include <iostream>

using namespace std;


int main(int argc, char const *argv[]) {

  void getArray(int *arr, int dim);
  int getMediana(int arr[], int dim);
  int getMax(int a, int b);

  int firstN, secondN;
  int *firstArr, *secondArr;
  int firstMed, secondMed;

  while(1){
    cout << "Inserire dimensioni due array separate da uno spazio (le dimensioni devono essere dispari)." << endl;
    cin >> firstN >> secondN;
    if((firstN % 2 != 0) && (secondN % 2 != 0)) break;
    cout << "Le dimensioni devono essere dispari!" << endl;
  }

  cout << "Inserire " << firstN << " numeri per il primo array." << endl;
  firstArr = new int[firstN];
  getArray(firstArr, firstN);

  cout << "Inserire " << secondN << " numeri per il secondo array." << endl;
  secondArr = new int[secondN];
  getArray(secondArr, secondN);

  firstMed = getMediana(firstArr, firstN);
  secondMed = getMediana(secondArr, secondN);

  cout << "La prima mediana è: " << firstMed << endl;
  cout << "La seconda mediana è: " << secondMed << endl;
  cout << "Il massimo è: " << getMax(firstMed, secondMed);
  return 0;
}

void getArray(int arr[], int dim){
  for(int n = 0; n < dim; n++){
    cin >> arr[n];
  }
}

int getMediana(int arr[], int dim){
  int estremi = (dim - 1)/2;
  int estrD, estrS;

  for(int i = 0; i < dim; i++){
    estrD = 0;
    estrS = 0;
    for(int b = 0; b < dim; b++){
      if(arr[b] < arr[i]) estrS++;
      if(arr[b] > arr[i]) estrD++;
    }
    if((estrS <= estremi)&&(estrD <= estremi)){
      return arr[i];
    }
  }
  return 0;
}

int getMax(int a, int b){
  if(a >= b) return a;
  if(a < b) return b;
  return 0;
}

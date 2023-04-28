/*
  ALGORITMI DI ORDINAMENTO
  1. bubble sort
  2. ordinamento per inserimento
*/
#include <iostream>

#define DIM 10

using namespace std;

void readArray(int[], int);
void printArray(int[], int);
void copyArray(const int[], int[], int);
void bubbleSort(int[], int);
void insertSort(int[], int);
void selectSort(int[], int);
int minIndex(int[], int);

int main(int argc, char const *argv[]) {

  int tempArr[DIM];
  int array[DIM];
  cout << "Programma che effettua l'ordinamento degli elementi di un vettore secondo tre algoritmi." << endl;
  cout << "________________________________________________________________________________________" << endl;
  cout << "Istruzioni: " << endl;
  cout << "Inserire " << DIM << " numeri interi da ordinare: " << endl;
  readArray(array, DIM);
  cout << "________________________________________________________________________________________" << endl;
  copyArray(array, tempArr, DIM);
  bubbleSort(tempArr, DIM);
  cout << "Algoritmo Bubble Sort:" << endl;
  printArray(tempArr, DIM);
  cout << "________________________________________________________________________________________" << endl;
  copyArray(array, tempArr, DIM);
  insertSort(tempArr, DIM);
  cout << "Algoritmo Inserimento:" << endl;
  printArray(tempArr, DIM);
  cout << "________________________________________________________________________________________" << endl;
  copyArray(array, tempArr, DIM);
  selectSort(tempArr, DIM);
  cout << "Algoritmo Selezione:" << endl;
  printArray(tempArr, DIM);

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

int minIndex(int arr[], int dim){
  int min = arr[0];
  int ind = 0;
  for(int a = 0; a < dim; a++){
    if(arr[a] < min){
      min = arr[a];
      ind = a;
    }
  }
  return ind;
}

void copyArray(const int arr[], int copy[], int dim){
  for(int a = 0; a < dim; a++){
    copy[a] = arr[a];
  }
}

void bubbleSort(int arr[], int dim){
  bool sorted = false;
  int temp;

  while(!sorted){
    sorted = true;
    for(int a = 0; a < (dim - 1); a++){ //dim-1 per non sforare dall'array quando viene considerata l'ultima cella
      if(arr[a+1] < arr[a]){
        temp = arr[a];
        arr[a] = arr[a+1];
        arr[a+1] = temp;
        sorted = false;
      }
    }
  }
}

void insertSort(int arr[], int dim){
  int temp, ind;
  for(int a = 1; a < dim; a++){
    temp = arr[a];
    ind = a;
    while(ind > 0 && temp < arr[ind - 1]){
      arr[ind] = arr[ind - 1];
      ind--;
    }
    arr[ind] = temp;
  }
}

void selectSort(int arr[], int dim){
  int tempArr[DIM];
  int ind, index, temp;
  for(int a = 0; a < dim; a++){
    ind = 0;
    for(int b = a; b < dim; b++){
      tempArr[ind] = arr[b];
      ind++;
    }
    index = minIndex(tempArr, ind) + a;
    temp =  arr[a];
    arr[a] = arr[index];
    arr[index] = temp;
  }
}

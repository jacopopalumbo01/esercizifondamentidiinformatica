#include <iostream>

using namespace std;

struct Nodo{
  int valore;
  Nodo * nextPtr;
};

void insert(Nodo * &, int);
void print(Nodo * &);
int calcoloMediana(Nodo * &);

int main(int argc, char const *argv[]) {
  //Inizializzazione lista.
  Nodo * lista = new Nodo;
  lista->nextPtr = 0;

  int tot, num;

  cout << "Calcolo mediana" << endl;
  cout << "Quanti numeri si vogliono inserire nella lista? ";
  cin >> tot;
  cout << "Inserire " << tot << " numeri:" << endl;

  for(int a = 0; a < tot; a++){
    cin >> num;
    insert(lista, num);
  }

  cout << "La lista è: " << endl;
  print(lista);

  cout << "La mediana è: " << calcoloMediana(lista);
  return 0;
}

void insert(Nodo * &start, int num){
  Nodo * ptr = start;

  while(ptr->nextPtr != 0){
    ptr = ptr->nextPtr; //Last element
  }

  Nodo *temp = new Nodo;
  temp->valore = num;
  temp->nextPtr= 0; //append

  ptr->nextPtr = temp; //Save address of the new element in the last element
}

void print(Nodo * &start){
  Nodo * temp = new Nodo;
  temp = start->nextPtr; //start from the first element. Start is used only for saving the address of the first element
  while(temp != 0){
    cout << temp->valore << " ";
    temp = temp->nextPtr;
  }
  cout << endl;
}

int calcoloMediana(Nodo * &start){
  Nodo *ptr;
  int mediana, maggiori, minori;

  int n = 0;

  for(ptr = start->nextPtr; ptr->nextPtr != 0; ptr = ptr->nextPtr){
    n++;
  }

  ptr = start->nextPtr;

  do{
    maggiori = 0;
    minori = 0;
    for(Nodo * ptr1 = start->nextPtr; ptr1->nextPtr != 0; ptr1 = ptr1->nextPtr){
      if(ptr1->valore > ptr->valore)maggiori++;
      else if(ptr1->valore < ptr->valore)minori++;

      mediana = ptr->valore;
      ptr = ptr->nextPtr;
    }
  }while(!((minori <= (n-1)/2 && maggiori <= n/2) || (minori <= n/2 && maggiori <= (n-1)/2)));

  return mediana;
}

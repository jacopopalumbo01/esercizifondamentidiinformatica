#include <iostream>

using namespace std;

struct Node{
  int val;
  Node * next;
};

struct List{
  Node * first;
};

void appendElement(List &, int);
void printList(Node * &);
void printInvertedList(Node * &);
void deallocList(Node * &);

int main(int argc, char const *argv[]) {

  List lista;

  int max, val;

  cout << "Quanti numeri si vogliono inserire nella lista? ";
  cin >> max;
  cout << "Inserire " << max << " numer:" << endl;

  for(int a = 0; a < max; a++){
    cin >> val;
    appendElement(lista, val);
  }

  cout << "La lista è:" << endl;
  printList(lista.first);
  cout << endl << "La lista invertita è: " << endl;;
  printInvertedList(lista.first);
  cout << endl << "Lista eliminata.";
  deallocList(lista.first);
  return 0;
}

void appendElement(List &list, int val){
  if(list.first == 0){
    Node * temp = new Node;
    temp->val = val;
    temp->next = 0;
    list.first = temp;
    return;
  }

  Node * iter = list.first;
  while(iter->next != 0){
    iter = iter->next;
  }
  Node * temp = new Node;
  temp->val = val;
  temp->next = 0;
  iter->next = temp;
  return;
}

void printList(Node * &nodo){
  if(nodo != 0)
    cout << nodo->val << " ";
  if(nodo->next != 0)
    printList(nodo->next);
}

void printInvertedList(Node * &nodo){
  if(nodo->next != 0)
    printInvertedList(nodo->next);
  cout << nodo->val << " ";
}

void deallocList(Node * &nodo){
  if(nodo->next != 0)
    deallocList(nodo->next);
  delete nodo;
}

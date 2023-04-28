#include <iostream>

struct listNode{
  int val;
  listNode * next;
};

struct List{
  listNode * first;
};

void appendElement(List &, int);
void printList(List);
List invertList(List);

int main(int argc, char const *argv[]) {

  List lista;
  lista.first = 0;

  int tot, num;

  std::cout << "Inversione di una lista di numeri. Quanti numeri? ";
  std::cin >> tot;
  std::cout << std::endl << "Inserire i numeri desiderati" << std::endl;

  for(int a = 0; a < tot; a++){
    std::cin >> num;
    appendElement(lista, num);
  }

  std::cout << "La lista inserita è:" << std::endl;
  printList(lista);
  std::cout << "La lista invertita è:" << std::endl;

  List inv = invertList(lista);

  printList(inv);


  return 0;
}

void appendElement(List &lista, int val){
  if(lista.first == 0){
    listNode * temp = new listNode;
    temp->val = val;
    temp->next = 0;
    lista.first = temp;
  }else{
    listNode * temp = lista.first;

    while(temp->next != 0)
      temp = temp->next;

    listNode * newNode = new listNode;
    newNode->val = val;
    newNode->next = 0;

    temp->next = newNode;
  }
}

void printList(List lista){
  if(lista.first == 0){
    std::cout << "Non sono presenti elementi nella lista" << std::endl;
    return;
  }

  listNode * nodo = lista.first;
  std::cout << nodo->val << " ";

  while(nodo->next != 0){
    nodo = nodo->next;
    std::cout << nodo->val << " ";
  }

  std::cout << std::endl;
}

List invertList(List lista){
  if(lista.first == 0){
    std::cout << "Non sono presenti elementi nella lista" << std::endl;
    return lista;
  }

  List inv;
  listNode * nodo = lista.first;

  listNode * temp = new listNode;
  temp->val = nodo->val;
  temp->next = nullptr;
  inv.first = temp;

  while(nodo->next != nullptr){
    nodo = nodo->next;

    listNode * temp = new listNode;
    temp->val = nodo->val;
    temp->next = inv.first;
    inv.first = temp;

  }
  delete temp;

  return inv;
}

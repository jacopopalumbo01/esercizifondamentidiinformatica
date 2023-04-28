#include <iostream>
#include <iomanip>

using namespace std;

struct ListaProdotti{
  int art;
  int coll;
  ListaProdotti * next;
};

struct ListaSpesa{
  int art;
  int num;
  ListaSpesa * next;
};

struct ListaOperatore{
  int art;
  int coll;
  int num;
  ListaOperatore * next;
};


void addProdotto(int, int, ListaProdotti *);
void printProdotti(ListaProdotti *);
bool insideProdotti(ListaProdotti *, int);
int getColl(ListaProdotti *, int);
void addSpesa(int, int, ListaSpesa *);
void printSpesa(ListaProdotti *, ListaSpesa *);
void generaListaOperatore(ListaProdotti *, ListaSpesa *, ListaOperatore *);
void recursiveLista(ListaProdotti *, ListaOperatore *, int, int);
void printOperatore(ListaOperatore *);


int main() {

  ListaProdotti prova;
  prova.art = 1005;
  prova.coll = 8;
  prova.next = 0;
  addProdotto(1009,14, &prova);
  addProdotto(1006,1, &prova);
  addProdotto(1000,15, &prova);
  addProdotto(1004,9, &prova);
  addProdotto(1003,10, &prova);
  addProdotto(1002,12, &prova);
  addProdotto(1010,18, &prova);
  addProdotto(1001,13, &prova);
  addProdotto(1008,3, &prova);
  addProdotto(1007,20, &prova);

  ListaSpesa spesa;
  spesa.art = 1010;
  spesa.num = 1;
  spesa.next = 0;
  addSpesa(1005, 5, &spesa);
  addSpesa(1001, 1, &spesa);
  addSpesa(1000, 2, &spesa);
  addSpesa(1106, 3, &spesa);
  addSpesa(1006, 3, &spesa);
  addSpesa(1004, 1, &spesa);

  printProdotti(&prova);
  printSpesa(&prova, &spesa);

  ListaOperatore lista;
  lista.art = 0;
  lista.coll = 0;
  lista.num = 0;
  lista.next = 0;

  generaListaOperatore(&prova, &spesa, &lista);

  printOperatore(&lista);

  return 0;
}



void addProdotto(int art, int coll, ListaProdotti * lista){
  if(lista->next == 0){
    ListaProdotti * temp = new ListaProdotti;
    temp->art = art;
    temp->coll = coll;
    temp->next = 0;
    lista->next = temp;
  }else{
    addProdotto(art, coll, lista->next);
  }
}

void printProdotti(ListaProdotti * lista){
  cout << "Catalogo prodotti a magazzino" << endl;
  while(1){
    cout << setw(11) << left << "Articolo:  " << setw(5) << left << lista->art << setw(15) << left << "Collocazione:  " << setw(5) << left << lista->coll << endl;
    if(lista->next == 0) return;
    lista = lista->next;
  }
}

bool insideProdotti(ListaProdotti * lista, int art){
  if(lista->art == art) return true;
  else if(lista->next == 0) return false;
  else return insideProdotti(lista->next, art);
}

int getColl(ListaProdotti * lista, int art){
  if(lista->art == art) return lista->coll;
  else if(lista->next == 0) return 0;
  else return getColl(lista->next, art);
}

void addSpesa(int art, int num, ListaSpesa * lista){
  if(lista->next == 0){
    ListaSpesa * temp = new ListaSpesa;
    temp->art = art;
    temp->num = num;
    temp->next = 0;
    lista->next = temp;
  }else{
    addSpesa(art, num, lista->next);
  }
}

void printSpesa(ListaProdotti * magazzino, ListaSpesa * lista){
  cout << "Spesa ordinata" << endl;
  while(1){
    if(insideProdotti(magazzino, lista->art))
      cout << setw(11) << left << "Articolo:  " << setw(5) << left << lista->art << setw(11) << left << "Quantità:  " << setw(5) << left << lista->num << endl;
    else
      cout << "- - Prodotto " << lista->art << " non esistente - -" << endl;

    if(lista->next == 0) return;
    lista = lista->next;
  }

}

void generaListaOperatore(ListaProdotti * magazzino, ListaSpesa * spesa, ListaOperatore * lista){
  if(insideProdotti(magazzino, spesa->art)){
    recursiveLista(magazzino, lista, spesa->art, spesa->num);
  }
  if(spesa->next != 0) generaListaOperatore(magazzino, spesa->next, lista);
  return;
}

void recursiveLista(ListaProdotti * magazzino, ListaOperatore * lista, int art, int num){
  if(lista->art == 0 && lista->coll == 0 && lista->num == 0){
    lista->art = art;
    lista->coll = getColl(magazzino, art);
    lista->num = num;
    lista->next = 0;
  }else if(lista->coll > getColl(magazzino, art)){
    ListaOperatore * temp = new ListaOperatore;
    temp->art = lista->art;
    temp->coll = lista->coll;
    temp->num = lista->num;
    temp->next = lista->next;

    lista->art = art;
    lista->coll = getColl(magazzino, art);
    lista->num = num;
    lista->next = temp;
  }else if(lista->next == 0){
    ListaOperatore * temp = new ListaOperatore;
    temp->art = art;
    temp->coll = getColl(magazzino, art);
    temp->num = num;
    temp->next = 0;

    lista->next = temp;
  }else recursiveLista(magazzino, lista->next, art, num);
}

void printOperatore(ListaOperatore * lista){
  cout << "Lista Operatore" << endl;
  while(1){
    cout << setw(11) << left << "Articolo:  " << setw(5) << left << lista->art << setw(15) << left << "Collocazione:  " << setw(5) << left << lista->coll << setw(11) << left << "Quantità:  " << setw(5) << left << lista->num << endl;
    if(lista->next == 0) return;

    lista = lista->next;
  }
}

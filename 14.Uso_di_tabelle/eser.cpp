/*
Gestione esami studenti corso universitario
*/

#include <iostream>
#include <iomanip>

#define MAX_ID 25
#define MAX_COURSE 30
#define MAX_EXAMS 30
#define MAX_STUD 100

struct Date{
  int d; //Giorno
  int m; //Mese
  int y; //Anno
};

struct Exam{
  char courseName[MAX_COURSE];
  int vote;
  enum lode {Y, N};
  Date date;
};

struct Student{
  char name[MAX_ID];
  char surname[MAX_ID];
  int matricola;
  int courseYear;
  enum statoIscrizione {C, FC} iscrizione; //Corso e Fuoricorso
  Exam exams[MAX_EXAMS];
};

void printLogo();
void initTable(Student[], int);
int getFirstFreeRow(Student[], int);
void insertElement(Student[], int, Student);
void copyString(char[], char[], int);
void cinStudent(Student *);
int cinString(char[], int);
void printTable(Student[], int);

int main(int argc, char const *argv[]) {

  printLogo();

  Student students[MAX_STUD];
  initTable(students, MAX_STUD);

  char command;
  Student temp;

  while(1){
    std::cout << "Menù:  " << "a: Inserisci Nuovo Utente  " << "b: Visualizza Tabella " << "e: Exit" << std::endl;
    std::cin >> std::skipws >> command;
    switch(command){
      case 'e':
        return 0;
        break;
      case 'a':
        cinStudent(&temp);
        insertElement(students, getFirstFreeRow(students, MAX_STUD), temp);
        break;
      case 'b':
        printTable(students, MAX_STUD);
        break;
      default:
        std::cout << "Comando non riconosciuto..." << std::endl;
        break;
    }
    std::cin.ignore(10000, '\n');
  }

  Student prova;
  prova.name[0] = 'D';
  prova.name[1] = 'i';
  prova.name[2] = 'e';
  prova.name[3] = 'g';
  prova.name[4] = 'o';
  prova.surname[0] = 'R';
  prova.matricola = 12345;
  prova.courseYear = 1;
  prova.iscrizione = Student::C;

  insertElement(students, 0, prova);

  std::cout << std::endl << prova.name;
  return 0;
}

void printLogo(){
std::cout << "    _    _                       _ " << std::endl;
std::cout << "   / \\  | |_   _ _ __ ___  _ __ (_)" << std::endl;
std::cout << "  / _ \\ | | | | | '_ ` _ \\| '_ \\| |" << std::endl;
std::cout << " / ___ \\| | |_| | | | | | | | | | |" << std::endl;
std::cout << "/_/   \\_\\_|\\__,_|_| |_| |_|_| |_|_|" << std::endl;
std::cout << "------------------------------------------" << std::endl;
std::cout << " An university students management system" << std::endl;
std::cout << "__________________________________________" << std::endl;
}

void copyString(char start[], char copy[], int dim){
  for(int a = 0; a < dim; a++){
    copy[a] = start[a];
  }
}

void initTable(Student table[], int dim){
  for(int a = 0; a < dim; a++){
    table[a].matricola = 0;
  }
}

int getFirstFreeRow(Student table[], int dim){
  for(int a = 0; a < dim; a++){
    if(table[a].matricola == 0){
      return a;
    }
  }
  return -1;
}

void insertElement(Student table[], int index, Student student){
  copyString(student.name, table[index].name, MAX_ID);
  copyString(student.surname, table[index].surname, MAX_ID);
  table[index].matricola = student.matricola;
  table[index].courseYear = student.courseYear;
  table[index].iscrizione = student.iscrizione;
}

void cinStudent(Student *student){
  char temp;
  std::cin.ignore(10000, '\n');
  std::cout << std::left << std::setw(15) << "Nome: ";
  cinString(student->name, MAX_ID);
  std::cout << std::left << std::setw(15) << "Cognome: ";
  cinString(student->surname, MAX_ID);
  std::cout << std::left << std::setw(15) << "Matricola: ";
  std::cin >> student->matricola;
  std::cin.ignore(10000, '\n');
  std::cout << std::left << std::setw(15) << "Anno di corso: ";
  std::cin >> student->courseYear;
  std::cin.ignore(10000, '\n');
  std::cout << std::left << std::setw(15) << "Fuori corso? (C / FC)";
  std::cin >> temp;
  if(temp == 'C') student->iscrizione = Student::C;
  else student->iscrizione = Student::FC;
}

int cinString(char string[], int dim){
  char temp;
  for(int a = 0; a < dim; a++){
    std::cin >> std::noskipws >> temp;
    if(temp == '\n')return 0;
    string[a] = temp;
  }
  return 0;
}

void printTable(Student table[], int dim){
  std::cout << std::setw(15) << "Matricola" << std::setw(MAX_ID) << "Nome" << std::setw(MAX_ID) << "Cognome" << std::setw(8) << "Anno" << std::setw(15) << "Iscrizione" << std::setw(20) << "Numero Esami" << std::endl;
  for(int a = 0; a < dim && table[a].matricola != 0; a++){
    std::cout << std::setw(15) << table[a].matricola << std::setw(MAX_ID) << table[a].name << std::setw(MAX_ID) << table[a].surname << std::setw(8) << table[a].courseYear << std::setw(15) << table[a].iscrizione << std::setw(20) << "Numero Esami" << std::endl;
  }
}

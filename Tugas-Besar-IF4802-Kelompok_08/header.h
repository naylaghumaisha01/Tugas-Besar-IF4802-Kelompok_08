#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct elmDeveloper *adrDeveloper;
typedef struct elmClient *adrClient;

struct Developer{
    string idDev;
    string nameDev;
};

struct Client{
    string idClient;
    string nameClient;
    string nameProject;
};

struct elmDeveloper{
    Developer info;
    adrDeveloper next;
    adrDeveloper prev;
    adrClient firstClient;
};

struct elmClient{
    Client info;
    adrClient next;
};

struct ListDeveloper{
    adrDeveloper first;
    adrDeveloper last;
};

//header parent
void createListDeveloper(ListDeveloper &LD);
adrDeveloper createElmDeveloper(string idDev, string nameDev);
void insertDevFirst(ListDeveloper &LD, adrDeveloper D);
void insertDevLast(ListDeveloper &LD, adrDeveloper D);
void insertDevAfter(ListDeveloper &LD, adrDeveloper prec, adrDeveloper D);
void deleteDevFirst(ListDeveloper &LD, adrDeveloper &D);
void deleteDevLast(ListDeveloper &LD, adrDeveloper &D);
void deleteDevAfter(ListDeveloper LD, adrDeveloper prec, adrDeveloper &D);
adrDeveloper searchDeveloper(ListDeveloper L, string idDev);
void mostClientDeveloper(ListDeveloper LD);
void showDeveloper(ListDeveloper LD);

//header child
adrClient createElmClient(string idClient, string nameClient, string nameProject);
void insertClientFirst(adrDeveloper D, adrClient C);
void insertClientLast(adrDeveloper D, adrClient C);
void insertClientAfter(adrClient prec, adrClient C);
void deleteClientFirst(adrDeveloper D, adrClient &C);
void deleteClientLast(adrDeveloper D, adrClient &C);
void deleteClientAfter(adrClient prec, adrClient &C);
adrClient searchClient(adrDeveloper D, string idClient);
int countClientsofDeveloper(adrDeveloper D);
int totalClient(ListDeveloper LD);
void showClient(ListDeveloper LD);
void showClientsofDeveloper(ListDeveloper LD, string idDev);
void showClientSorted(adrDeveloper D);

//header main
void menuAdmin();
void menuParent();
void menuChild();
void menuUser();

#endif // HEADER_H_INCLUDED

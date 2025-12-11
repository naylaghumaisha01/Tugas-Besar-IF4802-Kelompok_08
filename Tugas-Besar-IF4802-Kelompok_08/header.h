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

void createListDeveloper(ListDeveloper &LD);
adrDeveloper createElmDeveloper(string idDev, string nameDev);
adrClient createElmClient(string idClient, string nameClient);
void addDeveloper(ListDeveloper &LD, adrDeveloper D);
void addClient(adrDeveloper &D, adrClient C);
void deleteDeveloper(ListDeveloper &LD, string idDev);
void deleteClient(adrDeveloper D, string idClient);
adrDeveloper searchDeveloper(ListDeveloper L, string idDev);
adrClient searchClient(adrDeveloper D, string idClient);
void mostClientDeveloper(ListDeveloper LD);
int countClientsofDeveloper(adrDeveloper D);
int totalClient(ListDeveloper LD);
void displayList(ListDeveloper LD);
void showDeveloper(ListDeveloper LD);
void ShowClientsofDeveloper(ListDeveloper LD, string idDev);
void showUniqueClient(ListDeveloper LD);

#endif // HEADER_H_INCLUDED

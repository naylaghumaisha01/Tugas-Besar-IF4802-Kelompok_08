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

createListDeveloper(ListDeveloper &LD);
bool isEmptyDeveloper(ListDeveloper LD);
bool isEmptyClient(adrClient C);
adrDeveloper createElmDeveloper(string idDev, string nameDev);
adrClient createElmClient(string idClient, string nameClient);
void addDeveloper(ListDeveloper &LD, adrDeveloper D);
void addClient(adrDeveloper &D, adrClient C);
void deleteDeveloper(ListDeveloper &LD, string idDev);
void deleteClient(adrDeveloper D, string idClient);
adrDeveloper searchDeveloper(ListDeveloper L, string idDev);
adrClient searchClient(adrDeveloper D, string idClient);
void maxDeveloper(ListDeveloper LD);
int totalClient(ListDeveloper LD);
void displayList(ListDeveloper L);

#endif // HEADER_H_INCLUDED

#include "header.h"


void createListDeveloper(ListDeveloper &LD){
    LD.first = nullptr;
    LD.last = nullptr;
}

adrDeveloper createElmDeveloper(string idDev, string nameDev){
    adrDeveloper D;
    D = new elmDeveloper;
    D->info.idDev = idDev;
    D->info.nameDev = nameDev;
    D->next = nullptr;
    D->prev = nullptr;
    D->firstClient = nullptr;
    return D;
}

void insertDevFirst(ListDeveloper &LD, adrDeveloper D){
    if(LD.first == nullptr){
        LD.first = D;
        LD.last = D;
    }else {
        D->next = LD.first;
        LD.first->prev = D;
        LD.first = D;
    }
}

void insertDevLast(ListDeveloper &LD, adrDeveloper D){
    if(LD.first == nullptr){
        LD.first = D;
        LD.last = D;
    }else {
        LD.last->next = D;
        D->prev = LD.last;
        LD.last = D;
    }
}

void insertDevAfter(ListDeveloper &LD, adrDeveloper prec, adrDeveloper D){
    if(LD.first == nullptr){
        LD.first = D;
        LD.last = D;
    }else if(prec == LD.last){
        prec->next = D;
        D->prev = prec;
        LD.last = D;
    }else {
        D->next = prec->next;
        D->prev = prec;
        prec->next = D;
        D->next->prev = D;
    }
}

void deleteDevFirst(ListDeveloper &LD, adrDeveloper &D){
    if(LD.first == nullptr){
        D = nullptr;
    }
    if(LD.first == LD.last){
        D = LD.first;
        LD.first = nullptr;
        LD.last = nullptr;
    }else {
        D = LD.first;
        LD.first = D->next;
        LD.first->prev = nullptr;
        D->next = nullptr;
    }
}

void deleteDevLast(ListDeveloper &LD, adrDeveloper &D){
    if(LD.last == nullptr){
        D = nullptr;
    }else if(LD.first == LD.last){
        D = LD.last;
        LD.first = nullptr;
        LD.last = nullptr;
    }else {
        D = LD.last;
        LD.last = LD.last->prev;
        LD.last->next = nullptr;
        D->prev = nullptr;
    }
}

void deleteDevAfter(ListDeveloper LD, adrDeveloper prec, adrDeveloper &D){
    if(prec == nullptr || prec->next == nullptr){
        D = nullptr;
    }
    D = prec->next;
    if(D == LD.last){
        prec->next = nullptr;
        LD.last = prec;
    }else {
        prec->next = D->next;
        D->next->prev = prec;
    }
    D->next = nullptr;
    D->prev = nullptr;
}

adrDeveloper searchDeveloper(ListDeveloper LD, string idDev){
    adrDeveloper D;
    D = LD.first;
    while (D != nullptr){
        if(D->info.idDev == idDev){
            return D;
        }
        D = D->next;
    }
    return nullptr;
}

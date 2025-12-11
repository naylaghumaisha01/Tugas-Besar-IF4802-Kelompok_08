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

void addDeveloper(ListDeveloper &LD, adrDeveloper D){
    if(LD.first == nullptr){
        LD.first = D;
        LD.last - D;
    }else {
        LD.last->next = D;
        D->prev = LD.last;
        LD.last = D;
    }
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
    return D;
}

void deleteDeveloper(ListDeveloper &LD, string idDev){
    adrDeveloper D;
    D = searchDeveloper(LD, idDev);
    if (D == nullptr){
        cout << "List kosong" << endl;
    }
    if (D ==  LD.first && D == LD.last){
        LD.first = nullptr;
        LD.last = nullptr;
    }else if (D ==  LD.first) {
        LD.first = D->prev;
        LD.last->next = nullptr;
    }else {
        D->prev->next = D->next;
        D->next->prev == D->prev;
    }
}

#include "header.h"

int countClientsofDeveloper(adrDeveloper D){
    int Count;
    adrClient C;
    Count = 0;
    C = D->firstClient;
    while (C != nullptr){
        Count++;
        C = C->next;
    }
    return Count;
}

int totalClient(ListDeveloper LD){
    int total;
    adrDeveloper D;
    while (D != nullptr){
        total += countClientsofDeveloper(D);
        D = D->next;
    }
    return total;
}

void showUniqueClient(ListDeveloper LD){
    cout << "========== SEMUA CLIENT =========\n" << endl;
    adrDeveloper D;
    adrClient C;
    D = LD.first;
    while (D != nullptr){
        C = D->firstClient;
        while (C != nullptr){
            cout << "Nama Client : " << C->info.nameClient;
            cout << "Project : " << C->info.nameProject;
            cout << "Developer : " << D->info.nameDev << endl;
            C = C->next;
        }
        D = D->next;
    }
}

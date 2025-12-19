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
    int total = 0;
    adrDeveloper D;
    adrClient C;
    D = LD.first;
    while (D != nullptr){
        C = D->firstClient;
        while (C != nullptr){
            total++;
            C = C->next;
        }
        D = D->next;
    }
    return total;
}

void showClient(ListDeveloper LD){
    cout << "========== SEMUA CLIENT =========\n" << endl;
    adrDeveloper D;
    adrClient C;
    D = LD.first;
    while (D != nullptr){
        C = D->firstClient;
        while (C != nullptr){
            cout << "Nama Client : " << C->info.nameClient;
            cout << "\nID Client : " << C->info.idClient;
            cout << "\nProject : " << C->info.nameProject;
            cout << "\nDeveloper : " << D->info.nameDev << endl;
            cout << endl;
            C = C->next;
        }
        D = D->next;
    }
}

void showClientSorted(adrDeveloper D){
    adrClient i, C, minNode, current;
    string temp;
    if(D == nullptr || D->firstClient == nullptr){
        cout << "Developer tidak memiliki client" << endl;
    }
    for(i = D->firstClient; i != nullptr; i = i->next){
        minNode = i;
        for(C = i->next; C != nullptr; C = C->next){
            if(C->info.nameClient < minNode->info.nameClient){
                minNode = C;
            }
        }
        if(minNode != i){
            temp = i->info.nameClient;
            i->info.nameClient = minNode->info.nameClient;
            minNode->info.nameClient = temp;
        }
    }
    cout << "Daftar client sesuai urutan abjad :\n";
    current = D->firstClient;
    while(current != nullptr){
        cout << current->info.nameClient << endl;
        current = current->next;
    }
}

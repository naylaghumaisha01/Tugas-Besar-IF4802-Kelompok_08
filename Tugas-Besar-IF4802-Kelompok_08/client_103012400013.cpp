#include "header.h"

adrClient createElmClient(string idClient, string nameClient, string nameProject) {
    adrClient C = new elmClient;
    C->info.idClient = idClient;
    C->info.nameClient = nameClient;
    C->info.nameProject = nameProject;
    C->next = nullptr;
    return C;
}

void insertClientFirst(adrDeveloper D, adrClient C){
    if(D->firstClient == nullptr){
        D->firstClient = C;
        C->next = nullptr;
    }else {
        C->next = D->firstClient;
        D->firstClient = C;
    }
}

void insertClientLast(adrDeveloper D, adrClient C){
    adrClient P;
    P = D->firstClient;
    if (D->firstClient == nullptr) {
        D->firstClient = C;
        C->next = nullptr;
    }else {
        while (P->next != nullptr) {
            P = P->next;
        }
        P->next = C;
        C->next = nullptr;
    }
}

void insertClientAfter(adrClient prec, adrClient C){
    if(prec != nullptr){
        C->next = prec->next;
        prec->next = C;
    }
}

void deleteClientFirst(adrDeveloper D, adrClient &C){
    if(D->firstClient == nullptr){
        C = nullptr;
    }else {
        C = D->firstClient;
        D->firstClient = C->next;
        C->next = nullptr;
    }

}

void deleteClientLast(adrDeveloper D, adrClient &C){
    adrClient P;
    P = D->firstClient;
    if(D->firstClient == nullptr){
        C = nullptr;
    }else if(D->firstClient->next == nullptr){
        C = D->firstClient;
        D->firstClient = nullptr;
        C->next = nullptr;
    }else {
        while(P->next->next != nullptr){
            P = P->next;
        }
        C = P->next;
        P->next = nullptr;
        C->next = nullptr;
    }
}

void deleteClientAfter(adrClient prec, adrClient &C){
    if(prec == nullptr || prec->next == nullptr){
        C = nullptr;
    }else {
    C = prec->next;
    prec->next = C->next;
    C->next = nullptr;
    }
}

adrClient searchClient(adrDeveloper D, string idClient) {
    if (D == nullptr || D->firstClient == nullptr) {
        return nullptr;
    }

    adrClient C = D->firstClient;
    while (C != nullptr) {
        if (C->info.idClient == idClient) {
            return C;
        }
        C = C->next;
    }

    return nullptr;
}

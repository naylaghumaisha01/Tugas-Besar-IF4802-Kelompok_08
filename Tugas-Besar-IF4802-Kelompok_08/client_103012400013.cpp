#include "header.h"

adrClient createElmClient(string idClient, string nameClient) {
    adrClient C = new elmClient;
    C->info.idClient = idClient;
    C->info.nameClient = nameClient;
    C->info.nameProject = "";
    C->next = nullptr;
    return C;
}

void addClient(adrDeveloper &D, adrClient C) {
    if (D == nullptr || C == nullptr) {
        cout << "Developer atau Client tidak valid." << endl;
        return;
    }

    if (D->firstClient == nullptr) {
        D->firstClient = C;
    } else {
        adrClient last = D->firstClient;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = C;
    }
    cout << "Client " << C->info.nameClient << " berhasil ditambahkan ke Developer " << D->info.nameDev << "." << endl;
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

void deleteClient(adrDeveloper D, string idClient) {
    if (D == nullptr || D->firstClient == nullptr) {
        cout << "Developer tidak valid atau tidak memiliki Client." << endl;
        return;
    }

    adrClient current = D->firstClient;
    adrClient prev = nullptr;
    string clientName;

    if (current != nullptr && current->info.idClient == idClient) {
        clientName = current->info.nameClient;
        D->firstClient = current->next;
        current->next = nullptr;
        delete current;
        cout << "Client " << clientName << " (ID: " << idClient << ") berhasil dihapus dari Developer " << D->info.nameDev << "." << endl;
        return;
    }

    while (current != nullptr && current->info.idClient != idClient) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        clientName = current->info.nameClient;
        prev->next = current->next;
        current->next = nullptr;
        delete current;
        cout << "Client " << clientName << " (ID: " << idClient << ") berhasil dihapus dari Developer " << D->info.nameDev << "." << endl;
    } else {
        cout << "Client dengan ID " << idClient << " tidak ditemukan pada Developer " << D->info.nameDev << "." << endl;
    }
}

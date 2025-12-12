#include "HEADER_H_INCLUDED"

int countClientsofDeveloper(adrDeveloper D) {
    if (D == NULL || D->firstClient == NULL) {
        return 0;
    }

    int count = 0;
    adrClient C = D->firstClient;
    while (C != NULL) {
        count++;
        C = C->next;
    }
    return count;
}

void showDeveloper(ListDeveloper LD) {
    if (LD.first == NULL) {
        cout << "\n[!] Daftar Developer kosong." << endl;
        return;
    }

    cout << "\n==========================================" << endl;
    cout << "          DAFTAR SEMUA DEVELOPER          " << endl;
    cout << "==========================================" << endl;

    adrDeveloper D = LD.first;
    int i = 1;

    while (D != NULL) {
        cout << i << ". ID: " << D->info.idDev
             << " | Nama: " << D->info.nameDev
             << " | Jumlah Klien: " << countClientsofDeveloper(D) << endl;

        D = D->next;
        i++;
    }
    cout << "==========================================" << endl;
}

void mostClientDeveloper(ListDeveloper LD) {
    if (LD.first == NULL) {
        cout << "\n[!] Daftar Developer kosong." << endl;
        return;
    }

    adrDeveloper D = LD.first;
    int maxClients = 0;

    while (D != NULL) {
        int currentClients = countClientsofDeveloper(D);
        if (currentClients > maxClients) {
            maxClients = currentClients;
        }
        D = D->next;
    }

    if (maxClients == 0) {
        cout << "\n[i] Tidak ada Developer yang memiliki Client saat ini." << endl;
        return;
    }

    cout << "\n===========================================================" << endl;
    cout << "      DEVELOPER DENGAN JUMLAH CLIENT TERBANYAK (" << maxClients << " CLIENT)" << endl;
    cout << "===========================================================" << endl;

    D = LD.first;
    while (D != NULL) {
        if (countClientsofDeveloper(D) == maxClients) {
            cout << "-> ID: " << D->info.idDev
                 << " | Nama: " << D->info.nameDev << endl;
        }
        D = D->next;
    }
    cout << "===========================================================" << endl;
}

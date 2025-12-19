#include "header.h"

ListDeveloper LD;
adrDeveloper D, P, precD;
adrClient C, precC;
string idD, idC, idAfter, nameD, nameC, project;

void menuAdmin(){
    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Admin============" << endl;
        cout << "|| 1. Developer                  ||" << endl;
        cout << "|| 2. Client                     ||" << endl;
        cout << "|| 0. back                       ||" << endl;
        cout << "===================================" << endl;
        cout << "Choose your option : ";
        cin >> option;

        switch(option) {
           case 1  :
              menuParent();
              continue;
           case 2  :
              menuChild();
              continue;
        }
    }
}


void menuParent(){
    int option = -99;
    while (option != 0){
        system("cls");
        cout << "============ Menu Developer============ " << endl;
        cout << "|| 1. insert first                    ||" << endl;
        cout << "|| 2. insert last                     ||" << endl;
        cout << "|| 3. insert after                    ||" << endl;
        cout << "|| 4. delete first                    ||" << endl;
        cout << "|| 5. delete last                     ||" << endl;
        cout << "|| 6. delete after                    ||" << endl;
        cout << "|| 7. search developer                ||" << endl;
        cout << "|| 8. show developer                  ||" << endl;
        cout << "|| 0. back                            ||" << endl;
        cout << "========================================" << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
            case 1:
                cout << "ID Developer : ";
                cin >> idD;
                cout << "Nama Developer : ";
                cin >> nameD;
                D = createElmDeveloper(idD, nameD);
                insertDevFirst(LD, D);
                cout << "Halo, " << nameD << "! data mu berhasil ditambahkan." << endl;
                system("pause");
            break;

            case 2:
                cout << "ID Developer : ";
                cin >> idD;
                cout << "Nama Developer : ";
                cin >> nameD;
                D = createElmDeveloper(idD, nameD);
                insertDevLast(LD, D);
                cout << "Halo, " << nameD << "! data mu berhasil ditambahkan." << endl;
                system("pause");
            break;

            case 3:
                cout << "Masukkan ID Developer setelah ID : ";
                cin >> idAfter;
                precD = searchDeveloper(LD, idAfter);
                if(precD != nullptr){
                    cout << "ID New Developer : ";
                    cin >> idD;
                    cout << "Nama Developer : ";
                    cin >> nameD;
                    D = createElmDeveloper(idD, nameD);
                    insertDevAfter(LD, precD, D);
                cout << "Halo, " << nameD << "! data mu berhasil ditambahkan." << endl;
                } else {
                    cout << "ID yang kamu masukkan tidak dapat ditemukan :(" << endl;
                }
                system("pause");
            break;

            case 4:
                deleteDevFirst(LD, D);
                cout << "Data telah dihapus!" << endl;
                system("pause");
            break;

            case 5  :
                deleteDevLast(LD, D);
                cout << "Data telah dihapus!" << endl;
                system("pause");
            break;

            case 6:
                cout << "Menghapus ID Developer setelah ID : ";
                cin >> idAfter;
                precD = searchDeveloper(LD, idAfter);
                if(precD != nullptr){
                    deleteDevAfter(LD, precD, D);
                    cout << "Data telah dihapus!" << endl;
                } else {
                    cout << "ID yang kamu masukkan tidak dapat ditemukan :(" << endl;
                }
                system("pause");
            break;

            case 7  :
                cout << "Cari ID Developer : ";
                cin >> idD;
                D = searchDeveloper(LD, idD);
                if(D != nullptr){
                    cout << "Data telah ditemukan!\n";
                    cout << D->info.nameDev << " adalah pemilik ID " << idD << endl;
                } else {
                    cout << "ID yang kamu masukkan tidak dapat ditemukan :(" << endl;
                }
                system("pause");
            break;

            case 8:
                showDeveloper(LD);
                system("pause");
            break;
        }
    }
}

void menuChild(){
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Client=============" << endl;
        cout << "|| 1. insert first                 ||" << endl;
        cout << "|| 2. insert last                  ||" << endl;
        cout << "|| 3. insert after                 ||" << endl;
        cout << "|| 4. delete first                 ||" << endl;
        cout << "|| 5. delete last                  ||" << endl;
        cout << "|| 6. delete after                 ||" << endl;
        cout << "|| 7. search client                ||" << endl;
        cout << "|| 8. show client                  ||" << endl;
        cout << "|| 0. back                         ||" << endl;
        cout << "=====================================" << endl;
        cout << "Choose your option : ";
        cin >> option;

        switch(option) {
            case 1:
                cout << "Masukkan ID Developer : ";
                cin >> idD;
                D = searchDeveloper(LD, idD);
                if(D != nullptr){
                    cout << "ID Client : ";
                    cin >> idC;
                    cout << "Nama Client : ";
                    cin >> nameC;
                    cout << "Nama Project : ";
                    cin >> project;
                    C = createElmClient(idC, nameC, project);
                    insertClientFirst(D, C);
                    cout << "Halo, " << nameC << "! data mu berhasil ditambahkan." << endl;
                } else {
                    cout << "Developer tidak ditemukan!" << endl;
                }
                system("pause");
            break;

            case 2:
                cout << "Masukkan ID Developer : ";
                cin >> idD;
                D = searchDeveloper(LD, idD);
                if(D != nullptr){
                    cout << "ID Client : ";
                    cin >> idC;
                    cout << "Nama Client : ";
                    cin >> nameC;
                    cout << "Nama Project : ";
                    cin >> project;
                    C = createElmClient(idC, nameC, project);
                    insertClientLast(D, C);
                    cout << "Halo, " << nameC << "! data mu berhasil ditambahkan." << endl;
                } else {
                    cout << "Developer tidak ditemukan!" << endl;
                }
                system("pause");
            break;

            case 3:
                cout << "Masukkan ID Developer : ";
                cin >> idAfter;
                D = searchDeveloper(LD, idAfter);
                if(D != nullptr){
                    cout << "Masukkan ID Client setelah ID : ";
                    cin >> idAfter;
                    precC = searchClient(D, idAfter);
                    if(precC != nullptr){
                        cout << "ID Client : ";
                        cin >> idC;
                        cout << "Nama Client : ";
                        cin >> nameC;
                        cout << "Nama Project : ";
                        cin >> project;
                        C = createElmClient(idC, nameC, project);
                        insertClientAfter(precC, C);
                        cout << "Halo, " << nameC << "! data mu berhasil ditambahkan." << endl;
                    } else {
                        cout << "ID yang kamu masukkan tidak dapat ditemukan :(" << endl;
                    }
                }
                system("pause");
            break;

            case 4:
                cout << "ID Developer : ";
                cin >> idD;
                D = searchDeveloper(LD, idD);
                if(D != nullptr){
                    deleteClientFirst(D, C);
                    cout << "Data telah dihapus!" << endl;
                }
                system("pause");
            break;

            case 5  :
                cout << "ID Developer : ";
                cin >> idD;
                D = searchDeveloper(LD, idD);
                if(D != nullptr){
                    deleteClientLast(D, C);
                    cout << "Data telah dihapus!" << endl;
                }
                system("pause");
            break;

            case 6:
                cout << "ID Developer : ";
                cin >> idD;
                D = searchDeveloper(LD, idD);
                if(D != nullptr){
                    cout << "ID Client setelah ID : ";
                    cin >> idAfter;
                    precC = searchClient(D, idAfter);
                    if(precC != nullptr){
                        deleteClientAfter(precC, C);
                        cout << "Data telah dihapus!" << endl;
                    }
                }
                system("pause");
            break;

            case 7  :
                cout << "ID Developer : ";
                cin >> idD;
                D = searchDeveloper(LD, idD);
                if(D != nullptr){
                    cout << "Cari ID Client: ";
                    cin >> idC;
                    C = searchClient(D, idC);
                    if(C != nullptr){
                        cout << "Data telah ditemukan!\n";
                        cout << C->info.nameClient << " adalah pemilik ID " << idC << endl;
                    } else {
                        cout << "ID yang kamu masukkan tidak dapat ditemukan :(" << endl;
                    }
                }
                system("pause");
            break;

            case 8:
                showClient(LD);
                system("pause");
            break;
        }
    }
}

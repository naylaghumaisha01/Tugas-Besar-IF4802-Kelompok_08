#include "header.h"

void menuUser(){
    ListDeveloper LD;
    createListDeveloper(LD);
    adrDeveloper D, precD;
    adrClient C, precC;
    string idD, idC, idAfter, nameD, nameC, project;
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "=============== Menu Studi Kasus ===============" << endl;
        cout << "||  1. Tambah Developer                       ||" << endl;
        cout << "||  2. Hapus Developer                        ||" << endl;
        cout << "||  3. Tambah Client                          ||" << endl;
        cout << "||  4. Hapus Client                           ||" << endl;
        cout << "||  5. Cari Developer                         ||" << endl;
        cout << "||  6. Cari Client                            ||" << endl;
        cout << "||  7. Hitung total client                    ||" << endl;
        cout << "||  8. Developer dengan client terbanyak      ||" << endl;
        cout << "||  9. Tampilkan Developer                    ||" << endl;
        cout << "|| 10. Tampilkan Client                       ||" << endl;
        cout << "|| 11. Tampilkan Client berdasarkan abjad     ||" << endl;
        cout << "|| 0. back                                    ||" << endl;
        cout << "================================================" << endl;
        cout << "Choose your option : ";
        cin >> option;

        switch(option) {
            case 1:
                cout << "ID Developer : ";
                cin >> idD;
                cout << "Nama Developer : ";
                cin >> nameD;
                D = createElmDeveloper(idD, nameD);
                insertDevLast(LD, D);
                cout << "Halo, " << nameD << "! data mu berhasil ditambahkan." << endl;
                system("pause");
            break;

            case 2 :
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

            case 3 :
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

            case 4 :
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

            case 5 :
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

            case 6 :
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

            case 7 :
                cout << "Total client yang telah terdaftar : " << totalClient(LD) << endl;
                system("pause");
            break;

            case 8 :
                cout << "Developer dengan client terbanyak adalah : ";
                mostClientDeveloper(LD);
                system("pause");
            break;

            case 9 :
                showDeveloper(LD);
                system("pause");
            break;

            case 10 :
                showClient(LD);
                system("pause");
            break;

            case 11 :
                showClientSorted(D);
                system("pause");
            break;
        }
    }
}

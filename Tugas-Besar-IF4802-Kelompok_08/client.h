#ifndef MULTILIST_H
#define MULTILIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ProyekNode *address_proyek;
typedef struct KlienNode *address_klien;
typedef struct DeveloperNode *address_developer;

typedef struct ProyekNode {
    int id_proyek;
    char nama_proyek[100];
    char status[50];

    address_proyek next_proyek;
} Proyek;

typedef struct KlienNode {
    int id_klien;
    char nama_klien[100];
    address_proyek first_proyek;
    address_klien next_klien;
} Klien;

typedef struct DeveloperNode {
    int id_developer;
    char nama_developer[100];
    address_klien first_klien;
    address_developer next_developer;
} Developer;

typedef struct {
    address_developer first_developer;
} MultiList;

void createList(MultiList *L);
address_developer createDeveloper(int id, const char *nama);
void insertDeveloper(MultiList *L, address_developer newDev);
address_developer findDeveloper(MultiList L, int id);
void deleteDeveloper(MultiList *L, int id);
address_klien createKlien(int id, const char *nama);
void insertKlien(address_developer dev, address_klien newKlien);
address_klien findKlien(MultiList L, int id_developer, int id_klien);
void deleteKlien(address_developer dev, int id_klien);
address_proyek createProyek(int id, const char *nama, const char *status);
void insertProyek(address_klien klien, address_proyek newProyek);
address_proyek findProyek(address_klien klien, int id_proyek);
void updateProyekStatus(address_proyek proyek, const char *newStatus);
void deleteProyek(address_klien klien, int id_proyek);
void displayAll(MultiList L);

#endif

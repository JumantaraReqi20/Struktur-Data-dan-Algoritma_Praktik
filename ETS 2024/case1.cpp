#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <string.h>
#include "case1.h"
#include <stdbool.h>

// #include "ADTLIST.h"
#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

kt* searchKota(kt* first, infotype nama_Kota) {
    kt* bantu = first;
    bool temu = false;
    while (bantu != Nil && !temu) {
        if (strcmp(bantu->kota, nama_Kota) == 0) {
            temu = true;
        } else {
            bantu = bantu->next2;
        }
    }
    return bantu;
}

kt* allocateKota(infotype name) {
    kt* newNode = (kt*)malloc(sizeof(kt));
    if (newNode == Nil) {
        printf("Alokasi Memori Gagal!\n");
        exit(1);
    } else {
        strcpy(newNode->kota, name);
        newNode->next1 = Nil;
        newNode->next2 = Nil;
        return newNode;
    }
}

void tambahKota(kt** kota, infotype namaKota) {
    kt* newNode = allocateKota(namaKota);
    if (*kota == Nil) {
        *kota = newNode;
    } else {
        kt* bantu = *kota;
        while (bantu->next2 != Nil) {
            bantu = bantu->next2;
        }
        bantu->next2 = newNode;
    }
}


void ubahKota(kt* first, infotype namaKota, infotype newNamaKota) {
    kt* kota = searchKota(first, namaKota);
    if (kota == Nil) {
        printf("Nama kota tidak ditemukan!\n");
        return;
    }
    strcpy(kota->kota, newNamaKota);
}

bool isEmpty(kt* first) {
    return (first == Nil);
}

void tambahWarga(kt* first, infotype namaKota, infotype namaWarga) {
    kt* kota = searchKota(first, namaKota);
    if (kota == Nil) {
        printf("Nama kota tidak ditemukan!\n");
        return;
    }
    address newWrga = (address)malloc(sizeof(mhs));
    if (newWrga == Nil) {
        printf("Alokasi memori gagal!");
        exit(1);
    } else {
        strcpy(newWrga->info, namaWarga);
        newWrga->next = Nil;
    }
    if (kota->next1 == Nil) {
        kota->next1 = newWrga;
    } else {
        address lastWrga = kota->next1;
        while (lastWrga->next != Nil) {
            lastWrga = lastWrga->next;
        }
        lastWrga->next = newWrga;
    }
}

void displayMhs(kt* kota) {
    printf("DAFTAR WARGA\n");
    if (kota->next1 != Nil) {
        address current = kota->next1;
        while (current != Nil) {
            printf("\tNama\t: %s\n", current->info);
            current = current->next;
        }
    }
}

void displayKota(kt* first) {
    printf("\n\n________DAFTAR KOTA________\n");
    kt* bantu = first;
    int counter = 1;
    while (bantu != Nil) {
        printf("\n%d. %s\n", counter, bantu->kota);
        displayMhs(bantu);
        bantu = bantu->next2;
        counter++;
    }
}


void deallocAllMhs(address first) {
    if (first != Nil) {
        deallocAllMhs(first->next); // Rekursi untuk node selanjutnya
        free(first); // Bebaskan memori node saat ini
    }
}



void deallocKota(kt** first, infotype kota) {
    kt* bantu = *first;
    kt* prev = NULL;

    while (bantu != NULL && strcmp(bantu->kota, kota) != 0) {
        prev = bantu;
        bantu = bantu->next2;
    }

    if (bantu == NULL) {
        printf("Nama kota tidak ditemukan!\n");
        return;
    }

    address warga = bantu->next1;
    deallocAllMhs(warga);

    if (prev == NULL) {
        *first = bantu->next2;
    } else {
        prev->next2 = bantu->next2;
    }
    free(bantu);
}

void deallocAllKota(kt* first) {
    if (first != Nil) {
        address warga = first->next1;
        deallocAllMhs(warga); // Bebaskan memori linked list mhs
        kt* next = first->next2;
        free(first); // Bebaskan memori node kt saat ini
        deallocAllKota(next); // Rekursi untuk node kt selanjutnya
    }
}

void ubahWarga(kt* first, infotype kota, infotype namaWarga, infotype namaBaru)
{
    kt* temp = searchKota(first, kota);

    address warga = temp->next1;
    bool temu = false;

    while (warga != Nil && !temu){
        if (strcmp(warga->info, namaWarga)==0){
            temu = true;
        } else {
            warga = warga->next;
        }
    }

    strcpy(warga->info, namaBaru);
}

void deallocWarga(kt** first, infotype kota, infotype namaWarga) {

    kt* temp = searchKota(*first, kota);

    address warga = temp->next1;
    address prev = Nil;
    bool temu = false;

    while (warga != Nil && !temu){
        if (strcmp(warga->info, namaWarga)==0){
            temu = true;
        } else {
            prev = warga;
            warga = warga->next;
        }
    }
    
    if (warga == Nil){
        printf("Kota tidak ditemukan!\n");
        return;
    }

    if (prev == Nil){
        temp->next1 = warga->next;
    } else {
        prev->next = warga->next;
    }
    free(warga);
}
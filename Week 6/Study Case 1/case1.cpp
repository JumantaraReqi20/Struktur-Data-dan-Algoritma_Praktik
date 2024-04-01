#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <string.h>
#include "case1.h"

// #include "ADTLIST.h"
#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL
#define MAX_KOTA 8
kt ArrayKota[MAX_KOTA];
int indexKota = 0;

kt* searchKota(infotype nama_Kota){
    int index = 0;
    kt* currentKota = Nil;
    while (index < MAX_KOTA){
        if (strcmp(ArrayKota[index].kota, nama_Kota) == 0){
            currentKota = &ArrayKota[index];
        }
        index++;
    }

    return currentKota;
}


void tambahKota(infotype namaKota){
    if(indexKota > MAX_KOTA ){
        printf("Mohon maaf, Array sudah penuh!\n");
        return;
    }

    strcpy(ArrayKota[indexKota].kota, namaKota);
    ArrayKota[indexKota].next1 = Nil;
    ArrayKota[indexKota].isDeleted = false;

    indexKota++;
}


void ubahKota(infotype namaKota, infotype newNamaKota)
{
    kt* kota = searchKota(namaKota);

    if (kota == Nil){
        printf("Nama kota tidak ditemukan!\n");
        return;
    }

    strcpy((*kota).kota, newNamaKota);
}

bool isEmpty(){
    if(indexKota < 0){
        return true;
    } else {
        return false;
    }
}

void tambahWarga(infotype namaKota, infotype namaWarga){
    kt* kota = searchKota(namaKota);
    
    if (kota == Nil){
        printf("Nama kota tidak ditemukan!\n");
        return;
    }

    address newMhs = (address) malloc (sizeof(mhs));
    if(newMhs == Nil){
        printf("Alokasi memori gagal!");
        exit(1);
    } else {
        strcpy(newMhs->info, namaWarga);
        newMhs->next = Nil;
    }

    if ((*kota).next1 == Nil){
        (*kota).next1 = newMhs;
    } else {
        address lastMhs = (*kota).next1;
        while (lastMhs->next != Nil){
            lastMhs = lastMhs->next;
        }
        lastMhs->next = newMhs;
    }
}


void displayMhs(kt kota){
    printf("\n___DAFTAR WARGA____\n");
    if (kota.next1 != Nil){
        address current = kota.next1;
        while (current != Nil){
            printf("\tNama\t: %s\n", current->info);
            current = current->next;
        }
    }
}

void displayKota(){
    printf("______DAFTAR KOTA______\n");
    for (int index = 0; index < indexKota; index++){
        if (!ArrayKota[index].isDeleted){
            printf("\n\n%d. %s", index+1, ArrayKota[index].kota);
            displayMhs(ArrayKota[index]);
        }
    }
    getch();
}

void deallocAllMhs(address first){
    if(first->next != Nil){
        deallocAllMhs(first->next);
    }

    free(first);
}


void deleteKota(infotype namaKota){
    kt* kota = searchKota(namaKota);
    if(kota == Nil || kota->isDeleted){
        printf("Kota tidak ditemukan!\n");
        sleep(3);
        return;
    }

    if(kota->next1 != Nil){
        deallocAllMhs(kota->next1);
    }
    kota->next1 = Nil;
    kota->isDeleted = true;
}
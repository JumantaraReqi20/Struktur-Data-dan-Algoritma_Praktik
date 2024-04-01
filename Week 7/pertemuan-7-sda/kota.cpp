#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "kota.h"

int IndexKota_ = 0;
kt ArrayKota_[MAX_KOTA];

/**
 * Mencaru kota dalam array kota
*/
kt* cariKotaa(infotype namaKota){
    int index = 0;
    kt* currentKota = NULL;

    while(index < IndexKota_){
        if(strcmp(ArrayKota_[index].kota, namaKota) == 0){
            currentKota = &ArrayKota_[index];
            break;
        }

        index++;
    }

    return currentKota;
}

/**
 * Mendealokasi semua node mahasiswa
*/
void deallocAllMhs(address first){
    if(first->next != NULL){
        deallocAllMhs(first->next);
    }

    free(first);
}

void tambahKota(infotype namaKota){
    if(IndexKota_ + 1 > MAX_KOTA){
        printf("ARRAY KOTA SUDAH PENUH!\n");
        sleep(2);
        return;
    }

    strcpy(ArrayKota_[IndexKota_].kota, namaKota);
    ArrayKota_[IndexKota_].next1 = NULL;
    ArrayKota_[IndexKota_].isDeleted = false;

    IndexKota_++;
}

void tampilMahasiswaDalamKota(kt kota){
    printf("-#- ISI MAHASISWA -#-\n");
    if(kota.next1 != NULL){
        address currentMhs = kota.next1;
        while(currentMhs != NULL){
            printf("\t NAMA\t: %s\n", currentMhs->info);
            currentMhs = currentMhs->next;
        }
    }
}

void tampilKota(){
    printf("########## LIST KOTA ##########\n");
    for(int index = 0; index < IndexKota_; index++){
        if(!ArrayKota_[index].isDeleted){
            printf("%2d. %s\n", index + 1, ArrayKota_[index].kota);
            tampilMahasiswaDalamKota(ArrayKota_[index]);
        }
    }
}

void tambahMahasiswaDalamKota(infotype namaKota, infotype namaMhs){
    kt* kota = cariKotaa(namaKota);

    if(kota == NULL){
        printf("KOTA TIDAK DITEMUKAN!\n");
        sleep(2);
        return;
    }
    
    address mhsBaru = (address) malloc(sizeof(mhs));

    if(mhsBaru == NULL){
        printf("ALOKASI GAGAL!\n");
        exit(1);
    }

    strcpy(mhsBaru->info, namaMhs);
    mhsBaru->next = NULL;

    if((*kota).next1 == NULL){
        (*kota).next1 = mhsBaru;
    } else {
        address lastMhs = (*kota).next1;
        while(lastMhs->next != NULL){
            lastMhs = lastMhs->next;
        }

        lastMhs->next = mhsBaru;
    }
}

void deleteKota(infotype namaKota){
    kt* kota = cariKotaa(namaKota);
    if(kota == NULL || kota->isDeleted){
        printf("KOTA TIDAK DITEMUKAN!\n");
        sleep(2);
        return;
    }

    if(kota->next1 != NULL){
        deallocAllMhs(kota->next1);
    }

    kota->next1 = NULL;
    kota->isDeleted = true;
}
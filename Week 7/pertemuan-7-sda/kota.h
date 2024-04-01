#ifndef KOTAA_H
#define KOTAA_H

#define MAX_KOTA 7

#include<stdbool.h>

// struktur data SLL
typedef char infotype[100];
typedef struct tElmtList *address;
typedef struct tElmtList
{
    infotype info;
    address next;
} mhs;

// struktur data array
typedef struct
{
    infotype kota;
    address next1;
    bool isDeleted;
} kt;

// Menyimpan jumlah kota
extern int IndexKota_;

// Membuat array kota
extern kt ArrayKota_[MAX_KOTA];

/**
 * Menambahkan kota baru ke dalam array
*/
void tambahKota(infotype);

/**
 * Menampilkan kota yang ada
*/
void tampilKota();

/**
 * Menambah mahasiswa dalam kota
*/
void tambahMahasiswaDalamKota(infotype namaKota, infotype namaMhs);

/**
 * Menghapus suatu kota dan semua mahasiswa
*/
void deleteKota(infotype);

#endif
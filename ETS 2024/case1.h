#ifndef case1_h
#define case1_h
#include <stdbool.h>

#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

typedef char infotype[100];
typedef struct tElmtList *address;
typedef struct tElmtList
{
    /** data **/
    infotype info;
    address next;
}mhs;

typedef struct kt
{
    /** data **/
    infotype kota;
    address next1;
    struct kt* next2;
}kt;

extern int indexKota;

/**Method yang digunakan**/
kt* searchKota(kt* first, infotype nama_Kota);

void tambahKota(kt** kota, infotype namaKota);

void ubahKota(kt* first, infotype namaKota, infotype newNamaKota);

void deallocKota(kt** first, infotype kota);

void tambahWarga(kt* first, infotype namaKota, infotype namaWarga);

void ubahWarga(kt* first, infotype kota, infotype namaWarga, infotype namaBaru);

void deallocWarga(kt** first, infotype kota, infotype warga);

void displayMhs(kt* kota);

void displayKota(kt* first);

void deallocAllMhs(address first);

void deallocAllKota(kt* first);

bool isEmpty(kt* first);

#endif
#ifndef case1_h
#define case1_h

typedef char infotype[100];
typedef struct tElmtList *address;
typedef struct tElmtList
{
    /* data */
    infotype info;
    address next;
}mhs;

typedef struct kt
{
    /* data */
    infotype kota;
    address next1;
    bool isDeleted;
}kt;

extern int indexKota;

/**Method yang digunakan*/

kt* searchKota(infotype nama_Kota);

void tambahKota(infotype namaKota);

void tambahWarga(infotype namaKota, infotype namaMhs);

void displayMhs(kt kota);

void displayKota();

void deallocAllMhs(address first);

void deleteKota(infotype namaKota);

void ubahKota(infotype namaKota, infotype newNamaKota);

bool isEmpty();

void editNamaWarga(infotype kota, infotype namaLama, infotype namaBaru);

#endif
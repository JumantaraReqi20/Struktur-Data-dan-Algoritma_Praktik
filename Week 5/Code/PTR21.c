/*----------------------------------------------------------------------------*/
/* File			: PTR21.cpp
/* Deskripsi	: contoh deklarasi list dan penggunaan single linked list
/* Dibuat oleh 	: Tim Dosen SDP
/* Dimodifikasi oleh : Reqi Jumantara Hapid
/* Tanggal 		: 13-03-2024
*/

/*----------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Definisi akses komponen type, standard kuliah Algoritma dan pemrograman */
#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

/* Element list linier */
typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist
{
    infotype info;
    address next;
} ElmtList;

/* Alternatif Lain
typedef struct nElmtlist {
infotype info;
struct nElmtlist *next;
} ElmtList1;
ElmtList1 *address1;
*/

/* Method yang digunakan */
ElmtList *createNode(int value);
address searchPos(address L, int value);
void insertBetween(address list, int value, int key);
void displayLinkedList(address L);

/* Program Utama */
int main()
{
    /* kamus */
    address First;
    address P, Q;

    /* program */
    /* Create list kosong */
    First = Nil;
    /* Alokasi, insert as first elemen */
    P = createNode(10);
    First = P;

    /* Alokasi, insert as first elemen */
    Q = createNode(20);
    next(Q) = First;
    First = Q;

    /* Alokasi, insert as first elemen */
    P = createNode(30);
    next(P) = First;
    First = P;

    /* Alokasi, insert as first elemen */
    Q = createNode(40);
    next(Q) = First;
    First = Q;

    /* Alokasi, insert as last elemen */
    Q = createNode(60);
    address current;
    current = First;
    while (next(current) != Nil)
    {
        current = next(current);
    }
    next(current) = Q;
    /*End alokasi, insert as last elemen */

    insertBetween(First, 35, 30);

    displayLinkedList(First);

    return 0;
}

// Membuat Node Baru
ElmtList* createNode(int value)
/*  IS : Node belum terdefinisi
    FS : Node terbentuk dan 'data' sudah terisi oleh 'value'
         Alokasi memori berhasil jika newNode tidak NULL
*/
{
    ElmtList *newNode = (ElmtList *)malloc(sizeof(ElmtList));
    if (newNode == NULL)
    {
        printf("Error! Memory tidak cukup.\n");
        exit(1);
    }

    info(newNode) = value;
    next(newNode) = Nil;

    return newNode;
}

// Mencari posisi dari suatu nilai
/* Mengembalikan alamat 'list' yang memiliki nilai 'data' yang dicari*/
address searchPos(address L, int value)
{
    address current = L;
    bool temu = 0;
    while ((!temu) && (current != NULL))
    {
        if (info(current) == value)
        {
            temu = 1;
            return current; // key ditemukan
        }
        else
        {
            current = next(current);
        }
    }
    return NULL; // key tidak ditemukan
}

// Fungsi untuk Menambahkan Node di Antara Dua Node yang Ada
void insertBetween(address list, int value, int key)
/*  IS : Linked list list mungkin kosong atau memiliki node-node di dalamnya.
    FS : Sebuah node baru dengan nilai value telah disisipkan di antara dua node yang sudah ada dalam linked list.
         Node baru ini memiliki posisi setelah node dengan nilai key.
*/
{
    address newNode = createNode(value);

    if (list == NULL)
    {
        printf("Linked List kosong, tidak ada node untuk disisipkan.\n");
        return;
    }

    address position = searchPos(list, key);
    if (position == NULL)
    {
        printf("Key tidak ditemukan dalam linked list\n");
        return;
    }

    next(newNode) = next(position);
    next(position) = newNode;
}

// Menampilkan Isi Linked List
void displayLinkedList(address L) 
	/*	IS : Layar kosong
		FS : Layar menampilkan isi 'data' dari setiap node pada linked list tersebut
	*/
{
    address current = L;
    if (current == NULL) {
        printf("Linked List kosong.\n");
        return;
    }
    printf("Isi Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->info);
        current = current->next;
    }
    printf("NULL\n");
}
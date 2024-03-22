#ifndef ADTLIST_h
#define ADTLIST_h

#include <stdio.h>
#include <stdlib.h>
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
address createNode(int value);
/*  IS : Node belum terdefinisi
    FS : Node terbentuk dan 'data' sudah terisi oleh 'value'
         Alokasi memori berhasil jika newNode tidak NULL
*/

void insertAtBeginning(address *list, int value);
/*  IS : Linked list list mungkin kosong atau memiliki node-node di dalamnya.
    FS : Sebuah node baru dengan nilai value telah ditambhkan ke dalam bagian 
    awal single linked list tersebut.
*/

void insertBetween(address list, int value, int key);
/*  IS : Linked list list mungkin kosong atau memiliki node-node di dalamnya.
    FS : Sebuah node baru dengan nilai value telah disisipkan di antara dua node yang sudah ada dalam linked list.
         Node baru ini memiliki posisi setelah node dengan nilai key.
*/

void insertLast(address L, infotype value);
/*  IS : Linked list list mungkin kosong atau memiliki node-node di dalamnya.
    FS : Sebuah node baru dengan nilai value di tambahkan setelah node terakhir yang sudah ada dalam linked list.
*/

infotype Del_Beginning (address *list);
/* Mengembalikan nilai dari 'info' pada node yang dihapus di awal pada linked list*/

infotype Del_Last (address *list);
/* Mengembalikan nilai dari 'info' pada node yang dihapus di akhir pada linked list*/

infotype Del_Between(address *list, infotype value);
/* Mengembalikan nilai dari 'info' pada node yang dihapus setelah node tertentu pada linked list*/

void update(address list, infotype value, infotype newValue);
/*  IS : Linked list list mungkin kosong atau memiliki node-node di dalamnya.
    FS : Sebuah node sudah memiliki nilai 'info' yang baru.
*/

int getFirst(address list);
/*Mengembalikan nilai 'data' dari node pertama dalam linked list tersebut*/

int getLast(address list);
/*Mengembalikan nilai 'data' dari node terakhir dalam linked list tersebut*/

void displayList(address list);
/*	IS : Layar kosong
	FS : Layar menampilkan isi 'data' dari setiap node pada linked list tersebut
*/

address searchPos(address L, int value);
/* Mengembalikan alamat 'list' yang memiliki nilai 'info' yang dicari*/

int jumlahNode(address list);
/*Mengembalikan jumlah node yang ada dalam sebuah linked list*/

#endif
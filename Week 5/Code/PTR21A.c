/*----------------------------------------------------------------------------*/
/* File			    : PTR21.cpp
/* Deskripsi	    : contoh deklarasi list dan penggunaan single linked list
/* Dibuat oleh 	    : Tim Dosen SDP
/* Dimodifikasi oleh: Reqi Jumantara Hapid (231524023)
/* Tanggal 		    : 13-03-2024
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
address createNode(int value);
address searchPos(address L, int value);
void insertAtBeginning(address *list, int value);
void insertBetween(address list, int value, int key);
void insertLast(address L, infotype value);
infotype Del_Beginning (address *list);
infotype Del_Last (address *list);
infotype Del_Between(address *list, infotype value);
void displayList(address list);
void update(address list, infotype value, infotype newValue);


/* Program Utama */
int main()
{
    /* kamus */
    address First;

    /********************* PROGRAM *********************/

    /* Create list kosong */
    First = Nil;
    /* Alokasi, insert as first elemen */
    insertAtBeginning(&First, 10);
    insertAtBeginning(&First, 20);
    insertAtBeginning(&First, 30);
    insertAtBeginning(&First, 40);
    insertAtBeginning(&First, 50);
    insertAtBeginning(&First, 70);
    insertAtBeginning(&First, 80);
    insertAtBeginning(&First, 90);
    insertAtBeginning(&First, 100);


    /* Alokasi, insert as last elemen */
    insertLast(First, 60);

    /*Change*/
    // update(First,40, 45);

    /*Insert di antara dua node*/
    insertBetween(First, 35, 30);

    /*Delete node di awal*/
    infotype deleted = Del_Beginning(&First);

    /*Delete node di akhir*/
    infotype deleted_last = Del_Last (&First);

    /*Delete node di tengah*/
    infotype deleted_mid = Del_Between(&First, 70);

    displayList(First);

    printf("\nIsi yang dihapus di awal: %d", deleted);
    printf("\nIsi yang dihapus di akhir: %d", deleted_last);
    printf("\nIsi yang dihapus di tengah: %d", deleted_mid);
    

    return 0;
}

/*****START Add Node*****/
/* Method untuk membuat Node Baru*/
address createNode(int value)
/*  IS : Node belum terdefinisi
    FS : Node terbentuk dan 'data' sudah terisi oleh 'value'
         Alokasi memori berhasil jika newNode tidak NULL
*/
{
    address newNode = (address)malloc(sizeof(ElmtList));
    if (newNode == NULL)
    {
        printf("Error! Memory tidak cukup.\n");
        exit(1);
    }

    info(newNode) = value;
    next(newNode) = Nil;

    return newNode;
}

/* Menambahkan node di awal list*/
void insertAtBeginning(address *list, int value)
/*  IS : Linked list list mungkin kosong atau memiliki node-node di dalamnya.
    FS : Sebuah node baru dengan nilai value telah ditambhkan ke dalam bagian 
    awal single linked list tersebut.
*/
{
    address newNode = createNode(value);
    if (newNode == NULL)
    {
        printf("Error! Alokasi memori gagal!");
    }
    else if (*list == Nil)
    {
        *list = newNode;
    }
    else
    {
        next(newNode) = *list;
        *list = newNode;
    }
}

/* Fungsi untuk Menambahkan Node di Antara Dua Node yang Ada*/
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
        exit;
    }

    next(newNode) = next(position);
    next(position) = newNode;
}

/* Menambahkan node di akhir list*/
void insertLast(address L, infotype value)
/*  IS : Linked list list mungkin kosong atau memiliki node-node di dalamnya.
    FS : Sebuah node baru dengan nilai value di tambahkan setelah node terakhir yang sudah ada dalam linked list.
*/
{
    address temp = createNode(value);
    if (L == Nil){
        printf("List masih kosong!\n");
    }
    address current = L;
    while (next(current) != Nil){
        current = next(current);
    }
    next(current) = temp;
}
/*****END Add Node*****/


/*****START Delete Node*****/
/* Menghapus node di awal list*/
/* Mengembalikan nilai dari 'info' pada node yang dihapus di awal linked list*/
infotype Del_Beginning (address *list)
{
    infotype value;

    if (*list == Nil)
    {
        printf("\nUnderflow! List masih kosong\n");
    }
    value = (*list)->info;
    address temp = *list;
    *list = (*list)->next;
    free(temp);

    return value;
}

/* Menghapus node di akhir*/
/* Mengembalikan nilai dari 'info' pada node yang dihapus di akhir pada linked list*/
infotype Del_Last (address *list)
{
    address secondLast = *list;
    infotype value;

    if (secondLast == Nil){
        printf("\nUnderflow! List masih kosong\n");
    }
    while ((secondLast)->next->next != Nil){
        (secondLast) = (secondLast)->next;
    }

    value = (secondLast)->next->info;
    free((secondLast)->next);
    (secondLast)->next = Nil;

    return value;
}

/* Menghapus node di tengah, setelah suatu nilai tertentu*/
/* Mengembalikan nilai dari 'info' pada node yang dihapus setelah node tertentu pada linked list*/
infotype Del_Between(address *list, infotype value) {
    address current = *list;
    address prev = NULL;
    infotype back = -1; // Inisialisasi dengan nilai default yang valid

    while (current != NULL && current->info != value) {
        prev = current;
        current = current->next;
    }

    if (current != Nil && current->next != Nil) {
        address nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        back = nodeToDelete->info;
        free(nodeToDelete);
    } else {
        printf("Node dengan nilai tersebut tidak ditemukan\n");
        // Tidak perlu mengembalikan nilai default karena sudah diinisialisasi di awal
    }

    return back;
}
/*****END Delete Node*****/

/*****START Update Node*****/
/*Update Info*/
void update (address list, infotype value, infotype newValue)
/*  IS : Linked list list mungkin kosong atau memiliki node-node di dalamnya.
    FS : Sebuah node sudah memiliki nilai 'info' yang baru.
*/
{
    address nodeChange = searchPos(list, value);
    if(nodeChange == Nil){
        printf("Info tidak ditemukan!\n");
    }
    
    nodeChange->info = newValue;
}
/*****END Update Node*****/

/******START Retrieve******/
// Retrieve: Mendapatkan Nilai dari Node Pertama
/*Mengembalikan nilai 'data' dari node pertama dalam linked list tersebut*/
int getFirst(address list) {
    if (list == NULL) {
        printf("Linked List kosong.\n");
        exit(1);
    }
    return list->info;
}

// Retrieve: Mendapatkan Nilai dari Node Terakhir
/*Mengembalikan nilai 'data' dari node terakhir dalam linked list tersebut*/
int getLast(address list) {
    if (list == NULL) {
        printf("Linked List kosong.\n");
        exit(1);
    }
    
    address current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    return current->info;
}

/* Menampilkan info dalam seluruh node */
void displayList(address list)
/*	IS : Layar kosong
	FS : Layar menampilkan isi 'data' dari setiap node pada linked list tersebut
*/
{
    address current = list;
    while (current != Nil)
    {
        printf("%d -> ", info(current));
        current = next(current);
    }
}

// Mencari posisi dari suatu nilai
/* Mengembalikan alamat 'list' yang memiliki nilai 'info' yang dicari*/
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

// Fungsi untuk Mendapatkan Jumlah Node dalam Linked List
/*Mengembalikan jumlah node yang ada dalam sebuah linked list*/
int jumlahNode (address head){
    int count;
    address current = head;
    while (current != Nil){
        current = current->next;
        count++;
    }

    return count;
}
/******END Retrieve******/
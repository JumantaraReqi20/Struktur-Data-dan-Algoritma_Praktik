#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "ADTLIST.h"

/*****START Add Node*****/
/* Method untuk membuat Node Baru*/
address createNode(infotype value)
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

    strcpy(info(newNode), value);
    next(newNode) = Nil;

    return newNode;
}

/* Menambahkan node di awal list*/
void insertAtBeginning(address *list, infotype value)
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
void insertBetween(address list, infotype value, infotype key)
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
        exit(EXIT_SUCCESS);
    }

    next(newNode) = next(position);
    next(position) = newNode;
}

/* Menambahkan node di akhir list*/
void insertLast(address L, infotype value)
/*  IS : Linked list list mungkin kosong atau memiliki node-node di dalamnya.
    FS : Sebuah node baru dengan nilai value telah disisipkan di antara dua node yang sudah ada dalam linked list.
         Node baru ini memiliki posisi setelah node dengan nilai key.
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
/* Mengembalikan nilai dari 'info' pada node yang dihapus*/
// infotype Del_Beginning (address *list)
// {
//     infotype* value;

//     if (*list == Nil)
//     {
//         printf("\nUnderflow! List masih kosong\n");
//     }
//     strcpy(*value, info((*list)));
//     address temp = *list;
//     *list = (*list)->next;
//     free(temp);

//     return value;
// }

/* Menghapus node di akhir*/
/* Mengembalikan nilai dari 'info' pada node yang dihapus*/
// infotype Del_Last (address *list)
// {
//     address secondLast = *list;
//     infotype value;

//     if (secondLast == Nil){
//         printf("\nUnderflow! List masih kosong\n");
//     }
//     while ((secondLast)->next->next != Nil){
//         (secondLast) = (secondLast)->next;
//     }
//     strcpy(value, (secondLast)->next->info);
//     free((secondLast)->next);
//     (secondLast)->next = Nil;

//     return value;
// }

/* Menghapus node di tengah, setelah suatu nilai tertentu*/
/* Mengembalikan nilai dari 'info' pada node yang dihapus*/
// infotype Del_Between(address *list, infotype value) {
//     address current = *list;
//     infotype back = ""; // Inisialisasi dengan nilai default yang valid

//     while (current != NULL && current->info != value) {
//         current = current->next;
//     }

//     if (current != Nil && current->next != Nil) {
//         address nodeToDelete = current->next;
//         current->next = nodeToDelete->next;
//         strcpy(back, info(nodeToDelete));
//         free(nodeToDelete);
//     } else {
//         printf("Node dengan nilai tersebut tidak ditemukan\n");
//         // Tidak perlu mengembalikan nilai default karena sudah diinisialisasi di awal
//     }

//     return back;
// }
/*****END Delete Node*****/

/*****START Update Node*****/
/*Update Info*/
void update (address list, infotype value, infotype newValue)
/*  IS : Linked list list mungkin kosong atau memiliki node-node di dalamnya.
    FS : Sebuah node baru dengan nilai value telah disisipkan di antara dua node yang sudah ada dalam linked list.
         Node baru ini memiliki posisi setelah node dengan nilai key.
*/
{
    address nodeChange = searchPos(list, value);
    if(nodeChange == Nil){
        printf("Info tidak ditemukan!\n");
    }
    
    strcpy(info(nodeChange), newValue);
}
/*****END Update Node*****/

/******START Retrieve******/
// Retrieve: Mendapatkan Nilai dari Node Pertama
/*Mengembalikan nilai 'data' dari node pertama dalam linked list tersebut*/
// int getFirst(address list) {
//     if (list == NULL) {
//         printf("Linked List kosong.\n");
//         exit(1);
//     }
//     return list->info;
// }

// Retrieve: Mendapatkan Nilai dari Node Terakhir
/*Mengembalikan nilai 'data' dari node terakhir dalam linked list tersebut*/
// int getLast(address list) {
//     if (list == NULL) {
//         printf("Linked List kosong.\n");
//         exit(1);
//     }
    
//     address current = list;
//     while (current->next != NULL) {
//         current = current->next;
//     }
//     return current->info;
// }

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
/* Mengembalikan alamat 'list' yang memiliki nilai 'data' yang dicari*/
address searchPos(address L, infotype value)
{
    address current = L;
    bool temu = 0;
    while ((!temu) && (current != NULL))
    {
        if ((strcmp(info(current), value)==0))
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "ADTLIST.h"
#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

typedef char infotype[100];
typedef struct tElmtList *address;
typedef struct kt *address1;
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
}kt;

kt A[100];
mhs Mahasiswa[100];

address createNode(infotype value);
void insertAtBeginning(address *list, infotype value);
void insertLast(address *head, infotype value);
void displayList(address list);


int main(){
    address First;
    // address1 First1;

    // int index;
    strcpy(A[0].kota, "Bandung");
    strcpy(A[1].kota, "Jakarta");

    //Menambahkan di dekat array
    insertAtBeginning(&A[0].next1, "Reqi");
    // A[0].next1 = First;

    insertAtBeginning(&First, "Agus");
    // insertAtBeginning(&First, "yakk");
    // insertAtBeginning(&First, "sadh");
    // insertAtBeginning(&First, "fuiii");
    
    insertLast(&First, "Yuhuu");

    displayList(First);
    // printf("%s", First->next->info);
    // printf("%s", First1->info);

    return 0;
}

void ins_kota(A[no_kota].next1){
    
}


address createNode (infotype nama){
    address 
}

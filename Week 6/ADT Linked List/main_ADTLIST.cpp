#include "ADTLIST.h"

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
    update(First,40, 45);

    /*Insert di antara dua node*/
    insertBetween(First, 35, 30);

    /*Delete node di awal*/
    infotype deleted = Del_Beginning(&First);

    /*Delete node di akhir*/
    infotype deleted_last = Del_Last (&First);

    /*Delete node di tengah*/
    infotype deleted_mid = Del_Between(&First, 70);

    displayList(First);

    infotype count =  jumlahNode(First);

    printf("\nIsi yang dihapus di awal: %d", deleted);
    printf("\nIsi yang dihapus di akhir: %d", deleted_last);
    printf("\nIsi yang dihapus di tengah: %d\n", deleted_mid);
    printf("\nJumlah Node : %d\n", count);
    
    return 0;
}

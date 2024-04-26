/*
    FILE    :   NON BINARY TREE ADT (BODY)
    Author  :   REQI JUMANTARA HAPID
    NIM     :   231524023
    DATE    :   25 APRIL 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "NBTree.h"

nbTree* Create_node(infotype data){
    nbTree* new_node = (nbTree*) malloc (sizeof(nbTree));
    if (!new_node){
        printf("Alokasi Memory Gagal !\n");
        exit(0);
    } else {
        new_node->info = data;
        new_node->ps_fs = nil;
        new_node->ps_nb = nil;
        new_node->ps_pr = nil;
    }
    return new_node;
}

void Create_tree(nbTree* root, int jml_node){
    int jml_input = 1, jml_anak;
    infotype temp;
    nbTree* parent = root;

    printf("Masukkan Node pertama (sebagai root)!\n");
    printf(">>> "); scanf(" %c", &root->info);
    
    while(jml_input < jml_node){
        printf("\n\nParent : %c\n", parent->info);
        printf("Masukkan jumlah anak!\n");
        printf(">>> "), scanf(" %d", &jml_anak);

        if((jml_anak > 0) && (jml_anak + jml_input <= jml_node)){
            nbTree* newNodeTemp = nil;
            for (int i = 1; i <= jml_anak; i++){
                printf("\nMasukkan data anak ke %d!\n", i);
                printf(">>> "); scanf(" %c", &temp);

                if (!Search(root, temp)){
                    nbTree* newNode = Create_node(temp);
                    if (i == 1){
                        parent->ps_fs = newNode;
                    } else {
                        newNodeTemp->ps_nb = newNode;
                    }
                    newNodeTemp = newNode;
                    jml_input++;
                } else {
                    printf("Data sudah ada di dalam root!\n");
                    i--;
                }
            }
            parent = parent->ps_fs;
        } else if (jml_anak == 0){
            parent = parent->ps_nb;
        }
    }
}


// void Create_tree(nbTree* root, int jml_node) {
//     int jml_input = 1, jml_anak;
//     nbTree* parent = root;
//     infotype temp;

//     printf("Masukkan Node pertama (sebagai root)!\n");
//     printf(">>> ");
//     scanf(" %c", &root->info);

//     while (jml_input < jml_node) {
//         printf("\n\nParent : %c\n", parent->info);
//         printf("Masukkan jumlah anak!\n");
//         printf(">>> ");
//         scanf(" %d", &jml_anak);

//         if (jml_anak > 0 && jml_input + jml_anak <= jml_node) {
//             nbTree* temp_node = NULL;
//             for (int i = 1; i <= jml_anak; i++) {
//                 printf("\nMasukkan data anak ke %d!\n", i);
//                 printf(">>> ");
//                 scanf(" %c", &temp);
//                 if (!Search(root, temp)) {
//                     nbTree* newNode = Create_node(temp);
//                     if (i == 1) {
//                         parent->ps_fs = newNode;
//                     } else {
//                         temp_node->ps_nb = newNode;
//                     }
//                     temp_node = newNode;
//                     jml_input++;
//                 } else {
//                     printf("Data sudah ada di database!\n");
//                     i--;
//                 }
//             }
//             parent = parent->ps_fs;
//         } else if (jml_anak == 0) {
//             parent = parent->ps_nb;
//         }
//     }
// }


bool Search(nbTree* P, infotype X) {
    if (P == NULL)
        return false;

    if (P->info == X)
        return true;

    // Cari pada anak-anak dari node saat ini
    nbTree* temp = P->ps_fs;
    while (temp != NULL) {
        if (Search(temp, X))
            return true;
        temp = temp->ps_nb;
    }

    return false;
}

void Traversal_PreOrder(nbTree* root) {
    if (root != NULL) {
        printf("%c => ", root->info);
        Traversal_PreOrder(root->ps_fs);
        Traversal_PreOrder(root->ps_nb);
    }
}

int main() {
    int jml_node;
    printf("Masukkan jumlah node: ");
    scanf("%d", &jml_node);

    nbTree* root = Create_node('D');
    Create_tree(root, jml_node);
    Traversal_PreOrder(root);
    getch();

    // Lakukan operasi lain pada Tree jika diperlukan

    return 0;
}


/*
void Create_tree(Isi_tree x, int jml_node){
    int jml_input, posisi, parent, jml_anak;
    infotype temp;

    jml_input = 1;
    posisi = 1;
    parent = 1;
    
    printf("Masukkan Node pertama (sebagai root)!\n");
    printf(">>> "); scanf(" %c", &x[posisi].info);
    jml_input++;

    x[1].ps_fs = nil;
    x[1].ps_nb = nil;
    x[1].ps_pr = nil;

    system("cls");
    printf("\n\nRoot : %c", x[1].info);
    

    while (jml_input <= jml_node)
    {
        printf("\n\nParent : %c\n", x[parent].info);
        if (parent == 1) {
            printf("Root tidak boleh memiliki jumlah anak 0!\n");
            printf("Masukkan jumlah anak!\n");
            printf(">>> ");
            scanf(" %d", &jml_anak);
            while (jml_anak == 0) {
                printf("Root tidak boleh memiliki jumlah anak 0!\n");
                printf("Masukkan jumlah anak!\n");
                printf(">>> ");
                scanf(" %d", &jml_anak);
            }
        } else {
            printf("Masukkan jumlah anak!\n");
            printf(">>> "), scanf(" %d", &jml_anak);
        }

        if ((jml_anak > 0) && (jml_anak + posisi <= jml_node) && (jml_anak + parent <= jml_node))
        {
            int i;
            for (i = 1; i <= jml_anak; i++){
                posisi++;
                printf("\nMasukkan data anak ke %d!\n", i);
                printf(">>> "); scanf(" %c", &temp);

                if(!Search(x, temp)){
                    x[posisi].info = temp;
                    x[posisi].ps_fs = nil;
                    jml_input++;

                    if (i == 1){
                        x[parent].ps_fs = posisi;
                    }

                    if (i < jml_anak){
                        x[posisi].ps_nb = posisi + 1;
                    } else {
                        x[posisi].ps_nb = 0;
                    }

                    x[posisi].ps_pr = parent;

                } else {
                    printf("Data sudah ada di database!\n");
                    posisi--;
                    i--;
                }
            }
            parent++;
        } else if (jml_anak + posisi > jml_node){
            printf("Overflow!\n");
        }

        if (jml_anak == 0){
            parent++;
        } 
    }
}

boolean Search (Isi_tree P, infotype X)
{
    for(int i = 1; i <= jml_maks; i++){
        if(P[i].info == X){
            return true;
        } 
    }
    return false;
}

*/

/*
boolean Is_empty(Isi_tree X){
    if (X->info == 0){
        return true;
    } else {
        return false;
    }
}

void Print_PreOrder(Isi_tree x){
    int posisi = 1;
    bool resmi = true;
    printf("%c => ", x[posisi].info);
    do {
        if ((x[posisi].ps_fs != 0) && resmi){
            posisi = x[posisi].ps_fs;
            printf("%c => ", x[posisi].info);
        } else if ((x[posisi].ps_nb != 0)){
            posisi = x[posisi].ps_nb;
            printf("%c =>", x[posisi].info);
            resmi = true;
        } else {
            posisi = x[posisi].ps_pr;
            resmi = false;
        }
    } while (posisi != 0);
}

void Print_PostOrder(Isi_tree x){
    int posisi = 1;
    bool resmi = false;

    while (posisi != 0){
        if ((x[posisi].ps_fs != 0) && (!resmi)){
            posisi = x[posisi].ps_fs;
        } else {
            printf("%c =>", x[posisi].info);
            if (x[posisi].ps_nb != 0){
                posisi = x[posisi].ps_nb;
                resmi = false;
            } else {
                posisi = x[posisi].ps_pr;
                resmi = true;
            }
        }
    }
}

void Print_level_order(Isi_tree X, int jml_Node)
{
    int i;
    if(!Is_empty(X)){
	    for (i = 1; i <= jml_Node; i++) {
	        if (X[i].info != nil) {
	            printf("%c => ", X[i].info);
	        }
	    }
	} else {
		printf("Node kosong...");
	}
}


void Print_InOrder(Isi_tree P)
{
    int posisi;   
    bool Resmi; 
    posisi = 1;
    Resmi = true;
    
    if(!Is_empty(P)){
	    while (posisi != 0)
	    {
	        if (P[posisi].ps_fs != 0 && Resmi)
	        {
	            posisi = P[posisi].ps_fs;
	        }
	        else
	        {
	            if (Resmi)
	            {
	                printf("%c => ", P[posisi].info);
	            }
	
	            if (posisi == P[P[posisi].ps_pr].ps_fs)
	            {
	                printf("%c => ", P[P[posisi].ps_pr].info);
	            }
	
	            if (P[posisi].ps_nb != 0)
	            {
	                posisi = P[posisi].ps_nb;
	                Resmi = true;
	            }
	            else
	            {
	                posisi = P[posisi].ps_pr;
	                Resmi = false; 
	            }
	        }
	    }
	}else{
		printf("--> Node kosong...");
	}
    printf("\n");
}

int nbElmt (Isi_tree x){
	int posisi, jml_node = 0;   // Posisi Node Aktif
    bool Resmi; // Sifat kunjungan resmi
    posisi = 1;
    jml_node++;
    Resmi = true;
    do
    {
        if (x[posisi].ps_fs != 0 && Resmi)
        {
            posisi = x[posisi].ps_fs;
            jml_node++;
        }
        else if (x[posisi].ps_nb != 0)
        {
            posisi = x[posisi].ps_nb;
            jml_node++;
            Resmi = true;
        }
        else
        {
            posisi = x[posisi].ps_pr;
            Resmi = false;
        }
    } while ((x[posisi].ps_pr != 0));
    return jml_node;
}


void Print_tree(Isi_tree X){
    int jml_node = nbElmt(X);
    int i;
    for (i = 1; i <= jml_node; i++)
    {
        printf("\n--> Indeks ke-%d \n", i);
        printf("----------------------------------\n");
        printf("Data array ke %d \t: %c\n", i, X[i].info);
        printf("First son array ke %d \t: %d\n", i, X[i].ps_fs);
        printf("Next brother array ke %d : %d\n", i, X[i].ps_nb);
        printf("Parent array ke %d \t: %d\n", i, X[i].ps_pr);
        printf("----------------------------------\n");
    }
}

int nbDaun (Isi_tree x){
	int posisi, jml_daun = 0;   
    bool Resmi; 
    posisi = 1;
    Resmi = true;
    
    if(!Is_empty(x)){
	    do
	    {
	        if (x[posisi].ps_fs != 0 && Resmi)
	        {
	            posisi = x[posisi].ps_fs;
	        }
	        else if (x[posisi].ps_nb != 0)
	        {
	            if (x[posisi].ps_fs == 0){
	            	jml_daun++;
				}
	            posisi = x[posisi].ps_nb;
	            Resmi = true;
	        }
	        else
	        {
	            if (x[posisi].ps_fs == 0){
	            	jml_daun++;
				}
	            posisi = x[posisi].ps_pr;
	            Resmi = false;
	        }
	    } while ((x[posisi].ps_pr != 0));	    
	}
	return jml_daun;
}

int Level(Isi_tree x, infotype data){
    int i, level;
    int jml_node;
    jml_node = nbElmt(x);
    for (i = 1; i <= jml_node; i++){
        if (x[i].info == data){
            level = x[i].ps_pr;
            break;
        }
    }
    return level;
}

int Depth(Isi_tree x){
    int i, jml_node, max;
    jml_node = nbElmt(x);
    max = x[1].ps_pr;
    for (i = 1; i <= jml_node; i++){
        if(x[i].ps_pr >= max){
            max = x[i].ps_pr;
        }
    }
    return max;
}

int Max(infotype Data1, infotype Data2){
    if(Data1 > Data2){
        return Data1;
    } else {
        return Data2;
    }
}

*/
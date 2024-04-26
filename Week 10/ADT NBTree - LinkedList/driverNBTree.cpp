// /*
//     FILE    :   NON BINARY TREE ADT (DRIVER)
//     Author  :   REQI JUMANTARA HAPID
//     NIM     :   231524023
//     DATE    :   25 APRIL 2024
// */
// #include <stdio.h>
// #include <string.h>
// #include <conio.h>
// #include <windows.h>
// #include "NBTree.h"


// int main(){
//     Isi_tree x;
//     int jml_node, pilihan;

//     while (true){
//         system("cls");
//         printf("\nMasukkan jumlah node yang akan dimasukkan! Maks: 20\n");
//         scanf(" %d", &jml_node);
//         if (!((jml_node > 0) && (jml_node <= 20))){
//             printf("\nError!\nAngka yang anda masukkan tidak berada di dalam jangkauan!\n");
//             printf("Tekan di mana saja untuk melanjutkan!\n"); getch();
//         } else {
//             break;
//         }
//     }
//     Create_tree(x, jml_node);

//     for(;;){
//         system("cls");
//         printf("Pilihan Menu: \n");
//         printf("1. Print Tree\n");
//         printf("2. Traversal PreOrder\n");
//         printf("3. Traversal PostOrder\n");
//         printf("4. Traversal InOrder\n");
//         printf("5. Traversal Level Order\n");
//         printf("6. Menghitung jumlah daun\n");
//         printf("7. Membandingkan Dua node \n");
//         printf("8. Level suatu node\n");
//         printf("9. Depth/ Kedalamman Tree\n");
//         printf("10. EXIT!\n");
    
//         printf("\nMasukkan pilihan Anda!\n");
//         printf(">>> "); scanf(" %d", &pilihan);

//         switch (pilihan)
//         {
//         case 1 :
//             printf("\nIlustrasi Root:\n");
// 			Print_tree(x);
// 		    printf("\nKlik apapun untuk melanjutkan!"); getch();
// 			break;
//         case 2:
//             printf("\nTraversal Pre Order:\n");
//             Print_PreOrder(x);
//             printf("\nKlik apapun untuk melanjutkan!"); getch();
//             break;
//         case 3:
//             printf("\nTraversal Post Order:\n");
//             Print_PostOrder(x);
//             printf("\nKlik apapun untuk melanjutkan!"); getch();
//             break;
//         case 4:
//             printf("\nTraversal In Order:\n");
//             Print_InOrder(x);
//             printf("\nKlik apapun untuk melanjutkan!"); getch();
//             break;
//         case 5:
//             printf("\nTraversal Level Order:\n");
//             Print_level_order(x, jml_node);
//             printf("\nKlik apapun untuk melanjutkan!"); getch();
//             break;
//         case 6:
//             int Jml_daun;
//             Jml_daun = nbDaun(x);
//             printf("\nJumlah Daun pada Tree tersebut adalah: %d \n", Jml_daun);
//             printf("\nKlik apapun untuk melanjutkan!"); getch();
//             break;
//         case 7:
//             infotype data1, data2;
//             printf("Masukkan data node pertama !\n");
//             printf(">>> "); scanf(" %c", &data1);
//             fflush(stdin);
//             printf("Masukkan data node kedua !\n");
//             printf(">>> "); scanf(" %c", &data2);

//             if ((Search(x, data1)) && Search(x, data2)){
//                 printf("\nNode dengan nilai maksimum adalah: %c", Max(data1, data2));
//             } else {
//                 printf("Data tidak dapat terdapat pada tree\n"); 
//             }
//             printf("\nKlik apapun untuk melanjutkan!"); getch();
// 			break;
//         case 8:
//         char data;
//             printf("Masukkan data node yang ingin dicari levelnya!\n");
//             printf(">>> "); scanf(" %c", &data);
//             int level;
//             level = Level(x, data);
//             printf("\nLevel dari node tersebut adalah: %d", level);
//             printf("\nKlik apapun untuk melanjutkan!"); getch();
//             break;
//         case 9:
//             printf("Depth/ Kedalaman dari tree tersebut adalah: \n");
//             printf(">>> %d", Depth(x));
//             printf("\nKlik apapun untuk melanjutkan!"); getch();
//             break;
//         case 10:
//             exit(0);
//             break;
//         default:
//             printf("Maaf menu yang Anda pilih tidak ada, pilih menu 1-8");
// 			printf("\nKlik apapun untuk melanjutkan!"); getch();
//         }
//     }

//     return 0;
// }
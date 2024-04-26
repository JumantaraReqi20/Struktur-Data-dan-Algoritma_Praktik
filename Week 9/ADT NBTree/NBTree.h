/*
    FILE    :   NON BINARY TREE ADT (HEADER)
    Author  :   REQI JUMANTARA HAPID
    NIM     :   231524023
    DATE    :   25 APRIL 2024
*/

#ifndef nbtree_h
#define nbtree_h

#include "BOOLEAN.h"

//Maksimal node yang dapat ditampung dalam array
#define jml_maks 20

// Arah Traversal
#define kebawah 1
#define keatas 2
#define kekanan 3
#define nil 0

/* TYPE DATA */
typedef char infotype;
typedef int address;
typedef struct {
    infotype info;
    address ps_fs, ps_nb, ps_pr;
} nbTree;
 typedef nbTree Isi_tree[jml_maks + 1];

/* SPESIFIKASI */
 
void Create_tree(Isi_tree X, int Jml_Node); 
// Create Non Binary Tree sebanyak Jml_Node 
// Tujuan mengentrykan Non Binary Tree ke array Isi_tree dengan pola Level Order 
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input 
boolean Is_empty (Isi_tree P); 
/* Mengirimkan true jika Isi_tree KOSONG */


/***** Traversal *****/ 
void Print_PreOrder (Isi_tree P); 
/* Traversal PreOrder */ 
/* IS : P terdefinisi */ 
/* FS : Semua simpul P sudah ditampilkan secara PreOrder : Parent, fs, nb */
void Print_PostOrder (Isi_tree P); 
/* Traversal PostOrder */ 
/* IS : P terdefinisi */ 
/* FS : Semua simpul P sudah ditampilkan secara PostOrder : fs, nb, Parent */  
void Print_InOrder (Isi_tree P); 
/* Traversal InOrder */ 
/* IS : P terdefinisi */ 
/* FS : Semua simpul P sudah ditampilkan secara InOrder : fs, Parent, Sisa anak lain */ 
void Print_level_order(Isi_tree X, int jml_Node);
/* Traversal LevelOrder */ 
/* IS : P terdefinisi */ 
/* FS : Semua simpul P sudah ditampilkan secara Level Order */ 
void Print_tree (Isi_tree P); 
/* IS : P terdefinisi */ 
/* FS : Semua simpul P sudah ditulis ke layar */ 
/***** Search *****/ 
boolean Search (Isi_tree P, infotype X); 
/* Mengirimkan true jika ada node dari P yang bernilai X */ 

/****** Fungsi Lain ******/
int nbElmt (Isi_tree P); 
/* Mengirimkan banyak elemen (node) di pohon non biner P */ 
int nbDaun (Isi_tree P); 
/* Mengirimkan banyak daun (node) pohon non biner P */ 
int Level (Isi_tree P, infotype X); 
/* Mengirimkan level dari node X yang merupakan salah satu simpul */ 
/* dr pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */ 
int Depth (Isi_tree P); 
/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari 
Pohon */ 
/* Basis : Pohon Kosong, tingginya Nol */ 
int Max (infotype Data1, infotype Data2); 
/* Mengirimkan Nilai terbesar dari dua data */ 
#endif
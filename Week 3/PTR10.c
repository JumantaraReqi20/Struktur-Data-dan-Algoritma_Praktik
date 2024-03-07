/* -------------------------------------------------------------- */ 
/* 	File    	: PTR10.cpp             
	Deskripsi  	: Pointer dan fungsi/prosedur
	Author		: Reqi Jumantara Hapid
*/ 
/* -------------------------------------------------------------- */ 
#include <stdio.h> 
/* Prototype */ 
void f1(void); 
void f2(void); 
void f3(void); 
void f4(void); 

/* kamus Global */ 
#define true 1 
#define false 0 

int quit = false; 
int main() 
{ 
	/* kamus lokal */ 
	void (*tab[4]) () = {f1, f2, f3, f4}; 
	/* Definisi tabel yang elemennya adalah pointer ke fungsi */ 
	/* Elemen tabel yang ke - i akan mengakses fungsi ke - (i+1) */ 
	/* Pilihan menjadi indeks tabel, dan dipakai untuk mengaktifkan fungsi yang sesuai */ 
	 
	/* program */ 
	printf("Pointer to function : \n"); 
	
	/* Menu */ 
	do 
	{ 
	printf("\nPilih salah satu : \n"); 
	/* Pointer ke procedure */ 
	printf("1. Buka file hanya untuk baca \n"); 
	printf("2. Tutup file \n"); 
	printf("3. Edit file \n"); 
	printf("4. Quit \n");
	
	/*Mengaktifkan fungsi sesuai dengan inputan user*/ 
	tab[getchar() - '1'] () ; 
	
	getchar();   
	/* untuk membersihkan karakter newline (\n)*/
	 
	} while (!quit);  
	/*Perulangan berhenti ketika quit bernilai true (di prosedur f4)*/
	return 0; 
} 

/* Body Function */ 
void f1 () 
{ 
	printf("\nIni fungsi f1 \n"); 
} 
 
void f2 () 
{ 
 	printf("\nIni fungsi f2 \n"); 
} 
 
void f3 () 
{ 
 	printf("\nIni fungsi f3 \n"); 
} 
 
void f4 () 
{ 
	quit = true;  //Untuk menghentikan perulangan
 	printf("\nQuit ... \n"); 
}

/* ----------------------------------------------------- */ 
/* File Program : PTR6.C	                              */             
/* Author 		: Reqi Jumantara Hapid (231524023)		 */
/* Date			: 1 Maret 2024							 */
/* Deskripsi	: pointer yang menunjuk ke array         */ 
/* ----------------------------------------------------- */ 


#include <stdio.h> 
int main() 
{ 
	/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/ 
	static int tgl_lahir[] = {18, 6, 1989};						//Inisialisasi variabel array bertipe integer dan bersifat statis* dengan nilai 18, 6, 1989
	int *ptgl; 													//Deklarasi variabel pointer ke integer bernama ptgl
	ptgl = tgl_lahir; 											//Assign alamat dari var tgl_lahir ke var ptgl**
	printf("Nilai yang ditunjuk oleh ptgl = %d\n", *ptgl); 		//Mencetak nilai pada alamat yang ditunjuk oleh pointer ptgl
	printf("Nilai dari tgl_lahir[0] = %d\n", tgl_lahir[0]);     //Mencetak nilai dari array index ke 0
	
	printf("\nSetelah diperbarui:\n");
	
	printf("\nSeluruh nilai yang ada pada array :\n");
	printf("=====================================\n");
	int i;														//Deklarasi var i bertipe integer yang nantinya akan digunakan sebagai pencacah
	for (i = 0; i < sizeof(tgl_lahir) / sizeof(int); i++){ 		//Kode untuk membuat perulangan yaitu selama nilai 'i' lebih kecil dari banyaknya anggota dalam array
		printf("Nilai yang ditunjuk: %d\n", *(ptgl + i));		//Mencetak nilai pada alamat yang ditunjuk oleh "pointer + pencacah"***
	}
	return 0; 
} 

/* *Variabel bersifat statis artinya variabel tersebut akan mempertahankan nilainya di antara pemanggilan fungsi yang berbeda. 
	Dalam hal ini, tgl_lahir adalah variabel lokal yang akan mempertahankan nilainya setelah fungsi selesai dieksekusi. */
	
/* **Dalam aturan khusus bahasa C, saat kita menetapkan suatu array ke pointer, kita tidak perlu menggunakan tanda '&'(address of)
	untuk mendapatkan alamat memori dari array tersebut.
	Jadi, dalam contoh ptgl = tgl_lahir;, tgl_lahir adalah nama array itu sendiri. Ketika Anda menggunakan nama array dalam konteks 
	di mana alamat memori diharapkan, itu akan secara otomatis memberikan alamat memori dari elemen pertama array tersebut.*/
	
/* ***printf("Nilai yang ditunjuk: %d\n", *(ptgl + i));: Dalam loop ini, kita mencetak nilai yang ditunjuk oleh pointer ptgl ditambah dengan i. 
	Ini dilakukan dengan menggunakan operator dereference * pada ekspresi (ptgl + i) yang berarti kita mendapatkan nilai pada 
	alamat memori yang ditunjuk oleh ptgl ditambah i.

	Pada iterasi pertama (ketika i = 0), kita mencetak nilai yang ditunjuk oleh ptgl yaitu nilai array index ke 0
	Pada iterasi kedua (ketika i = 1), kita mencetak nilai yang ditunjuk oleh ptgl + 1, yaitu nilai kedua dalam array/ array index ke 1
	Pada iterasi ketiga/ terakhir (ketika i = 2), kita mencetak nilai yang ditunjuk oleh ptgl + 2, yaitu nilai kedua dalam array/ array index ke 2 */

	
	
/* STUDI KASUS : */ 	
/* Eksekusi dan pahami maksud program ini (tulis tujuan program ini) */ 
/* Modifikasi program tersebut agar bisa menampilkan seluruh elemen array tgl_lahir !*/

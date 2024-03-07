/* --------------------------------------------------------- */ 
/* File Program : PTR1.CPP        */ 
/* Author		: Reqi Jumantara H. (231524023) */ 
/* Contoh pemakaian pointer       */
/* Tujuan 		: mengetahui panjang dan posisi variabel di memory */ 
/* --------------------------------------------------------- */ 

#include <stdio.h>

int main(){
	int x, y; //deklarasi variabel bertipe integer
	int *px; // deklarasi variabel px bertipe pointer
	
	x = 87; // inisialisasi nilai x dengan 87
	
	y = *px; // menyimpan nilai yang terdapat di alamat yang ditunjuk oleh px ke dalam variabel y
	px = &x; // menyimpan alamat dari variabel x ke dalam variabel pointer px
	
	printf("Nilai x = %d\n", x); // menampilkan alamat dari variabel x
	printf("Alamat x = %p\n", &x); // menampilkan isi dari variabel x
	printf("Isi px = %p\n", px); // menampilkan nilai yang terkandung dalam variabel px
	printf("Nilai yang ditunjukkan oleh px = %d\n", *px); // menampilkan nilai yang ditunjuk oleh pointer px
	printf("Nilai y = %d\n", y); // menampilkan nilai yang terkandung dalam variabel y

	printf("Alamat y = %p\n", &y); // menampilkan alamat variabel y
	return (0);	
}

/* STUDI KASUS : */ 
/* - Eksekusi file program tersebut dan pahami maksud program ini */ 
/* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */ 	
/* - Tambahkan pernyataan untuk menampilkan Alamat varabel y, eksekusi, dan perhatikan hasilnya */ 
/* - Bila pernyataan px = &x; diganti dengan y = *px; ,apa yang terjadi? */ 
/* - Tulis hasil pemahaman Anda pada kertas yang disediakan */ 

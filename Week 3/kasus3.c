/* --------------------------------------------------------- */ 
/* File Program : PTR3.CPP        */ 
/* Author		: Reqi Jumantara H. (231524023) */ 
/* Contoh mengubah isi suatu variabel melalui pointer    */
/* Tujuan 		: menggunakan type data pointer dan manipulasinya */ 
/* --------------------------------------------------------- */

#include <stdio.h>

int main(){
	
	float d, *pd; //deklarasi var 'd' bertipe float dan var 'pd' bertipe pointer ke float
	
	d = 54.5; //inisialisasi var 'd' dengan nilai 54.5
	
	printf("Isi d semula = %g\n", d); //mencetak nilai d sebelum dimanipulasi
	
	pd = &d; // menyimpan alamat var 'd' ke dalam var 'pd'
	*pd = *pd + 10; // menyimpan hasil penjumlahan nilai pada alamat yang ditunjuk oleh var pointer 'pd' dengan 10
	
	printf("Isi d kini = %g\n", d); //mencetak nilai d setelah dimanipulasi
	
	return 0;
	
}

/* STUDI KASUS : */
/* - Eksekusi file program tersebut dan pahami maksud program ini */
/* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
/* - Tulis hasil pemahaman Anda pada kertas yang disediakan */ 

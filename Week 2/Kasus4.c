/* --------------------------------------------------------- */ 
/* File Program : PTR4.CPP        */ 
/* Author		: Reqi Jumantara H. (231524023) */ 
/* Contoh operasi antar variabel menggunakan pointer   */
/* Tujuan 		: menggunakan type data pointer dan manipulasinya */ 
/* --------------------------------------------------------- */

#include <stdio.h>

int main(){
	
	int z, s, *ps, *pz;
	/*
	Deklarasi var 'z' dan 's' bertipe integer
	Deklarasi var 'pz' dan 'ps' bertipe pointer ke integer
	*/
	
	z = 20; //inisialisasi var z dengan nilai 20
	s = 30; //inisialisasi var s dengan nilai 30
	
	pz = &z; //menyimpan alamat var 'z' ke dalam var 'pz'
	ps = &s; //menyimpan alamat var 's' ke dalam var 'ps'
	*pz = *pz + *ps; 
	/*
	meng assign nilai pada alamat yang ditunjuk oleh var 'pz' oleh hasil penjumlahan
	nilai pada alamat yang ditunjuk oleh var 'pz' dengan nilai pada alamat yang ditunjuk oleh var 'ps'
	z <- (z + s)
	*/
	
	printf("z = %d, s = %d\n", z, s); //mencetak nilai z dan nilai s
	
	return 0;
}

/* STUDI KASUS : */
/* - Eksekusi file program tersebut dan pahami maksud program ini */
/* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */
/* - Tulis hasil pemahaman Anda pada kertas yang disediakan */ 


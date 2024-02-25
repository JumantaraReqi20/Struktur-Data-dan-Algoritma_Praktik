/* --------------------------------------------------------- */ 
/* File Program : PTR2.CPP        */ 
/* Author		: Reqi Jumantara H. (231524023) */ 
/* Contoh pemakaian pointer  yang salah     */
/* Tujuan 		: mengetahui panjang dan posisi variabel di memory */ 
/* --------------------------------------------------------- */

#include <stdio.h>

int main(){
	
	float *pu; // deklarasi var pointer bertipe float
	float nu; // deklarasi var bertipe float
	
//	int u = 1234;
	float u = 1234; // inisialisasi var u bertipe integer dengan nilai 1234
				  // harusnya, agar program berjalan baik, tipe data 'u' adalah float
	
	pu = &u; // menyimpan alamat var 'u' di var 'pu'
	nu = *pu; // menyimpan nilai yang ditunjuk oleh var 'pu' di var 'nu'
	
	printf("u = %f\n", u); //mencetak nilai u
	printf("nu = %f\n", nu); // mencetak nilai nu;
	
	return 0;
}

 
/* STUDI KASUS : */ 
/* - Eksekusi file program tersebut dan pahami maksud program ini */ 
/* - Komentari setiap baris program (maksud tiap pernyataan di tiap baris program ) */ 
/* - Tulis hasil pemahaman Anda pada kertas yang disediakan */

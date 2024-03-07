/* ----------------------------------------------------- */ 
/* File Program : PTR7.C	                             */             
/* Author 		: Reqi Jumantara Hapid (231524023)		 */
/* Date			: 1 Maret 2024							 */
/* Deskripsi	: pointer yang menunjuk ke array         */ 
/* ----------------------------------------------------- */ 

#include <stdio.h> 

int main() 
{ 
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/ 
	char *pkota = "BANDUNG";	// Mendeklarasikan pointer pkota yang menunjuk ke constant string "BANDUNG"*
	puts(pkota); 				// Mencetak string yang ditunjuk oleh pkota menggunakan puts()**
	
	return 0; 
} 
/*	Dalam bahasa C, saat kita mendeklarasikan suatu var bertipe pointer ke char kemudian mengisinya dengan constant string
	maka, compiler akan otomatis mengalokasikan memori untuk string "BANDUNG"(khusus untuk data konstan)
	Kemudian pkota akan menyimpan alamat dari var pointer tersebut. */

/* STUDI KASUS : */ 
/* Apa perbedaan deklarasi variabel char *pkota='BANDUNG'; dengan char kota[]='BANDUNG'  ? 
*/

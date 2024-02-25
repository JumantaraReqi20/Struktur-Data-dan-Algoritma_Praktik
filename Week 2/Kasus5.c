/* --------------------------------------------------------- */ 
/* File Program : PTR5.CPP        */ 
/* Author		: Reqi Jumantara H. (231524023) */ 
/* Contoh penggunaan pointer secara lebih lengkap  */
/* Tujuan 		: menggunakan type data pointer dan manipulasinya */ 
/* --------------------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>


int main()
{
 /* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
 
 int i = 5, j; // inisialisasi var i  bertipe integer dengan nilai 5, dan var j bertipe integer
 char c = 'X'; // inisialisasi var c bertipe character dengan nilai 'X'
 
 int *Ptri = (int *) malloc(4);
 /*
 Deklarasi pointer 'Ptri' yang menunjuk ke alamat memori yang dialokasikan dan 
 hasilnya dikonversi menjadi pointer ke integer
 */
 
 int *Ptrj = (int *) malloc(sizeof(int));
 /*
 Deklarasi pointer 'Ptrj' yang menunjuk ke alamat memori yang dialokasikan dan 
 hasilnya dikonversi menjadi pointer ke integer
 */
 
 float *fx = (float *) malloc(sizeof(float));
 /*
 Deklarasi pointer 'fx' yang menunjuk ke alamat memori yang dialokasikan dan 
 hasilnya dikonversi menjadi pointer ke float
 */
 
 int A[5]; //deklarasi var array 'A' dengan 5 elemen bertipe integer
 float f = 7.23; // inisialisasi var 'f' bertipe float dengan nilai 7.23
 
 
 /* program */
 *Ptri = 8; //meng assign nilai 8 ke nilai pada alamat yang ditunjuk oleh pointer 'Ptri'
 *Ptrj = 0; //meng assign nilai 0 ke nilai pada alamat yang ditunjuk oleh pointer 'Ptrj'
 *fx = 3; //meng assign nilai 3 ke nilai pada alamat yang ditunjuk oleh pointer 'fx' 
 
 printf("Alamat i = %x \n", &i); //mencetak alamat var 'i' dalam bentuk hexadecimal
 printf("Nilai i = %d \n", i); //mencetak nilai var 'i'
 printf("Ukuran int = %d byte\n\n", sizeof(int)); //mencetak ukuran tipe data integer
 
 printf("Alamat j = %x \n", &j); //mencetak alamat var 'j' dalam bentuk hexadecimal
 printf("Nilai j = %d \n", j); //mencetak nilai var 'j'
 
 printf("\nAlamat c = %x \n", &c); //mencetak alamat var 'c'
 printf("Nilai c = %c \n", c); //mencetak nilai var 'c'
 printf("Ukuran char = %d byte\n\n", sizeof(char)); //mencetak ukuran tipe data character
 
 printf("Alamat Ptri = %x \n", &Ptri); //mencetak alamat var pointer 'Ptri'
 printf("Isi var Ptri = %x \n", Ptri); //mencetak isi var pointer 'Ptri'
 printf("Nilai yang ditunjuk oleh Ptri = %d \n", *Ptri); //mencetak nilai pada alamat yang ditunjuk oleh var pointer 'Ptri'
 printf("Ukuran pointer int = %d byte\n\n", sizeof(int *)); //mencetak ukuran tipe data pointer ke integer
 
 printf("Alamat Ptrj = %x \n", &Ptrj); //mencetak alamat var pointer 'Ptrj'
 printf("Isi var Ptrj = %x \n", Ptrj); //mencetak isi var pointer 'Ptrj'
 printf("Nilai yang ditunjuk oleh Ptrj = %d \n", *Ptrj); //mencetak nilai pada alamat yang ditunjuk oleh var pointer 'Ptrj'
 
 Ptrj = Ptri; //meng-assign isi pointer 'Ptri' ke pointer 'Ptrj'
 
 printf("\nIsi var Ptrj sekarang = %x \n", Ptrj); //mencetak isi var pointer 'Ptrj' setelah di-assign
 printf("Nilai yang ditunjuk oleh Ptrj sekarang = %d \n", *Ptrj); //mencetak nilai pada alamat yang ditunjuk oleh var pointer 'Ptrj' sekarang
 
 printf("\nAlamat A = %x \n", &A); //mencetak alamat var 'A'
 printf("Isi var A = %x \n", A[0]); //mencetak isi var 'A' indeks ke 0
 printf("Ukuran array A = %d byte\n\n", sizeof(A)); //mencetak ukuran tipe data var 'A'
 
 printf("Alamat f = %x \n", &f); //mencetak alamat var 'f'
 printf("Nilai f = %f \n", f); //mencetak nilai var 'f'
 printf("Ukuran float = %d byte\n\n", sizeof(float)); //mencetak ukuran tipe data float
 
 return 0;
} 

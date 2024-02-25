#include<stdio.h>

int fun(int);
int main()
{
 float k=3;
 fun(k=fun(fun(k)));
 /*ini juga termasuk ke dalam rekursif, tetapi
untuk yang ini tidak ada terminasi yang akan membuat
program berhenti otomatis karena datanya masih dalam 
ruang lingkup kecil*/
 printf("%f\n", k);
 return 0;
}
int fun(int i)
{
 i++; // increment
 return i;
}

 /*kita harus detail saat membaca soal, ada yang menanyakan
 output, dan ada juga yang menanyakan final state dari
 suatu variable*/

#include<stdio.h>

int fun(int i)
{
 i++;
 return i;
}
int main()
{
 int fun(int);
 int i=3;
 fun(i=fun(fun(i)));
 /*ini juga termasuk ke dalam rekursif, tetapi
untuk yang ini tidak ada terminasi yang akan membuat
program berhenti otomatis karena datanya masih dalam 
ruang lingkup kecil*/
 printf("%d\n", i);
 return 0;
 }
 
 /*kita harus detail saat membaca soal, ada yang menanyakan
 output, dan ada juga yang menanyakan final state dari
 suatu variable*/


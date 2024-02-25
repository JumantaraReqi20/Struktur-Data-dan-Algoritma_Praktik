#include<stdio.h>

int func1(int);
int main()
{
 int k=35;
 k =
func1(k=func1(k=func1(k)));
/*ini juga termasuk ke dalam rekursif, tetapi
untuk yang ini tidak ada terminasi yang akan membuat
program berhenti otomatis karena datanya masih dalam 
ruang lingkup kecil*/
 printf("k=%d\n", k);
 return 0;
}
int func1(int k)
{
 k++;
 return k;
}

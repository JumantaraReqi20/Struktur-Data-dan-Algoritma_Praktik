#include<stdio.h>

int addmult(int ii, int jj)
{
 int kk, ll;
 kk = ii + jj;
 ll = ii * jj;
 return (kk, ll);
 /*di bahasa C, jika ada return yang lebih dari satu, maka nilai
 yang kembalian yang masuk ke variabel nantinya
 adalah yang terakhir, dalam kasus di atas 'll'*/
}
int main()
{
 int i=3, j=4, k, l;
 k = addmult(i, j);
 l = addmult(i, j);
 printf("%d %d\n", k, l);
 return 0;
}


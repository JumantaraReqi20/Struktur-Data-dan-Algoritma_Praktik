#include<stdio.h>

int main()
{
 FILE *fs, *ft, *fp;
 fp = fopen("A.C", "r");
 fs = fopen("B.C", "r");
 ft = fopen("C.C", "r");
 fclose(fp, fs, ft);
 /*akan error karena untuk menutup file
 kita perlu menutupnya satu per satu
 tidak bisa berbarengan seperti itu*/
 return 0;
}


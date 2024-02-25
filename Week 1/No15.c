#include<stdio.h>
int main()
{
 int i, fss;
 char ch, source[20] =
"source.txt",

target[20]="target.txt", t;
 FILE *fs, *ft;
 fs = fopen(source, "r");
 ft = fopen(target, "w");
 //membuka file
 while(1)
 {
 ch=getc(fs);//mengambil karakter dari file fs
 if(ch==EOF)// jika end of file
 break;
 else
 {
 fseek(fs, 4L, SEEK_CUR);
 /*memindahkan pointer sebanyak 4 satuan*/
 fputc(ch, ft); // menyalin karakter tsb ke dalam file target
 }
 }
 return 0;
}


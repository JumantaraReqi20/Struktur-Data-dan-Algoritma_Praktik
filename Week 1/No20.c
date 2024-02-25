#include<stdio.h>
int main()
{
 FILE *ptr;
 char i;
 ptr = fopen("myfile.c","r");

while((i=fgetc(ptr))!=NULL)
/*Dalam loop while, karakter tersebut
akan dibaca satu per satu. Jika fgetch() tidak
dapat membaca karakter lagi, ia akan mengembalikan
END OF FILE. Namun dalam konndisi while di sini,
bukan EOF yang digunakan untuk memeriksan akhir file,
melainkan karakter itu sendiri. Karena karakter tidak
dapat menjadi NULL dalam konteks ini, melainkan EOF, 
maka loop tersebut tidak pernah berhenti*/
 printf("%c", i);
 return 0;
}


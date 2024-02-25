#include<stdio.h>
#include<stdlib.h>

int main()
{
 unsigned char;
 FILE *fp;
 fp=fopen("trial", "r");
 if(!fp) // jika file kosong
 {
	 printf("Unable to open file");
	 exit(1);
 }
 fclose(fp);
 return 0;
}


#include<stdio.h>

int check(int);

int main()
{
 int i=45, c;
 c = check(i);
 printf("%d\n", c);
 return 0;
}
int check(int ch) //pengecekkan nilai
{
 if(ch >= 45){
 	return 100; //kembalian jika benar
 }
 else{
 	return 10; // kembalian jika salah
 }
}

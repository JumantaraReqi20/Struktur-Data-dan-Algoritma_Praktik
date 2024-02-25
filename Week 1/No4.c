#include <stdio.h>

int main()
{
	void fun(char*);
	/*deklaraisi parameter yang mengindikasikan bahwa itu menerima
	pointer ke karakter(passing by reference)*/
	char a[100];
	a[0] = 'A'; a[1] = 'B';
	a[2] = 'C'; a[3] = 'D';
	fun(&a[0]);
	/*pemanggilan fungsi fungsi fun() dengan memberikan alamat dari
	elemen pertama dari array a*/
	
	return 0;
}

void fun(char *a)
{
	a++;
	printf("%c", *a);
	a++;
	printf("%c", *a);
}

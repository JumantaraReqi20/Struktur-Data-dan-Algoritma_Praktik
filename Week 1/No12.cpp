#include <iostream>
using namespace std;
void Sum(int a, int b, int &
c)
/*int a dan b: passing by value
int c : passing by reference*/
{
 a = b + c;
 b = a + c;
 c = a + b;
}
int main()
{
 int x = 2, y =3;
 Sum(x, y, y);
 /*nilai yang akan berubah hanyalah yang y paling kanan
 karena parameternya sudah menggunakan passing 
 by reference*/
 cout << x << " " << y;
 return 0;
}


#include <iostream>
using namespace std;
void fun(int &x)
/*parameter x menggunakan passing parameter by address*/
{
 x = 20;
}

int main()
{
 int x = 10;
 fun(x);
 //nilai x akan berubah
 cout << "New value of x is "
<< x;
 return 0;
}


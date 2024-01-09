#include<iostream>
using namespace std;
void abcd(int *p)
{
*p=100;
}
int main()
{
int x;
x=5;
abcd(&x);
cout<<x<<endl;
return 0;
}
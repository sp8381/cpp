#include<iostream>
using namespace std;
void abcd(int &p)
{
p=120;
}
int main()
{
int x;
x=10;
abcd(x);	// call by reference abcd(&x)
cout<<x<<endl;
return 0;
}
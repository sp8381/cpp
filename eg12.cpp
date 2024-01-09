#include<iostream>
using namespace std;
int main()
{
int x;
int *p;
p=&x;
*p=120;
cout<<x<<endl;
x=210;
cout<<*p<<endl;
return 0;
}
#include<iostream>
using namespace std;

int operator++()
{
*this=*this+20;
return *this;
}

int main()
{
int a,b;
b=100;
a=b++;
cout<<a<<" "<<b<<endl;
return 0;
}
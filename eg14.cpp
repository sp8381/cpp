#include<iostream>
using namespace std;
int main()
{
int x;
int &p=x;	//here p is an alias of x
x=100;
cout<<p<<endl;
p=200;
cout<<x<<endl;
return 0;
}
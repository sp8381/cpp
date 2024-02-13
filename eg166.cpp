#include<iostream>
using namespace std;
int main()
{
int x=10;
const int *p;
p=&x;
*p=100;
cout<<x<<endl;
return 0;
}
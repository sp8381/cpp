#include<iostream>
using namespace std;
int main()
{
int x=10,y=20;
const int *p;
p=&x;
*p=100;		//error
p=&y;
*p=200;		//error
cout<<x<<endl;
return 0;
}
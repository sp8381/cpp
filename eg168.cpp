#include<iostream>
using namespace std;
int main()
{
int x=10,y=20;
int * const p;
p=&x;	//error
*p=100;		
p=&y;	//error
*p=200;		
cout<<x<<endl;
return 0;
}
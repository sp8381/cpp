#include<iostream>
using namespace std;
void lmn(int p,int q)
{
cout<<"Total is "<<p+q<<endl;
}
int pqr(int x)
{
return x*x;
}
int main()
{
int (*k)(int);
void (*j)(int,int);
k=pqr;
j=lmn;
cout<<k(10)<<endl;
j(200,20);
return 0;
}
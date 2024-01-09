#include<iostream>
using namespace std;
void add(int p,int q)
{
cout<<"total is "<<p+q<<endl;
}
void add(int p,int q,int r)
{
cout<<"total is "<<p+q+r<<endl;
}
int main()
{
add(10,20);
add(100,200,300);
return 0;
}
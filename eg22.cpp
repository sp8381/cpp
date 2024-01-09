#include<iostream>
using namespace std;
int add(int p,int q)
{
return p+q;
}
void add(int e,int f)
{
cout<<e+f<<endl;
}
int main()
{
int x;
x=add(10,20);
add(300,500);
return 0;
}
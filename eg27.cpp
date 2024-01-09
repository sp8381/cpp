#include<iostream>
using namespace std;
void add(float a,float b)
{
cout<<a+b<<endl;
}
void add(int a,int b)
{
cout<<a+b<<endl;
}
int main()
{
add(10,20);
add(2.33f,4.44f);
}
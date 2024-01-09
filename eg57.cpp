//cannot create the function of default argument function 
//which is alternative of more than one function
//then note that we don't write the copy of the function 
//whose alternative is created by default argument function

#include<iostream>
using namespace std;
void add(int p,int q,int r=0)
{
cout<<"Total is "<<(p+q+r)<<endl;
}
void add(int p,int q)
{
cout<<"Total is "<<(p+q)<<endl;
}
int main()
{
add(1,20,30);
add(10,20);
return 0;
}
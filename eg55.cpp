//this code won't compile as 
//error : the parameter is missig for third argument 
#include<iostream>
using namespace std;
void add(int p,int q=0,int r)
{
cout<<"total is "<<(p+q+r)<<endl;
}
int main()
{
add(10,20,30);
add(10,20);
return 0;
}
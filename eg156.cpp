#include<iostream>
using namespace std;
template<class T1,class T2>
void add(T1 x,T2 y)
{
T1 z;
z=x+y;
cout<<"Total is : "<<z<<endl;
}
int main()
{
add(20,30.33f);	//loss of precision as of z is int
add(40.44f,20);
return 0;
}
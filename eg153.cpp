#include<iostream>
using namespace std;
void add(int x,int y)
{
int z;
z=x+y;
cout<<"Total is : "<<z<<endl;
}
void add(float x,float y)
{
float z;
z=x+y;
cout<<"Total is : "<<z<<endl;
}
int main()
{
add(10,20);
add(10.11f,20.22f);
return 0;
}

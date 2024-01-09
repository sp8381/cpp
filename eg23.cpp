//this code won't complie
//error: embiguity in float and passed double value 
//22.22 is double, 22.22f is float 

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
int mmain()
{
add(10,20);
add(22.22,4.44);
return 0;
}
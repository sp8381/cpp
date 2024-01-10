#include<iostream>
using namespace std;
class aaa
{
public:
aaa()
{
cout<<"Base class Default constructor "<<endl;
}
~aaa()
{
cout<<"Base class Destructor"<<endl;
}
};
class bbb:public aaa
{
public:
bbb()
{
cout<<"Derived class default constructor"<<endl;
}
~bbb()
{
cout<<"Derived class destructor"<<endl;
}
};
int main()
{
bbb b;
cout<<"Cool"<<endl;
return 0;
}
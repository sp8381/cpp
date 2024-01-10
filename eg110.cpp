#include<iostream>
using namespace std;
class aaa
{
public:
aaa()
{
cout<<"Base class Default constructor "<<endl;
}
virtual ~aaa()
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
aaa *p;		//Base ka pointer 
p=new bbb;	//Derived ka object/address, then derived destructor will not executed
cout<<"Cool"<<endl;
delete p;
return 0;
}
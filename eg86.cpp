//Derived class can access the methods of base class by inheritance and
//Base class can access the methods of derived class by creating pointer and creating object of derived class and declaring the methods in base class as virtual 

#include<iostream>
using namespace std;
class aaa
{
public:
void sam()
{
cout<<"Great"<<endl;
}
virtual void tom()	//here we need to create the dummy method and to declare as virtual 
{
}
};
class bbb:public aaa
{
public:
void tom()
{
cout<<"Cool"<<endl;
}
};
int main()
{
aaa *a;
a=new bbb;
a->sam();
a->tom();
return 0;
}
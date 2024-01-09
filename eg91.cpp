#include<iostream>
using namespace std;
class Car
{
public:
virtual void manual()	//dummy method declared as virtual
{
}
};
class Maruti800:public Car
{
public:
void manual()
{
cout<<"Operation details of Maruti800"<<endl;
}
};
class HondaCity:public Car
{
public:
void manual()
{
cout<<"Operation details of HondaCity"<<endl;
}
};

int main()
{
int ch;
Car *c;
cout<<"1. Maruti800"<<endl;
cout<<"2. HondaCity"<<endl;
cout<<"Enter you choice : ";
cin>>ch;
if(ch>=1 && ch<=2)
{
if(ch==1)
{
c=new Maruti800;
}
if(ch==2)
{
c=new HondaCity;
}
c->manual();
}
else
{
cout<<"Invalid choice"<<endl;
}
return 0;
}
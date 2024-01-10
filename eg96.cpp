//ABSTRACT CLASS

#include<iostream>
using namespace std;
class Car 
{
public:
virtual void manual()=0;
};
class ServiceStation
{
public:
void doService(Car *c)
{
c->manual();
cout<<"service done"<<endl;
}
};
class HondaCity:public Car
{
public:
void manual()
{
cout<<"Some information about HondaCity"<<endl;
}
};
int main()
{
ServiceStation ss;
HondaCity h;
ss.doService(&h);	
//now this wiil compile as HondaCity is a Car, and provided the implementation of the pure virtual function of abstract class
return 0;
}
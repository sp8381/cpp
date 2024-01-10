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
class HondaCity
{
};
int main()
{
ServiceStation ss;
HondaCity h;
ss.doService(&h);	//will not compile, bcoz h is not a car, and h is not implemented the abstract class
return 0;
}
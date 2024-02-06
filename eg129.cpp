#include<iostream>
using namespace std;
class Bulb
{
int w;
public:
void setWattage(int e)
{
w=e;
}
int getWattage()
{
return w;
}
Bulb()
{
cout<<"Default constructor called "<<endl;
w=0;
}
Bulb(int w)
{
cout<<"Parameterised constructor called "<<endl;
this->w=w;
}
Bulb(const Bulb &v)
{
cout<<"Copy constructor called "<<endl;
this->w=v.w;
}
};
int main()
{
Bulb b;
b.setWattage(50);
Bulb g=60;	//Bulb g(60);	parametrised constructor
Bulb k=g;	//Bulb k(g);	copy constructor 
return 0;
}
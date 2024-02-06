#include<iostream>
using namespace std;
class Bulb
{
int w;
public:
void setWattage(int w)
{
this->w=w;
}
int getWattage()
{
return w;
}
Bulb()
{
cout<<"Default constructor called "<<endl;
this->w=0;
}
Bulb(int w)
{
cout<<"parameterised constructor called "<<endl;
this->w=w;
}
Bulb(const Bulb &v)
{
cout<<"copy constructor called "<<endl;
this->w=v.w;
}
};
int main()
{
Bulb k;
Bulb b;
b=k;
return 0;
}
#include<iostream>
using namespace std;
class Bulb 
{
int w;
public:
void setWatage(int w)
{
this->w=w;
}
int getWattage()
{
return this->w;
}
Bulb()
{
cout<<"Default constructor called "<<endl;
this->w=0;
}
Bulb(int e)
{
cout<<"Parameterised constructor called "<<endl;
this->w=e;
}
Bulb(const Bulb &v)
{
cout<<"Copy constructor called "<<endl;
this->w=v.w;
}
};

int main()
{
Bulb(60);
Bulb();
return 0;
}
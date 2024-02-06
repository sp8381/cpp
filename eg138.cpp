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
return this->w;
}
Bulb()
{
cout<<"Default constructor called"<<endl;
this->w=0;
}
Bulb(int w)
{
cout<<"parameterised constructor called"<<endl;
this->w=w;
}
Bulb(const Bulb &v)
{
cout<<"Copy constructor called"<<endl;
this->w=v.w;
}
Bulb& operator=(int w)
{
cout<<"Operator= function called"<<endl;
this->w=w;
return *this;
}
};
int main()
{
Bulb k;
k=60;	//k=Bulb(60);

Bulb m;
m=k;
return 0;
}


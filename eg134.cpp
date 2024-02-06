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
Bulb(const Bulb &v)
{
cout<<"Copy constructor called "<<endl;
this->w=v.w;
}
};

int main()
{
Bulb k;
k=60;	//compiler will look for operator= function
	//k=Bulb(60);
return 0;
}
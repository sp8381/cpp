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
cout<<"parameterised constructor called "<<endl;
this->w=e;
}
Bulb(const Bulb &v)
{
cout<<"Copy constructor called "<<endl;
this->w=v.w;
}

/*
//-------------compiler will provide the below code
Bulb & operator=(Bulb &other)
{
cout<<"operator= function invoked "<<endl;
this->w=other.w;
return *this;
}
*/
};
/* 
//this code won't  compile
//error : 'void operator=' function must be non static member function

void operator=(Bulb &left,Bulb &right)
{
cout<<"Independent operator= function invoked "<<endl;
left.w=tight.w;
}
*/

int main()
{
Bulb k;
Bulb m;
k=m;
return 0;
}
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
cout<<"Default constructor called "<<endl;
this->w=0;
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

//If we don't provide this 'operator=' function
//then compiler will provide
void operator=(const Bulb &other)
{
cout<<"Operator= got invoked"<<endl;
this->w=other.w;
}
};
int main()
{
Bulb k;
k=60;	//k=Bulb(60);

return 0;
}
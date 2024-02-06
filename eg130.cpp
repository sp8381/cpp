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
k=60;	//k(60);
		//here default constructor and 
		//parametriesed constructor is called
return 0;
}
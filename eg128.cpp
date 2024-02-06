#include<iostream>
using namespace std;
class Bulb
{
int w;
public:
void setWattage(int e)
{
this->w=e;
}
int getWattage()
{
return w;
}
Bulb(int e)
{
cout<<"Parameterised constructor called"<<endl;
this->w=w;
}
};
int main()
{
Bulb b=60;	//Bulb b(60);
return 0;
}
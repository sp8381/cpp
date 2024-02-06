//this code won't compile as 
//there is ambiguity in doSomething(aaa a) and doSomething(Bulb b)

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
cout<<"Default constructor called"<<endl;
w=0;
}
Bulb(int e)
{
cout<<"parameterised constructor called"<<endl;
w=e;
}
Bulb(const Bulb &b)
{
cout<<"Copy constructor called"<<endl;
w=b.w;
}
};

void doSomething(Bulb t)	//Bulb t=10; new object created here
{
cout<<"33333"<<endl;
cout<<"Wattage is "<<t.getWattage()<<endl;;
}
int main()
{
doSomething(10);
return 0;
}
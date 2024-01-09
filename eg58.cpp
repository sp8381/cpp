//if we declare the parameterised function as default argument function then it will create ambiguity

#include<iostream>
using namespace std;
class Bulb 
{
int w;
public :
Bulb()
{
w=0;
}
Bulb(int e)
{
w=e;
}

Bulb(const Bulb &v)
{
w=v.w;
}
void setWattage(int e)
{
w=e;
}
int getWattage()
{
return w;
}
};
int main()
{
Bulb g;
Bulb t(60);
Bulb m(t);
cout<<"Wattage is "<<g.getWattage()<<endl;
cout<<"Wattage is "<<t.getWattage()<<endl;
cout<<"Wattage is "<<m.getWattage()<<endl;

return 0;
}
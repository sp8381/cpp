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
};
int main()
{
Bulb b,t;
b.setWattage(50);
t.setWattage(100);
cout<<"Wattage is "<<b.getWattage()<<endl;
cout<<"Wattage is "<<t.getWattage()<<endl;
return 0;
}
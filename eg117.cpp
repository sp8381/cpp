#include<iostream>
using namespace std;
class Bulb
{
int wattage;
public:
void setWattage(int wattage)
{
this->wattage=wattage;
}
int getWattage()
{
return this->wattage;
}
};
int main()
{
Bulb b;
b.setWattage(60);
cout<<b.getWattage()<<endl;
return 0;
}
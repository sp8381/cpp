#include<iostream>
using namespace std;
class Bulb
{
private: 
int w;
public :
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
g.setWattage(60);
cout<<"Wattage is "<<g.getWattage()<<endl;
Bulb k,m;
m.setWattage(100);
k.setWattage(240);
cout<<"Wattage is "<<k.getWattage()<<endl;
cout<<"Wattage is "<<m.getWattage()<<endl;
return 0;
}
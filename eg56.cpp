#include<iostream>
using namespace std;
class Bulb 
{
int w;
public :
Bulb(int e=0)
{
w=e;
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
Bulb t(60);
Bulb g;
cout<<"Wattage is "<<t.getWattage()<<endl;
cout<<"Wattage is "<<g.getWattage()<<endl;
return 0;
}
#include<iostream>
using namespace std;
class Bulb
{
int w;
public:
Bulb(int e)
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
Bulb b;	//Error
Bulb t(60);

cout<<"Wattage is "<<b.getWattage()<<endl;
cout<<"Wattage is "<<t.getWattage()<<endl;
Bulb k;	//ERROR	
cout<<"Wattage is "<<k.getWattage()<<endl;

return 0;
}
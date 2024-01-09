#include<iostream>
using namespace std;
class Bulb
{
private :
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
Bulb g;
Bulb *k;
k=&g;
k->setWattage(60);
cout<<"Wattage is "<<k->getWattage()<<endl;
return 0;
}
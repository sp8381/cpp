#include<iostream>
using namespace std;
class Bulb
{
private:
int w;
public:
void setWattage(int e)
{
if(e>=0 && e<=240) w=e;
else	w=0;
}
int getWattage()
{
return w;
}
};
int main()
{
Bulb b;
b.setWattage(60);
cout<<b.getWattage()<<endl;
return 0;
}
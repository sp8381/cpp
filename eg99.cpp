#include<iostream>
using namespace std;
class Bulb
{
private:
int w;
public:
void setWattage(int w)
{
this->w=w;
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
#include<iostream>
using namespace std;
class Bulb
{
private:
int w;
public:
void setWattage(int w)
{
w=w;	//here nothing happends 
}
int getWattage()
{
return w; //returns garbage value
}
};
int main()
{
Bulb b;
b.setWattage(60);
cout<<b.getWattage()<<endl;
return 0;
}
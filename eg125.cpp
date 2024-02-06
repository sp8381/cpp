#include<iostream>
using namespace std;
class Bulb
{
int wattage;
int price;
public:
void setWattage(int wattage)
{
this->wattage=wattage;
}
int getWattage()
{
return this->wattage;
}
void setPrice(int price)
{
this->price=price;
}
int getPrice()
{
return this->price;
}
int operator<(Bulb &v)
{
return this->price<v.price;
}
};

int main()
{
Bulb b,g;
b.setWattage(60);
b.setPrice(100);
g.setWattage(100);
g.setPrice(200);
if(b<g)
{
cout<<"Price of b is less than g"<<endl;
}
else
{
cout<<"Price of b is not less than g"<<endl;
}
return 0;
}
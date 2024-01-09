//The above code won't compile as the compiler does not provide space for static properties

#include<iostream>
using namespace std;
class Bulb
{
int w;
static int p;
public:
void setWattage(int e)
{
w=e;
}
int getWattage()
{
return w;
}
void setPrice(int e)
{
p=e;
}
int getPrice()
{
return p;
}
};
int Bulb::p;
int main()
{
Bulb b,d;
b.setWattage(60);
b.setPrice(10);
cout << "Wattage is " << b.getWattage() << endl;
cout << "Price is " << b.getPrice() << endl;

d.setWattage(100);
d.setPrice(20);
cout << "Wattage is "<<d.getWattage()<<endl;
cout << "Price is "<<d.getPrice()<<endl;

cout<<"Wattage is "<<b.getWattage()<<endl;
cout<<"Price is "<<b.getPrice()<<endl;

return 0;
}
#include<iostream>
using namespace std;
class Toy
{
int price;
public:
void setPrice(int price)
{
this->price=price;
}
int getPrice()
{
return this->price;
}
int operator+(int x,Toy b)
{
return a+b.getPrice();
}
};
int main()
{
Toy t1;
t1.setPrice(100);
int x=50;
int z;
z=x+t1;
cout<<z<<endl;
return 0;
}
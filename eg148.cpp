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
void operator+=(int x)
{
this->price=this->price+x;
}
};
int main()
{
Toy t1;
t1.setPrice(100);
t1+=20;
cout<<t1.getPrice()<<endl;
return 0;
}
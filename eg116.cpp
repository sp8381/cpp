#include<iostream>
using namespace std;
class Fridge;
class TV
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
friend class Calculator;
};
class Fridge
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
friend class Calculator;
};

class Calculator
{
public:
int getTotalCost(TV &t,Fridge &f)
{
return t.price+f.price;
}
int getCostDifference(TV &t,Fridge &f)
{
return t.price-f.price;
}
};

int main()
{
TV sony;
Fridge lg;
sony.setPrice(50000);
lg.setPrice(25000);

Calculator c;
int total=c.getTotalCost(sony,lg);
int diff=c.getCostDifference(sony,lg);
cout<<"Total price of sony tv and lg fridge is "<<total<<endl;
cout<<"Cost difference in sony price and lg fridge is "<<diff<<endl;
return 0;
}
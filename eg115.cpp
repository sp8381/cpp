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
friend int getTotalCost(TV &,Fridge &);
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
friend int getTotalCost(TV &,Fridge &);
};
int getTotalCost(TV &t,Fridge &f)
{
return t.price+f.price;
}
int main()
{
TV sony;
Fridge lg;
sony.setPrice(50000);
lg.setPrice(25000);
int total=getTotalCost(sony,lg);
cout<<"Total price of sony tv and lg fridge is "<<total<<endl;
return 0;
}
#include<iostream>
using namespace std;
class TV
{
private:
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
friend int getTotalCost(TV &,Fridge f);
};
class Fridge
{
private:
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
friend int getTotalCost(TV &,Fridge f);
};
int getTotalCost(TV &t,Fridge &f)
{
int total;
total=t.price+f.price;
return total;
}

int main()
{
TV product1;
Fridge product2;
product1.setPrice(50000);
product2.setPrice(25000);
int total=getTotalCost(product1,product2);
cout<<"Total Cost "<<total<<endl;
return 0;
}
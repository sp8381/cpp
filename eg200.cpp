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
friend int operator<(TV &,Fridge&);
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
friend int operator<(TV &,Fridge&);
};
int operator<(TV &a,Fridge&b)
{
return a.price<b.price;
}
int main()
{
TV t;
Fridge f;
t.setPrice(50000);
f.setPrice(25000);
if(t<f)
{
cout<<"TV is  cheaper than Fridge"<<endl;
}
else
{
cout<<"Fridge is cheaper than TV"<<endl;
}
return 0;
}
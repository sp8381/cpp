#include<iostream>
using namespace std;
class TV;
class Fan;
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
friend int operator+(TV &t,Fridge &f);
};
class TV
{
int price;
public:
void setPrice(int price);
int getPrice();
friend int operator+(TV &t,Fridge &f);
friend int operator+(TV &t,Fan &f);
};
void TV::setPrice(int price)
{
this->price=price;
}
int TV::getPrice()
{
return this->price;
}
class Fan
{
int price;
public:
void setPrice(int price);
int getPrice();
operator int()
{
return this->price;
}
};
void Fan::setPrice(int price)
{
this->price=price;
}
int Fan::getPrice()
{
return this->price;
}
int operator+(TV &t,Fridge &f)
{
int total=t.price+f.price;
return total;
}
int main()
{
TV t1;
Fridge f1;
t1.setPrice(10000);
f1.setPrice(25000);
int sum=t1+f1;
cout<<"Price of tv and fridge : "<<sum<<endl;
Fan fan1;
fan1.setPrice(200);
sum=t1+f1+fan1;
cout<<"Price of tv, fridge and fan : "<<sum<<endl;
return 0;
}
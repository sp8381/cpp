//Independent function

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
friend int operator<(TV &t,Fridge &f);
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
friend int operator<(TV &t,Fridge &f);
};
int operator<(TV &t,Fridge &f)
{
return t.price<f.price;
}
int main ()
{
TV t;
Fridge f;
t.setPrice(50000);
f.setPrice(25000);
if(t<f)
{
cout<<"Price of TV is less than Fridge"<<endl;
}
else 
{
cout<<"Price of TV is not less than Fridge"<<endl;
}
return 0;
}
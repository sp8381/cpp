/*performing math operation on properties using object name. 
//Calculate sum of the price of object 

TV t1(1000);
Fridge f1(2000);
int sum=t1+f1;
cout<<sum<<endl;
Fan fan1(300);
sum=t1+f1+fan1;
cout<<sum<<endl;

solution : we have 2 solution 
one is to create independent function and declare them as friend in classes
another is to write a conversion operator overloading OR type overloading 
Both are success

now to be able to write this 
tv+fridge+fan 
tv+fan+fridge
fridge+tv+fan
fridge+fan+tv
fan+tv+fridge
fan+fridge+tv

we have to create 1 operator overloading method in each class and 1 type overloading method
overloading + operator and int type overloading.
*/ 

#include<iostream>
using namespace std;
class TV;
class Fan;
class Fridge
{
int price;
public:
void setPrice(int price);
int getPrice();
friend int operator+(Fridge &fridge,Fan &fan);
friend int operator+(Fan &fan,Fridge &fridge);
friend int operator+(Fridge &f,TV &t);
friend int operator+(TV &t,Fridge &f);
operator int()
{
return this->price;
}
};
void Fridge::setPrice(int price)
{
this->price=price;
}
int Fridge::getPrice()
{
return this->price;
}
class TV
{
int price;
public:
void setPrice(int price);
int getPrice();
friend int operator+(TV &t,Fridge &f);
friend int operator+(Fridge &f,TV &t);
friend int operator+(TV &t,Fan &f);
friend int operator+(Fan &f,TV &t);
operator int()
{
return this->price;
}
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
friend int operator+(Fan &f,TV &t);
friend int operator+(TV &t,Fan &f);
friend int operator+(Fan &fan,Fridge &fridge);
friend int operator+(Fridge &fridge,Fan &fan);
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
int operator+(TV &t,Fan &f)
{
return t.price+f.price;
}
int operator+(Fridge &f,TV &t)
{
int total=t.price+f.price;
return total;
}
int operator+(Fridge &fridge,Fan &fan)
{
int total=fan.price+fridge.price;
return total;
}
int operator+(Fan &f,TV &t)
{
int total=f.price+t.price;
return total;
}
int operator+(Fan &fan,Fridge &fridge)
{
int total=fan.price+fridge.price;
return total;
}
/*// independent function int and fan
int operator+(int t,Fan &f)
{
cout<<t<<" "<<f.price<<endl;
return t+f.price;
}
*/
int main()
{
TV t1;
Fridge f1;
t1.setPrice(10000);
f1.setPrice(25000);
int sum=t1+f1;
cout<<"Price of tv and fridge : "<<sum<<endl;
sum=f1+t1;
cout<<"Price of fridge and tv : "<<sum<<endl;

Fan fan1;
fan1.setPrice(200);
sum=t1+f1+fan1;
cout<<"Price of tv, fridge and fan : "<<sum<<endl;
sum=t1+fan1+f1;
cout<<"Price of tv, fan and fridge : "<<sum<<endl;
sum=f1+t1+fan1;
cout<<"Price of fridge, tv and fan : "<<sum<<endl;
sum=f1+fan1+t1;
cout<<"Price of fridge, fan and tv : "<<sum<<endl;
sum=fan1+t1+f1;
cout<<"Price of fan, tv and fridge : "<<sum<<endl;
sum=fan1+f1+t1;
cout<<"Price of fan, tv and fridge : "<<sum<<endl;
return 0;
}
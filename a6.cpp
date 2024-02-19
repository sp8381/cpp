/* assingment : assign the value of t1 before increament  
and increament by 50;
Toy t1;
t1.setPrice(100);
int a;
a=t1++;		//increment by 50
cout<<t1<<endl;	//150
cout<<a<<endl;	//100
*/


#include<iostream>
using namespace std;
class Toy
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
int operator++()		//prefix
{
cout<<"Operator++ (prefix) got called"<<endl;
this->price=this->price+50;
return this->price;
}
int operator++(int)		//postfix
{
cout<<"Operator++ (postfix) got called"<<endl;
int k;
k=this->price;
this->price=this->price+50;
return k;
}
int operator=(Toy &t)
{
cout<<"Operator= got called"<<endl;
return t.getPrice();
}
operator int()
{
cout<<"type conversion got called"<<endl;
return this->price;
}
};


int main()
{
Toy t1;
t1.setPrice(120);
cout<<"Price of toy : "<<t1.getPrice()<<endl;
int a,b,c;
a=t1++;
cout<<"After a=t1++"<<endl;
cout<<"a = "<<a<<endl;
cout<<"Price of toy after postfix increament : "<<t1.getPrice()<<endl;
b=++t1;
cout<<"After b=++t1"<<endl;
cout<<"b = "<<b<<endl;
cout<<"Price of toy after prefix increment: "<<t1.getPrice()<<endl;

return 0;
}
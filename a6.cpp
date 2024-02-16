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
void operator++()		//prefix
{
this->price=this->price+50;
}
void operator++(int)		//postfix
{
this->price=this->price+50;
}
int operator=(Toy &t)
{
return t.getPrice();
}
friend Toy & operator=(int a,Toy &t);
};

Toy & operator=(int a,Toy &t)
{
a=t.price;
return t;
}


int main()
{
Toy t1;
t1.setPrice(120);
cout<<"Price of toy : "<<t1.getPrice()<<endl;
int a;
a=10;
a=t1;
cout<<a;
cout<<"Price of toy after postfix increment: "<<t1.getPrice()<<endl;
++t1;
cout<<"Price of toy after prefix increment: "<<t1.getPrice()<<endl;

return 0;
}
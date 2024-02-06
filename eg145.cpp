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
int operator++()	//pre Increament, preFix
{
return this->price=this->price+20;
}
int operator++()	//postIncreament, postFix
{
return this->price=this->price+10;
}
};
int main()
{
Toy t1,t2;
t1.setPrice(100);
t2.setPrice(150);
int a,b;
a= (t1++);
b= (++t2);
cout<<t1.getPrice()<<endl;
cout<<t2.getPrice()<<endl;
cout<<a<<endl;
cout<<b<<endl;
return 0;
}
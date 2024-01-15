//assingment is to print the price of object only using name

#include<iostream>
using namespace std;
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
};

//Independent function
ostream & operator<<(ostream &o,TV &t)
{
o<<t.getPrice();
return o;
}

int main()
{
TV t;
t.setPrice(50000);
cout<<"Price is TV is : "<<t<<endl;
return 0;
}

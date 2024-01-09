#include<iostream>
#include<string.h>
using namespace std;
class SDCard
{
int capacity;
public:
void setCapacity(int e)
{
//here we assume that the value assigned by user 
//is validated
capacity=e;
}
int getCapacity()
{
return capacity;
}
};
class MobilePhone
{
private:
char brandName[36];
SDCard sdCard;
int price;
public:
void setBrandName(const char *b)
{
strcpy(brandName,b);
}
void getBrandName(char *b)
{
strcpy(b,brandName);
}
void setPrice(int e)
{
price=e;
}
int getPrice()
{
return price;
}
void setSDCard(SDCard s)
{
sdCard=s;
}
SDCard getSDCard()
{
return sdCard;
}
};

int main()
{
MobilePhone m;
m.setBrandName("Nokia");
m.setPrice(2500);
SDCard ss;
ss.setCapacity(10);
m.setSDCard(ss);
char br[36];
m.getBrandName(br);
int pr;
pr=m.getPrice();
SDCard kk=m.getSDCard();
cout<<"MobilePhone details"<<endl;
cout<<"Brand : "<<br<<endl;
cout<<"price : "<<pr<<endl;
cout<<"capacity of SDCard in Mobile : "<<kk.getCapacity()<<endl;

return 0;
}
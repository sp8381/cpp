#include<iostream>
using namespace std;
class Bulb
{
int w;
public:
void setWattage(int e)
{
w=e;
}
int getWattage()
{
return w;
}
};
int main()
{
Bulb *p;
p=new Bulb;
p->w=50;	//error 
p->setWattage(60);
cout<<"Wattage is "<<p->getWattage()<<endl;
p->ramu();	//error
return 0;
}
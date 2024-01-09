//Here this code has error that the programmer 
//has returned the address of the encapsulated member
//hence, it is a security breach

#include<iostream>
using namespace std;
class Bulb
{
int w;
public :
void setWattage(int e)
{
if(e>=0 && e<=240) w=e;
else w=0;
}
int *getWattage()
{
return &w;
}
};
int main()
{
Bulb b;
int *p;
b.setWattage(60);
p=b.getWattage();
cout<<*p<<endl;
*p=120;
cout<<*p<<endl;
*p=-3;
cout<<*p<<endl;
return 0;
}
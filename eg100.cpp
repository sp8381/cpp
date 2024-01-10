//proof that the compiler introduces 'this' named pointer 
//here we used 'ramu' inplace of 'this' see does it works?

#include<iostream>
using namespace std;
class Bulb
{
private:
int w;
public:
void setWattage(int w)
{
ramu->w=w;
}
int getWattage()
{
return w;
}
};
int main()
{
Bulb b;
b.setWattage(60);
cout<<b.getWattage()<<endl;
return 0;
}
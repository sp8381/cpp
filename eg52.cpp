//CASE 4 

#include<iostream>
using namespace std;
class Bulb
{
int w;
public:

Bulb(int e)
{
w=e;
}
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
Bulb b;	
Bulb t(60);	//Error

return 0;
}
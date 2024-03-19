#include<iostream>
using namespace std;
class Bulb
{
private:
int w;
public:
void setWattage(int e)
{
w=e;
}
int operator*()
{
return w;
}
};
int main()
{
Bulb g;
g.setWattage(60);
cout<<*g<<endl;
return 0;
}
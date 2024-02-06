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
Bulb()
{
w=0;
}
Bulb(int e)
{
w=e;
}
Bulb(const Bulb &b)
{
w=b.w;
}

};

//Independent function
ostream & operator<<(ostream &o,Bulb &b)
{
o<<b.getWattage();
return o;
}
int main()
{
Bulb g;
g.setWattage(60);

cout<<g<<endl;

return 0;
}
#include<iostream>
using namespace std;
class Bulb
{
private: 
int w;
public :
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
Bulb g;
g.w=100;	//this line won't compile as w is private
	//and encapsulated and hence cannot accessed from outside the class

}
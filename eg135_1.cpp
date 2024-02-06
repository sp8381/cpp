#include<iostream>
using namespace std;
class Bulb
{
int w;
public:
void setWattage(int w)
{
this->w=w;
}
int getWattage()
{
return this->w;
}
//we have to provide prameterised constructor and default constructor
};
int main()
{
Bulb k;		//Bulb k(); // demands default constructor
Bulb g;		//Bulb k(); // demands default consturctor
g=k;	//g=k();   this will compile demand  parametrised constructor and compiler will provide the 'operator=' function
g=60;	//g=k(60);  this will not compile, No operator= function
Bulb(60);	//anonymous object, //demands parameterised function
return 0;
}

/*
we provided the parameterised constructor 
then compiler will look for 'operator=' function
if not then copiler gives error that 
no match for 'operator=' function 
if we provide parameterised fuction then 
compiler will provide the 'operator=' function

and the "9 rules for cunstructor" are always followed

*/
//ABSTRACT CLASS
#include<iostream>
using namespace std;

class Car
{
public :
virtual void manual()=0;
};
int main()
{
Car a;	//wrong, cannot create object of abstract class
Car *p;
new Car;	//wrong, cannot create object of abstract class

return 0;
}
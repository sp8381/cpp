//ABSTRACT CLASS
//EXAMPLE OF PURE VIRTUAL FUNCTION 

#include<iostream>
using namespace std;
class Car
{
public:
virtual void manual()=0;
};
class Maruti800:public Car
{
public:
void manual()
{
cout<<"Cool"<<endl;
}
};
int main()
{
Maruti800 m;	
m.manual();
return 0;
}
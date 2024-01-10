//ABSTRACT CLASS

#include<iostream>
class Car
{
public:
virtual void manual()=0;
};
class Maruti800:public Car
{
public:
};
int main()
{
Maruti800 m;	//wrong, cannot create object of abstract class, as maruti 800 is inheriting the abstract class and did not provide the implementation of the pure virtual function, hence derived also became abstract 

return 0;
}
//Note: if the object of dericed class is created then first the base class constructor is called and then the derived class constructor is called

#include<iostream>
using namespace std;
class aaa
{
public:
aaa()
{
cout<<"Base class default constructor"<<endl;
}
};
class bbb:aaa
{
public:
bbb()
{
}
};
int main()
{
bbb b;
return 0;
}
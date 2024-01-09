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
class bbb:public aaa
{
public:
bbb()
{
cout<<"Derived class default constructor"<<endl;
}
bbb(int e)
{
cout<<"Derived class parameterised constructor"<<endl;
}
};
int main()
{
bbb b;
bbb t(60);
return 0;
}
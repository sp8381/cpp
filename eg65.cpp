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
};
int main()
{
bbb b;
bbb g;
return 0;
}
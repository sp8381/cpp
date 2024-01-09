#include<iostream>
using namespace std;
class aaa
{
public:
aaa(int e)
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
return 0;
}
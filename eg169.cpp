#include<iostream>
using namespace std;
class aaa
{
public:
int doSomething()
{
cout<<"doSomething got called"<<endl;
return 20;
}
};
int main()
{
const aaa a;
a.doSomething();

return 0;
}
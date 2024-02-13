#include<iostream>
using namespace std;
class aaa
{
public:
int doSomething() const		//here we declared const , that we will not change the value in this function
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
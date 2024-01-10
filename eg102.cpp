#include<iostream>
using namespace std;
class aaa
{
public:
aaa()
{
cout<<"Default constructor "<<endl;
}
~aaa()
{
cout<<"Destructor"<<endl;
}
};
void lmn()
{
aaa g,t;
cout<<"Cool"<<endl;
}
int main()
{
aaa a;
cout<<"Whatever"<<endl;
lmn();
cout<<"Good"<<endl;
return 0;
}
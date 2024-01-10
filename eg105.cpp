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

int main()
{
aaa *p;
p=new aaa[5];	
delete p;
return 0;
}
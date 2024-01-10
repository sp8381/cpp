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
aaa a;
cout<<"Whatever"<<endl;
aaa *p;
cout<<"Ujjain"<<endl;
p=new aaa;	
cout<<"Good"<<endl;
delete p;
cout<<"Indore"<<endl;
return 0;
}
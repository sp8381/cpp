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
p=new aaa;	//here memory won't be released for aaa becaus it is dynamically allocated
cout<<"Good"<<endl;
return 0;
}
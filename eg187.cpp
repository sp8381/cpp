 #include<iostream>
#include<string.h>
using namespace std;
int main()
{
string a="ujjain";
cout<<a<<endl;
cout<<a.capacity()<<endl;
a.resize(4);
cout<<"("<<a<<")"<<endl;
cout<<a.capacity()<<endl;
a.resize(16);
cout<<"("<<a<<")"<<endl;
cout<<a.capacity()<<endl;
a.resize(7);
cout<<"("<<a<<")"<<endl;
cout<<a.capacity()<<endl;

return 0;
}
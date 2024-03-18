#include<iostream>
using namespace std;
int main()
{
string a;
cout<<a.capacity()<<endl;
a="Ujjain";
cout<<"a : "<<a<<endl;
cout<<"size : "<<a.size()<<endl;
cout<<"length : "<<a.length()<<endl;
cout<<"capacity : "<<a.capacity()<<endl;
cout<<"max size of a : "<<a.max_size()<<endl;

a=a+"-Indore";
cout<<a<<endl;
cout<<"capacity : "<<a.capacity()<<endl;
a.resize(1000);
cout<<"after resizing 1000"<<endl;
cout<<"capacity : "<<a.capacity()<<endl;

return 0;
}
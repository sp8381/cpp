#include<iostream>
using namespace std;
int main()
{
string a="Ujjain";
string b="Indore";
cout<<a<<", "<<b<<endl;
string c;
c=a;
a=b;
b=c;
cout<<a<<", "<<b<<endl;

a.swap(b);

cout<<a<<", "<<b<<endl;

return 0;
}
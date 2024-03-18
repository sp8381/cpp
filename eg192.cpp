#include<iostream>
using namespace std;
int main()
{
string a="Ujjain";
string b="Good";

cout<<(a==b)<<endl;
cout<<(a!=b)<<endl;
cout<<(a<=b)<<endl;
cout<<(a>=b)<<endl;
cout<<(a<b)<<endl;
cout<<(a>b)<<endl;

a.append("-Indore");
cout<<a<<endl;
a.push_back('b');
cout<<a<<endl;

return 0;
}
#include<iostream>
using namespace std;
int main()
{
string g="Ujjain";

string::iterator i=g.begin();
while(i!=g.end())
{
cout<<*i<<endl;
++i;
}

return 0;
}
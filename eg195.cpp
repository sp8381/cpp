#include<iostream>
using namespace std;
int main()
{
string a="Ujjain";
cout<<a<<endl;

const char *p;
p=a.c_str();
//*p='I';	//error: assingment to read only variable
char *q;
q=(char *)p;
*q='I';
cout<<a<<endl;

return 0;
}
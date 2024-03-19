#include<iostream>
using namespace std;
int main()
{
string g="Ujjain";

g.replace(2,2,10,'A');
cout<<g<<endl;		//UjAAAAAAAAAAin

return 0;
}
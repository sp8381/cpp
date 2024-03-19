#include<iostream>
using namespace std;
int main()
{
string g="Ujjain";
string b="abcdefghijkl";
g.insert(2,b,3);
cout<<g<<endl;		//Ujdefghijkljain

g="Ujjain";
g.insert(2,b,3,2);
cout<<g<<endl;		//Ujdejain

return 0;
}
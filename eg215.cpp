#include<iostream>
using namespace std;
int main()
{
string g="Ujjain";
string b="abcdefgh";
g.replace(2,1,b);
cout<<g<<endl;		//Ujabcdefghain

return 0;
}
#include<iostream>
using namespace std;
int main()
{
string g="Ujjain";
string b="abcdefgh";
g.replace(2,3,b);
cout<<g<<endl;	//Ujabcdefgn

return 0;
}
#include<iostream>
using namespace std;
int main()
{
string g="Ujjain";
string b="abcdefgh";

g.replace(2,1,b,3,2);	//abc de fgh
cout<<g<<endl;		//Uj de ain
			//Ujdeain	
return 0;
}
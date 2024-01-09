#include<iostream>
using namespace std;
int main()
{
int x;
cout<<&x<<endl;
//cout<<(unsigned int)&x<<endl;	//this will not work as the sizeof(int *) is 8 byte on this machine dell inspiron 6 so use long long unsigned int

return 0;
}
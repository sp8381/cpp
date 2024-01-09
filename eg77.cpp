#include<iostream>
using namespace std;
int main()
{
int x;
cout<<(long long unsigned int)&x<<endl;
int *p;
p=&x;
cout<<(long long unsigned int)p<<endl;
p++;
//p=(sizeof(p)*1)
cout<<(long long unsigned int)p<<endl;
p=p+10;
//p=(sizeof(p)*10)
cout<<(long long unsigned int)p<<endl;

return 0;
}
#include<iostream>
using namespace std;
int main()
{
int x;
string a;
char m;
cout<<"Enter a number : ";
cin>>x;
cin.ignore(1000,'\n');
cout<<"Enter a string : ";
getline(cin,a);
cout<<"Enter a char : ";
cin>>m;
cout<<"***********************"<<endl;
cout<<"("<<x<<")"<<endl;
cout<<"("<<a<<")"<<endl;
cout<<"("<<m<<")"<<endl;

return 0;
}
#include<iostream>
#include<ios>
#include<limits>
using namespace std;
int main()
{
int x;
string a;
char m;
cout<<"Enter a number : ";
cin>>x;
//cin.ignore(1000,'\n');
cin.ignore(numeric_limits<streamsize>::max(),'\n');

cout<<"Enter a string : ";
getline(cin,a);
cout<<"Enter a char : ";
cin>>m;
cout<<"***********************"<<endl;
cout<<x<<endl;
cout<<a<<endl;
cout<<m<<endl;
cout<<numeric_limits<streamsize>::max()<<endl;


return 0;
}
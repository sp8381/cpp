#include<iostream>
#include<fstream>
using namespace std;

int main()
{
int a,b;
char str[21];
char j;

ifstream k;
k.open("tmp.pqr");
k>>a;
k>>str;
k>>b;
k>>j;
cout<<"("<<a<<")"<<endl;
cout<<"("<<str<<")"<<endl;
cout<<"("<<b<<")"<<endl;
cout<<"("<<j<<")"<<endl;

k>>a;
k>>str;
k>>b;
k>>j;
cout<<"("<<a<<")"<<endl;
cout<<"("<<str<<")"<<endl;
cout<<"("<<b<<")"<<endl;
cout<<"("<<j<<")"<<endl;

k.close();
return 0;
}
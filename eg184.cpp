#include<fstream>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
int x,y;
char str[21];
char m;

ofstream f;
f.open("tmp.pqr");

x=1010;
y=2020;
strcpy(str,"Ujjain");
m='A';
f<<x;
f<<" ";
f<<str;
f<<" ";
f<<y;
f<<" ";
f<<m;

x=4040;
y=6050;
strcpy(str,"Indore");
m='Z';
f<<x;
f<<" ";
f<<str;
f<<" ";
f<<y;
f<<" ";
f<<m;

cout<<"Data inserted"<<endl;
f.close();
return 0;
}
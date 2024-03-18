#include<iostream>
#include<string.h>
using namespace std;
int main()
{
string a="Ujjain";
char b[21];

strcpy(b,a.c_str());

cout<<b<<endl;

return 0;
}
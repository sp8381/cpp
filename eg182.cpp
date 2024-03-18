#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
char a[32];
cout<<"Enter name : ";
fgets(a,22,stdin);
char m;
//fflush(stdin);
while(getchar()!='\n');
a[strlen(a)-1]='\0';
cout<<a<<endl;
return 0;
}
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class TMString
{
char *ptr;
int length;

public:

void printString()
{
cout<<this->ptr;
}

TMString()
{
ptr=NULL;
cout<<"default constructor called"<<endl;
}

void operator=(char *g)
{
this->length=strlen(g);
//condition check 
if(this->ptr==NULL)
{
this->ptr=(char *)malloc(length+1);
for(int i=0;i<length;i++) this->ptr[i]=g[i];
ptr[length]='\0';
}
else
{
free(this->ptr);
this->ptr=(char *)malloc(length+1);
for(int i=0;i<length;i++) this->ptr[i]=g[i];
this->ptr[length]='\0';
}
}

~TMString()
{
cout<<"destructor called"<<endl;
free(ptr);
}

void operator=(TMString &v)
{
if(v.ptr==NULL)
{
cout<<"Empty string cannot assign"<<endl;
return;
}
int len=strlen(v.ptr);
this->ptr=(char *)malloc(len);
cout<<"memory allocated"<<len<<endl;
for(int i=0;i<len;i++)
{
this->ptr[i]=v.ptr[i];
}
cout<<"data copied"<<endl;
}

};

ostream & operator<<(ostream &o,TMString &j)
{
j.printString();
return o;
}

int main()
{
TMString s;
s="Ujjain"; 
cout<<s<<endl;
s="Indore dewas"; 
cout<<s<<endl;

TMString k;
k=s;	//k=TMString(s);
cout<<k<<endl;
s="Dubai";
cout<<s<<endl;
cout<<k<<endl;

TMString m;
TMString j;
m=j;
cout<<m<<endl;

return 0;
}
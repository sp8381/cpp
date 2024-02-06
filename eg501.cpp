//assingment is to assign string direct to object 
//without declaring size of string and 
//print the string using the object name
//TMString s;	//created object;
//s="Ujjian";	//assigned string directly
//cout<<s;	//printing stirng directly with object name

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class TMString
{
char *p;
int length;

public:
void getString()
{
cout<<this->p;
} 
TMString()
{
cout<<"default constructor called"<<endl;
this->p=NULL;
}

void operator=(char *g)
{
this->length=strlen(g)+1;
if(p!=NULL)
{
free(p);
p=(char *)malloc(length);
int i;
for(i=0;i<length-1;i++)	p[i]=g[i];
p[i]='\0';
}
else
{
p=(char *)malloc(length);
int i;
for(i=0;i<length-1;i++)
{
p[i]=g[i];
}
p[i]='\0';
}
}

void operator=(TMString &v)
{
}

~TMString()
{
free(this->p);
cout<<"destructor called"<<endl;
}

};

ostream & operator<<(ostream &o,TMString &s)
{
s.getString();
return o;
}

int main()
{
TMString s;
s="Ujjain";
cout<<s<<endl;
s="Indore Dewas";
cout<<s<<endl;

TMString k;
k=s;
cout<<k<<endl;
s="DUBAI";
cout<<s<<endl;
cout<<k<<endl;
return 0;
}
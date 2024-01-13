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
cout<<"memory released "<<endl;
free(p);
p=(char *)malloc(length);
int i;
for(i=0;i<length-1;i++)	p[i]=g[i];
p[i]='\0';

cout<<"p=Indore"<<endl;
}
else
{
p=(char *)malloc(length);
cout<<"s=Ujjain"<<endl;

int i;
for(i=0;i<length-1;i++)
{
p[i]=g[i];
}
p[i]='\0';

}
}

~TMString()
{
cout<<"destructor called"<<endl;
free(p);
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

return 0;
}
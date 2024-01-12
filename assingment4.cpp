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
public:
void getString()
{
cout<<this->p<<endl;
} 
TMString()
{
this->p=NULL;
}

void operator=(char *g)
{
this->p=(char *)malloc(strlen(g)+1);
this->p=g;
}

~TMString()
{
cout<<"destructor called"<<endl;
delete p;
}
};

ostream & operator<<(ostream &o,TMString &s)
{
s.getString();
return o;
}
 
namespace thinkingmachines
{
TMString s;
}

using namespace thinkingmachines;
int main()
{
s="Ujjain";

cout<<s<<endl;

return 0;
}
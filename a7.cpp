/* small play with strings 
Assingment Done 20/02/2024
TMString s,k;
s="Ujjain";
s="Indore Dewas"; // new memory allocated and prvious released 
k=s;	//assigning string 
s="Dubai";	

TMString k,s;
k=s;		//assinging empty string (done)

k=s+g;
m+=g;
m+="Sonu";
if(k<s)
if(k>s)
if(k<=s)
if(k>=s)
if(k!=s)
if(k==s);
*/
//Assigning string to object 
//TMString s;
//s="Ujjain";

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int lastCode=0;
class TMString
{
char *ptr;
int length;
int code;

public:

void printString()
{
cout<<this->ptr;
}

TMString()
{
ptr=NULL;
code=lastCode+1;
lastCode++;
//cout<<"default constructor called with code "<<this->code<<endl;
}

TMString & operator=(const char *g)
{
//cout<<"Operator= got called with parameter const char *"<<endl;
this->length=strlen(g);
//condition check 
if(this->ptr==NULL)
{
this->ptr=(char *)malloc(length+1);
for(int i=0;i<length;i++) this->ptr[i]=g[i];
this->ptr[length]='\0';
return *this;
}
else
{
free(this->ptr);
this->ptr=(char *)malloc(length+1);
for(int i=0;i<length;i++) this->ptr[i]=g[i];
this->ptr[length]='\0';
return *this;
}
}

~TMString()
{
//cout<<"destructor called with code "<<this->code<<endl;
free(this->ptr);
}

TMString & operator=(const TMString &v)
{
//cout<<"Operator= got called with parameter const TMString &"<<endl;
if(v.ptr==NULL)
{
cout<<"Empty string cannot assign"<<endl;
return *this;
}
free(this->ptr);
int len=strlen(v.ptr);
this->ptr=(char *)malloc(len+1);
//cout<<"memory allocated for length : "<<len<<endl;
for(int i=0;i<len;i++) this->ptr[i]=v.ptr[i];
this->ptr[len]='\0';
return *this;
//cout<<"data copied"<<endl;
}


TMString operator+(const TMString &v)
{
//cout<<"Operator+ got called with parameter const TMString &v"<<endl;
TMString k;
if(v.ptr==NULL) return k;
int len=strlen(this->ptr)+strlen(v.ptr);
k.ptr=(char *)malloc(len+1);
//cout<<"memory allocated for length of k : "<<len<<endl;
int i=0,j=0;
while(this->ptr[i]!='\0')
{
k.ptr[j]=this->ptr[i];
i++;
j++;
}
i=0;
while(v.ptr[i]!='\0')
{
k.ptr[j]=v.ptr[i];
i++;
j++;
}
k.ptr[len]='\0';
//cout<<"data copied"<<endl;
return k;
}

TMString operator+=(const char *g)
{
//cout<<"Operator+= got called with parameter const char *"<<endl;
int length=strlen(this->ptr)+strlen(g);
TMString k;
k.ptr=this->ptr;
this->ptr=(char *)malloc(length+1);
int i,j;
for(i=0,j=0;i<strlen(k.ptr);i++,j++)
{
this->ptr[j]=k.ptr[i];
}
cout<<this->ptr<<endl;
length=strlen(g);
for(i=0;i<length;i++,j++)
{
this->ptr[j]=g[i];
}
this->ptr[j]='\0';
return *this;
}

int operator<(const TMString &v)
{
if(strlen(this->ptr)<strlen(v.ptr)) return 1;
else return 0;
}
int operator>(const TMString &v)
{
if(strlen(this->ptr)>strlen(v.ptr)) return 1;
else return 0;
}
int operator<=(const TMString &v)
{
if(strlen(this->ptr)<strlen(v.ptr) || strlen(this->ptr)==strlen(v.ptr)) return 1;
else return 0;
}
int operator>=(const TMString &v)
{
if(strlen(this->ptr)>strlen(v.ptr) || strlen(this->ptr)==strlen(v.ptr)) return 1;
else return 0;
}
int operator!=(const TMString &v)
{
if(strlen(this->ptr)!=strlen(v.ptr)) return 1;
else return 0;
}
int operator==(const TMString &v)
{
if(strlen(this->ptr)==strlen(v.ptr)) return 1;
else return 0;
}
};

ostream & operator<<(ostream &o,TMString &j)
{
j.printString();
return o;
}

int main()
{
TMString k,s,g;
k="Dewas";
s="Ujjain";
g="Indore";

k=s+g;
cout<<"k : "<<k<<endl;
k+="Sonu";
cout<<"k : "<<k<<endl;
cout<<"K : "<<k<<endl;
cout<<"s : "<<s<<endl;
cout<<"g : "<<g<<endl;

if(k<s) cout<<"k length is smaller than s"<<endl;
else cout<<"k length is not smaller than s"<<endl;

if(k>s) cout<<"k length is greater than s"<<endl;
else cout<<"k length is not greater than s"<<endl;

if(s==g) cout<<"s length is equal to g"<<endl;
else cout<<"s length is not equal to g"<<endl;

if(k!=g) cout<<"k length is not equal to g"<<endl;
else cout<<"s length is equal to g"<<endl;

if(k<=g) cout<<"k length is less or equal to g"<<endl;
else cout<<"k length is not less or equal to g"<<endl;

if(s>=g) cout<<"s length is less or equal to g"<<endl;
else cout<<"s length is not less or equal to g"<<endl;

return 0;
}
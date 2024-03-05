/* small play with strings 
Assingment Done 20/02/2024
TMString a,b;
a="Ujjain";
a="Indore Dewas"; // new memory allocated and prvious released 
b=a;	//assigning string 
a="Dubai";	

TMString c="cool";		//assinging empty string (done)

TMString d=c;
k=s+g;
k=s+"shubham";
m+=g;
m+="Sonu";

if(k<s)	// k="go", s="come"  so answer is false(0),don't calculate on base of length.
if(k>s)
if(k<=s)
if(k>=s)
if(k!=s)
if(k==s);

TMString j;	(Done) 3Mar2024
j="AB:
j=j*10;  	//this is something new to do.

new topic 

j="shubham "+s;		//yaha ptr array reutrn hoga op+(const char *ptr,const TMString &other);
j="shubham "+"patil";	//same yaha bhi ptr array return hoga  or op+(const char *ptr,const char *ptr);

TMString t;
cin>>t;		//this is the last one
cout<<t;

*/
//------------------------------------------

#include<iostream>
#include<string.h>
using namespace std;
class TMString
{
private:
char *ptr;
int size;
int releaseMemory;

public:
int getStringLength()
{
return strlen(this->ptr);
}
int getSize()
{
return this->size;
}
TMString();
TMString(const char *ptr);
TMString(const TMString &other);
~TMString();
TMString & operator=(const TMString &other);
TMString & operator=(const char *ptr);
TMString operator+(const TMString &other);
TMString operator+(const char *ptr);
TMString operator*(int i);
void operator+=(const char *ptr);
void operator+=(const TMString &other);

friend void operator>>(istream & ii,TMString &tmString);
friend ostream & operator<<(ostream & out,const TMString &tmString);
};
TMString::TMString()
{
this->ptr=NULL;
this->size=0;
this->releaseMemory=1;
};
TMString::TMString(const char *ptr)
{
this->ptr=NULL;
this->size=0;
this->releaseMemory=1;
this->size=strlen(ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,ptr);
}
TMString::TMString(const TMString &other)
{
this->ptr=NULL;
this->size=0;
this->releaseMemory=1;
this->size=strlen(other.ptr);
this->ptr=new char[this->size];
strcpy(this->ptr,other.ptr);
}
TMString::~TMString()
{
if(this->releaseMemory) delete [] this->ptr;
}
TMString & TMString::operator=(const char *ptr)
{
if(!ptr) return *this;	//if(!ptr) is as good as if(ptr==NULL)
if(this->ptr) delete [] this->ptr;
this->ptr=NULL;
this->size=0;
this->size=strlen(ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,ptr);
return *this;
}
TMString & TMString::operator=(const TMString &other)
{
if(!other.ptr) return *this;	//if(!other.ptr) is as good as if(other.ptr==NULL)
if(this->ptr) delete [] this->ptr;
if(other.releaseMemory==0) 
{
this->ptr=other.ptr;
this->size=other.size;
return *this;
}
this->ptr=NULL;
this->size=0;
this->size=strlen(other.ptr);
this->ptr=new char[this->size+1];
strcpy(this->ptr,other.ptr);

this->ptr[size]='\0';
return *this;
}
TMString TMString::operator+(const TMString &other)
{
TMString k;
k.releaseMemory=0;
if(this->ptr==NULL && other.ptr==NULL) return k;
else if(other.ptr==NULL) k=other;
else
{
k=(*this);
k+=(other);
}
return k;
}
TMString TMString::operator+(const char *ptr)
{
TMString k;
k.releaseMemory=0;
if(this->ptr==NULL && ptr==NULL) return k;
else if(ptr==NULL) k=(*this);
else
{
k=(*this);
k+=(ptr);
}
return k;
}
void TMString::operator+=(const char *ptr)
{
if(this->ptr==NULL && ptr==NULL) return ;
if(ptr==NULL) return;
if(this->ptr==NULL) 
{
(*this)=ptr;
return;
}
int len=strlen(ptr);
char *tmp=new char[this->size+len+1];
strcpy(tmp,this->ptr);
strcat(tmp,ptr);
delete [] this->ptr;
this->ptr=tmp;
this->size=this->size+len;
}
void TMString::operator+=(const TMString &other)
{
if(this->ptr==NULL && other.ptr==NULL) return ;
if(other.ptr==NULL) return;
if(this->ptr==NULL) 
{
(*this)=other;
return;
}
char *tmp=new char[this->size+other.size+1];
strcpy(tmp,this->ptr);
strcat(tmp,other.ptr);
delete [] this->ptr;
this->ptr=tmp;
this->size=this->size+other.size;
}

TMString TMString::operator*(int i)
{
TMString k;
k.releaseMemory=0;
if(i<=1) return k;
if(this->ptr==NULL) return k;
k.ptr=new char[((this->size)*i)+1];
strcpy(k.ptr,this->ptr);
for(int j=1;j<i;j++)
{
strcat(k.ptr,this->ptr);
}
return k;
}

ostream & operator<<(ostream & out,const TMString &tmString)
{
if(tmString.ptr==NULL)	return out;
out<<tmString.ptr;
return out; 
}

void operator>>(istream & ii,TMString &tmString)
{
if(tmString.ptr) delete [] tmString.ptr;
tmString.ptr=NULL;
tmString.size=0;
char *tmp;
tmp=NULL;
int i=0;
int j,k;

while(1)
{
char m=getchar();
if(m=='\n') break;
tmString.size++;
tmp=new char[tmString.size+1];
if(tmString.ptr!=NULL)
{
for(k=0;k<tmString.size-1;k++)
{
tmp[k]=tmString.ptr[k];
}
}
tmp[k]=m;
if(tmString.ptr) delete [] tmString.ptr;
tmString.ptr=tmp;
}
tmString.ptr[tmString.size]='\0';
}

int main()
{
TMString b;
cout<<"Enter a string : ";
cin>>b;
cout<<b<<endl;

return 0;
}
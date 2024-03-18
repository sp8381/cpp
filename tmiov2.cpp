//File Handling 

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<ios>
#include<limits>
using namespace std;

class OutputFileStream
{
private:
FILE *f;
int mode;
int lastOperationFailed;
public:
const static int append=1;
const static int overwrite=2;
OutputFileStream()
{
this->f=NULL;
this->mode=-1;
this->lastOperationFailed=0;
}
OutputFileStream(const char *fileName,int mode)
{
this->f=NULL;
this->mode=-1;
this->lastOperationFailed=0;
this->open(fileName,mode);
}
void open(const char *fileName,int mode)
{
if(this->f!=NULL) 
{
fclose(this->f);
this->f=NULL;
this->mode=-1;
}
this->lastOperationFailed=1;
if(fileName==NULL) return;
if(mode!=append && mode!=overwrite) return;
if(mode==append)
{
f=fopen(fileName,"a");
}
else if(mode==overwrite)
{
f=fopen(fileName,"w");
}
if(f==NULL) return;
lastOperationFailed=0;
}
int fail()
{
return lastOperationFailed;
}
void close()
{
lastOperationFailed=0;
if(this->f==NULL) return;
fclose(this->f);
}
OutputFileStream & operator<<(char c)
{
this->lastOperationFailed=1;
if(this->f==NULL) return *this;
fputc(c,this->f);
this->lastOperationFailed=0;
return *this;
}
//version 2 methods

OutputFileStream & operator<<(const char *str)
{
this->lastOperationFailed=1;
if(this->f==NULL) return *this;
fputs(str,this->f);
this->lastOperationFailed=0;
return *this;
}
OutputFileStream & operator<<(string str)
{
this->lastOperationFailed=1;
if(this->f==NULL) return *this;
fputs(str.c_str(),this->f);
this->lastOperationFailed=0;
return *this;
}

OutputFileStream & operator<<(int num)
{
char str[21];
sprintf(str,"%d",num);
this->lastOperationFailed=1;
if(this->f==NULL) return *this;
fputs(str,this->f);
this->lastOperationFailed=0;
return *this;
}

};

class InputFileStream
{
private:
FILE *f;
int lastOperationFailed;
public:
InputFileStream()
{
this->f=NULL;
this->lastOperationFailed=0;
}
InputFileStream(const char *fileName)
{
this->f=NULL;
this->lastOperationFailed=0;
this->open(fileName);
}
void open(const char *fileName)
{
if(this->f!=NULL)
{
fclose(this->f);
this->f=NULL;
}
this->lastOperationFailed=1;
if(fileName==NULL) return;
f=fopen(fileName,"r");
if(f==NULL) return;
lastOperationFailed=0;
}
int fail()
{
return this->lastOperationFailed;
}
void close()
{
this->lastOperationFailed=0;
if(this->f!=NULL) fclose(this->f);
}
InputFileStream & operator>>(char &c)
{
this->lastOperationFailed=1;
if(this->f==NULL) return *this;
if(feof(this->f)) return *this;
c=fgetc(this->f);
if(feof(this->f)) return *this;
this->lastOperationFailed=0;
return *this;
}

//version 2 methods
InputFileStream & operator>>(char *str)
{
this->lastOperationFailed=1;
if(this->f==NULL) return *this;
if(feof(this->f)) return *this;
char g;
char *p=str;
while(1)
{
g=fgetc(this->f);
if(feof(this->f) || g=='\n') break;
*p=g;
p++;
}
*p='\0';
this->lastOperationFailed=0;
return *this;
}
InputFileStream & operator>>(string &str)
{
str.clear();
this->lastOperationFailed=1;
if(this->f==NULL) return *this;
if(feof(this->f)) return *this;
char g;
while(1)
{
g=fgetc(this->f);
if(feof(this->f) || g=='\n') break;
str.push_back(g);
}
this->lastOperationFailed=0;
return *this;
}
InputFileStream & operator>>(int &num)
{
char a[21];
this->lastOperationFailed=1;
if(this->f==NULL) return *this;
if(feof(this->f)) return *this;
char g;
int x=0;
while(1)
{
g=fgetc(this->f);
if(feof(this->f) || g==' ' || g=='\n') break;
a[x]=g;
x++;
}
if(x==0) return *this;
a[x]='\0';
this->lastOperationFailed=0;
num=atoi(a);
return *this;
}

};

void addStudent()
{
int rollNumber;
string name;
char gender;
cout<<"Enter roll nnumber : ";
cin>>rollNumber;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
cout<<"Enter a name : ";
getline(cin,name);
cout<<"Enter Gender : ";
cin>>gender;

OutputFileStream f("students.dat",OutputFileStream::append);

f<<rollNumber;
f<<" ";
f<<name;
f<<"\n";
f<<gender;
f.close();
}

void displayListOfStudent()
{
InputFileStream k("students.dat");
if(k.fail())
{
cout<<"No students added."<<endl;
return;
}
int rollNumber;
string name;
char gender;
while(1)
{
k>>rollNumber;
if(k.fail()) break;
k>>name;
k>>gender;
cout<<"RollNumber : "<<rollNumber<<", Name : "<<name<<", Gender : "<<gender<<endl;
}
k.close();
}

int main()
{
int ch;
char m;
while(1)
{
cout<<"1. Add Student."<<endl;
cout<<"2. Display list of Student"<<endl;
cout<<"3. Exit"<<endl;
cout<<"Enter you choice : ";
scanf("%d",&ch);
while(m=getchar()!='\n');
if(ch==1) addStudent();
if(ch==2) displayListOfStudent();
//if(ch!=1 || ch!=2) break;
if(ch==3) break;
}
}
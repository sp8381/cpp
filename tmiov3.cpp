//File Handling 

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<ios>
#include<limits>
#include<stdlib.h>
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
const static int binary=4;
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
if(mode!=append && mode!=overwrite && mode!=(append | binary) && mode!=(overwrite | binary)) return;
this->mode=mode;
if(mode==append)
{
f=fopen(fileName,"a");
}
else if(mode==overwrite)
{
f=fopen(fileName,"w");
}
else if(mode==(append | binary))
{
f=fopen(fileName,"ab");
}
else if(mode==(overwrite | binary))
{
f=fopen(fileName,"wb");
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

//version 3 method 
void write(char *stream,int size)
{
this->lastOperationFailed=1;
if(this->f==NULL) return;
fwrite(stream,size,1,this->f);
this->lastOperationFailed=0;
return;
}
};

class InputFileStream
{
private:
FILE *f;
int mode;
int lastOperationFailed;
public:
const static int binary=4;
const static int reading=1;
InputFileStream()
{
this->mode=-1;
this->f=NULL;
this->lastOperationFailed=0;
}
InputFileStream(const char *fileName,int mode)
{
this->mode=-1;
this->f=NULL;
this->lastOperationFailed=0;
this->open(fileName,reading);
}
void open(const char *fileName,int mode)
{
if(this->f!=NULL)
{
this->mode=-1;
fclose(this->f);
this->f=NULL;
}
this->lastOperationFailed=1;
if(fileName==NULL) return;
this->mode=mode;
if(mode!=reading && mode!=binary) return;
this->mode=mode;
if(this->mode==reading)
{
f=fopen(fileName,"r");
}
else
{
f=fopen(fileName,"rb");
}
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
//version 3 methods
void read(char *stream,int size)
{
this->lastOperationFailed=1;
if(this->f==NULL) return;
if(feof(this->f)) return;
fread(stream,size,1,f);
if(feof(this->f)) return;
this->lastOperationFailed=0;
}
};

class Student
{
private:
int rollNumber;
char name[21];
char gender;
public:
void setRollNumber(int rollNumber)
{
this->rollNumber=rollNumber;
}
int getRollNumber()
{
return this->rollNumber;
}
void setName(const char *name)
{
strcpy(this->name,name);
}
void getName(char *name)
{
strcpy(name,this->name);
}
void setGender(char gender)
{
this->gender=gender;
}
char getGender()
{
return this->gender;
}
};
void addStudent()
{
int rollNumber;
string name;
char gender;
cout<<"Enter a roll Numeber : ";
cin>>rollNumber;
cin.ignore(1000,'\n');
cout<<"Enter a name : ";
getline(cin,name);
cout<<"Enter gender : ";
cin>>gender;
Student s;
s.setRollNumber(rollNumber);
s.setName(name.c_str());
s.setGender(gender);
OutputFileStream f("students.ppp",ios::app | ios::binary);
f.write((char *)&s,sizeof(Student));
f.close();
cout<<"Student Added"<<endl;
}
void displayListOfStudents()
{
cout<<"Student List Module"<<endl;
InputFileStream k("students.ppp",InputFileStream::binary);
if(k.fail()) 
{
cout<<"No students added."<<endl;
return ;
}
Student s;
while(1)
{
k.read((char *)&s,sizeof(Student));
if(k.fail()) break;
cout<<"Roll Number : "<<s.getRollNumber()<<endl;
char name[21];
s.getName(name);
cout<<"Name : "<<name<<endl;
cout<<"Gender : "<<s.getGender()<<endl;
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
if(ch==2) displayListOfStudents();
//if(ch!=1 || ch!=2) break;
if(ch==3) break;
}
}
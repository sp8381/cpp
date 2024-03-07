//File Handling 

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
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
f=NULL;
this->mode=-1;
lastOperationFailed=0;
}
OutputFileStream(const char *fileName,int mode)
{
this->f=NULL;
this->mode=-1;
lastOperationFailed=0;
this->open(fileName,mode);
}
void open(const char *fileName,int mode)
{
if(f!=NULL) 
{
fclose(f);
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
this->lastOperationFailed=0;
}

void close()
{
this->lastOperationFailed=0;
if(this->f==NULL)  return;
fclose(this->f);
}

int fail()
{
return this->lastOperationFailed;
}

OutputFileStream & operator<<(char c)
{
this->lastOperationFailed=1;
if(f==NULL) return *this;
fputc(c,this->f);
this->lastOperationFailed=0;
return *this;
}
};

class InputFileStream
{
private :
FILE *f;
int lastOperationFailed;
public:
InputFileStream()
{
this->f=NULL;
lastOperationFailed=0;
}
InputFileStream(const char *fileName)
{
this->f=NULL;
lastOperationFailed=0;
this->open(fileName);
}
void open(const char *fileName)
{
if(this->f!=NULL)
{
fclose(this->f);
lastOperationFailed=0;
}
lastOperationFailed=1;
if(fileName==NULL) return;
this->f=fopen(fileName,"r");
if(f==NULL) return;
lastOperationFailed=0;
}

int fail()
{
return this->lastOperationFailed;
}

InputFileStream & operator>>(char &c)
{
this->lastOperationFailed=1;
if(this->f==NULL) return *this;
if(feof(this->f)) return *this;
c=fgetc(this->f);
if(feof(this->f)) return *this;
this->lastOperationFailed=1;
return *this;
}

void close()
{
this->lastOperationFailed=0;
if(this->f!=NULL) fclose(this->f);
}

};




void addFriend()
{
char m;
char name[22],contactNumber[82];
cout<<"Enter a name : ";
fgets(name,22,stdin);
//while(m=getchar()!='\n');
name[strlen(name)-1]='\0';
int i=0;
while(name[i]!='\0')
{
if(name[i]=='!')
{
cout<<"Name cannot contain '!' symbol"<<endl;
return ;
}
i++;
}
cout<<"Enter contact number : ";
fgets(contactNumber,82,stdin);
//while(m=getchar()!='\n');
contactNumber[strlen(contactNumber)-1]='\0';
i=0;
while(contactNumber[i]!='\0')
{
if(contactNumber[i]=='!')
{
cout<<"Contact number cannot contain '!' symbol"<<endl;
return ;
}
if(contactNumber[i]<48 || contactNumber[i]>57)
{
cout<<"Enter numbers"<<endl;
return;
}
i++;
}
OutputFileStream f("friends.ddd",OutputFileStream::append);
i=0;
while(name[i]!='\0')
{
f<<name[i];
i++;
}
f<<'!';
i=0;
while(contactNumber[i]!='\0')
{
f<<contactNumber[i];
i++;
}
f<<'!';
f.close();
cout<<"Friend Added"<<endl;
}



void displayListOfFriend()
{
InputFileStream k("friends.ddd");
if(k.fail())
{
cout<<"No friends added"<<endl;
return;
}
char nm[21],cn[81];
int x=1;
char m;
while(1)
{
k>>m;
if(k.fail()) break;
nm[0]=m;
x=1;
while(1)
{
k>>m;
if(m=='!') break;
nm[x]=m;
x++;
}
nm[x]='\0';
x=0;
while(1)
{
k>>m;
if(m=='!') break;
cn[x]=m;
x++;
}
cn[x]='\0';
cout<<"Name : "<<nm<<", Contact Number : "<<cn<<endl;
}

}

int main()
{
int ch;
char m;
while(1)
{
cout<<"1. Add Friend."<<endl;
cout<<"2. Display list of Friend"<<endl;
cout<<"3. Exit"<<endl;
cout<<"Enter you choice : ";
scanf("%d",&ch);
while(m=getchar()!='\n');
if(ch==1) addFriend();
if(ch==2) displayListOfFriend();
//if(ch!=1 || ch!=2) break;
if(ch==3) break;
}
}
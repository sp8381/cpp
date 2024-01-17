#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>

//ASSINGMENT STARTS HERE 

class FileInputStream
{
FILE *ptr;
public:
FileInputStream(char *fileName,char *mode)
{
ptr=fopen(fileName,mode);
}

void operator>>(char *string)
{
int i=0;
while(string[i]!='\0')
{
fputc(string[i],this->ptr);
i++;
}
}

void operator>>(char c)
{
fputc(c,this->ptr);
}

void close()
{
fclose(ptr);
}

~FileInputStream()
{
fclose(ptr);
}

};
class FileOutputStream
{
FILE *ptr;
public:

FileOutputStream(char *fileName)
{
ptr=fopen(fileName,"r");
if(ptr==NULL) cout<<"Low memory, file not opened"<<endl;
}

void operator<<(char *string)
{
int i=0;
char g;

while(1)
{
g=fgetc(this->ptr);
if(g=='\n' || feof(this->ptr)) break;
string[i]=g;
i++;
}
string[i]='\0';
}

void close()
{
fclose(this->ptr);
}

int failed()
{
if(feof(ptr)) return 1;
return 0;
}

};

//ASSINGMENT ENDS HERE

void addStudent()
{
char rollNumber[21];
char firstName[21];
char lastName[21];
char contactNumber[51];
cout<<"----------------------"<<endl;
cout<<"  Student Add Module"<<endl;
cout<<"----------------------"<<endl;
cout<<"Enter roll number: ";
cin>>rollNumber;
cout<<"Enter first name : ";
cin>>firstName;
cout<<"Enter last name : ";
cin>>lastName;
cout<<"Enter contact number: ";
cin>>contactNumber;

FileInputStream fis("student.data","a");

fis>>rollNumber;
fis>>'\n';
fis>>firstName;
fis>>'\n';
fis>>lastName;
fis>>'\n';
fis>>contactNumber;
fis>>'\n';
fis.close();
cout<<"--------------"<<endl;
cout<<"Student added"<<endl;
cout<<"--------------"<<endl;
}
void displayStudent()
{

FileOutputStream fos("student.data");
if(fos.failed())
{
cout<<"No students added"<<endl;
return;
}

char fn[21];
char ln[21];
char rn[21];
char cn[51];
cout<<"----------------------"<<endl;
cout<<"  Student List "<<endl;
while(1)
{
fos<<rn;
if(fos.failed()) break;
fos<<fn;
fos<<ln;
fos<<cn;

cout<<"----------------------"<<endl;
cout<<"Roll Number : "<<rn<<endl;
cout<<"First Name : "<<fn<<endl;
cout<<"Last Name : "<<ln<<endl;
cout<<"Contact Number : "<<cn<<endl;
}
fos.close();
}
int main()
{
int ch;
do
{
cout<<"----------------------"<<endl;
cout<<"	Menu"<<endl;
cout<<"----------------------"<<endl;
cout<<"1. Add Student "<<endl;
cout<<"2. Display list of Student"<<endl;
cout<<"3. Exit "<<endl;
cout<<"Enter your choice : ";
cin>>ch;
if(ch==1) addStudent();
if(ch==2) displayStudent();
if(ch==3) break;
}
while(ch==1 || ch==2);

return 0;
}

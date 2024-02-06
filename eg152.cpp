#include<iostream>
using namespace std;
//assingment starts here
class FileInputStream
{
public:
};
class FileOutputStream
{
public:
};

//assingment endss here

void addStudent()
{
int rollNumber;
char firstName[21];
char lastName[21];
char contactNumber[51];
cout<<"Enter roll number: ";
cin>>rollNumber;
cout<<"Enter first name : ";
cin>>firstName;
cout<<"Enter last name : ";
cin>>lastName;
cout<<"Enter contact number: ";
cin>>contactNumber;

/*
FileInputStream fos("student.data",FileInputStream::APPEND);
fis<<rollNumber;
fis<<"\n";
fis<<firstName;
fis<<"\n";
fis<<lastName;
fis<<"\n";
fis<<contactNumber;
fis<<"\n";
fis.close();
*/
cout<<"Student added"<<endl;
}
void displayStudent()
{
/*
FileOutputStream fos("student.data");
if(fos.failed())
{
cout<<"No students added"<<endl;
return;
}
char fn[21];
char ln[21];
int rn;
char cn[51];
while(1)
{
fos>>rn;
if(fos.failed()) break;
fos>>fn;
fos>>ln;
fos>>cn;

cout<<"Roll Number : "<<rn<<endl;
cout<<"First Name : "<<fn<<endl;
cout<<"Last Name : "<<ln<<endl;
cout<<"Contact Number : "<<cn<<endl;
}
fis.close();
*/
}
int main()
{
int ch;
do
{
cout<<"1. Add Student "<<endl;
cout<<"2. Display Student"<<endl;
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
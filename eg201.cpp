#include<iostream>
#include<fstream>
#include<ios>
#include<string.h>
using namespace std;

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
ofstream f("students.ppp",ios::app | ios::binary);
f.write((char *)&s,sizeof(Student));
f.close();
cout<<"Student Added"<<endl;
}
void displayListOfStudents()
{
cout<<"Student List Module"<<endl;
ifstream k("students.ppp",ios::binary);
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
int choice;
while(1)
{
cout<<"Student Menu"<<endl;
cout<<"1. Add Student."<<endl;
cout<<"2. Display List Of Student."<<endl;
cout<<"3. Exit"<<endl;
cout<<"Enter a choice : ";
cin>>choice;
cin.ignore(1000,'\n');
if(choice==1) addStudent();
if(choice==2) displayListOfStudents();
if(choice==3) break;
}
return 0;
}
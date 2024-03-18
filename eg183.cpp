#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
using namespace std;

void addFriend()
{
char name[22],contactNumber[82];
cout<<"Enter your name : ";
fgets(name,22,stdin);
fflush(stdin);
name[strlen(name)-1]='\0';
int x=0;
while(name[x]!='\0')
{
if(name[x]=='!')
{
cout<<"Name cannot contail '!' symbol"<<endl;
return;
}
x++;
}
cout<<"Enter contact Number : ";
fgets(contactNumber,82,stdin);
fflush(stdin);
contactNumber[strlen(contactNumber)-1]='\0';
x=0;
while(contactNumber[x]!='\0')
{
if(contactNumber[x]=='!')
{
cout<<"contact number cannot contain '!' symbol"<<endl;
return;
}
x++;
}

ofstream f("students.pp",ios::app);
x=0;
while(name[x]!='\0')
{
f<<name[x];
x++;
}
f<<"!";
x=0;
while(contactNumber[x]!='\0')
{
f<<contactNumber[x];
x++;
}
f<<"!";
f.close();
cout<<"Friend Added."<<endl;
}

void displayListOfFriends()
{
ifstream k("students.pp");
if(k.fail()) 
{
cout<<"No students"<<endl;
return;
}
char name[21],contactNumber[81];
int x=1;
char m;
while(1)
{
//m=fgetc(k);  	//in c programming 
k>>m;
if(k.fail()) break;
name[0]=m;
x=1;
while(1)
{
k>>m;
if(m=='!') break;
name[x]=m;
x++;
}
name[x]='\0';
x=0;
while(1)
{
k>>m;
if(m=='!') break;
contactNumber[x]=m;
x++;
}
contactNumber[x]='\0';
cout<<"Name : "<<name<<", Contact Number : "<<contactNumber<<endl;
}
k.close();
}

int main()
{
int ch;
char m;
while(1)
{
cout<<"1. Add friend"<<endl;
cout<<"2. Display list of friends"<<endl;
cout<<"3. Exit"<<endl;
cout<<"Enter you choice : ";
scanf("%d",&ch);
while(m=getchar()!='\n');
if(ch==1) addFriend();
else if(ch==2) displayListOfFriends();
else if(ch==3) break;
}
return 0;
}
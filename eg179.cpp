//File Handling 

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
using namespace std;

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
ofstream f("friends.ddd",ios::app);
i=0;
while(name[i]!='\0')
{
f<<name[i];
i++;
}
f<<"!";
i=0;
while(contactNumber[i]!='\0')
{
f<<contactNumber[i];
i++;
}
f<<"!";
f.close();
cout<<"Friend Added"<<endl;
}
void displayListOfFriend()
{
ifstream k("friends.ddd");
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
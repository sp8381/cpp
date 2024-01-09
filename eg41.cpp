#include<iostream>
#include<string.h>
using namespace std;
class Person
{
private:
char name[21];
public:
void setName(const char *n)
{
strcpy(name,n);
}
void getName(char *n)
{
strcpy(n,name);
}
};
class Employee
{
private :
int id;
int salary;
public:
void setId(int i)
{
id=i;
}
int getId()
{
return id;
}
void setSalary(int s)
{
salary=s;
}
int getSalary()
{
return salary;
}
};
class Doctor:public Person,public Employee
{
char type[51];
public:
void setType(const char *t)
{
strcpy(type,t);
}
void getType(char *t)
{
strcpy(t,type);
}
};
int main()
{
Doctor d;
d.setName("Chakravarti");
d.setType("Family Doctor");
d.setSalary(50000);
d.setId(921);
int salary;
int id;
char name[21];
char type[51];
d.getName(name);
d.getType(type);
salary=d.getSalary();
id=d.getId();
cout<<"Employee Details"<<endl;
cout<<"Name : "<<name<<endl;
cout<<"Id : " << id<<endl;
cout<<"type : "<<type<<endl;
cout<<"Salary : "<<salary<<endl;
return 0;
}
#include<iostream>
using namespace std;
class IntCollection
{
int *x;
int size;
public:
IntCollection(int req)
{
if(req>0)
{
x=new int[req];
size=req;
}
else
{
x=NULL;
size=0;
}
}
IntCollection(const IntCollection &v)
{
if(v.size>0)
{
size=v.size;
x=new int[size];
for(int i=0;i<size;i++)
{
x[i]=v.x[i];
}
}
else 
{
x=NULL;
size=0;
}
}
void acceptInput()
{
for(int i=0;i<size;i++)
{
cout<<"Enter a number: ";
cin>>x[i];
}
}
void printCollection()
{
for(int i=0;i<size;i++)
{
cout<<x[i]<<endl;
}
}
};
int main()
{
IntCollection c1(5);
c1.acceptInput();
cout<<"Printing collection for c1"<<endl;
c1.printCollection();

IntCollection c2(c1);
c2.acceptInput();
cout<<"Printing collection for c2"<<endl;
c2.printCollection();
cout<<"Printing collection for c1"<<endl;
c1.printCollection();
return 0;
}





/*
//Note : If we do not use the copy constructor in below example then new memory wont be allocated and the same address allocated first time will be used only

#include<iostream>
using namespace std;
class IntCollection
{
int *x;
int size;
public:
IntCollection(int req)
{
if(req>0)
{
x=new int[req];
size=req;
}
else
{
x=NULL;
size=0;
}
}
void acceptInput()
{
for(int i=0;i<size;i++)
{
cout<<"Enter a number: ";
cin>>x[i];
}
}
void printCollection()
{
for(int i=0;i<size;i++)
{
cout<<x[i]<<endl;
}
}
};
int main()
{
IntCollection c1(5);
c1.acceptInput();
cout<<"Printing collection for c1"<<endl;
c1.printCollection();

IntCollection c2(c1);
c2.acceptInput();
cout<<"Printing collection for c2"<<endl;
c2.printCollection();
cout<<"Printing collection for c1"<<endl;
c1.printCollection();
return 0;
}
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class IntCollection
{
int **ptr2ptr;
int size=10;
int totalAdded=0;
int p2p=0;
int p=0;
int count=0;

public:
IntCollection()
{
cout<<"Default constructor called"<<endl;
ptr2ptr=(int **)malloc(size*sizeof(int));
if(ptr2ptr==NULL) 
{
cout<<"**ptr2ptr memory not allocated by constructor "<<endl;
}
for(int i=0;i<size;i++)
{
ptr2ptr[i]=(int *)malloc(10*sizeof(int));
if(ptr2ptr[i]==NULL) 
{
cout<<"*ptr2ptr memory not allocated by constructor "<<endl;
}
}
cout<<"memory allocated by constructor "<<endl;
}

void add(int e)
{
ptr2ptr[p2p][p]=e;
p++;
totalAdded++;

if(p==10) 
{
p2p++;
p=0;
if(p2p==size)
{
cout<<"add10more() call done from add() function"<<endl;
add10more();
}
}
}

void add10more()
{
cout<<"More memory added"<<endl;
int **oldptr2ptr;
oldptr2ptr=ptr2ptr;
//new memory allocation
ptr2ptr=(int **)malloc((size+10)*sizeof(int));
if(ptr2ptr==NULL) 
{
cout<<"**ptr2ptr memory not allocated by constructor "<<endl;
}
for(int i=0;i<size+10;i++)
{
ptr2ptr[i]=(int *)malloc(10*sizeof(int));
if(ptr2ptr[i]==NULL) 
{
cout<<"*ptr2ptr memory not allocated by constructor "<<endl;
}
}

//data copied to new collection
for(int a=0;a<size;a++)
{
for(int b=0;b<10;b++)
{
ptr2ptr[a][b]=oldptr2ptr[a][b];
}
}
cout<<"data copied "<<endl;

//releasing previous allocated memory 
for(int i=0;i<size;i++)
{
free(oldptr2ptr[i]);
}
free(oldptr2ptr);
cout<<"previous memory released "<<endl;

size=size+10;
}

int operator[](int e)
{
if(e>0 && e<=totalAdded )
{
int i,j;
i=(e/10);
j=(e%10);
return (ptr2ptr[i][j]);
}
cout<<"Data not added yet "<<endl;
return 0;
}

~IntCollection()
{
cout<<"Destructor called"<<endl;
for(int i=0;i<p2p;i++)
{
free(ptr2ptr[i]);
}
free(ptr2ptr);
cout<<"memory released by destructor"<<endl;
}

void operator=()
{
if(ic.totalAdded>0)
{
 for(int i=0;i<ic.totalAdded;i++)
 {
  this-add(ic[j]);
 }
}
else
{
 cout<<"Empty collection "<<endl;
 return ;
}
}
}; 

int main()
{
IntCollection ic1;
 
for(int i=0;i<1280;i++)
{
ic1.add(i);
}
cout<<"Printing collection of ic1"<<endl;
for(int j=0;j<1285;j++)
{
cout<<"ic1 ["<<j<<"] : "<<ic1[j]<<endl;
}

IntCollection ic2;
ic2=ic1;
ic2.add(3040);
ic2.add(5040);
cout<<"Printing collection of ic2"<<endl;
for(int i=0;i<ic2.getSize();i++)
{
cout<<"ic2 ["<<i<<"] : "<<ic1[i]<<endl;
}
 
return 0;
}

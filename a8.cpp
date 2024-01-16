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
cout<<"data added in add function ptr2ptr[p2p][p]  "<<ptr2ptr[p2p][p]<<endl;
p++;
totalAdded++;

if(p==10) 
{
cout<<"set value p=0 and p2p++"<<endl;
p2p++;
p=0;
cout<<"size : "<<size<<endl;
if(p2p==size)
{
add10more();
cout<<"size : "<<size<<endl;
cout<<"add10more() call done from add() function"<<endl;
}
}
//cout<<"add function called "<<"TotalAdded "<<totalAdded<<endl;
}

void add10more()
{
cout<<"More memory added"<<endl;
int **oldptr2ptr;
oldptr2ptr=ptr2ptr;
//new memory allocation
ptr2ptr=(int **)malloc((size+10)*sizeof(int));
cout<<"memory allocated for **ptr2ptr"<<endl;
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
cout<<"memory allocated for *ptr2ptr"<<endl;
}

//data copied to new collection
for(int a=0;a<size;a++)
{
cout<<"Outer loop of data copied -----------------"<<endl;
for(int b=0;b<10;b++)
{
ptr2ptr[a][b]=oldptr2ptr[a][b];
cout<<"ptr2ptr[a][b] : "<<ptr2ptr[a][b]<<endl;
}
cout<<"DATA COPIED inner loop "<<endl;
}
cout<<"data copied of outer loop"<<endl;

for(int i=0;i<size;i++)
{
cout<<"memory released oldptr2ptr[i]"<<oldptr2ptr[i]<<endl;
free(oldptr2ptr[i]);
}
cout<<"memory released oldptr2ptr"<<oldptr2ptr<<endl;
free(oldptr2ptr);
cout<<"memory released oldptr2ptr"<<endl;

cout<<"Size : "<<size<<endl;
size=size+10;
cout<<"Size : "<<size<<endl;
//add(e);
}

int operator[](int e)
{
int i,j;
i=(e/10);
j=(e%10);
return (ptr2ptr[i][j]);
}

~IntCollection()
{
cout<<"Destructor called"<<endl;
for(int i=0;i<p2p;i++)
{
cout<<"memory released 1"<<endl;
free(ptr2ptr[i]);
cout<<"memory released 2"<<endl;
}
free(ptr2ptr);
cout<<"memory released 3"<<endl;
}

};
 

int main()
{
IntCollection ic1;
//int num;
for(int i=0;i<128;i++)
{
ic1.add(i);
}
for(int j=0;j<128;j++)
{
cout<<"ic1 ["<<j<<"] : "<<ic1[j]<<endl;
}


//ic1
return 0;
}
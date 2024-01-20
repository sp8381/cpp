//stack using Array List

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

public:
IntCollection()
{
cout<<"Array list Default constructor called"<<endl;
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
//cout<<"memory allocated by constructor "<<endl;
}

void add(int e)
{
ptr2ptr[p2p][p]=e;
//cout<<"data added in add function ptr2ptr[p2p][p]  "<<ptr2ptr[p2p][p]<<endl;
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


template<class T>
class TMStack
{
IntCollection ic;
int top;

public:
TMStack();
TMStack(const TMStack &other);
TMStack & operator=(const TMStack &other);
virtual ~TMStack();
void push(T data);
T pop();
int isEmpty();
int isFull();
};
template<class T>
TMStack<T>::TMStack()
{
this->top=-1;
}
template<class T>
TMStack<T>::TMStack(const TMStack &other)
{
//s1=s2;
this->ic=other.ic;
/*
int e;
e=-1;
while(e!=other.top)
{
this->ic.add(e)=other.x[e];
e++;
}
*/
this->top=other.top;
}
template<class T>
TMStack<T> & TMStack<T>::operator=(const TMStack<T> &other)
{
//this->ic=other.ic;

int e;
e=-1;
while(e!=other.top)
{
this->ic=other.ic;
e--;
}
this->top=other.top;
return *this;
}
template<class T>
TMStack<T>::~TMStack()
{
//do nothing

}
template<class T>
void TMStack<T>::push(T data)
{
//if(top==-1) return;
this->ic.add(data);
top++;
}
template<class T>
T TMStack<T>::pop()
{
if(top==-1) return 0;
T data = this->ic[top--];
return data;
}
template<class T>
int TMStack<T>::isEmpty()
{
return this->top==-1;
}
template<class T>
int TMStack<T>::isFull()
{
//do something
return 0;
}
int main()
{
TMStack<int> s1;
s1.push(10);
s1.push(20);
s1.push(30);
TMStack<int> s2=s1;
s2.push(40);
TMStack<int> s3;
s3=s2;
s3.push(50);
cout<<"popping elements from s1"<<endl;
while(!s1.isEmpty()) cout<<s1.pop()<<endl;
cout<<"popping elements from s2"<<endl;
while(!s2.isEmpty()) cout<<s2.pop()<<endl;
cout<<"popping elements from s3"<<endl;
while(!s3.isEmpty()) cout<<s3.pop()<<endl;

return 0;
}
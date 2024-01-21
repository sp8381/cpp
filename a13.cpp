//TMSinglyLinkedList

#include<iostream>
using namespace std;
#include<stdio.h>

struct data
{
int index;
int data;
struct data *next;
};

class TMList
{
public:
virtual void add(int data,int *success)=0;
//virtual void insertAt(int index,int data,bool *success)=0;
virtual int  removeAt(int index,int *success)=0;
virtual void update(int index,int data,int *success)=0;
virtual int  get(int index,int *success)=0;
virtual void removeAll()=0;
virtual int  getSize()=0;
};

class TMSinglyLinkedList:public TMList
{
struct data *t;
struct data *firstNode;
int index;
struct data *next;

public:
void add(int data,int *success);
int  removeAt(int index,int *success);
void update(int index,int data,int *success);
int  get(int index,int *success);
void removeAll();
int  getSize();

TMSinglyLinkedList();
TMSinglyLinkedList(int index);
TMSinglyLinkedList(const TMSinglyLinkedList &list);
void operator=(const TMSinglyLinkedList &list);
void operator[](int index);
void operator+(const TMSinglyLinkedList &list);
void operator+=(const TMSinglyLinkedList &list);
~TMSinglyLinkedList();
};

TMSinglyLinkedList::TMSinglyLinkedList()
{
firstNode=NULL;
index=0;
next=NULL;
}

void TMSinglyLinkedList::add(int data,int *success)
{
t=(struct data *)malloc(sizeof(struct data));
t->data=data;
t->index=index++;
t->next=NULL;

struct data *j;
if(firstNode==NULL)
{
firstNode=t;
*success=1;
}
else
{
j=firstNode;
while(j->next!=NULL)
{
j=j->next;
}
j->next=t;
*success=1;
}
*success=0;

}

int  TMSinglyLinkedList::removeAt(int index,int *success)
{
int found=0;
struct data *j;
for(t=firstNode;t!=NULL;j=t,t=t->next)
{
if(t->index==index)
{
found=1;
break;
}
}
if(found==0)
{
cout<<"invalid input index in removeAt function"<<endl;
return 0;
}
if(firstNode==t)
{
firstNode=firstNode->next;
}
else
{
j->next=t->next;
}
free(t);	//remove
}

void TMSinglyLinkedList::update(int index,int data,int *success)
{
for(t=firstNode;t!=NULL;t=t->next)
{
if(t->index==index)
{
t->data=data;
*success=1;
return ;
}

}
cout<<"Invalid index in update module "<<endl;
*success=0;

}
int  TMSinglyLinkedList::get(int index,int *success)
{
int found=0;
for(t=firstNode;t!=NULL;t=t->next)
{
if(t->index==index)
{
*success=1;
return t->data;
}
}

*success=0;
cout<<"Invalid index in get function "<<endl;
return 0;

}
void TMSinglyLinkedList::removeAll()
{
while(this->firstNode!=NULL)
{
t=firstNode;
firstNode=firstNode->next;
free(t);
cout<<"memory released by removeAll()."<<endl;
}
}

int  TMSinglyLinkedList::getSize()
{
return this->index;
}


TMSinglyLinkedList::~TMSinglyLinkedList()
{
//releasing memory 
while(firstNode!=NULL)
{
t=firstNode;
firstNode=firstNode->next;
free(t);
cout<<"memory released "<<endl;
}
}


int main()
{
int success=0;

TMSinglyLinkedList list1;
list1.add(10,&success);
list1.add(20,&success);

cout<<list1.get(0,&success)<<endl;
cout<<list1.get(1,&success)<<endl;
cout<<list1.get(2,&success)<<endl;

list1.update(1,40,&success);
cout<<list1.get(1,&success)<<endl;

success=list1.removeAt(1,&success);
cout<<list1.get(1,&success)<<endl;

list1.removeAll();

return 0;
}
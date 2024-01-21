/*assingment TMList, 
TMArrayList, 
TMSinglyLinkedList, 
TMDoublyLinkedList
*/

#include<stdio.h>
#include<iostream>
using namespace std;

class TMList
{
public:
virtual void add(int data,int *success)=0;
virtual void insertAt(int index,int data,int *success)=0;
virtual int  removeAt(int index,int *success)=0;
virtual void update(int index,int data,int *success)=0;
virtual int  get(int index,int *success)=0;
virtual void removeAll()=0;
virtual void clear()=0;
virtual int  getSize()=0;
};

class TMArrayList:public TMList
{
int **ptr2ptr;
int size=0;
int totalAdded=0;
int p2p=0;
int p=0;

public:
void add(int data,int *success);
void insertAt(int index,int data,int *success);
int removeAt(int index,int *success);
void update(int index,int data,int *success);
int get(int index,int *success);
void removeAll();
void clear();
int getSize();
int getTotalSize();

TMArrayList();	//done 
TMArrayList(int size);
TMArrayList(const TMArrayList &list);
void operator=(TMArrayList &list);
int operator[](int e);
void operator+(TMArrayList &list);
void operator+=(TMArrayList &list);
~TMArrayList();	//done 

void add10more();	//done 
};

TMArrayList::TMArrayList()		//default constructor
{
size=10;
ptr2ptr=(int **)malloc(size*sizeof(int));
if(ptr2ptr==NULL) 
{
printf("**ptr2ptr memory not allocated by constructor  \n");
}
for(int i=0;i<size;i++)
{
ptr2ptr[i]=(int *)malloc(10*sizeof(int));
if(ptr2ptr[i]==NULL) 
{
printf("*ptr2ptr memory not allocated by constructor \n");
}
}
//printf("memory allocated \n");

//initializing all values with 0.
for(int i=0;i<size;i++)
{
for(int j=0;j<10;j++)
{
ptr2ptr[i][j]=0;
}
}

}

TMArrayList::TMArrayList(int s)		//parameterised constructor
{
if(s<10 && s>0) size=1;
else
{
size=(s/10);
}
ptr2ptr=(int **)malloc(size*sizeof(int));
if(ptr2ptr==NULL) 
{
cout<<"**ptr2ptr memory not allocated by constructor "<<endl;
}

int i=0;
do
{
ptr2ptr[i]=(int *)malloc(10*sizeof(int));
i++;
}
while(i<size);

for(int i=0;i<size;i++)
{
for(int j=0;j<10;j++)
{
ptr2ptr[i][j]=0;
}
}

}


TMArrayList::TMArrayList(const TMArrayList &list)//copy constructor
{
//allocating memory 
size=list.size;
this->p2p=list.p2p;
this->p=list.p;

ptr2ptr=(int **)malloc(size*sizeof(int));
if(ptr2ptr==NULL) 
{
cout<<"**ptr2ptr memory not allocated by copy constructor "<<endl;
}
for(int i=0;i<size;i++)
{
ptr2ptr[i]=(int *)malloc(10*sizeof(int));
if(ptr2ptr[i]==NULL) 
{
printf("*ptr2ptr memory not allocated by constructor \n");
}
}
//printf("memory allocated \n");


//data copy 
for(int i=0;i<list.size;i++)
{
for(int j=0;j<10;j++)
{
ptr2ptr[i][j]=list.ptr2ptr[i][j];
}
}


}

void TMArrayList::add10more()
{
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


//initializing all values with 0.
for(int i=0;i<size+10;i++)
{
for(int j=0;j<10;j++)
{
ptr2ptr[i][j]=0;
}
}

//data copied to new collection
int a=0;
do
{
for(int b=0;b<10;b++)
{
ptr2ptr[a][b]=oldptr2ptr[a][b];
}
a++;
}while(a<size);

//releasing previous allocated memory 

a=0;
do
{
free(oldptr2ptr[a]);
a++;
}while(a<size);

free(oldptr2ptr);

size=size+10;
}

void TMArrayList::add(int data,int *success)
{
ptr2ptr[p2p][p]=data;
if(ptr2ptr[p2p][p]==data) *success=1;
else *success=0;
p++;
totalAdded++;

if(p==10) 
{
p2p++;
p=0;
if(p2p==size)
{
add10more();
}
}
}

void TMArrayList::insertAt(int index,int data,int *success)
{

while(index>=this->getTotalSize()) 
{
add10more();
}

int i,j;
i=index/10;
j=index%10;
ptr2ptr[i][j]=data;
if(ptr2ptr[i][j]==data) 
{
*success=1;
totalAdded++;
}
else *success=0;
}

int TMArrayList::removeAt(int index,int *success)
{
int i,j;
i=index/10;
j=index%10;
ptr2ptr[i][j]=0;
if(ptr2ptr[i][j]=0) 
{
*success=1;
totalAdded--;
}
else *success=0;
}

void TMArrayList::update(int index,int data,int *success)
{
while((index/10)>size) 
{
add10more();
}
int i,j;
i=index/10;
j=index%10;
ptr2ptr[i][j]=data;
if(ptr2ptr[i][j]==data) 
{
*success=1;
}
else *success=0;
}

int TMArrayList::get(int index,int *success)
{
int i,j;
i=index/10;
j=index%10;
if(ptr2ptr[i][j]==0) 
{
*success=0;
return 0;
}
else 
{
*success=1;
return ptr2ptr[i][j];
}
}

void TMArrayList::removeAll()
{
//setting 0 for all values as some value may be at ramdom index's
for(int i=0;i<size;i++)
{
for(int j=0;j<10;j++)
{
ptr2ptr[i][j]=0;
}
}
}

void TMArrayList::clear()
{
//both have same functionality 
removeAll();
}

int TMArrayList::getSize()
{
return totalAdded;
}

int TMArrayList::getTotalSize()
{
return size*10;
}

int TMArrayList::operator[](int index)
{
if(index>=0 && index<=size*10)
{
int i,j;
i=(index/10);
j=(index%10);
return ptr2ptr[i][j];
}
cout<<"Data not added yet "<<endl;
return 0;
}

void TMArrayList::operator=(TMArrayList &list) 
{


int success=0;
if(list.totalAdded>0)
{
for(int i=0;i<list.getTotalSize();i++)
{
this->add(list[i],&success);

}
}
else
{
 return ;
}
this->p2p=list.p2p;
this->p=list.p;
}

void TMArrayList::operator+(TMArrayList &list)
{

}

void TMArrayList::operator+=(TMArrayList &list) 
{
}

TMArrayList::~TMArrayList()
{
for(int i=0;i<p2p;i++)
{
free(ptr2ptr[i]);
}
free(ptr2ptr);
//cout<<"memory released by destructor"<<endl;
}

int main()
{
TMArrayList list1(10);
int success=0;

list1.add(10,&success);
list1.add(20,&success);
printf("total added : %d\n",list1.getSize());

list1.insertAt(5,50,&success);
printf("success : %d\n",success);
printf("total added : %d\n",list1.getSize());

int y=list1.get(5,&success);
cout<<"value at index 5 : "<<y<<endl;
printf("total added : %d\n",list1.getSize());

list1.update(5,60,&success);
printf("success : %d\n",success);
printf("value at index 5 : %d\n",list1.get(5,&success));


printf("total added : %d\n",list1.getSize());

list1.removeAt(5,&success);
printf("value at index 5 : %d\n",list1.get(5,&success));

printf("total added : %d\n",list1.getSize());

list1.insertAt(9,99,&success);
list1.insertAt(10,111,&success);

//list1.insertAt(11,111,&success);



cout<<"list1 elements"<<endl;
for(int i=0;i<list1.getTotalSize();i++)
{
cout<<list1[i]<<"  ";
}
cout<<endl;

TMArrayList list2=list1;	
list2.add(70,&success);
list2.add(80,&success);
list2.add(90,&success);

cout<<"list2 elements"<<endl;
for(int i=0;i<list2.getTotalSize();i++)
{
cout<<list2[i]<<"  ";
}
cout<<endl;


TMArrayList list3;
list3=list2;
list3.add(110,&success);
list3.add(120,&success);

cout<<"list3 elements"<<endl;
for(int i=0;i<list3.getTotalSize();i++)
{
cout<<list3[i]<<"  ";
}
cout<<endl;

return 0;

}
#include<iostream>
using namespace std;

#define bool int
#define true 1
#define True 1
#define TRUE 1
#define false 0
#define False 0
#define FALSE 0

class Iterator
{
private :
int releaseIteratorAfterIteration;
Iterator *iterator;

public:
Iterator ()
{
this->releaseIteratorAfterIteration=1;
this->iterator=NULL;
}
Iterator(Iterator *iterator)
{
this->releaseIteratorAfterIteration=1;
this->iterator=iterator;
}
Iterator(const Iterator &other)
{
this->releaseIteratorAfterIteration=1;
this->iterator=other.iterator;
}
Iterator & operator=(const Iterator &other)
{
this->iterator=other.iterator;
return *this;
}
virtual int hasMoreElements()
{
if(iterator!=NULL) return this->iterator->hasMoreElements();
return 0;
}
virtual int next()
{
//here also we can add the code to delete the iterator and release the dynamically allocated memory 
if(iterator!=NULL) return this->iterator->next();
return 0;
}
virtual ~Iterator()
{
if(this->releaseIteratorAfterIteration==1) delete this->iterator;
}
void setReleaseIteratorAfterIteration(int releaseIteratorAfterIteration)
{
this-> releaseIteratorAfterIteration = releaseIteratorAfterIteration;
}
};

class Iterable
{
public:
virtual Iterator getIterator()=0;
};

class TMList:public Iterable
{
public:
virtual void add(int data,bool *success)=0;
virtual int get(int index,int *success) const =0;
virtual int getSize() const=0;

virtual void insertAt(int index,int data,bool *success)=0;
virtual int removeAt(int index,int *success)=0;
virtual void update(int index,int data,int *success)=0;
virtual void removeAll()=0;
virtual void clear()=0;
TMList()
{
//cout<<"Default constructor of TMlist"<<endl;
}
TMList(const TMList &other)
{
//cout<<"Copy constructor of TMlist"<<endl;
}

};

/*
default constructor (Done)
parameterised constructor (Done)
copy constructor (Done)
operator=  (Done)
operator+= (Done)
operator[]	self
operator+ 
virtual destructor 

*/

class TMArrayList:public TMList
{
private:
int **ptr;
int capacity;
int size;
bool addRow();
int allocationFlag;		//for handling issue related to operator +


public:
class TMArrayListIterator:public Iterator
{
int index;
int size;
int **ptr;

public:
TMArrayListIterator(int **ptr,int size)
{
this->index=0;
this->size=size;
this->ptr=ptr;
}

/*TMArrayListIterator(const TMArrayListIterator *other)
{
this->index=other.index;
}*/

TMArrayListIterator(const TMArrayListIterator &other)
{
this->index=other.index;
}
TMArrayListIterator & operator=(const TMArrayListIterator &other)
{
this->index=other.index;
return *this;
}
int hasMoreElements()
{
return this->index<size;
}
int next()
{
//here also we can introduce the code to release memor just after the iteration is completed.
if(this->index==size) return 0;
int rowIndex=index/10;
int columnIndex=index%10;
int data=this->ptr[rowIndex][columnIndex];
index++;
return data;
}
};

public:
Iterator getIterator()
{
TMArrayListIterator *tmArrayListIterator; 		//pointer created 
tmArrayListIterator = new TMArrayListIterator(this->ptr,this->size);
Iterator k(tmArrayListIterator);
k.setReleaseIteratorAfterIteration(0);
return k;		//here a local object iss passed and due to relase Iterator flag is 0 
			//memory won't be released.
}





public:
TMArrayList();
TMArrayList(int bufferSize);
TMArrayList(const TMArrayList &other);
TMArrayList(const TMList &other);
~TMArrayList();
TMArrayList & operator=(const TMArrayList &other);
TMArrayList & operator=(const TMList &other);
void operator+=(const TMArrayList &other);
void operator+=(const TMList &other);
TMArrayList operator+(const TMArrayList &other);
TMArrayList operator+(const TMList &other);
int & operator[](int index);	//assingment - (done)
void add(int data,bool *success);
int  get(int index,int *success) const;
int  getSize() const;
void insertAt(int index,int data,bool *success);
int  removeAt(int index,int *success);
void update(int index,int data,int *success);
void removeAll();
void clear();
};
bool TMArrayList::addRow()
{
if(capacity%100==0)
{
int numberOfPointers;
numberOfPointers=this->capacity/10;
int **tmp=new int *[numberOfPointers+10];
if(tmp==NULL) return false;
for(int i=0;i<numberOfPointers;i++) tmp[i]=this->ptr[i];
delete [] this->ptr;
this->ptr=tmp;
}
int i=this->capacity/10;
this->ptr[i]=new int[10];
if(this->ptr[i]==NULL) return false;
this->capacity=this->capacity+10;
return true;
}
TMArrayList::TMArrayList()
{
this->allocationFlag=0;		//for handling issue related to operator +
this->ptr=new int *[10];
this->ptr[0]=new int[10];
this->capacity=10;
this->size=0;
}
TMArrayList::TMArrayList(int bufferSize)
{
this->allocationFlag=0;		//for handling issue related to operator +
if(bufferSize<=0)
{
this->ptr=new int *[10];
this->ptr[0]=new int[10];
this->capacity=10;
this->size=0;
}
else
{
int rows;
int numberOfPointers;
rows=bufferSize/10;
if(bufferSize%10!=0) rows++;
numberOfPointers=rows+(10-(rows%10));
this->ptr=new int *[numberOfPointers];
for(int i=0;i<rows;i++)
{
this->ptr[i]=new int[10];
}
this->capacity=rows*10;
this->size=0;
}
}
TMArrayList::TMArrayList(const TMArrayList &other)
{
this->allocationFlag=0;		//for handling issue related to operator +
int bufferSize=other.size;
if(bufferSize<=0)
{
this->ptr=new int *[10];
this->ptr[0]=new int[10];
this->capacity=10;
this->size=0;
}
else
{
int rows;
int numberOfPointers;
rows=bufferSize/10;
if(bufferSize%10!=0) rows++;
numberOfPointers=rows+(10-(rows%10));
this->ptr=new int *[numberOfPointers];
for(int i=0;i<rows;i++)
{
this->ptr[i]=new int[10];
}
this->capacity=rows*10;
this->size=0;
}
int succ;
for(int i=0;i<other.size;i++)
{
this->add(other.get(i,&succ),&succ);
}
}

TMArrayList::TMArrayList(const TMList &other)
{
cout<<"Parameterised constructor of TMArrayList with parameter TMList &"<<endl;
int rows;
int numberOfPointers;
int bufferSize=other.getSize();
rows=bufferSize/10;
if(bufferSize%10!=0) rows++;
numberOfPointers=rows+(10-(rows%10));
this->ptr=new int *[numberOfPointers];
for(int i=0;i<rows;i++)
{
this->ptr[i]=new int[10];
}
this->capacity=rows*10;
this->size=0;

int succ;
for(int i=0;i<other.getSize();i++)
{
this->add(other.get(i,&succ),&succ);
}
}


TMArrayList::~TMArrayList()
{
if(this->allocationFlag==0)		//for handling issue related to operator +
			 		//or this->ptr!=NULL but ptr is declared const.
{
int rows=this->capacity/10;
int j;
for(j=0;j<rows;j++)
{
delete [] this->ptr[j];
}
delete [] this->ptr;
}
}
TMArrayList & TMArrayList::operator=(const TMArrayList &other)	
{
if(other.allocationFlag==0)		//for handling issue related to operator +
{
this->size=0;
int succ;
for(int e=0;e<other.size;e++)
{
this->add(other.get(e,&succ),&succ);
}
}
else
{
int rows=this->capacity/10;
int j;
for(j=0;j<rows;j++)
{
delete [] this->ptr[j];
}
delete [] this->ptr;
this->ptr=other.ptr;
this->capacity=other.capacity;
this->size=other.size;
//done till here

//other.ptr=NULL;
//other.allocationFlag=0;
}
return *this;
}

TMArrayList & TMArrayList::operator=(const TMList &other)	
{
cout<<"Operator= got called for TMArrayList with parameter TMList"<<endl;
this->size=0;
int succ;
for(int e=0;e<other.getSize();e++)
{
this->add(other.get(e,&succ),&succ);
}
return *this;
}

void TMArrayList::operator+=(const TMArrayList &other)
{
int succ;
for(int e=0;e<other.size;e++)
{
this->add(other.get(e,&succ),&succ);
}
}

void TMArrayList::operator+=(const TMList &other)
{
int succ;
for(int e=0;e<other.getSize();e++) this->add(other.get(e,&succ),&succ);
}

TMArrayList TMArrayList::operator+(const TMArrayList &other)
{
TMArrayList k;
int succ;
for(int e=0;e<this->size;e++) k.add(this->get(e,&succ),&succ);
for(int e=0;e<other.size;e++) k.add(other.get(e,&succ),&succ);
k.allocationFlag=1;			//for handling issue related to operator +
return k;
}


TMArrayList TMArrayList::operator+(const TMList &other)
{
TMArrayList k;
int succ;
for(int e=0;e<this->size;e++) k.add(this->get(e,&succ),&succ);
for(int e=0;e<other.getSize();e++) k.add(other.get(e,&succ),&succ);
k.allocationFlag=1;
return k;
}

int & TMArrayList::operator[](int index)	//(done)
{
int succ;
int faltu;
int rowIndex=index/10;
int columnIndex=index%10;
if(index<0 || index>size)
{
return ptr[rowIndex][columnIndex];
}
return ptr[rowIndex][columnIndex];
}

void TMArrayList::add(int data,bool *success)
{
if(success) *success=false;
if(this->size==this->capacity)
{
if(!addRow()) return ;
}
int rowIndex,columnIndex;
rowIndex=this->size/10;
columnIndex=this->size%10;
this->ptr[rowIndex][columnIndex]=data;
this->size++;
if(success) *success=true;
}

int TMArrayList::get(int index,int *success) const 
{
if(success) *success=false;
if(index<0 || index>=this->size) return 0;
int rowIndex=index/10;
int columnIndex=index%10;
if(success) *success=true;
return ptr[rowIndex][columnIndex];
}

int TMArrayList::getSize() const
{
return this->size;
} 

void TMArrayList::insertAt(int index,int data,bool *success)
{
if(success) *success=false;
if(index<0 || index>this->size) return;
if(index==this->size)
{
this->add(data,success);
return ;
}
bool succ;
int k=this->get(this->size-1,&succ);
this->add(k,&succ);
if(succ==false) return;
int j;
j=this->size-3;
while(j>=index)
{
this->update(j+1,this->get(j,&succ),&succ);
j--;
}
this->update(index,data,&succ);
if(success) *success=true;
}

int  TMArrayList::removeAt(int index,bool *success)
{
if(success) *success=false;
if(index<0 || index>-size) return 0;
bool succ;
int data=this->get(index,&succ);
int j;
int ep=this->size-2;
j=index;
while(j<=ep)
{
this->update(j,this->get(j+1,&succ),&succ);
j++;
}
this->size--;
if(success) *success=true;
return data;
}

void TMArrayList::update(int index,int data,bool *success)
{
if(success) *success=false;
if(index<0 || index>=size) return;
int rowIndex=index/10;
int columnIndex=index%10;
this->ptr[rowIndex][columnIndex]=data;
if(success) *success=true;
}
void TMArrayList::removeAll()
{
this->size=0;
}
void TMArrayList::clear()
{
}

//TMForwardList Implementation starts here 

class TMForwardList:public TMList
{
class TMNode
{
public:
int data;
TMNode *next;
TMNode()
{
this->next=NULL;
}
};

private:
TMNode *start,*end;
int size;
int allocationFlag;		//for handling issue related to operator +

public:
class TMForwardListIterator:public Iterator
{
TMNode *ptr;

public:
TMForwardListIterator()
{
this->ptr=NULL;
}

TMForwardListIterator(TMNode *ptr) 
{
this->ptr=ptr;
}

TMForwardListIterator(const TMForwardListIterator *other)
{
this->ptr=other->ptr;
}

TMForwardListIterator(const TMForwardListIterator &other)
{
this->ptr=other.ptr;
}
TMForwardListIterator & operator=(const TMForwardListIterator &other)
{
this->ptr=other.ptr;
return *this;
}
int hasMoreElements()
{
return this->ptr!=NULL;
}
int next()
{
//here also we can introduce the code to release memor just after the iteration is completed.
if(this->ptr==NULL) return 0;
int data=this->ptr->data;
this->ptr=this->ptr->next;
return data;
}
};

public:
Iterator getIterator()
{
TMForwardListIterator *tmForwardListIterator; 		//pointer created 
tmForwardListIterator=new TMForwardListIterator(this->start);
Iterator k(tmForwardListIterator);
k.setReleaseIteratorAfterIteration(0);
return k;		//here a local object iss passed and due to relase Iterator flag is 0 
			//memory won't be released.
}

public:
TMForwardList();
TMForwardList(int bufferSize);
TMForwardList(const TMForwardList &other);
TMForwardList(const TMList &other);
~TMForwardList();
TMForwardList & operator=(const TMForwardList &other);
TMForwardList & operator=(const TMList &other);
void operator+=(const TMForwardList &other);
void operator+=(const TMList &other);
TMForwardList operator+(const TMForwardList &other);
TMForwardList operator+(const TMList &other);
int operator[](int index);
void add(int data,bool *success);
int  get(int index,int *success) const;
int  getSize() const;
void insertAt(int index,int data,bool *success);
int  removeAt(int index,int *success);
void update(int index,int data,int *success);
void removeAll();
void clear();
};
TMForwardList::TMForwardList()
{
this->start=NULL;
this->end=NULL;
this->size=0;
this->allocationFlag=0;
}
TMForwardList::TMForwardList(int bufferSize)
{
this->start=NULL;
this->end=NULL;
this->size=0;
this->allocationFlag=0;
}
TMForwardList::TMForwardList(const TMForwardList &other)
{
this->start=NULL;
this->end=NULL;
this->size=0;
this->allocationFlag=0;
int succ;
for(int e=0;e<other.getSize();e++)
{
this->add(other.get(e,&succ),&succ);
}
}

TMForwardList::TMForwardList(const TMList &other)
{
cout<<"Parameterised constructor of TMForwardList with parameter TMList &"<<endl;
this->start=NULL;
this->end=NULL;
this->size=0;
this->allocationFlag=0;
int succ;
for(int e=0;e<other.getSize();e++)
{
this->add(other.get(e,&succ),&succ);
}
}

TMForwardList::~TMForwardList()
{
if(allocationFlag==0) this->clear();
}

TMForwardList & TMForwardList::operator=(const TMForwardList &other)	
{
this->clear();
if(allocationFlag==1)
{
this->size=other.size;
this->start=other.start;
this->end=other.end;
}
else
{
int succ;
for(int e=0;e<other.getSize();e++) this->add(other.get(e,&succ),&succ);
}
return *this;
}
TMForwardList & TMForwardList::operator=(const TMList &other)
{
this->clear();
int succ;
for(int e=0;e<other.getSize();e++) this->add(other.get(e,&succ),&succ);
return *this;
}

void TMForwardList::operator+=(const TMForwardList &other)
{
int succ;
for(int e=0;e<other.getSize();e++) this->add(other.get(e,&succ),&succ);
}

void TMForwardList::operator+=(const TMList &other)
{
int succ;
for(int e=0;e<other.getSize();e++) this->add(other.get(e,&succ),&succ);
}

TMForwardList TMForwardList::operator+(const TMForwardList &other)
{
TMForwardList k;
k+=(*this);
k+=other;
return k;
}

TMForwardList TMForwardList::operator+(const TMList &other)
{
TMForwardList k;
k+=(*this);
k+=other;
return k;
}

int TMForwardList::operator[](int index)
{
return 0;
}
void TMForwardList::add(int data,bool *success)
{
if(success) *success=false;
TMNode *t;
t=new TMNode;
if(t==NULL) return;
t->data=data;
if(this->start==NULL)
{
this->start=this->end=t;
}
else
{
this->end->next=t;
this->end=t;
}
this->size++;
if(success) *success=true;
}
int TMForwardList::get(int index,int *success) const 
{
if(success) *success=false;
if(index<0 || index>size) return 0;
TMNode *t;
t=this->start;
for(int x=0;x<index;x++) t=t->next;
if(success) *success=true;
return t->data;
}
int TMForwardList::getSize() const
{
return this->size;
} 
void TMForwardList::insertAt(int index,int data,bool *success)
{
if(success) *success=false;
if(index<0 || index>this->size) return ;
if(index==this->size)
{
this->add(data,success);
return;
}
TMNode *gg;
gg=new TMNode;
if(gg==NULL) return ;
gg->data=data;
TMNode *j,*t;
int x;
t=this->start; 	
for(x=0;x<index;x++)
{
j=t;
t=t->next;
}
if(t==this->start)
{
gg->next=this->start;
this->start=gg;	
}
else
{
j->next=gg;
gg->next=t;
}
this->size++;
if(success) *success=true;
}
int  TMForwardList::removeAt(int index,bool *success)
{
int data=0;
if(success) *success=false;
if(index<0 || index>=this->size) return data;
TMNode *t,*j;
t=this->start;
int x;
for(x=0;x<index;x++)
{
j=t;
t=t->next;
}
data=t->data;
if(t==this->start && t==this->end) //only one node
{
this->start=this->end=NULL;
}
else if(t==this->start) //many but delete first
{
this->start=this->start->next;
}
else if(t==this->end) //many but delete end
{
j->next=NULL;
this->end=j;
}
else 	//neither first nor last
{
j->next=t->next;
}
this->size--;
delete t;
if(success) *success=true;
return data;
}
void TMForwardList::update(int index,int data,bool *success)
{
if(success) *success=false;
if(index<0 || index>=size) return;
TMNode *t;
int x;
for(t=this->start,x=0;x<index;x++,t=t->next);
t->data=data;
if(success) *success=true;
}
void TMForwardList::removeAll()
{
clear();
}
void TMForwardList::clear()
{
TMNode *t;
while(this->start!=NULL) 
{
t=this->start;
this->start=this->start->next;
delete t;
}
this->end=NULL;
this->size=0;
}


int mainTMArrayList()
{
TMArrayList list1(6000);
bool k;
for(int i=100;i<=123;i++)
{
list1.add(i,&k);
}
cout<<"Size of list1 is "<<list1.getSize()<<endl;
for(int i=0;i<list1.getSize();i++)
{
cout<<list1.get(i,&k)<<"  ";
}
cout<<endl;
list1.update(102,5000,&k);
if(k) cout<<"Data upadate at index 102"<<endl;
else cout<<"Unable to update data at index 102"<<endl;
list1.update(3,3030,&k);
if(k)  cout<<"Data updated at index 3"<<endl;
else cout<<"Unable to update data at index 3"<<endl;
cout<<"list1 data"<<endl;
for(int e=0;e<list1.getSize();e++)
{
cout<<list1.get(e,&k)<<" ";
}
cout<<endl;
list1.insertAt(8,6060,&k);
if(k) cout<<"Data inserted at index 8"<<endl;
else cout <<"unable to insert data at index 8"<<endl;
cout<<"list1 data"<<endl;
for(int e=0;e<list1.getSize();e++)
{
cout<<list1.get(e,&k)<<" ";
}
cout<<endl;
int u=list1.removeAt(3,&k);
if(k) cout<<u<<" removed from index 3"<<endl;
else cout<<"Unable to remove data from index 3"<<endl;
cout<<"Contents of list1"<<endl;
for(int e=0;e<list1.getSize();e++)
{
cout<<list1.get(e,&k)<<" ";
}
cout<<endl<<"*******************"<<endl;

TMArrayList list2;
list2=list1;
cout<<"After assigning list2=list1"<<endl;
cout<<"Contents of list2"<<endl;
for(int x=0;x<list2.getSize();x++) cout<<list2.get(x,&k)<<" ";
cout<<endl;
list2.removeAll();
cout<<"list2 contents removed"<<endl;
for(int u=908;u<=1034;u++) list2.add(u,&k);
cout<<"list2 data"<<endl;
for(int x=0;x<list2.getSize();x++) cout<<list2.get(x,&k)<<" ";
cout<<endl<<"list2 Size is "<<list2.getSize()<<endl;

list2+=list1;
cout<<"After list2+=list1 "<<endl;
cout<<"Contents of list2"<<endl;
for(int x=0;x<list2.getSize();x++) cout<<list2.get(x,&k)<<" ";
cout<<endl<<"Size of list2 : "<<list2.getSize()<<endl;
cout<<"Size of list1 : "<<list1.getSize()<<endl;

TMArrayList list3;
list3=list2+list1;
cout<<"list3=list2+list1"<<endl;
cout<<"Contents of list3"<<endl;
for(int x=0;x<list3.getSize();x++) cout<<list3.get(x,&k)<<" ";
cout<<endl;
cout<<"Size of list3 : "<<list3.getSize()<<endl;
cout<<"Size of list2 : "<<list2.getSize()<<endl;
cout<<"Size of list1 : "<<list1.getSize()<<endl;

cout<<"list3 data printed using Operator[] "<<endl;
cout<<"list3[176]"<<list3[176]<<endl;
list3[75]=2021;	//list3.update(75,2021,&succ);
list3[76]=3029;	//(done)
list3[77]=104;	
list3[176]=1204;	
list3[177]=204;	

for(int x=0;x<list3.getSize();x++) cout<<list3[x]<<" ";
cout<<endl<<"Size of list3 : "<<list3.getSize()<<endl;
cout<<"Size of list2 : "<<list2.getSize()<<endl;
cout<<"Size of list1 : "<<list1.getSize()<<endl;
cout<<"list3[73] : "<<list3[73]<<endl;
cout<<"list3[74] : "<<list3[74]<<endl;
cout<<"list3[75] : "<<list3[75]<<endl;
cout<<"list3[76] : "<<list3[76]<<endl;

TMArrayList list4;
list4=list1+list2+list3;
cout<<"list4 size : "<<list4.getSize()<<endl;
cout<<"Contents of list4"<<endl;
for(int x=0;x<list4.getSize();x++) cout<<list4[x]<<" ";
cout<<endl;

return 0;
}

int main()
{
cout<<"Now Iterating TMArrayList"<<endl;
TMForwardList list1;
bool k;
list1.add(100,&k);
list1.add(20,&k);
list1.add(30,&k);
list1.add(543,&k);
list1.add(423,&k);
list1.add(4234,&k);
list1.add(232,&k);

Iterator iterator1=list1.getIterator();
Iterator iterator2=list1.getIterator();
Iterator iterator3=list1.getIterator();

cout<<iterator1.next()<<endl;
cout<<iterator2.next()<<endl;
cout<<iterator3.next()<<endl;
cout<<"**********************"<<endl;
cout<<iterator1.next()<<endl;
cout<<iterator2.next()<<endl;
cout<<iterator3.next()<<endl;

cout<<"Now Iterating TMForwardList"<<endl;
TMForwardList list2;
list2.add(100,&k);
list2.add(20,&k);
list2.add(30,&k);
list2.add(543,&k);
list2.add(423,&k);
list2.add(4234,&k);
list2.add(232,&k);

iterator1=list2.getIterator();
iterator2=list2.getIterator();
iterator3=list2.getIterator();

cout<<iterator1.next()<<endl;
cout<<iterator2.next()<<endl;
cout<<iterator3.next()<<endl;
cout<<"**********************"<<endl;
cout<<iterator1.next()<<endl;
cout<<iterator2.next()<<endl;
cout<<iterator3.next()<<endl;

return 0;
}
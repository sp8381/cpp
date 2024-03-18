#include<iostream>
using namespace std;

#define bool int
#define true 1
#define True 1
#define TRUE 1
#define false 0
#define False 0
#define FALSE 0

template<class T1>
class Iterator
{
private :
int releaseIteratorAfterIteration;
Iterator<T1> *iterator;

public:
Iterator ()
{
this->releaseIteratorAfterIteration=1;
this->iterator=NULL;
}
Iterator(Iterator<T1> *iterator)
{
this->releaseIteratorAfterIteration=1;
this->iterator=iterator;
}
Iterator(const Iterator<T1> &other)
{
this->releaseIteratorAfterIteration=1;
this->iterator=other.iterator;
}
Iterator<T1> & operator=(const Iterator<T1> &other)
{
this->iterator=other.iterator;
return *this;
}
virtual int hasMoreElements()
{
if(iterator!=NULL) return this->iterator->hasMoreElements();
return 0;
}
virtual T1 next()
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

template<class T1>
class Iterable
{
public:
virtual Iterator<T1> getIterator()=0;
};

template<class T1>
class TMList:public Iterable<T1>
{
public:
virtual void add(T1 data,bool *success)=0;
virtual T1 get(int index,int *success) const =0;
virtual int getSize() const=0;

virtual void insertAt(int index,T1 data,bool *success)=0;
virtual T1 removeAt(int index,int *success)=0;
virtual void update(int index,T1 data,int *success)=0;
virtual void removeAll()=0;
virtual void clear()=0;
TMList()
{
//cout<<"Default constructor of TMlist"<<endl;
}
TMList(const TMList<T1> &other)
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


template<class T1>
class TMArrayList:public TMList<T1>
{
private:
T1 **ptr;
int capacity;
int size;
bool addRow();
int allocationFlag;		//for handling issue related to operator +


public:
class TMArrayListIterator:public Iterator<T1>
{
int index;
int size;
T1 **ptr;

public:
TMArrayListIterator(T1 **ptr,int size)
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
T1 next()
{
//here also we can introduce the code to release memor just after the iteration is completed.
if(this->index==size) return 0;
int rowIndex=index/10;
int columnIndex=index%10;
T1 data=this->ptr[rowIndex][columnIndex];
index++;
return data;
}
};

public:

Iterator<T1> getIterator()
{
TMArrayListIterator *tmArrayListIterator; 		//pointer created 
tmArrayListIterator = new TMArrayListIterator(this->ptr,this->size);
Iterator<T1> k(tmArrayListIterator);
k.setReleaseIteratorAfterIteration(0);
return k;		//here a local object iss passed and due to relase Iterator flag is 0 
			//memory won't be released.
}





public:
TMArrayList();
TMArrayList(int bufferSize);
TMArrayList(const TMArrayList &other);
TMArrayList(const TMList<T1> &other);
~TMArrayList();
TMArrayList & operator=(const TMArrayList &other);
TMArrayList & operator=(const TMList<T1> &other);
void operator+=(const TMArrayList &other);
void operator+=(const TMList<T1> &other);
TMArrayList operator+(const TMArrayList &other);
TMArrayList operator+(const TMList<T1> &other);
T1 & operator[](int index);	//assingment - (done)
void add(T1 data,bool *success);
T1  get(int index,int *success) const;
int  getSize() const;
void insertAt(int index,T1 data,bool *success);
T1  removeAt(int index,int *success);
void update(int index,T1 data,int *success);
void removeAll();
void clear();
};
template<class T1>
bool TMArrayList<T1>::addRow()
{
if(capacity%100==0)
{
int numberOfPointers;
numberOfPointers=this->capacity/10;
T1 **tmp=new T1 *[numberOfPointers+10];
if(tmp==NULL) return false;
for(int i=0;i<numberOfPointers;i++) tmp[i]=this->ptr[i];
delete [] this->ptr;
this->ptr=tmp;
}
int i=this->capacity/10;
this->ptr[i]=new T1[10];
if(this->ptr[i]==NULL) return false;
this->capacity=this->capacity+10;
return true;
}
template<class T1>
TMArrayList<T1>::TMArrayList()
{
this->allocationFlag=0;		//for handling issue related to operator +
this->ptr=new T1 *[10];
this->ptr[0]=new T1[10];
this->capacity=10;
this->size=0;
}
template<class T1>
TMArrayList<T1>::TMArrayList(int bufferSize)
{
this->allocationFlag=0;		//for handling issue related to operator +
if(bufferSize<=0)
{
this->ptr=new T1 *[10];
this->ptr[0]=new T1 [10];
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
this->ptr=new T1*[numberOfPointers];
for(int i=0;i<rows;i++)
{
this->ptr[i]=new T1[10];
}
this->capacity=rows*10;
this->size=0;
}
}
template<class T1>
TMArrayList<T1>::TMArrayList(const TMArrayList<T1> &other)
{
this->allocationFlag=0;		//for handling issue related to operator +
int bufferSize=other.size;
if(bufferSize<=0)
{
this->ptr=new T1 *[10];
this->ptr[0]=new T1 [10];
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
this->ptr=new T1 *[numberOfPointers];
for(int i=0;i<rows;i++)
{
this->ptr[i]=new T1[10];
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

template<class T1>
TMArrayList<T1>::TMArrayList(const TMList<T1> &other)
{
//cout<<"Parameterised constructor of TMArrayList with parameter TMList &"<<endl;
int rows;
int numberOfPointers;
int bufferSize=other.getSize();
rows=bufferSize/10;
if(bufferSize%10!=0) rows++;
numberOfPointers=rows+(10-(rows%10));
this->ptr=new T1 *[numberOfPointers];
for(int i=0;i<rows;i++)
{
this->ptr[i]=new T1 [10];
}
this->capacity=rows*10;
this->size=0;

int succ;
for(int i=0;i<other.getSize();i++)
{
this->add(other.get(i,&succ),&succ);
}
}

template<class T1>
TMArrayList<T1>::~TMArrayList()
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

template<class T1>
TMArrayList<T1> & TMArrayList<T1>::operator=(const TMArrayList<T1> &other)	
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

template<class T1>
TMArrayList<T1> & TMArrayList<T1>::operator=(const TMList<T1> &other)	
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

template<class T1>
void TMArrayList<T1>::operator+=(const TMArrayList<T1> &other)
{
int succ;
for(int e=0;e<other.size;e++)
{
this->add(other.get(e,&succ),&succ);
}
}

template<class T1>
void TMArrayList<T1>::operator+=(const TMList<T1> &other)
{
int succ;
for(int e=0;e<other.getSize();e++) this->add(other.get(e,&succ),&succ);
}

template<class T1>
TMArrayList<T1> TMArrayList<T1>::operator+(const TMArrayList<T1> &other)
{
TMArrayList k;
int succ;
for(int e=0;e<this->size;e++) k.add(this->get(e,&succ),&succ);
for(int e=0;e<other.size;e++) k.add(other.get(e,&succ),&succ);
k.allocationFlag=1;			//for handling issue related to operator +
return k;
}


template<class T1>
TMArrayList<T1> TMArrayList<T1>::operator+(const TMList<T1> &other)
{
TMArrayList k;
int succ;
for(int e=0;e<this->size;e++) k.add(this->get(e,&succ),&succ);
for(int e=0;e<other.getSize();e++) k.add(other.get(e,&succ),&succ);
k.allocationFlag=1;
return k;
}

template<class T1>
T1 & TMArrayList<T1>::operator[](int index)	//(done)
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

template<class T1>
void TMArrayList<T1>::add(T1 data,bool *success)
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

template<class T1>
T1 TMArrayList<T1>::get(int index,int *success) const 
{
if(success) *success=false;
if(index<0 || index>=this->size) return 0;
int rowIndex=index/10;
int columnIndex=index%10;
if(success) *success=true;
return ptr[rowIndex][columnIndex];
}

template<class T1>
int TMArrayList<T1>::getSize() const
{
return this->size;
} 

template<class T1>
void TMArrayList<T1>::insertAt(int index,T1 data,bool *success)
{
if(success) *success=false;
if(index<0 || index>this->size) return;
if(index==this->size)
{
this->add(data,success);
return ;
}
bool succ;
T1 k=this->get(this->size-1,&succ);
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

template<class T1>
T1  TMArrayList<T1>::removeAt(int index,bool *success)
{
if(success) *success=false;
if(index<0 || index>=this->size) return 0;
bool succ;
T1 data=this->get(index,&succ);
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

template<class T1>
void TMArrayList<T1>::update(int index,T1 data,bool *success)
{
if(success) *success=false;
if(index<0 || index>=size) return;
int rowIndex=index/10;
int columnIndex=index%10;
this->ptr[rowIndex][columnIndex]=data;
if(success) *success=true;
}

template<class T1>
void TMArrayList<T1>::removeAll()
{
this->size=0;
}

template<class T1>
void TMArrayList<T1>::clear()
{
}

//TMForwardList Implementation starts here 

template<class T1>
class TMForwardList:public TMList<T1>
{
class TMNode
{
public:
T1 data;
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
class TMForwardListIterator:public Iterator<T1>
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

T1 next()
{
//here also we can introduce the code to release memor just after the iteration is completed.
if(this->ptr==NULL) return 0;
T1 data=this->ptr->data;
this->ptr=this->ptr->next;
return data;
}
};

public:
Iterator<T1> getIterator()
{
TMForwardListIterator *tmForwardListIterator; 		//pointer created 
tmForwardListIterator=new TMForwardListIterator(this->start);
Iterator<T1> k(tmForwardListIterator);
k.setReleaseIteratorAfterIteration(0);
return k;		//here a local object iss passed and due to relase Iterator flag is 0 
			//memory won't be released.
}

public:
TMForwardList();
TMForwardList(int bufferSize);
TMForwardList(const TMForwardList &other);
TMForwardList(const TMList<T1> &other);
~TMForwardList();
TMForwardList & operator=(const TMForwardList &other);
TMForwardList & operator=(const TMList<T1> &other);
void operator+=(const TMForwardList &other);
void operator+=(const TMList<T1> &other);
TMForwardList operator+(const TMForwardList &other);
TMForwardList operator+(const TMList<T1> &other);
int operator[](int index);

void add(T1 data,bool *success);
T1  get(int index,int *success) const;
int  getSize() const;
void insertAt(int index,T1 data,bool *success);
T1  removeAt(int index,int *success);
void update(int index,T1 data,int *success);
void removeAll();
void clear();
};

template<class T1>
TMForwardList<T1>::TMForwardList()
{
this->start=NULL;
this->end=NULL;
this->size=0;
this->allocationFlag=0;
}

template<class T1>
TMForwardList<T1>::TMForwardList(int bufferSize)
{
this->start=NULL;
this->end=NULL;
this->size=0;
this->allocationFlag=0;
}
template<class T1>
TMForwardList<T1>::TMForwardList(const TMForwardList<T1> &other)
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

template<class T1>
TMForwardList<T1>::TMForwardList(const TMList<T1> &other)
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

template<class T1>
TMForwardList<T1>::~TMForwardList()
{
if(allocationFlag==0) this->clear();
}

template<class T1>
TMForwardList<T1> & TMForwardList<T1>::operator=(const TMForwardList<T1> &other)	
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
template<class T1>
TMForwardList<T1> & TMForwardList<T1>::operator=(const TMList<T1> &other)
{
this->clear();
int succ;
for(int e=0;e<other.getSize();e++) this->add(other.get(e,&succ),&succ);
return *this;
}

template<class T1>
void TMForwardList<T1>::operator+=(const TMForwardList<T1> &other)
{
int succ;
for(int e=0;e<other.getSize();e++) this->add(other.get(e,&succ),&succ);
}

template<class T1>
void TMForwardList<T1>::operator+=(const TMList<T1> &other)
{
int succ;
for(int e=0;e<other.getSize();e++) this->add(other.get(e,&succ),&succ);
}

template<class T1>
TMForwardList<T1> TMForwardList<T1>::operator+(const TMForwardList<T1> &other)
{
TMForwardList k;
k+=(*this);
k+=other;
return k;
}

template<class T1>
TMForwardList<T1> TMForwardList<T1>::operator+(const TMList<T1> &other)
{
TMForwardList k;
k+=(*this);
k+=other;
return k;
}

template<class T1>
int TMForwardList<T1>::operator[](int index)
{
return 0;
}

template<class T1>
void TMForwardList<T1>::add(T1 data,bool *success)
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

template<class T1>
T1 TMForwardList<T1>::get(int index,int *success) const 
{
if(success) *success=false;
if(index<0 || index>size) return 0;
TMNode *t;
t=this->start;
for(int x=0;x<index;x++) t=t->next;
if(success) *success=true;
return t->data;
}

template<class T1>
int TMForwardList<T1>::getSize() const
{
return this->size;
} 

template<class T1>
void TMForwardList<T1>::insertAt(int index,T1 data,bool *success)
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

template<class T1>
T1  TMForwardList<T1>::removeAt(int index,bool *success)
{
T1 data=0;
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

template<class T1>
void TMForwardList<T1>::update(int index,T1 data,bool *success)
{
if(success) *success=false;
if(index<0 || index>=size) return;
TMNode *t;
int x;
for(t=this->start,x=0;x<index;x++,t=t->next);
t->data=data;
if(success) *success=true;
}

template<class T1>
void TMForwardList<T1>::removeAll()
{
clear();
}

template<class T1>
void TMForwardList<T1>::clear()
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

int main()
{
cout<<"Now Iterating TMArrayList"<<endl;
TMArrayList<char> list1;
bool k;
for(int i=97;i<=122;i++)
{
list1.add(i,&k);
}

TMArrayList<int> list2;
for(int i=101;i<=111;i++)
{
list2.add(i,&k);
}

TMArrayList<float> list3;
for(float i=10.22;i<=21.22;i++)
{
list3.add(i,&k);
}

Iterator<char> iterator1=list1.getIterator();
Iterator<int> iterator2=list2.getIterator();
Iterator<float> iterator3=list3.getIterator();

while(iterator1.hasMoreElements())
{
cout<<iterator1.next()<<" ";
}
cout<<endl;
cout<<list2.get(1,&k)<<endl;
list2.update(1,545,&k);
cout<<list2.get(1,&k)<<endl;
cout<<list2.removeAt(1,&k)<<endl;
cout<<"K : "<<k<<endl;
cout<<list2.get(1,&k)<<endl;
list2.insertAt(1,343,&k);
cout<<list2.get(1,&k)<<endl;

cout<<endl<<"************************"<<endl;
while(iterator2.hasMoreElements())
{
cout<<iterator2.next()<<" ";
}
cout<<endl<<"************************"<<endl;
while(iterator3.hasMoreElements())
{
cout<<iterator3.next()<<" ";
}
cout<<endl<<"************************"<<endl;
cout<<"_______________________________"<<endl;

cout<<"Now Iterating TMForwardList"<<endl;
TMForwardList<char> list4;
for(int i=65;i<=90;i++)
{
list4.add(i,&k);
}

TMForwardList<int> list5;
for(int i=201;i<=211;i++)
{
list5.add(i,&k);
}

TMForwardList<float> list6;
for(float i=51.33;i<=61.33;i++)
{
list6.add(i,&k);
}

Iterator<char> iterator4=list4.getIterator();
Iterator<int> iterator5=list5.getIterator();
Iterator<float> iterator6=list6.getIterator();

while(iterator4.hasMoreElements())
{
cout<<iterator4.next()<<" ";
}
cout<<endl<<"************************"<<endl;
while(iterator5.hasMoreElements())
{
cout<<iterator5.next()<<" ";
}
cout<<endl<<"************************"<<endl;
while(iterator6.hasMoreElements())
{
cout<<iterator6.next()<<" ";
}
cout<<endl<<"************************"<<endl;
cout<<"_____________________________________"<<endl;

TMForwardList<int> list14;
list14.add(100,&k);
list14.add(20,&k);
list14.add(30,&k);
list14.add(543,&k);
list14.add(423,&k);
list14.add(4234,&k);
list14.add(232,&k);

Iterator<int> iterator14=list14.getIterator();

return 0;
}
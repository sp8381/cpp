#include<iostream>
#define bool int
#define true 1
#define True 1
#define TRUE 1
#define false 0
#define False 0
#define FALSE 0

using namespace std;
class TMList
{
public:
virtual void add(int data,bool *success)=0;
virtual int get(int index,int *success) const =0;
virtual int getSize()=0;

virtual void insertAt(int index,int data,bool *success)=0;
virtual int removeAt(int index,int *success)=0;
virtual void update(int index,int data,int *success)=0;
virtual void removeAll()=0;
virtual void clear()=0;
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
TMArrayList();
TMArrayList(int bufferSize);
TMArrayList(const TMArrayList &other);
~TMArrayList();
TMArrayList & operator=(const TMArrayList &other);
void operator+=(const TMArrayList &other);
TMArrayList operator+(const TMArrayList &other);
//int operator[](int index);
int operator[](int index);
void add(int data,bool *success);
int  get(int index,int *success) const;
int  getSize();
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
TMArrayList::~TMArrayList()
{
if(this->allocationFlag==0)		//for handling issue related to operator +
			 		//or this->ptr!=NULL but ptr is declared const.
{
cout<<"Releasing memory "<<this->ptr<<endl;
int rows=this->capacity/10;
int j;
for(j=0;j<rows;j++)
{
delete [] this->ptr[j];
}
cout<<"Finally Releasing memory "<<this->ptr<<endl;
delete [] this->ptr;
}
cout<<"Destructor Ends"<<endl;
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
void TMArrayList::operator+=(const TMArrayList &other)
{
int succ;
for(int e=0;e<other.size;e++)
{
this->add(other.get(e,&succ),&succ);
}
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

int TMArrayList::operator[](int index)
{
int succ;
int faltu;
if(index<0 || index>size)
{
return faltu;
}
//int k=get(index,&succ);
return get(index,&succ);;
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

int TMArrayList::getSize()
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


int main()
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
//cout<<"list3[176]"<<list3[176]<<endl;
//list3[75]=2021;	//list3.add(2021);
//list3[76]=3029;	//this code was not done
//list3[77]=204;	//print faltu

for(int x=0;x<list3.getSize();x++) cout<<list3[x]<<" ";
cout<<endl<<"Size of list3 : "<<list3.getSize()<<endl;
cout<<"Size of list2 : "<<list2.getSize()<<endl;
cout<<"Size of list1 : "<<list1.getSize()<<endl;
cout<<"list3[73] : "<<list3[73]<<endl;
cout<<"list3[74] : "<<list3[74]<<endl;
cout<<"list3[75] : "<<list3[75]<<endl;
cout<<"list3[76] : "<<list3[76]<<endl;

return 0;
}
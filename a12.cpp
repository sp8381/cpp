/*assingment TMList, 
TMArrayList, 
TMSinglyLinkedList, 
TMDoublyLinkedList
*/

#include<iostream>
using namespace std;
#define bool int 

class TMList 
{
public:
virtual void add(int data,bool *success)=0;
virtual void insertAt(int index,int data,bool *success)=0;
virtual int removeAt(int index,int *success)=0;
virtual void update(int index,int *success)=0;
virtual int get(int index,int *success)=0;
virtual void removeAll()=0;
virtual void clear()=0;
virtual int getSize()=0;

};

class TMArrayList:public TMList
{
void add(int data,bool *success);
void insertAt(int index,int data,bool *success);
int removeAt(int index,int *success);
void update(int index,int *success);
int get(int index,int *success);
void removeAll();
void clear();
int getSize();

};

void TMArrayList::add(int data,bool *success)
{
cout<<"Hello add"<<endl;
}

void TMArrayList::insertAt(int index,int data,bool *success)
{
cout<<"Insert At"<<endl;
}
int TMArrayList::removeAt(int index,int *success)
{
return 0;
}
void TMArrayList::update(int index,int *success)
{
}
int TMArrayList::get(int index,int *success)
{
return 0;
}
void TMArrayList::removeAll()
{
}
void TMArrayList::clear()
{
}
int TMArrayList::getSize()
{
return 0;
}

int main()
{
TMArrayList al;

return 0;

}
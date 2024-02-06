#include<iostream>
using namespace std;
class TMStack
{
int x[10];
int top;
public:
TMStack();
TMStack(const TMStack &other);
TMStack & operator=(const TMStack &other);
virtual ~TMStack();
void push(int data);
int pop();
int isEmpty();
int isFull();
};
TMStack::TMStack()
{
this->top=10;
}
TMStack::TMStack(const TMStack &other)
{
int e;
e=9;
while(e>=other.top)
{
this->x[e]=other.x[e];
e--;
}
this->top=other.top;
}
TMStack & TMStack::operator=(const TMStack &other)
{
int e;
e=9;
while(e>=other.top)
{
this->x[e]=other.x[e];
e--;
}
this->top=other.top;
return *this;
}
TMStack::~TMStack()
{
//do nothing 
}
void TMStack::push(int data)
{
if(top==0) return;
this->x[--top]=data;
}
int TMStack::pop()
{
if(top==10) return 0;
int data = this->x[top++];
return data;
}
int TMStack::isEmpty()
{
return this->top==10;
}
int TMStack::isFull()
{
return this->top==0;
}
int main()
{
TMStack s1;
s1.push(10);
s1.push(20);
s1.push(30);
TMStack s2=s1;
s2.push(40);
TMStack s3;
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
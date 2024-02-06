#include<iostream>
using namespace std;
template<class T>
class TMStack
{
T x[10];
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
this->top=10;
}
template<class T>
TMStack<T>::TMStack(const TMStack &other)
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
template<class T>
TMStack<T> & TMStack<T>::operator=(const TMStack<T> &other)
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
template<class T>
TMStack<T>::~TMStack()
{
//do nothing 
}
template<class T>
void TMStack<T>::push(T data)
{
if(top==0) return;
this->x[--top]=data;
}
template<class T>
T TMStack<T>::pop()
{
if(top==10) return 0;
T data = this->x[top++];
return data;
}
template<class T>
int TMStack<T>::isEmpty()
{
return this->top==10;
}
template<class T>
int TMStack<T>::isFull()
{
return this->top==0;
}

class Bulb
{
int wattage;
public:
Bulb()
{
this->wattage=0;
}
Bulb(int wattage)
{
this->wattage=wattage;
}
void setWattage(int wattage)
{
this->wattage=wattage;
}
int getWattage()
{
return this->wattage;
}
};

int main()
{
TMStack<Bulb *> stack;
stack.push(new Bulb());
stack.push(new Bulb(60));
stack.push(new Bulb(100));
Bulb *b;
while(!stack.isEmpty())
{
b=stack.pop();
cout<<"Bulb with wattage "<<b->getWattage()<<endl;
delete b;
}
return 0;
}
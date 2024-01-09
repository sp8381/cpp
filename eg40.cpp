#include<iostream>
using namespace std;
class aaa
{
int x;
public :
int y;
};
class bbb:protected aaa
{
public:
//some members
void abc()
{
y=10;
cout<<"protected accessed can access the member using methods"<<endl;
}
};
class ccc:public aaa
{
public:
void sam()
{
y=20;
cout<<"inheriting publicly can use the public members directly"<<endl;
}
};
class ddd:public ccc
{
public :
void joy()
{
y=30;
}
};
class eee:public ddd
{
public :
void tom()
{
y=200;
}
};
class fff:private eee
{
public:
void tim()
{
y=4000;
}
};
class ggg:public fff
{
public:
void sunny()
{
y=3029;	// cannot access y, y is private.
};
};
int main()
{
aaa a;
a.y=200;
bbb b;
//b.y=20;	//cannot access y,y is as good as private
b.abc();
ccc c;
c.y=200;
c.sam();
return 0;
}

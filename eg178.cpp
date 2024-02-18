#include<iostream>
using namespace std;
class ccc;
class aaa
{
public:
aaa()
{
cout<<"Default constructor of aaa"<<endl;
}
aaa(const aaa &other)
{
cout<<"Copy constructor of aaa"<<endl;
}
};
class bbb:public aaa
{
public:
bbb()
{
cout<<"Default constructor of bbb"<<endl;
}
bbb(const bbb &other)
{
cout<<"Copy constructor of bbb"<<endl;
}
bbb(const aaa &other)
{
cout<<"Parameterised constructor of bbb with parameter of aaa &"<<endl;
}
bbb & operator=(const aaa &other)
{
cout<<"Operator= of bbb with parameter const aaa &"<<endl;
return *this;
}
void operator+=(const bbb &other)
{
cout<<"Operator+= of bbb with parameter bbb &"<<endl;
}
void operator+=(const aaa &other)
{
cout<<"Operator+= of bbb with parameter aaa &"<<endl;
}
};
class ccc:public aaa
{
public:
ccc()
{
cout<<"Default constructor of ccc"<<endl;
}
ccc(const ccc &other)
{
cout<<"Copy constructor of ccc"<<endl;
}
ccc(const aaa &other)
{
cout<<"Parameterised constructor of ccc with parameter aaa &"<<endl;
}
ccc & operator=(const aaa &other)
{
cout<<"Operator= of class ccc with parameter aaa &"<<endl;
return *this;
}
void operator+=(const ccc &other)
{
cout<<"Operator+= of ccc with parameter ccc &"<<endl;
}
void operator+=(const aaa &other)
{
cout<<"Operator+= of ccc with parameter aaa &"<<endl;
}
};
int main()
{
bbb b;	
ccc c(b);
cout<<"***************"<<endl;
ccc d;
bbb e(d);
cout<<"***************************"<<endl;
ccc f;
f=e;	//f=bbb(e);	anonymous object will be created and 
		//	anonymous object will be passed to the copy constructor of ccc
cout<<"---------------"<<endl;
bbb g;
g=f;
cout<<"***************"<<endl;
f+=d;	//same of class ccc
g+=e;	//same of class bbb
g+=f;	//different of class bbb and class ccc
f+=g;
cout<<"-------------------------"<<endl;
return 0;
}
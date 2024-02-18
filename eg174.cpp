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
aaa(const aaa &)
{
cout<<"Copy constructor of aaa"<<endl;
}
//virtual aaa & operator=(const aaa &)=0;
};
class bbb:public aaa
{
public:
bbb()
{
cout<<"Default constructor of bbb"<<endl;
}
bbb(const bbb &)
{
cout<<"Copy constructor of bbb"<<endl;
}
bbb(const ccc &)
{
cout<<"Parameterised constructor of bbb with parameter ccc &"<<endl;
}
};
class ccc:public aaa
{
public:
ccc()
{
cout<<"Default constructor of ccc"<<endl;
}
ccc(const ccc &)
{
cout<<"Copy constructor of ccc"<<endl;
}
ccc(const aaa &)
{
cout<<"Parameterised constructor of ccc with parameter aaa"<<endl;
}
ccc(const bbb &)
{
cout<<"Parameterised constructor of ccc with parameter bbb"<<endl;
}
};
int main()
{
bbb b;	//pehle base ka constructor fir derived ka constructor 
ccc c(b);
return 0;
}
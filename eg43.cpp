#include<iostream>
using namespace std;
class aaa
{
public:
void sam()
{
cout<<"Whatever"<<endl;
}
};
class bbb:public aaa
{
public:
void tom()
{
cout<<"Good"<<endl;
}
};
class ccc:public aaa
{
public:
void joy()
{
cout<<"Great"<<endl;
}
};
class ddd:public bbb,public ccc
{
public:
void bobby()
{
cout<<"better"<<endl;
}
};
int main()
{
ddd d;
d.bbb::sam();
d.ccc::sam();
return 0;
}
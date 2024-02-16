#include<iostream>
using namespace std;
class aaa
{
public:
virtual aaa & operator=(const aaa &)=0;
};
class bbb:public aaa
{
bbb & operator=(const aaa &)
{
}
aaa & operator=(const aaa &)
{
}
};
class ccc:public aaa
{
ccc & operator=(const ccc &)
{
}
aaa & operator=(const aaa &)
{
}
};
int main()
{
bbb b;
ccc c;
b=c;
return 0;
}
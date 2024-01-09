#include<iostream>

class aaa
{
};
class bbb:public aaa
{
};
int main()
{
aaa *a;
a=new bbb;
bbb *b;
b=new aaa;	//error, derive ka pointer base ka object access nahi kar sakta
return 0;
}
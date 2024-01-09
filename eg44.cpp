#include<iostream>
using namespace std;
class aaa
{
public :
void sam()
{
cout<<"Whatever"<<endl;
}
};
class bbb:virtual public aaa
{
public:
void tom()
{
cout<<"Good"<<endl;
}
};
class ccc:virtual public aaa
{
public:
void tim()
{
cout<<"Better"<<endl;
}
};
class ddd:public bbb,public ccc
{
public:
void bob()
{
cout<<"Cool"<<endl;
}
};
int main()
{
ddd d;
d.sam();	//this code will work
	//here both the classes had decared virtual and 
	//this is not a fullproof solution
return 0;
}
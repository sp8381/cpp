//if compiler provides the copy constructor of derived class then base class copy constructor is called after creating object
//and if prrgrammer provides copy constructor then the compiler calls the Base class default constructor before the derived class copy constructor


#include<iostream>
using namespace std;
class aaa
{
public:
aaa()
{
cout<<"Base class default constructor"<<endl;
}
aaa(const aaa &v)
{
cout<<"Base class copy constructor"<<endl;
}
};
class bbb:public aaa
{
public:
bbb()
{
cout<<"Derived class default constructor"<<endl;
}
};
int main()
{
bbb b;
bbb g(b);
return 0;
}




/*
#include<iostream>
using namespace std;
class aaa
{
public:
aaa()
{
cout<<"Base class default constructor"<<endl;
}
};
class bbb:public aaa
{
public:
bbb()
{
cout<<"Derived class default constructor"<<endl;
}
bbb(const bbb &b)
{
cout<<"Derived class default constructor"<<endl;
}
};
int main()
{
bbb b;
bbb g(b);
return 0;
}

*/



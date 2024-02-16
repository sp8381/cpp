#include<iostream>
using namespace std;
int lastCode=0;
class aaa
{
private :
int code;
public:
aaa()
{
this->code=lastCode+1;
lastCode++;
cout<<"Default constructor called with code "<<this->code<<endl;
}
aaa(const aaa &other)
{
this->code=lastCode+1;
lastCode++;
cout<<"Copy constructor called with code "<<this->code<<endl;
cout<<"other's code "<<other.code<<endl;
}
virtual ~aaa()
{
cout<<"Destructor called for code : "<<this->code<<endl;
}
aaa & operator=(const aaa &other)
{
cout<<"Operator= got called for code : "<<this->code<<endl;
cout<<"other's code : "<<other.code<<endl;
return *this;
}
aaa operator+(const aaa &other)
{
aaa k;
cout<<"Operator+ got called for code : "<<this->code<<endl;
cout<<"other's code : "<<other.code<<endl;
return k;
}
};

int main()
{
aaa a1,a2,a3;
cout<<"Object created"<<endl;
a1=a2+a3;
cout<<"The End"<<endl;
return 0;
}
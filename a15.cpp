// assingment 	//now a1=a2+a3	(done)
//TMList a1,a2,a3,a4;
//a1=a2+a3+a4;


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
cout<<"Default constructor called with code "<<this->code<<endl;
}
virtual ~aaa()
{
cout<<"destructor called for object with code "<<this->code<<endl;
}
aaa & operator=(const aaa &other)
{
cout<<"Operator= called for object with code "<<this->code<<endl;
cout<<"other's code"<<other.code<<endl;
return *this;
}
aaa operator+(const aaa &other)
{
cout<<"Operator+ called for object with code "<<this->code<<endl;
cout<<"other's code"<<other.code<<endl;
aaa k;
return k;
}
};
int main()
{
aaa a1,a2,a3,a4;
a1=a2+a3+a4;	//k+a4;	//a1=k
return 0;
}
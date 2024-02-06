#include<iostream>
using namespace std;

template<class T1,class T2>
class aaa
{
T1 x,y;
T2 z;
public:
void setX(T1 x);	//both are same
void setY(T1);		//both are same
void setZ(T2);
T1 getX();
T1 getY();
T2 getZ();
};
template<class T1,class T2>
void aaa<T1,T2>::setX(T1 x)
{
this->x=x;
}
template<class T1,class T2>
void aaa<T1,T2>::setY(T1 y)
{
this->y=y;
}
template<class T1,class T2>
void aaa<T1,T2>::setZ(T2 z)
{
this->z=z;
}
template<class T1,class T2>
T1 aaa<T1,T2>::getX()
{
return this->x;
}
template<class T1,class T2>
T1 aaa<T1,T2>::getY()
{
return this->y;
}
template<class T1,class T2>
T2 aaa<T1,T2>::getZ()
{
return this->z;
}

int main()
{
aaa<int,char> a;
a.setX(10);
a.setY(20);
a.setZ('A');
cout<<a.getX()<<","<<a.getY()<<","<<a.getZ()<<endl;
aaa<char,float> b;
b.setX('A');
b.setY('B');
b.setZ(10.22f);
cout<<b.getX()<<","<<b.getY()<<","<<b.getZ()<<endl;
return 0;
}
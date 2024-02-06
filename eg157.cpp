#include<iostream>
using namespace std;

template<class T1,class T2>
class aaa
{
T1 x,y;
T2 z;
public:
void setX(T1 x)
{
this->x=x;
}
void setY(T1 y)
{
this->y=y;
}
void setZ(T2 z)
{
this->z=z;
}
T1 getX()
{
return this->x;
}
T1 getY()
{
return this->y;
}
T2 getZ()
{
return this->z;
}
};

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
b.setZ(22.2f);
cout<<b.getX()<<","<<b.getY()<<","<<b.getZ()<<endl;
return 0;
}
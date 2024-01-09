#include<iostream>
using namespace std;
class Rectangle
{
int length;
int breadth;
public :
void setLength(int l)
{
length=l;
}
void setBreadth(int b)
{
breadth=b;
}
int getLength()
{
return length;
}
int getBreadth()
{
return breadth;
}
};
class Box:public Rectangle
{
int height;
public:
void setHeight(int h)
{
height=h;
}
int getHeight()
{
return height;
}
};
int main()
{
Box x;
//x.length=2;	//cannot access the private members of class
//x.breadth=3;	//cannot access the private members of class
//x.height=4;	//cannot access the private members of class

x.setLength(10);
x.setBreadth(20);
x.setHeight(30);

cout<<x.getLength()<<endl;
cout<<x.getBreadth()<<endl;
cout<<x.getHeight()<<endl;

return 0;
}
#include<iostream>
using namespace std;
class aaa
{
int faltu;
int x[10];
public:
void setData(int i,int data)
{
x[i]=data;
}
int & operator[](int index)
{
if(index<0 || index>9)
{
faltu=0;
return faltu;
}
return x[index];
}
};

int main()
{
aaa a; // a object is used as an array
a[0]=10;
a[1]=23;
a[2]=434;
a[1020]=302;
cout<<a[0]<<endl;
cout<<a[1]<<endl;
cout<<a[2]<<endl;
cout<<a[20203]<<endl;

return 0;
}
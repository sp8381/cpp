#include<iostream>
using namespace std;
class aaa
{
int faltu;
int x[10];
public:
void setData(int index,int data)
{
x[index]=data;
}
int & operator[](int index)
{
if(index<0 || index>9) return faltu;
return x[index];
}
};
int main()
{
aaa a;
a[0]=10;
a[1]=20;
a[2]=30;
a[1024]=302;
cout<<a[0]<<endl;
cout<<a[1]<<endl;
cout<<a[2]<<endl;
cout<<a[1024]<<endl;
return 0;
}
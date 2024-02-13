#include<iostream>
using namespace std;
class aaa
{
int x[10];
public:
void setData(int index,int data)
{
x[index]=data;
}
int operator[](int index)
{
return x[index];
}
};
int main()
{
aaa a;
a.setData(0,10);
a.setData(1,20);
a.setData(2,30);
cout<<a[0]<<endl;
cout<<a[1]<<endl;
cout<<a[2]<<endl;
return 0;
}
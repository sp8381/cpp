// topic related to operator[] 

#include<iostream>
using namespace std;
class aaa
{
int x[10];
public:
void setData(int i,int data)
{
x[i]=data;
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
a.setData(1,23);
a.setData(2,434);
cout<<a[0]<<endl;
cout<<a[1]<<endl;
cout<<a[2]<<endl;

return 0;
}
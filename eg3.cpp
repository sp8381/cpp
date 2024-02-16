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
int & operator[](int index)
{
return x[index];
}
};
int main()
{
aaa a;
a[0]=10;
a[1]=23;
a[2]=434;
a[1020]=202;
cout<<a[0]<<endl;
cout<<a[1]<<endl;
cout<<a[2]<<endl;

return 0;
}
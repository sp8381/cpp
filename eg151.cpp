// overloading subscript 
//Overloading [] operator 

#include<iostream>
using namespace std;
class aaa
{
int x[10];
public:
aaa()
{
}
void setValueAt(int e,int num)
{
if(e<0 || e>9) return;
x[e]=num;
}
int getSize()
{
return 10;
}
int operator[](int e)
{
if(e<0 || e>9) return 0;
return x[e];
}
};

int main()
{
int num;
aaa a;
for(int i=0;i<=9;i++)
{
cout<<"Enter as number : ";
cin>>num;
a.setValueAt(i,num);
}
cout<<"List of Numbers : "<<endl;
for(int i=0;i<a.getSize();i++)
{
cout<<a[i]<<endl;
}
return 0;
}
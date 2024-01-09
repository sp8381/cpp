#include<iostream>
using namespace std;
class Maruti800
{
public:
void manual()
{
cout<<"Operation details of Maruti800"<<endl;
}
};
class HondaCity
{
public:
void manual()
{
cout<<"Operation details of HondaCity"<<endl;
}
};
int main()
{
int ch;
Maruti800 *m;
HondaCity *h;
cout<<"1. Maruti800"<<endl;
cout<<"2. HondaCity"<<endl;
cout<<"Enter your choice : ";
cin>>ch;
if(ch==1)
{
m=new Maruti800;
m->manual();
}
else if(ch==2)
{
h=new HondaCity;
h->manual();
}
else
{
cout<<"Invalid choice"<<endl;
}
return 0;
}
//Creating template 

#include<iostream>
using namespace std;

template<class cartoon,class whatever>
void add(cartoon x,whatever y)
{
cartoon z;
z=x+y;
cout<<"Total is : "<<z<<endl;
}

int main()
{
add(10,20.22f);	//int , float 
add(33.3f,22);	//float , int 
add(44.4,10);	//double, int 
return 0;
}
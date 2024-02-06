//Creating template 

#include<iostream>
using namespace std;

template<class cartoon>
void add(cartoon x,cartoon y)
{
cartoon z;
z=x+y;
cout<<"Total is : "<<z<<endl;
}

int main()
{
add(10,20);
add(12.22f,22.33f);
add(10,20);
//add(10,20.33f);	//this will not compile 

return 0;
}
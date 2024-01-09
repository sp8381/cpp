//DYNAMIC MEMORY ALLOCATION 
//RELEASING MEMORY BY delete
//using pointer

#include<iostream>
using namespace std;
int main()
{
int *x,*p,y,req,total;
cout<<"Enter your requirenment :";
cin>>req;
if(req<=0)
{
cout<<"Invalid requirements"<<endl;
return 0;
}
x=new int[req];		//DMA
p=x;
y=1;
while(y<=req)
{
cout<<"Enter a number :";
cin>>*p;
p++;
y++;
}

p=x;
total=0;
y=1;
while(y<=req)
{
total=total+*(p);
p++;
y++;
}

cout<<"Total is "<<total<<endl;
delete [] x;		//Releasing memory

return 0;
}
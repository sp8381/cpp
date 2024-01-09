//DYNAMIC MEMORY ALLOCATION 
//RELEASING MEMORY BY delete

#include<iostream>
using namespace std;
int main()
{
int *x,y,req,total;
cout<<"Enter your requirenment :";
cin>>req;
if(req<=0)
{
cout<<"Invalid requirements"<<endl;
return 0;
}
x=new int[req];		//DMA
y=0;
while(y<req)
{
cout<<"Enter a number: ";
cin>>x[y];
y++;
}
y=0;
total=0;
while(y<req)
{
total=total+*(x+y);
y++;
}

cout<<"Total is "<<total<<endl;
delete [] x;		//Releasing memory

return 0;
}
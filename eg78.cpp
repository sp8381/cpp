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
for(y=0;y<req;y++)
{
cout<<"Enter a number : ";
cin>>x[y];
}
for(total=0,y=0;y<req;y++) 	total=total+x[y];

cout<<"Total is "<<total<<endl;
delete [] x;		//Releasing memory

return 0;
}
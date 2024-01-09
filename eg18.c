// this code won't compile 
// because c does not allow function with same name
#include<stdio.h>
void add(int p,int q)
{
printf("Total is %d\n",p+q);
}
void add(int p,int q,int r)
{
printf("Total is %d\n",p+q+r);
}
int main()
{
add(10,20);
add(100,200,300);
return 0;
}
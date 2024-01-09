#include<stdio.h>
int main()
{
int x;
int *p;
*p=120;
printf("x is %d\n",x);
x=210;
printf("x is %d\n",*p);
return 0;
}
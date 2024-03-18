#include<stdio.h>
int main()
{
int x=10203;
int y=303;
char a[81];

sprintf(a,"Cool %d Good %d",x,y);

printf("%s",a);

return 0;
}

/*
sprintf() function number ko string me char by char me convert krke rakh deta hai.

*/
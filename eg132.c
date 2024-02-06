#include<stdio.h>
struct abc
{
int x,y;
char m;
};
int main()
{
struct abc t,g;
t.x=10;
t.y=20;
t.m='A';

g=t;	//t ke 12 byte g ke 12 byte ko assing karo
printf("%d %d %c\n",g.x,g.y,g.m);
return 0;
}
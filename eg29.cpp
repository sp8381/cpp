#include<stdio.h>
struct Rectangle
{
int length;
int breadth;
int area;
};
void createRectangle()
{
struct Rectangle r;
printf("Enter a length: ");
scanf("%d",&r.length);
printf("Enter breadth: ");
scanf("%d",&r.breadth);
r.area=r.length*r.breadth;
printf("Area of length %d and breadth %d is %d\n",r.length,r.breadth,r.area);
}
int main()
{
struct Rectangle t;
printf("Enter length: ");
scanf("%d",&t.length);
printf("Enter breadth: ");
scanf("%d",&t.breadth);
t.area=2*(t.length+t.breadth);
printf("Area of length %d and breadth %d is %d\n",t.length,t.breadth,t.area);
return 0;
}
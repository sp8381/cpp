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
printf("Enter a breadth: ");
scanf("%d",&r.breadth);
r.area=r.length*r.breadth;
printf("Area of rectangle of length %d and breadth %d is :%d\n",r.length,r.breadth,r.area);

}
int main()
{
createRectangle();
return 0;
}
//CREATING REPLIACA OF 	cin>>

#include<stdio.h>
class Input
{
public:
void operator>>(int &k)
{
scanf("%d",&k);
char a;
while((a=getchar())!='\n' && a!=EOF);
}
void operator>>(char &k)
{
scanf("%c",&k);
char a;
while((a=getchar())!='\n' && a!=EOF);
}
void operator>>(const char *(k))
{
scanf("%s",k);
char a;
while((a=getchar())!='\n' && a!=EOF);
}
void operator>>(double &k)
{
scanf("%f",&k);
char a;
while((a=getchar())!='\n' && a!=EOF);
}
void operator>>(float &k)
{
scanf("%f",&k);
}

};
namespace sp
{
Input takeInput;
}
using namespace sp;
int main()
{
int a;
char b;
char c[21];
printf("Enter a number : ");
takeInput>>a;
printf("Enter a char : ");
takeInput>>b;
printf("Enter a string : ");
takeInput>>c;

printf("%d\n",a);
printf("%c\n",b);
printf("%s\n",c);
return 0;
}
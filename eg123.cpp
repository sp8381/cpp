#include<stdio.h>
namespace thinkingmachines
{
class Keyboard
{
public:
Keyboard & operator>>(int j)
{
scanf("%d",&j);
while(getchar()!='\n');
return *this;
}
Keyboard & operator>>(char j)
{
scanf("%c",&j);
while(getchar()!='\n');
return *this;
}
Keyboard & operator>>(char *j)
{
scanf("%s",j);
while(getchar()!='\n');
return *this;
}
};
Keyboard kin;
}
using namespace thinkingmachines;
int main()
{
int x;
char a;
char m[21];
printf("Enter a number : ");
kin>>x;
printf("Enter a character : ");
kin>>a;
printf("Enter a string : ");
kin>>m;
printf("%d\n",x);
printf("%c\n",a);
printf("%s\n",m);


return 0;
}
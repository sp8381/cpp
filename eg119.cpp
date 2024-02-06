//CREAITNG ALIAS OF cout

#include<stdio.h>
class Monitor
{
public:
void operator<<(int x)
{
printf("%d",x);
}
void operator<<(const char *x)
//if we user parameter *x then binardy of x printed 
//and x will print the char value 
{
printf("%s",x);
}
void operator<<(double x)
{
printf("%f",x);
}
void operator<<(float x)
{
printf("%f",x);
}
};

namespace thinkingmachines
{
Monitor mout;
}

using namespace thinkingmachines;
int main()
{
mout<<10;
mout<<'A';
mout<<2054.33;
mout<<20.33;
return 0;
}
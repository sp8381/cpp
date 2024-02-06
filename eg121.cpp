//CREAITNG ALIAS OF cout

#include<stdio.h>
class Monitor
{
public:
Monitor & operator<<(int x)
{
printf("%d",x);
return *this;
}
Monitor & operator<<(const char *x)
{
printf("%s",x);
return *this;
}
Monitor & operator<<(double x)
{
printf("%f",x);
return *this;
}
Monitor & operator<<(float x)
{
printf("%f",x);
return *this;
}

};

namespace thinkingmachines
{
Monitor mout;
}

using namespace thinkingmachines;
int main()
{
mout<<10<<20<<"God is Great"<<52.55<<77.88<<'Z';
return 0;
}
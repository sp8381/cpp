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

Monitor & operator<<(void (*p)())
{
p();
return *this;
}
};

namespace thinkingmachines
{
void newLine()
{
printf("\n");
}
Monitor mout;
}

using namespace thinkingmachines;
int main()
{
mout<<10<<newLine<<20<<newLine<<'A'<<newLine;
mout<<"Very Cool"<<newLine<<77.88<<newLine;
mout<<'A'<<newLine<<'Z'<<newLine;
return 0;
}
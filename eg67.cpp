#include<iostream>
using namespace std;
class aaa
{
public:
void sam()
{
cout<<"Cool"<<endl;
}
static void tom()
{
cout<<"Good"<<endl;
}
};
int main()
{
aaa a;
a.sam();
a.tom();
return 0;
}
//cannot call sam without creating object
//If method is static then no need to create method of class , we can access it directly

#include<iostream>
using namespace std;
class aaa
{
public:
void sam()
{
cout<<"Great"<<endl;
}
static void tom()
{
cout<<"Cool"<<endl;
}
};
int main()
{
aaa::sam();
aaa::tom();
return 0;
}
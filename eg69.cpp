#include<iostream>
using namespace std;
class aaa
{
public:
void sam()
{
cout<<"Cool"<<endl;
//tom();	//can access the static function without creating object
//tiger();	//can access the static function without creating object
}
static void tom()
{
cout<<"Great"<<endl;
//sam();	//cannot access member function without creating object
tiger();	//can access static function from static function
}
static void tiger()
{
cout<<"Tiger"<<endl;
}
};
int main()
{
return 0;
}
//Bhalte k poiinter me Bhalte ka address
//Bhalte Bhalte mtlb aapas me koi relation nhi hai

#include<iostream>
class aaa
{
};
class bbb
{
};
int main()
{
aaa *a;
a=new bbb;	//error, cannot conver bbb to aaa
	//a bbb ko nahi janta
bbb *b;
b=new aaa;	//error, cannot convert aaa to bbb
	//b aaa ko nahi janta 
}
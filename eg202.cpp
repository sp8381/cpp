#include<iostream>
using namespace std;
int main()
{
cout<<(1 | 2)<<endl;
cout<<(2|5)<<endl;
cout<<(1|2|4)<<endl;
cout<<(2|4)<<endl;
cout<<(1|3|5)<<endl;

return 0;
}


/*
In pipe case 1: 

	1 ka binary 
      + 2 ka binary 
      --------------------------
  sum 

00000001
00000010
-------------
00000011	result of case 1

____________________________________
case 2: (1|2|4)

00000001
00000010
00000100
-----------
00000111     result is 7





*/
#include<iostream>
using namespace std;
void prepare(int choice)
{
if(choice==1) cout<<"preparing Veg Pizza without cheese"<<endl;
else if(choice==2) cout<<"preparing Non Veg Pizza without cheese"<<endl;
else if(choice==5) cout<<"preparing Veg Pizza with cheese"<<endl;
else if(choice==6) cout<<"preparing Veg Pizza with cheese"<<endl;
}

int main()
{
int choice;
char addCheese;
cout<<"Select : "<<endl;
cout<<"1. Veg Pizza."<<endl;
cout<<"2. Non Veg Pizza."<<endl;
cout<<"Enter you choice : "<<endl;
cin>>choice;
cin.ignore(1000,'\n');
cout<<"Add cheese(Y/N) : ";
cin>>addCheese;
if(addCheese=='y' || addCheese=='Y') prepare(choice | 4);
else prepare(choice);

return 0;
}
#include<iostream>
#include<string.h>
using namespace std;
class Book
{
char title[36];
public:
void setTitle(const char *t)
{
if(strlen(t)>35) title[0]='\0';
else strcpy(title,t);
}
void getTitle(char *t)
{
strcpy(t,title);
}
};
int main()
{
Book b;
b.setTitle("Silicon Valley");
char ttt[36];
b.getTitle(ttt);
cout<<"Title is : "<<ttt<<endl;
return 0;
}